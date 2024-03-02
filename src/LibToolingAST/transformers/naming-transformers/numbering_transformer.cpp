#ifndef CLANG_LIBS
#define CLANG_LIBS

#include "clang/AST/RecursiveASTVisitor.h"
#include "llvm/Support/CommandLine.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"

#endif

#include "../ASTFrontendActionTemplate.inl"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"

#include "../include/SourceTextHelper.h"
#include "TypeMapping.h"
#include "VariableNameTransformer.h"
#include <regex>

using namespace clang;
using namespace clang::ast_matchers;

// ** These are the command line options **
static llvm::cl::OptionCategory MyOptionCategory("Global Const Include Transformer");

class RenamingTransformer : public MatchFinder::MatchCallback {
  public:
    explicit RenamingTransformer(
        ASTContext &Context, Rewriter &OurRewriter,
        VariableNameTransformer &variableNameTransformer, TypeMapping &typeMap)
        : OurRewriter(OurRewriter), context(Context),
          variableNameTransformer(variableNameTransformer), typeMap(typeMap){};

    virtual void run(const MatchFinder::MatchResult &Result) {
        ASTContext *Context = Result.Context;
        SourceManager &Manager = Context->getSourceManager();

        const auto *RD = Result.Nodes.getNodeAs<RecordDecl>("recordDecl");
        if (RD && Manager.isWrittenInMainFile(Manager.getSpellingLoc(RD->getLocStart())) &&
            std::find(renamed.begin(), renamed.end(), RD->getLocStart()) == renamed.end() &&
            std::find(renamed.begin(), renamed.end(), RD->getLocation()) == renamed.end() &&
            !RD->getNameAsString().empty()) {
            renamed.emplace_back(RD->getLocStart());
            renamed.emplace_back(RD->getLocation());

            std::stringstream stringstream;
            if (recordMap.count(RD->getNameAsString()) == 0) {
                stringstream << "record_" << recordCounter++;
                recordMap[RD->getNameAsString()] = stringstream.str();
            } else {
                stringstream << recordMap[RD->getNameAsString()];
            }
            // ToDo: For now just a simple hack, for stability maybe another way has to be found
            std::string typeName = RD->isClass() ? RD->getNameAsString() : RD->getKindName().str() + " " +
                                                                           RD->getNameAsString();
            std::string alternativeName = RD->isClass() ? RD->getQualifiedNameAsString() :
                                          RD->getKindName().str() + " " + RD->getQualifiedNameAsString();
            assert(typeName == getSourceTextStable(*Context, RD->getLocStart(),
                                                   RD->getLocStart().getLocWithOffset(typeName.size() - 1)));
            OurRewriter.ReplaceText(
                    SourceRange(RD->getLocation(),
                                RD->getLocation().getLocWithOffset(RD->getNameAsString().size() - 1)),
                    stringstream.str());
            auto typeLocs = typeMap.getTypeNameToTypeLoc(typeName);
            std::vector<SourceLocation> renamedTypes{RD->getLocStart()};
            for (auto curTypeLoc : typeLocs) {
                if (std::find(renamedTypes.begin(), renamedTypes.end(), curTypeLoc.getLocStart()) !=
                    renamedTypes.end()) {
                    continue;
                }
                if (std::find(renamed.begin(), renamed.end(), curTypeLoc.getLocStart()) != renamed.end()) {
                    continue;
                }
                if (std::find(renamed.begin(), renamed.end(), curTypeLoc.getLocStart().getLocWithOffset(strlen("struct "))) != renamed.end()) {
                    continue;
                }
                renamedTypes.emplace_back(curTypeLoc.getLocStart());
                renamedTypes.emplace_back(curTypeLoc.getLocEnd());
                renamedTypes.emplace_back(curTypeLoc.getLocStart().getLocWithOffset(strlen("struct ")));
                renamed.emplace_back(curTypeLoc.getLocStart().getLocWithOffset(strlen("struct ")));
                renamed.emplace_back(curTypeLoc.getLocStart());
                if (curTypeLoc.getType()->isReferenceType() || curTypeLoc.getType()->isPointerType()) {
                    curTypeLoc = curTypeLoc.getAs<ReferenceTypeLoc>().getPointeeLoc();
                }
                if (getSourceTextStable(*Context, curTypeLoc.getLocStart(), curTypeLoc.getLocEnd()).find("struct ") !=
                    std::string::npos) {
                    OurRewriter.ReplaceText(curTypeLoc.getSourceRange(), "struct " + stringstream.str());
                } else if (getSourceTextStable(*Context, curTypeLoc.getLocStart(), curTypeLoc.getLocEnd()).find("union ") !=
                    std::string::npos) {
                    OurRewriter.ReplaceText(curTypeLoc.getSourceRange(), "union " + stringstream.str());
                } else {
                    OurRewriter.ReplaceText(curTypeLoc.getSourceRange(), stringstream.str());
                }
            }
            if (alternativeName != typeName) {
                typeLocs = typeMap.getTypeNameToTypeLoc(alternativeName);
                for (auto curTypeLoc : typeLocs) {
                    if (std::find(renamedTypes.begin(), renamedTypes.end(), curTypeLoc.getLocStart()) !=
                        renamedTypes.end()) {
                        continue;
                    }
                    if (std::find(renamed.begin(), renamed.end(), curTypeLoc.getLocStart()) != renamed.end()) {
                        continue;
                    }
                    if (std::find(renamed.begin(), renamed.end(), curTypeLoc.getLocStart().getLocWithOffset(strlen("struct "))) != renamed.end()) {
                        continue;
                    }
                    renamedTypes.emplace_back(curTypeLoc.getLocStart());
                    renamed.emplace_back(curTypeLoc.getLocStart());
                    if (curTypeLoc.getType()->isReferenceType() || curTypeLoc.getType()->isPointerType()) {
                        curTypeLoc = curTypeLoc.getAs<ReferenceTypeLoc>().getPointeeLoc();
                    }
                    OurRewriter.ReplaceText(curTypeLoc.getSourceRange(), stringstream.str());
                }
            }
            if (auto record = dyn_cast<CXXRecordDecl>(RD)) {
                for (auto constructor : record->ctors()) {
                    if (constructor->isImplicit()) {
                        continue;
                    }
                    if (std::find(renamed.begin(), renamed.end(), constructor->getLocation()) != renamed.end())
                        continue;
                    renamed.emplace_back(constructor->getLocation());
                    OurRewriter.ReplaceText(constructor->getNameInfo().getSourceRange(), stringstream.str());
                }
                if (record->getDestructor() && !record->getDestructor()->isImplicit()) {
                    assert(false && "Not implemented so far");
                }
            }
        }

        const auto *CD = Result.Nodes.getNodeAs<CXXConstructorDecl>("cxxconstr");
        if (CD && Manager.isWrittenInMainFile(Manager.getSpellingLoc(CD->getLocation())) && !CD->isImplicit()) {
            for (auto parm : CD->parameters()) {
                if (std::find(renamedVars.begin(), renamedVars.end(), cast<VarDecl>(parm)) != renamedVars.end())
                    continue;
                renamedVars.push_back(cast<VarDecl>(parm));
                std::stringstream stringstream;
                stringstream << "var_" << varCounter++;
                variableNameTransformer.renamevariabledecl(cast<VarDecl>(parm), stringstream.str());
            }
        }

        const auto *pFieldDecl = Result.Nodes.getNodeAs<FieldDecl>("fieldDecl");
        if (pFieldDecl && Manager.isWrittenInMainFile(Manager.getSpellingLoc(pFieldDecl->getLocation())) &&
            std::find(renamedVars.begin(), renamedVars.end(), cast<VarDecl>(pFieldDecl)) == renamedVars.end() &&
            testCounter < 1) {
            renamedVars.push_back(cast<VarDecl>(pFieldDecl));
            std::stringstream stringstream;
            stringstream << "field_" << fieldCounter++;
            variableNameTransformer.renamevariabledecl(cast<VarDecl>(pFieldDecl), stringstream.str());
            if (fieldNameMapping.find(pFieldDecl->getParent()) == fieldNameMapping.end()) {
                fieldNameMapping[pFieldDecl->getParent()] = {};
            }
            auto& fieldMapping = fieldNameMapping[pFieldDecl->getParent()];
            if (std::find_if(fieldMapping.begin(), fieldMapping.end(), [pFieldDecl](const std::pair<std::string, std::string>& p) { return p.first == pFieldDecl->getNameAsString(); }) == fieldMapping.end()) {
                fieldMapping.emplace_back(std::make_pair<std::string, std::string>(pFieldDecl->getNameAsString(), stringstream.str()));
            }
        }

        const auto *VD = Result.Nodes.getNodeAs<VarDecl>("varDecl");
        if (VD && Manager.isWrittenInMainFile(Manager.getSpellingLoc(VD->getLocStart())) && !VD->isImplicit() &&
            !isInTemplateSpecification(VD) &&
            std::find(renamedVars.begin(), renamedVars.end(), VD) == renamedVars.end() &&
            (VD->getParentFunctionOrMethod() == nullptr ||
             !isConstructorOrDestructor(dyn_cast<FunctionDecl>(VD->getParentFunctionOrMethod()))) &&
            !VD->getNameAsString().empty()) {
            renamedVars.push_back(VD);
            std::stringstream stringstream;
            stringstream << "var_" << varCounter++;
            if (auto parm = dyn_cast<ParmVarDecl>(VD)) {
                auto function = cast<FunctionDecl>(VD->getParentFunctionOrMethod());
                if (function && !function->isThisDeclarationADefinition() && function->getDefinition()) {
                    auto definition = function->getDefinition();
                    auto parm_it = std::find(function->param_begin(), function->param_end(), parm);
                    assert(parm_it != function->param_end());
                    auto id = std::distance(function->param_begin(), parm_it);
                    auto definitionParm = definition->getParamDecl(id);
                    assert (std::find(renamedVars.begin(), renamedVars.end(), definitionParm) == renamedVars.end());
                    renamedVars.push_back(definitionParm);
                    variableNameTransformer.renamevariabledecl(definitionParm, stringstream.str());
                }
            }
            variableNameTransformer.renamevariabledecl(VD, stringstream.str());
        }

        const auto *CE = Result.Nodes.getNodeAs<CallExpr>("callExpr");
        if (CE && Manager.isWrittenInMainFile(Manager.getSpellingLoc(CE->getLocStart())) && CE->getCalleeDecl() &&
            Manager.isWrittenInMainFile(Manager.getSpellingLoc(CE->getCalleeDecl()->getLocation())) &&
            !isConstructorOrDestructor(cast<FunctionDecl>(CE->getCalleeDecl())) &&
            std::find(renamed.begin(), renamed.end(), Manager.getSpellingLoc(CE->getExprLoc())) == renamed.end() &&
            isa<FunctionDecl>(CE->getCalleeDecl()) && cast<FunctionDecl>(CE->getCalleeDecl())->isDefined()) {

            renamed.push_back(Manager.getSpellingLoc(CE->getExprLoc()));

            const std::string &funcName = cast<FunctionDecl>(CE->getCalleeDecl())->getNameAsString();

            if (funcName.rfind("operator", 0) != 0 && cast<FunctionDecl>(CE->getCalleeDecl())->getBuiltinID() == 0) {
                if (functionNameMap.find(funcName) == functionNameMap.end()) {
                    std::stringstream stringstream;
                    stringstream << "func_" << funcCounter++;
                    functionNameMap[funcName] = stringstream.str();
                }
                if (auto *MCE = dyn_cast<CXXMemberCallExpr>(CE)) {
                    auto *ME = cast<MemberExpr>(MCE->getCallee());
                    OurRewriter.ReplaceText(SourceRange(Manager.getSpellingLoc(ME->getMemberLoc()),
                                                        Manager.getSpellingLoc(ME->getLocEnd())),
                                            functionNameMap[funcName]);
                } else {
                    OurRewriter.ReplaceText(Manager.getSpellingLoc(CE->getCallee()->getLocStart()), funcName.length(),
                                            functionNameMap[funcName]);
                }
            }
        }

        const auto *FD = Result.Nodes.getNodeAs<FunctionDecl>("functionDecl");
        if (FD && Manager.isWrittenInMainFile(Manager.getSpellingLoc(FD->getLocation())) && !FD->isMain() &&
            std::find(renamed.begin(), renamed.end(), Manager.getSpellingLoc(FD->getLocation())) == renamed.end() &&
            isConstructorOrDestructor(FD)) {
            renamed.emplace_back(Manager.getSpellingLoc(FD->getLocation()));
            std::stringstream stringstream;
            if (recordMap.count(FD->getNameAsString()) == 0) {
                stringstream << "record_" << recordCounter++;
                recordMap[FD->getNameAsString()] = stringstream.str();
            } else {
                stringstream << recordMap[FD->getNameAsString()];
            }
            OurRewriter.ReplaceText(SourceRange(Manager.getSpellingLoc(FD->getNameInfo().getLocStart()),
                                                Manager.getSpellingLoc(FD->getNameInfo().getLocEnd())),
                                    stringstream.str());
        }
        if (FD && Manager.isWrittenInMainFile(Manager.getSpellingLoc(FD->getLocation())) && !FD->isMain() &&
            std::find(renamed.begin(), renamed.end(), Manager.getSpellingLoc(FD->getLocation())) == renamed.end() &&
            !isConstructorOrDestructor(FD) &&
            FD->isDefined()) {
            renamed.push_back(Manager.getSpellingLoc(FD->getLocation()));
            const std::string &funcName = FD->getNameAsString();
            if (funcName.rfind("operator", 0) != 0) {
                if (functionNameMap.find(funcName) == functionNameMap.end()) {
                    std::stringstream stringstream;
                    stringstream << "func_" << funcCounter++;
                    functionNameMap[funcName] = stringstream.str();
                }
                OurRewriter.ReplaceText(SourceRange(Manager.getSpellingLoc(FD->getNameInfo().getLocStart()),
                                                    Manager.getSpellingLoc(FD->getNameInfo().getLocEnd())),
                                        functionNameMap[funcName]);
            }
        }

        const auto *DRE = Result.Nodes.getNodeAs<DeclRefExpr>("declRef");
        if (DRE && Manager.isWrittenInMainFile(Manager.getSpellingLoc(DRE->getLocation())) &&
            isa<FunctionDecl>(DRE->getDecl()) &&
            Manager.isWrittenInMainFile(Manager.getSpellingLoc(DRE->getDecl()->getLocation())) &&
            std::find(renamed.begin(), renamed.end(), Manager.getSpellingLoc(DRE->getLocation())) == renamed.end() &&
            !isConstructorOrDestructor(cast<FunctionDecl>(DRE->getDecl())) &&
            cast<FunctionDecl>(DRE->getDecl())->isDefined()) {
            renamed.push_back(Manager.getSpellingLoc(DRE->getLocation()));

            const std::string &funcName = cast<FunctionDecl>(DRE->getDecl())->getNameAsString();
            if (functionNameMap.find(funcName) == functionNameMap.end()) {
                std::stringstream stringstream;
                stringstream << "func_" << funcCounter++;
                functionNameMap[funcName] = stringstream.str();
            }

            if (funcName.rfind("operator", 0) != 0) {
                OurRewriter.ReplaceText(SourceRange(Manager.getSpellingLoc(DRE->getLocStart()),
                                                    Manager.getSpellingLoc(DRE->getLocEnd())),
                                        functionNameMap[funcName]);
            }
        }

        const auto *ILE = Result.Nodes.getNodeAs<InitListExpr>("initListExpr");
        if (ILE && Manager.isWrittenInMainFile(Manager.getSpellingLoc(ILE->getLocStart())) && 
            std::find(renamed.begin(), renamed.end(), Manager.getSpellingLoc(ILE->getLocStart())) == renamed.end() &&
            ILE->getType().getTypePtr()->getAsStructureType() && 
            Manager.isWrittenInMainFile(Manager.getSpellingLoc(ILE->getType().getTypePtr()->getAsStructureType()->getDecl()->getLocation()))) {
            renamed.push_back(Manager.getSpellingLoc(ILE->getLocStart()));
            std::string exprString = getSourceTextStable(*Context, ILE->getLocStart(), ILE->getLocEnd());
            std::map<std::string, SourceRange> locFieldInit{};
            auto lastLoc = ILE->getLocStart().getLocWithOffset(1);
            for (auto *child : ILE->inits()) {
                child->dumpColor();
                while (getSourceTextStable(*Context, lastLoc, lastLoc) != ".") {
                    lastLoc = lastLoc.getLocWithOffset(1);
                }
                lastLoc = lastLoc.getLocWithOffset(1);
                auto endLoc = lastLoc.getLocWithOffset(1);
                while (isalnum(getSourceTextStable(*Context, endLoc, endLoc).c_str()[0])) {
                    endLoc = endLoc.getLocWithOffset(1);
                }
                auto range = SourceRange(lastLoc, endLoc);
                locFieldInit[getSourceTextStable(*Context, range.getBegin(), range.getEnd())] = range;
                lastLoc = Manager.getExpansionLoc(child->getLocEnd()).getLocWithOffset(1);
            }
            // Maybe this leads to a problem since other replacements before this will be overwritten.
            // Possible fix: Try to get the specific location, which is not directly accessible
            if (ILE->getType().getTypePtr()->getAsStructureType() && ILE->getType().getTypePtr()->getAsStructureType()->getDecl()) {
                RecordDecl* rec = ILE->getType().getTypePtr()->getAsStructureType()->getDecl();
                auto fields = fieldNameMapping[rec];
                for (auto& field : fields) {
                    if (locFieldInit.find(field.first) == locFieldInit.end()) continue;
                    auto range = locFieldInit[field.first];
                    OurRewriter.ReplaceText(range, field.second);
                }
            }
        }
    }

