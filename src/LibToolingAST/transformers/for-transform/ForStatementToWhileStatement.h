#ifndef AUTHORSHIP_EVASION_FORSTATEMENTTOWHILESTATEMENT_H
#define AUTHORSHIP_EVASION_FORSTATEMENTTOWHILESTATEMENT_H

#include "SourceTextHelper.h"
#include "clang/AST/AST.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Tooling/Core/Replacement.h"

using namespace std;
using namespace clang;
using namespace clang::tooling;
using namespace clang::ast_matchers;

class ForStatementToWhileStatementMatchHandler
    : public MatchFinder::MatchCallback {
  public:
    void run(const MatchFinder::MatchResult &Result) override;

    const vector<Replacement> &getReplaces() const { return Replaces; }

  private:
    string handleContinueStatements(const Stmt *S, ASTContext *Ctx,
                                    const StringRef &IncText);

    vector<Replacement> Replaces{};
};

class ForStatementToWhileStatementASTConsumer : public ASTConsumer {
  public:
    explicit ForStatementToWhileStatementASTConsumer(
        map<string, Replacements> &FileToReplaces)
        : FileToReplaces(FileToReplaces) {}

    void HandleTranslationUnit(ASTContext &Ctx) override;

  private:
    map<string, Replacements> &FileToReplaces;
};

#endif // AUTHORSHIP_EVASION_FORSTATEMENTTOWHILESTATEMENT_H
