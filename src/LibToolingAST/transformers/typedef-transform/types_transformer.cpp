#ifndef CLANG_LIBS
#define CLANG_LIBS

#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"

#endif

#include "../ASTFrontendActionTemplate.inl"
#include "../include/SourceTextHelper.h"
#include <sstream>

static llvm::cl::OptionCategory MyOptionCategory("Generic Types Transformer");

using namespace clang;

class GenericTypesTransformer : public RecursiveASTVisitor<GenericTypesTransformer> {
  private:
    ASTContext &Context;
    SourceManager &sm;
    Rewriter &OurRewriter;
    std::vector<SourceLocation> changedTypes{};

  public:
    explicit GenericTypesTransformer(ASTContext &Context, Rewriter &OurRewriter)
        : Context(Context), sm(Context.getSourceManager()),
          OurRewriter(OurRewriter){};

    bool VisitDeclStmt(DeclStmt *ds) {
        if (sm.isWrittenInMainFile(ds->getLocStart())) {
            for (auto *decl : ds->decls()) {
                if (auto *vd = dyn_cast<VarDecl>(decl)) {
                    changeType(vd);
                }
            }
        }
        return true;
    }

    void changeType(const DeclaratorDecl *decl) {
        if (sm.isBeforeInTranslationUnit(
                decl->getTypeSourceInfo()->getTypeLoc().getLocStart(),
                decl->getLocation().getLocWithOffset(-2)))
            changeType(decl->getType(), decl->getTypeSourceInfo()->getTypeLoc(),
                       decl->getLocation().getLocWithOffset(-2));
        else
            changeType(decl->getType(), decl->getTypeSourceInfo()->getTypeLoc(),
                       decl->getLocation().getLocWithOffset(-1));
    }

    void changeType(QualType type, TypeLoc typeLoc, SourceLocation endLoc,
                    bool addParens = false) {
        if (std::find(changedTypes.begin(), changedTypes.end(),
                      typeLoc.getLocStart()) != changedTypes.end()) {
            return;
        }
        changedTypes.push_back(typeLoc.getLocStart());
        if (endLoc.isMacroID())
            endLoc = sm.getExpansionRange(endLoc).second;

        /*
        * ToDo: Also chars and bools?
        */
        std::string newType{};
        if (type->isReferenceType()) {
            type = type.getNonReferenceType();
            typeLoc = typeLoc.getAs<ReferenceTypeLoc>().getPointeeLoc();
        }
        if (isa<AutoType>(type)) {
            return;
        }
        if (isa<EnumType>(type.getCanonicalType())) {
            return;
        }

        handleTemplateInit(type.getTypePtr(), typeLoc);
        newType = getNewType(type);
        if (addParens && newType.find(' ') != std::string::npos) {
            newType = "(" + newType;
            newType.append(")");
        }

        if (type->isArrayType()) {
            bool isHiddenInTypedef = false;
            while (type.getAsString().find('[') == std::string::npos) {
                isHiddenInTypedef = true;
                type = type.getDesugaredType(Context);
            }
            auto elementType = cast<ArrayType>(type)->getElementType();
            auto typeLocElement = typeLoc.getUnqualifiedLoc().getAs<ArrayTypeLoc>().getElementLoc();
            while (elementType->isArrayType() && !isa<TypedefType>(elementType.getTypePtr())) {
                while (type.getAsString().find('[') == std::string::npos) {
                    type = type.getDesugaredType(Context);
                }
                elementType = cast<ArrayType>(elementType)->getElementType();
                if (!isHiddenInTypedef)
                    typeLocElement = typeLocElement.getAs<ArrayTypeLoc>().getElementLoc();
            }
            if (isa<EnumType>(elementType.getCanonicalType()))
                return;
            handleTemplateInit(elementType.getTypePtr(), isHiddenInTypedef ? typeLoc : typeLocElement);
            auto origLength = elementType.getUnqualifiedType().getAsString().size();
            newType = getNewType(elementType);
            if (origLength > 0 && !newType.empty()) {
                OurRewriter.ReplaceText(SourceRange(typeLoc.getLocStart(), endLoc), newType);
            }
        } else if (!newType.empty()) {
            newType += " ";
            OurRewriter.ReplaceText(SourceRange(typeLoc.getLocStart(), endLoc), newType);
        }
    }