  private:
    Rewriter &OurRewriter;
    ASTContext &context;
    VariableNameTransformer &variableNameTransformer;
    TypeMapping &typeMap;
    std::vector<SourceLocation> renamed;
    std::vector<const VarDecl *> renamedVars;
    std::map<std::string, std::string> functionNameMap{{"main", "main"}};
    std::map<std::string, std::string> recordMap;
    std::map<const RecordDecl*, std::vector<std::pair<std::string, std::string>>> fieldNameMapping; 

    uint32_t varCounter = 0;
    uint32_t funcCounter = 0;
    uint32_t fieldCounter = 0;
    uint32_t recordCounter = 0;
    uint32_t testCounter = 0;

    bool isConstructorOrDestructor(const FunctionDecl *FD) const {
        if (FD == nullptr) {
            return false;
        }
        return isa<CXXConstructorDecl>(FD) || isa<CXXDestructorDecl>(FD) ||
               (FD->isDefaulted() && !FD->isExplicitlyDefaulted());
    }

    bool isInTemplateSpecification(const VarDecl *VD) {
        if (VD->getParentFunctionOrMethod() == nullptr)
            return false;
        if (!isa<FunctionDecl>(VD->getParentFunctionOrMethod()))
            return false;
        auto *FD = cast<FunctionDecl>(VD->getParentFunctionOrMethod());
        if (FD) {
            return FD->isFunctionTemplateSpecialization();
        }
        return false;
    }
};

