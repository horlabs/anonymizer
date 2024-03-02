#ifndef CLANG_LIBS
#define CLANG_LIBS

#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"

#endif

#include "../ASTFrontendActionTemplate.inl"
#include "../ControlDataFlow/DeclRefMapping/DeclRefMapping.h"
#include "../ControlDataFlow/DeclScopeBuilder/DeclScopeBuilder.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"

#include <memory>

using namespace clang;
using namespace clang::ast_matchers;

// ** These are the command line options **
static llvm::cl::OptionCategory MyOptionCategory("Iteration variable Transformer");

class IterVarTransformer : public MatchFinder::MatchCallback {
  public:
    explicit IterVarTransformer(DeclRefMapping *DeclRefMap, ASTContext &Context,
                                Rewriter &OurRewriter)
        : OurRewriter(OurRewriter), DeclRefMap(DeclRefMap), DSB(Context),
          Manager(Context.getSourceManager()) {
        DSB.buildScopeMap();
    };

    void run(const MatchFinder::MatchResult &Result) override {
        ASTContext *Context = Result.Context;

        const auto *FS = Result.Nodes.getNodeAs<ForStmt>("forStmt");
        if (FS && Context->getSourceManager().isWrittenInMainFile(FS->getLocStart())) {

            if (FS->getInit() != nullptr) {
                auto *DS = dyn_cast<DeclStmt>(FS->getInit());
                for (auto *declaration : DS->decls()) {
                    if (auto *declVar = dyn_cast<VarDecl>(declaration)) {
                        determineRenamingCandidate(Context, FS, declVar);
                    }
                }
            }
        }

        const auto *VD = Result.Nodes.getNodeAs<VarDecl>("varDecl");
        if (VD && Context->getSourceManager().isWrittenInMainFile(VD->getLocStart())) {
            if (std::find(varDecls.begin(), varDecls.end(), VD) == varDecls.end() && !VD->isImplicit()) {
                bool append = true;
                if (VD->getParentFunctionOrMethod()) {
                    if (auto *FD = dyn_cast<FunctionDecl>(VD->getParentFunctionOrMethod())) {
                        if (FD->isTemplateInstantiation()) {
                            append = false;
                        }
                    }
                }
                if (append) {
                    varDecls.push_back(VD);
                }
            }
        }

        const auto *DS = Result.Nodes.getNodeAs<DeclStmt>("declStmt");
        if (DS && Context->getSourceManager().isWrittenInMainFile(DS->getLocStart())) {
            bool append = true;
            if (std::find(renamingCandidates.begin(), renamingCandidates.end(),
                          DS) == renamingCandidates.end()) {
                for (auto *declVar : DS->decls()) {
                    if (declVar->getParentFunctionOrMethod()) {
                        if (auto *FD = dyn_cast<FunctionDecl>(declVar->getParentFunctionOrMethod())) {
                            if (FD->isTemplateInstantiation()) {
                                append = false;
                            }
                        }
                    }
                }
                if (append) {
                    renamingCandidates.push_back(DS);
                }
            }
        }

        const Stmt *WhileDoStmt = Result.Nodes.getNodeAs<Stmt>("whileDoStmt");
        if (WhileDoStmt && Context->getSourceManager().isWrittenInMainFile(WhileDoStmt->getLocStart())) {
            if (auto *binOp = Result.Nodes.getNodeAs<BinaryOperator>("binCond")) {
                auto *rhs = binOp->getRHS()->IgnoreCasts();
                auto *lhs = binOp->getLHS()->IgnoreCasts();
                if (auto *LHSDecl = dyn_cast<DeclRefExpr>(lhs)) {
                    determineRenamingCandidate(Context, WhileDoStmt, LHSDecl);
                }
                if (auto *RHSDecl = dyn_cast<DeclRefExpr>(rhs)) {
                    determineRenamingCandidate(Context, WhileDoStmt, RHSDecl);
                }
            } else if (auto *castEx = Result.Nodes.getNodeAs<CastExpr>("castCond")) {
                if (auto *declRef = dyn_cast<DeclRefExpr>(castEx->IgnoreCasts())) {
                    determineRenamingCandidate(Context, WhileDoStmt, declRef);
                }
            }
        }
    }

    void determineRenamingCandidate(ASTContext *Context, const Stmt *statement, const DeclRefExpr *declRef) {
        if (auto *declVar = llvm::dyn_cast<VarDecl>(declRef->getDecl()->getUnderlyingDecl())) {
            determineRenamingCandidate(Context, statement, declVar);
        }
    }

