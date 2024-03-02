#ifndef CLANG_LIBS
#define CLANG_LIBS

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

using namespace clang;
using namespace clang::ast_matchers;

// ** These are the command line options **
static llvm::cl::OptionCategory MyOptionCategory("Buffer Name Transformer");

class BufferNameTransformer : public MatchFinder::MatchCallback {
  public:
    explicit BufferNameTransformer(ASTContext &Context, Rewriter &OurRewriter, DeclRefMapping &DeclRefMap)
            : OurRewriter(OurRewriter),
              DSB(Context), DeclRefMap(DeclRefMap), context(Context) {
    };

    void run(const MatchFinder::MatchResult &Result) override {
        ASTContext *Context = Result.Context;

        const auto *DS = Result.Nodes.getNodeAs<DeclStmt>("declStmt");
        if (DS && Context->getSourceManager().isWrittenInMainFile(DS->getLocStart())) {
            for (const auto *curDecl : DS->decls()) {
                if (auto *vardecl = dyn_cast<VarDecl>(curDecl)) {
                    if (vardecl->getType().isConstant(*Context))
                        return;
                    if (vardecl->getType()->isPointerType() || vardecl->getType()->isArrayType()) {
                        // Check if multi-dimensional array (for now ignore it in that case)
                        if (auto *constArray = dyn_cast<ConstantArrayType>(vardecl->getType().getTypePtr())) {
                            if (constArray->getElementType()->isArrayType())
                                return;
                        }
                        if (vardecl->getType()->getPointeeOrArrayElementType()->isCharType()) {
                            candidates.push_back(vardecl);
                        }
                    }
                    if (vardecl->getType()->isRecordType() && vardecl->getType().getBaseTypeIdentifier() &&
                        vardecl->getType().getBaseTypeIdentifier()->getName() == "basic_string") {
                        candidates.push_back(vardecl);
                    }
                }
            }
        }
    }

    void identifyRenamingCandidates() {
        std::vector<const VarDecl *> renamingCandidates{};
        for (auto *candidate : candidates) {
            const CallExpr *firstCall = nullptr;
            const Expr *firstExprAfterDecl = nullptr;
            for (auto *declRef : DeclRefMap.getVarDeclToDeclRefExprs(candidate)) {
                if (firstExprAfterDecl == nullptr) {
                    firstExprAfterDecl = declRef;
                }
                if (context.getSourceManager().isBeforeInTranslationUnit(
                        declRef->getLocStart(),
                        firstExprAfterDecl->getLocStart())) {
                    firstExprAfterDecl = declRef;
                }
                for (auto &parentRef : context.getParents(*declRef)) {
                    auto *parent = parentRef.get<Stmt>();
                    if (parent == nullptr)
                        continue;
                    while (isa<ImplicitCastExpr>(parent)) {
                        parent = context.getParents(*parent)[0].get<Stmt>();
                    }
                    if (auto *call = dyn_cast<CallExpr>(parent)) {
                        if (auto *cxx = dyn_cast<CXXOperatorCallExpr>(call)) {
                            if (cxx->getOperator() != OverloadedOperatorKind::OO_GreaterGreater &&
                                cxx->getOperator() != OverloadedOperatorKind::OO_LessLess) {
                                continue;
                            }
                        }
                        if (firstCall == nullptr) {
                            firstCall = call;
                            continue;
                        }
                        if (context.getSourceManager().isBeforeInTranslationUnit(
                                    firstCall->getLocEnd(),
                                    call->getLocStart()))
                            continue;
                        firstCall = call;
                    }
                }
            }
            if (firstCall == nullptr)
                continue;
            if (!context.getSourceManager().isBeforeInTranslationUnit(firstExprAfterDecl->getLocStart(),
                                                                      firstCall->getLocStart())) {
                renamingCandidates.push_back(candidate);
            }
        }
        candidates = renamingCandidates;
    }

