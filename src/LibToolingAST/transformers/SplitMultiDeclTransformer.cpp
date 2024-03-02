#ifndef CLANG_LIBS
#define CLANG_LIBS

#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"

#endif

#include "ASTFrontendActionTemplate.inl"
#include "include/SourceTextHelper.h"

using namespace clang;

static llvm::cl::OptionCategory
    MyOptionCategory("Split multi decl Transformer");

/**
 * Split multi-decl statement in multiple single-decl statements
 */
class SplitMultiDeclTransformer
    : public RecursiveASTVisitor<SplitMultiDeclTransformer> {
  private:
    ASTContext &Context;
    SourceManager &sm;
    Rewriter &OurRewriter;
    std::map<SourceLocation, std::vector<const VarDecl *>> globalVarDecls;

  public:
    explicit SplitMultiDeclTransformer(ASTContext &Context, Rewriter &OurRewriter) : Context(Context),
                                                                                     sm(Context.getSourceManager()),
                                                                                     OurRewriter(OurRewriter) {};

    bool isRecordDecl(const VarDecl *VD) {
        auto type = VD->getType().getTypePtr();
        while (type->isPointerType() || type->isArrayType()) type = type->getPointeeOrArrayElementType()->getLocallyUnqualifiedSingleStepDesugaredType().getTypePtr();
        if (auto recType = dyn_cast<RecordType>(type)) {
            if (recType->getDecl()->getLocStart() == VD->getLocStart()) return true;
        }
        return false;
    }

    bool VisitVarDecl(const VarDecl *VD) {
        if (!sm.isWrittenInMainFile(VD->getLocStart()))
            return true;
        auto parent = Context.getParents(*VD)[0].get<TranslationUnitDecl>();
        if (parent == nullptr)
            return true;

        if (globalVarDecls.find(VD->getTypeSpecStartLoc()) ==
            globalVarDecls.end()) {
            globalVarDecls[VD->getTypeSpecStartLoc()] = {};
        }
        globalVarDecls[VD->getTypeSpecStartLoc()].emplace_back(VD);

        return true;
    }

    void splitGlobalDecls() {
        for (auto &entry : globalVarDecls) {
            if (entry.second.size() < 2)
                continue;
            std::string rewritten;
            llvm::raw_string_ostream sstream(rewritten);
            SourceLocation endLoc = entry.first;
            for (auto VD : entry.second) {
                auto typePtr = VD->getType().getTypePtr();
                while (typePtr->isArrayType()) {
                    typePtr = typePtr->getPointeeOrArrayElementType();
                }
                if (typePtr->getAsCXXRecordDecl() &&
                    entry.first == typePtr->getAsCXXRecordDecl()->getLocStart())
                    break;
                auto type = VD->getType().getAsString();
                std::string arrayLength;
                if (VD->getType()->isArrayType()) {
                    arrayLength = type.substr(type.find('['), type.size() - 1);
                    type = type.substr(0, type.find('['));
                }
                sstream << type << " " << VD->getNameAsString() << arrayLength;
                if (VD->hasInit() &&
                    getSourceTextStable(Context, VD->getInit()->getLocStart(),
                                        VD->getInit()->getLocEnd()) !=
                        VD->getNameAsString()) {

                    if (VD->getInitStyle() ==
                        VarDecl::InitializationStyle::CallInit) {
                        sstream << "(";
                    } else {
                        sstream << " = ";
                    }
                    VD->getInit()->printPretty(
                        sstream, nullptr,
                        PrintingPolicy(Context.getLangOpts()));
                    if (VD->getInitStyle() ==
                        VarDecl::InitializationStyle::CallInit) {
                        sstream << ")";
                    }
                }
                sstream << ";\n";
                if (sm.isBeforeInTranslationUnit(endLoc, VD->getLocEnd()))
                    endLoc = VD->getLocEnd();
            }
            sstream.flush();
            if (rewritten.empty())
                continue;
            rewritten = rewritten.substr(0, rewritten.size() - 2);
            OurRewriter.ReplaceText(SourceRange(entry.first, endLoc),
                                    rewritten);
        }
    }

    bool VisitDeclStmt(const DeclStmt *DS) {
        if (!sm.isWrittenInMainFile(DS->getLocStart()))
            return true;
        if (DS->isSingleDecl())
            return true;
        auto parent = Context.getParents(*DS)[0].get<ForStmt>();
        if (parent && cast<ForStmt>(parent)->getInit() == DS)
            return true;

        std::string output;
        llvm::raw_string_ostream sstream(output);
        for (auto decl : DS->decls()) {
            if (!isa<VarDecl>(decl))
                continue;
            auto *VD = cast<VarDecl>(decl);
            if (this->isRecordDecl(VD))
                continue;
            auto type = VD->getType().getAsString();
            std::string arrayLength;
            if (VD->getType()->isArrayType() && !isa<TypedefType>(VD->getType().getTypePtr())) {
                arrayLength = type.substr(type.find('['), type.size() - 1);
                type = type.substr(0, type.find('['));
            }
            sstream << type << " " << VD->getNameAsString() << arrayLength;

            if (VD->hasInit() &&
                getSourceTextStable(Context, VD->getInit()->getLocStart(),
                                    VD->getInit()->getLocEnd()) !=
                    VD->getNameAsString()) {

                if (VD->getInitStyle() ==
                    VarDecl::InitializationStyle::CallInit) {
                    sstream << "(";
                } else {
                    sstream << " = ";
                }
                VD->getInit()->printPretty(
                    sstream, nullptr, PrintingPolicy(Context.getLangOpts()));
                if (VD->getInitStyle() ==
                    VarDecl::InitializationStyle::CallInit) {
                    sstream << ")";
                }
            }
            sstream << ";\n";
        }
        if (sstream.str().empty()) return true;

        OurRewriter.ReplaceText(DS->getSourceRange(), sstream.str());

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
        transformer.splitGlobalDecls();
    }

  private:
    SplitMultiDeclTransformer transformer;
};

int main(int argc, const char **argv) {
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                      MyOptionCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                   OptionsParser.getSourcePathList());
    return Tool.run(&*clang::tooling::newFrontendActionFactory<
                     MyFrontendAction<MyASTConsumer>>());
}