    void determineRenamingCandidate(ASTContext *Context, const Stmt *statement, const VarDecl *declVar) {
        if (!declVar->getType()->isArithmeticType()) return;
        if (declVar->getParentFunctionOrMethod()) {
            if (auto *FD = dyn_cast<FunctionDecl>(declVar->getParentFunctionOrMethod())) {
                if (FD->isTemplateInstantiation()) {
                    return;
                }
            }
        }
        bool allInside = true;
        for (auto *vardecl : DeclRefMap->getVarDeclToDeclRefExprs(declVar)) {
            bool startInside = Context->getSourceManager().isBeforeInTranslationUnit(statement->getLocStart(),
                                                                                     vardecl->getLocStart());
            bool endInside = Context->getSourceManager().isBeforeInTranslationUnit(vardecl->getLocEnd(),
                                                                                   statement->getLocEnd());
            allInside &= static_cast<bool>(startInside & endInside);
        }
        if (allInside && declVar->getType()->isArithmeticType()) {
            if (isa<ParmVarDecl>(declVar)) {
                return;
            }
            for (auto &parent : Context->getParents(*declVar)) {
                if (parent.get<Decl>() && isa<TranslationUnitDecl>(parent.get<Decl>())) {
                    return;
                }
            }
            if (std::find(renamingCandidates.begin(), renamingCandidates.end(),
                          DeclRefMap->getVarDeclToDeclStmt(declVar)) == renamingCandidates.end()) {
                if (DeclRefMap->getVarDeclToDeclStmt(declVar) == nullptr) {
                    declVar->dumpColor();
                }
                renamingCandidates.push_back(DeclRefMap->getVarDeclToDeclStmt(declVar));
                assert(std::count(renamingCandidates.begin(), renamingCandidates.end(),
                                  DeclRefMap->getVarDeclToDeclStmt(declVar)) == 1);
            }
        }
    }

    bool renameIterVars() {
        for (const auto *candidateDecl : renamingCandidates) {
            std::vector<std::string> namesInScope{};
            // ToDo: Multi-Decl handling (should be not so complicated...)
            if (candidateDecl->isSingleDecl()) {
                auto *namedD = dyn_cast<VarDecl>(candidateDecl->getSingleDecl());
                if (namedD) {
                    for (auto *declInScope : DSB.getScopeForDecl(namedD)) {
                        if (declInScope == namedD)
                            continue;
                        if (renamed.find(declInScope) != renamed.end()) {
                            namesInScope.push_back(renamed[declInScope]);
                        } else {
                            namesInScope.push_back(declInScope->getNameAsString());
                        }
                    }
                    auto possibleName = possibleNames.begin();
                    for (auto &name : namesInScope) {
                        if (*possibleName == namedD->getNameAsString())
                            break;
                        if (*possibleName == name)
                            possibleName++;
                    }
                    bool nameHasToChange = (*possibleName != namedD->getNameAsString());
                    bool nameConflict =
                            std::find(namesInScope.begin(), namesInScope.end(), namedD->getNameAsString()) !=
                            namesInScope.end();

                    if (nameHasToChange || nameConflict) {
                        auto declrefexprs = DeclRefMap->getVarDeclToDeclRefExprs(namedD);
                        for (const auto &name : possibleNames) {
                            nameConflict =
                                    std::find(namesInScope.begin(), namesInScope.end(), name) != namesInScope.end();
                            if (nameConflict)
                                continue;
                            unsigned vardeclnamelength = (unsigned) namedD->getNameAsString().length();
                            for (auto *declrefexpr : declrefexprs) {
                                auto range = declrefexpr->getSourceRange();
                                range.setBegin(Manager.getSpellingLoc(range.getBegin()));
                                range.setEnd(Manager.getSpellingLoc(range.getEnd()));
                                OurRewriter.ReplaceText(range, name);
                            }
                            OurRewriter.ReplaceText(Manager.getSpellingLoc(namedD->getLocation()), vardeclnamelength,
                                                    name);
                            renamed[namedD] = name;
                            break;
                        }
                    }
                }
            }
        }
        return true;
    }

    /*
     * ToDo: After renaming, get through the translationunit again an search for
     * name conflicts (and resolve them) top->down, same renaming as for the
     * itervars if conflicts occur
     */
    bool resolveNameConflicts() {
        for (auto *curVarDecl : varDecls) {
            if (isa<ParmVarDecl>(curVarDecl))
                continue;
            std::vector<std::string> namesInScope{};
            // ToDo: Multi-Decl handling (should be not so complicated...)
            for (auto *declInScope : DSB.getScopeForDecl(curVarDecl)) {
                if (declInScope == curVarDecl)
                    continue;
                if (renamed.find(declInScope) != renamed.end()) {
                    namesInScope.push_back(renamed[declInScope]);
                } else {
                    namesInScope.push_back(declInScope->getNameAsString());
                }
            }
            auto varDeclName = curVarDecl->getNameAsString();
            if (renamed.find(curVarDecl) != renamed.end()) {
                varDeclName = renamed[curVarDecl];
            }
            bool nameConflict =
                    std::find(namesInScope.begin(), namesInScope.end(), varDeclName) !=
                    namesInScope.end() &&
                    std::find(possibleNames.begin(), possibleNames.end(), varDeclName) != possibleNames.end();

            if (nameConflict) {
                auto declrefexprs = DeclRefMap->getVarDeclToDeclRefExprs(curVarDecl);
                for (const auto &name : possibleNames) {
                    nameConflict =
                            std::find(namesInScope.begin(), namesInScope.end(), name) != namesInScope.end();
                    if (nameConflict)
                        continue;
                    auto vardeclnamelength = varDeclName.length();
                    for (auto *declrefexpr : declrefexprs) {
                        OurRewriter.ReplaceText(declrefexpr->getLocStart(), vardeclnamelength, name);
                    }
                    OurRewriter.ReplaceText(Manager.getSpellingLoc(curVarDecl->getLocation()), vardeclnamelength, name);
                    renamed[curVarDecl] = name;
                    break;
                }
                if (renamed.find(curVarDecl) == renamed.end() || renamed[curVarDecl] == varDeclName) {
                    llvm::errs() << "Code 123: No transformations possible\n";
                }
            }
        }
        return true;
    }

private:
    Rewriter &OurRewriter;
    DeclRefMapping *DeclRefMap;
    std::vector<const DeclStmt *> renamingCandidates{};
    std::vector<const VarDecl *> varDecls{};
    DeclScopeBuilder DSB;
    SourceManager &Manager;
    // ToDo: As cmdoption and use this as default
    const std::vector<std::string> possibleNames{
        "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s",
        "t", "u", "v", "w", "x", "y", "z", "a", "b", "c", "d"};
    std::map<const NamedDecl *, std::string> renamed{};
};