/* ****************** ************** **************** */

class MyASTConsumer : public ASTConsumer {
  public:
    explicit MyASTConsumer(ASTContext &Context, Rewriter &OurRewriter)
        : typeMap(Context), varNameTransformer(Context, OurRewriter),
          renamingTransformer(Context, OurRewriter, varNameTransformer,
                              typeMap) {

        StatementMatcher DeclStmtMatcher = anyOf(declStmt().bind("declStmt"), declRefExpr().bind("declRef"),
                                                 callExpr().bind("callExpr"), initListExpr().bind("initListExpr"));

        DeclarationMatcher FunctionDeclMatcher = anyOf(functionDecl().bind("functionDecl"), varDecl().bind("varDecl"));

        DeclarationMatcher RecordMatcher = anyOf(recordDecl().bind("recordDecl"), fieldDecl().bind("fieldDecl"));

        DeclarationMatcher ConstructorMatcher = cxxConstructorDecl().bind("cxxconstr");

        Matcher.addMatcher(DeclStmtMatcher, &renamingTransformer);
        Matcher.addMatcher(FunctionDeclMatcher, &renamingTransformer);
        Matcher.addMatcher(RecordMatcher, &renamingTransformer);
        Matcher.addMatcher(ConstructorMatcher, &renamingTransformer);
    }

    void HandleTranslationUnit(ASTContext &Context) override {
        typeMap.init(Context);
        varNameTransformer.init(Context);
        varNameTransformer.TraverseDecl(Context.getTranslationUnitDecl());
        Matcher.matchAST(Context);
    }

  private:
    MatchFinder Matcher;
    TypeMapping typeMap;
    VariableNameTransformer varNameTransformer;
    RenamingTransformer renamingTransformer;
};

int main(int argc, const char **argv) {
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                      MyOptionCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                   OptionsParser.getSourcePathList());
    return Tool.run(&*clang::tooling::newFrontendActionFactory<
                     MyFrontendAction<MyASTConsumer>>());
}