    std::string getNewType(const QualType &type) const {
        std::string newType{};
        if (type->isIntegerType() && !type->isCharType() && !type->isBooleanType()) {
            if (type->isUnsignedIntegerType()) {
                newType = "unsigned ";
            }
            switch (Context.getTypeInfo(type).Width) {
                case 16:
                    newType += "short";
                    break;
                case 32:
                    newType += "int";
                    break;
                case 64:
                    newType += "long long";
                    break;
                default:
                    llvm::errs() << Context.getTypeInfo(type).Width << " not supported for now\n";
                    assert(false);
            }
        }
        return newType;
    }

    void handleTemplateInit(const Type *type, TypeLoc typeLoc) const {
        if (type->isStructureType() && !isa<TemplateSpecializationType>(type) &&
            !(isa<ElaboratedType>(type) && type->getAs<ElaboratedType>() != nullptr &&
              type->getAs<ElaboratedType>()->getQualifier() != nullptr)) {
            return;
        }
        if (auto elTypeLoc = typeLoc.getAs<ElaboratedTypeLoc>()) {
            auto el = llvm::cast<ElaboratedType>(type);
            if (el->getQualifier() != nullptr && el->getQualifier()->getAsType() != nullptr) {
                handleTemplateInit(el->getQualifier()->getAsType(), elTypeLoc.getQualifierLoc().getTypeLoc());
            }
        }
        if (auto Specialization = typeLoc.getUnqualifiedLoc()
                                      .getAs<TemplateSpecializationTypeLoc>()) {
            for (unsigned int i = 0; i < Specialization.getNumArgs(); i++) {
                auto argLoc = Specialization.getArgLoc(i);
                auto arg = argLoc.getArgument();
                if (arg.getKind() != TemplateArgument::ArgKind::Type) {
                    continue;
                }
                std::string newType = getNewType(arg.getAsType());
                if (!newType.empty()) {
                    OurRewriter.ReplaceText(
                        SourceRange(argLoc.getTypeSourceInfo()
                                        ->getTypeLoc()
                                        .getLocStart(),
                                    argLoc.getTypeSourceInfo()
                                        ->getTypeLoc()
                                        .getLocEnd()),
                        newType);
                } else {
                    handleTemplateInit(
                        argLoc.getTypeSourceInfo()->getType().getTypePtr(),
                        argLoc.getTypeSourceInfo()->getTypeLoc());
                }
            }
        }
    }

    bool VisitExplicitCastExpr(ExplicitCastExpr *ce) {
        if (sm.isWrittenInMainFile(ce->getLocStart()) &&
            !isa<CXXFunctionalCastExpr>(ce)) {
            changeType(ce->getTypeAsWritten(),
                       ce->getTypeInfoAsWritten()->getTypeLoc(),
                       ce->getTypeInfoAsWritten()->getTypeLoc().getLocEnd());
        }
        return true;
    }

    bool VisitCXXFunctionalCastExpr(CXXFunctionalCastExpr *ce) {
        if (sm.isWrittenInMainFile(ce->getLocStart())) {
            changeType(ce->getTypeAsWritten(), ce->getTypeInfoAsWritten()->getTypeLoc(),
                       ce->getTypeInfoAsWritten()->getTypeLoc().getLocEnd(), true);
        }
        return true;
    }

    bool VisitCXXTemporaryObjectExpr(CXXTemporaryObjectExpr *TE) {
        if (sm.isWrittenInMainFile(TE->getLocation())) {
            changeType(TE->getType(), TE->getTypeSourceInfo()->getTypeLoc(),
                       TE->getTypeSourceInfo()->getTypeLoc().getEndLoc());
        }
        return true;
    }

