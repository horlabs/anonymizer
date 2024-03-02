#ifndef CLANG_LIBS
#define CLANG_LIBS

#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"

#endif

#include "AssertRemover.h"
#include "include/SourceTextHelper.h"

using namespace clang;

void AssertRemover::run(const MatchFinder::MatchResult &Result) {
    ASTContext &Context = *Result.Context;

    const auto *AP = Result.Nodes.getNodeAs<ParenExpr>("assertParens");
    if (AP) {
        std::pair<SourceLocation, SourceLocation> expansionRange =
            Context.getSourceManager().getImmediateExpansionRange(
                AP->getLocStart());
        llvm::errs() << getSourceTextStable(Context, expansionRange.first,
                                            expansionRange.second)
                     << "\n";
        llvm::errs() << AP->HasSideEffects(Context, false) << "\n";
        AP->dumpColor();
        auto tmp = cast<ConditionalOperator>(AP->getSubExpr());

        std::pair<SourceLocation, SourceLocation> tmpRange =
            Context.getSourceManager().getImmediateExpansionRange(
                tmp->getCond()->getLocStart());
        auto &Manager = Context.getSourceManager();
        llvm::errs() << getSourceTextStable(
                            Context,
                            Manager.getSpellingLoc(
                                tmp->getCond()->IgnoreCasts()->getLocStart()),
                            Manager.getSpellingLoc(
                                tmp->getCond()->IgnoreCasts()->getLocEnd()))
                     << "\n";
        auto options = Rewriter::RewriteOptions();
        options.RemoveLineIfEmpty = true;
        ourRewriter.RemoveText(
            SourceRange(expansionRange.first, expansionRange.second), options);
    }

    const auto *ULE = Result.Nodes.getNodeAs<UnresolvedLookupExpr>("unresExpr");
    if (ULE != nullptr && ULE->getName().getAsString() == "__assert_fail") {
        std::pair<SourceLocation, SourceLocation> expansionRange =
            Context.getSourceManager().getImmediateExpansionRange(
                ULE->getLocStart());
        llvm::errs() << getSourceTextStable(Context, expansionRange.first,
                                            expansionRange.second)
                     << "\n";
        llvm::errs() << ULE->HasSideEffects(Context) << "\n";
        auto options = Rewriter::RewriteOptions();
        options.RemoveLineIfEmpty = true;
        ourRewriter.RemoveText(
            SourceRange(expansionRange.first, expansionRange.second), options);
    }
}

void AssertRemover::removeAsserts(ASTContext &Context) {
    StatementMatcher AssertMatcher =
        parenExpr(
            isExpansionInMainFile(),
            has(conditionalOperator(findAll(
                callExpr(callee(implicitCastExpr(has(declRefExpr(hasDeclaration(
                    functionDecl(anyOf(hasName("__assert_rtn"),
                                       hasName("__assert_fail")))))))))))))
            .bind("assertParens");

    StatementMatcher test =
        parenExpr(isExpansionInMainFile(),
                  has(conditionalOperator(findAll(callExpr(
                      has(unresolvedLookupExpr().bind("unresExpr")))))))
            .bind("unresParens");

    assertMatcher.addMatcher(AssertMatcher, this);
    assertMatcher.addMatcher(test, this);
    assertMatcher.matchAST(Context);
}