/**
 * Builds DeclRefMapping by storing matched VarDecls, DeclStmts and
 * DeclRefExprs. ToDo: move this to own class or something like that
 */
class DeclRefMappingBuilder : public MatchFinder::MatchCallback {
  public:
    explicit DeclRefMappingBuilder(DeclRefMapping *DeclRefMap)
        : DeclRefMap(DeclRefMap) {}

    void run(const MatchFinder::MatchResult &Result) override {
        ASTContext *Context = Result.Context;
        auto &Manager = Context->getSourceManager();

        const auto *VD = Result.Nodes.getNodeAs<VarDecl>("varDecl");
        if (VD && Manager.isWrittenInMainFile(Manager.getSpellingLoc(VD->getLocStart()))) {
            DeclRefMap->insert_vardecl(VD);
        }

        const auto *DS = Result.Nodes.getNodeAs<DeclStmt>("declStmt");
        if (DS && Manager.isWrittenInMainFile(Manager.getSpellingLoc(DS->getLocStart()))) {
            DeclRefMap->insert_declstmt(DS);
        }

        const auto *DRE = Result.Nodes.getNodeAs<DeclRefExpr>("declRefExpr");
        if (DRE && Manager.isWrittenInMainFile(Manager.getSpellingLoc(DRE->getLocStart()))) {
            DeclRefMap->insert_declref(DRE);
        }
    }

  private:
    DeclRefMapping *DeclRefMap;
};

/* ****************** ************** **************** */

class MyASTConsumer : public ASTConsumer {
  public:
    explicit MyASTConsumer(ASTContext &Context, Rewriter &OurRewriter)
        : DeclRefMap(new DeclRefMapping(&Context)), DRMB(DeclRefMap.get()),
          transformer(DeclRefMap.get(), Context, OurRewriter) {

        DeclarationMatcher declarationMatcher = varDecl().bind("varDecl");
        StatementMatcher DeclRefMapStatementMatcher = anyOf(
            declStmt().bind("declStmt"), declRefExpr().bind("declRefExpr"));
        /**
         * For now only consider loops where the "running" variable is used only
         * in this loop and nothing else. Even if an assignement is executed
         * this var will not be renamed so far.
         */
        StatementMatcher LoopStatementMatcher =
            anyOf(forStmt(hasLoopInit(
                              declStmt(hasSingleDecl(varDecl().bind("varDecl")))
                                  .bind("declStmt")))
                      .bind("forStmt"),
                  whileStmt(hasCondition(anyOf(binaryOperator().bind("binCond"),
                                               castExpr().bind("castCond"))))
                      .bind("whileDoStmt"),
                  doStmt(hasCondition(anyOf(binaryOperator().bind("binCond"),
                                            castExpr().bind("castCond"))))
                      .bind("whileDoStmt"));

        PreMatcher.addMatcher(declarationMatcher, &DRMB);
        PreMatcher.addMatcher(DeclRefMapStatementMatcher, &DRMB);

        Matcher.addMatcher(LoopStatementMatcher, &transformer);
        Matcher.addMatcher(declarationMatcher, &transformer);
    }

    void HandleTranslationUnit(ASTContext &Context) override {
        // ToDo: global scope for DSB
        PreMatcher.matchAST(Context);
        Matcher.matchAST(Context);
        transformer.renameIterVars();
        transformer.resolveNameConflicts();
    }

  private:
    MatchFinder PreMatcher;
    MatchFinder Matcher;

    std::unique_ptr<DeclRefMapping> DeclRefMap;
    DeclRefMappingBuilder DRMB;
    IterVarTransformer transformer;
};

int main(int argc, const char **argv) {
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                      MyOptionCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                   OptionsParser.getSourcePathList());
    return Tool.run(&*clang::tooling::newFrontendActionFactory<
                     MyFrontendAction<MyASTConsumer>>());
}