    // ToDo: Find an elegant and stable way to do this, for now just a simple hack and only for 64-bit...
    bool VisitIntegerLiteral(IntegerLiteral *il) {
        if (sm.isWrittenInMainFile(il->getLocStart()) && 
            std::find(changedTypes.begin(), changedTypes.end(), il->getLocStart()) == changedTypes.end()) {
            changedTypes.emplace_back(il->getLocStart());
            auto source = getSourceTextStable(Context, il->getLocStart(), il->getLocEnd());
            std::for_each(source.begin(), source.end(), [](char &c) {
                c = static_cast<char>(std::tolower(c));
            });
            if (il->getType().getAsString() == "long" &&
                source.size() > std::to_string(il->getValue().getSExtValue()).size() &&
                source.find('l') != std::string::npos) {
                OurRewriter.ReplaceText(SourceRange(il->getLocStart(), il->getLocEnd()),
                                        source.replace(source.find('l'), 1, "ll"));
            }
        }
        return true;
    }

    bool VisitFunctionDecl(FunctionDecl *fd) {
        if (sm.isInMainFile(fd->getLocStart()) && !fd->isExternC()) {
            if (fd->getName() == "main") {
                // ToDo: every time, use two params (int argc and char* argv[]) and int as return type
            }
            for (auto *param : fd->parameters()) {
                changeType(param);
            }
            auto returnTypeLoc = fd->getTypeSourceInfo()->getTypeLoc().getAs<FunctionTypeLoc>().getReturnLoc();
            changeType(fd->getReturnType(), returnTypeLoc, fd->getReturnTypeSourceRange().getEnd());
        }
        return true;
    }

    // Catch globals
    bool VisitVarDecl(VarDecl *vd) {
        if (sm.isInMainFile(vd->getLocStart())) {
            auto parents = Context.getParents(*vd);
            for (auto &p : parents) {
                if (auto *node = p.get<Decl>()) {
                    if (isa<TranslationUnitDecl>(node)) {
                        changeType(vd);
                        break;
                    }
                }
            }
        }
        return true;
    }

    // Change types of class/struct members
    bool VisitFieldDecl(FieldDecl *fd) {
        if (sm.isInMainFile(fd->getLocStart())) {
            auto typeLen = getSourceTextStable(Context, fd->getTypeSourceInfo()->getTypeLoc().getBeginLoc(), fd->getTypeSourceInfo()->getTypeLoc().getEndLoc()).size();
            if (fd->getNameAsString() == "") {
                changeType(fd->getType(), fd->getTypeSourceInfo()->getTypeLoc(), fd->getLocation().getLocWithOffset(typeLen));
            } else {
                changeType(fd);
            }
        }
        return true;
    }

    bool VisitTypedefDecl(TypedefDecl *td) {
        if (sm.isWrittenInMainFile(td->getLocation())) {
            auto endLoc = td->getTypeSourceInfo()->getTypeLoc().getEndLoc();
            if (sm.isBeforeInTranslationUnit(
                td->getTypeSourceInfo()->getTypeLoc().getLocStart(), 
                td->getLocation().getLocWithOffset(-2))) {
                endLoc = td->getLocation().getLocWithOffset(-2);
            }
            changeType(td->getTypeSourceInfo()->getType(),
                       td->getTypeSourceInfo()->getTypeLoc(),
                       endLoc);
        }
        return true;
    }

    bool VisitTypeAliasDecl(TypeAliasDecl *tad) {
        if (sm.isWrittenInMainFile(tad->getLocation())) {
            changeType(tad->getUnderlyingType(),
                       tad->getTypeSourceInfo()->getTypeLoc(),
                       tad->getTypeSourceInfo()->getTypeLoc().getEndLoc());
        }
        return true;
    }

};

/* ****************** ************** **************** */

class MyASTConsumer : public ASTConsumer {
  public:
    explicit MyASTConsumer(ASTContext &Context, Rewriter &OurRewriter)
        : transformer(Context, OurRewriter) {}

    void HandleTranslationUnit(ASTContext &Context) override {
        transformer.TraverseDecl(Context.getTranslationUnitDecl());
    }

  private:
    GenericTypesTransformer transformer;
};

int main(int argc, const char **argv) {
    assert(sizeof(long long) ==
           sizeof(long)); // We assume this for 64-bit Systems
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                      MyOptionCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                   OptionsParser.getSourcePathList());
    return Tool.run(&*clang::tooling::newFrontendActionFactory<
                     MyFrontendAction<MyASTConsumer>>());
}