    bool renameCandidates() {
        std::sort(candidates.begin(), candidates.end());
        candidates.erase(std::unique(candidates.begin(), candidates.end()),
                         candidates.end());
        for (const auto *candidateVarDecl : candidates) {
            std::vector<std::string> namesInScope{};
            if (candidateVarDecl) {
                for (auto *declInScope : DSB.getScopeForDecl(candidateVarDecl)) {
                    if (declInScope == candidateVarDecl)
                        continue;
                    if (renamed.find(declInScope) != renamed.end()) {
                        namesInScope.push_back(renamed[declInScope]);
                    } else {
                        namesInScope.push_back(declInScope->getNameAsString());
                    }
                }
                std::string newName{};

                bool nameConflict;
                do {
                    if (candidateVarDecl->getType()->isRecordType() &&
                        candidateVarDecl->getType().getBaseTypeIdentifier()->getName() == "basic_string") {
                        newName = "str";
                        newName += strBufCount == 0 ? "" : "_" + std::to_string(strBufCount);
                        strBufCount++;
                    } else {
                        newName = "buf";
                        newName += charBufCount == 0 ? "" : "_" + std::to_string(charBufCount);
                        charBufCount++;
                    }
                    nameConflict =
                            std::find(namesInScope.begin(), namesInScope.end(), newName) !=
                            namesInScope.end();
                } while (nameConflict);
                unsigned vardeclnamelength = (unsigned) candidateVarDecl->getNameAsString().length();
                for (auto *declrefexpr : DeclRefMap.getVarDeclToDeclRefExprs(candidateVarDecl)) {
                    OurRewriter.ReplaceText(declrefexpr->getSourceRange(), newName);
                }
                OurRewriter.ReplaceText(candidateVarDecl->getLocation(), vardeclnamelength, newName);
                renamed[candidateVarDecl] = newName;
            }
        }
        return true;
    }

    // ToDo: resolve nameconflicts if created due to the transformation

  private:
    Rewriter &OurRewriter;
    DeclScopeBuilder DSB;
    DeclRefMapping &DeclRefMap;
    ASTContext &context;

    uint16_t charBufCount = 0;
    uint16_t strBufCount = 0;

    std::vector<const VarDecl *> candidates{};
    std::map<const NamedDecl *, std::string> renamed{};
};

/**
 * Builds DeclRefMapping by storing matched VarDecls, DeclStmts and DeclRefExprs.
 */
class DeclRefMappingBuilder : public MatchFinder::MatchCallback {
  public:
    explicit DeclRefMappingBuilder(DeclRefMapping *DeclRefMap)
        : DeclRefMap(DeclRefMap) {}

    void run(const MatchFinder::MatchResult &Result) override {
        ASTContext *Context = Result.Context;

        const auto *VD = Result.Nodes.getNodeAs<VarDecl>("varDecl");
        if (VD && Context->getSourceManager().isWrittenInMainFile(VD->getLocStart())) {
            DeclRefMap->insert_vardecl(VD);
        }

        const auto *DS = Result.Nodes.getNodeAs<DeclStmt>("declStmt");
        if (DS && Context->getSourceManager().isWrittenInMainFile(DS->getLocStart())) {
            DeclRefMap->insert_declstmt(DS);
        }

        const auto *DRE = Result.Nodes.getNodeAs<DeclRefExpr>("declRefExpr");
        if (DRE && Context->getSourceManager().isWrittenInMainFile(DRE->getLocStart())) {
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
        : DeclRefMap(&Context), DRMB(&DeclRefMap),
          transformer(Context, OurRewriter, DeclRefMap) {

        DeclarationMatcher DeclRefMapDeclarationMatcher = varDecl().bind("varDecl");
        StatementMatcher DeclRefMapStatementMatcher = anyOf(
                declStmt().bind("declStmt"),
                declRefExpr().bind("declRefExpr"));
        PreMatcher.addMatcher(DeclRefMapDeclarationMatcher, &DRMB);
        PreMatcher.addMatcher(DeclRefMapStatementMatcher, &DRMB);

/**
 * For now only consider loops where the "running" variable is used only in this loop and nothing else.
 * Even if only an assignment is executed outside the loop this var will not be renamed so far.
 */
        StatementMatcher BufferDeclMatcher = declStmt().bind("declStmt");

        Matcher.addMatcher(BufferDeclMatcher, &transformer);
    }

    void HandleTranslationUnit(ASTContext &Context) override {
        DeclScopeBuilder scopeBuilder(Context.getTranslationUnitDecl()->getASTContext());
        scopeBuilder.buildScopeMap();

        PreMatcher.matchAST(Context);
        Matcher.matchAST(Context);
        transformer.identifyRenamingCandidates();
        transformer.renameCandidates();
    }

  private:
    MatchFinder PreMatcher;
    MatchFinder Matcher;

    DeclRefMapping DeclRefMap;
    DeclRefMappingBuilder DRMB;
    BufferNameTransformer transformer;
};

int main(int argc, const char **argv) {
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                      MyOptionCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                   OptionsParser.getSourcePathList());
    return Tool.run(&*clang::tooling::newFrontendActionFactory<
                     MyFrontendAction<MyASTConsumer>>());
}