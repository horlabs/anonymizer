#ifndef LIBTOOLINGAST_ASSERTREMOVER_H
#define LIBTOOLINGAST_ASSERTREMOVER_H

#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"

using namespace clang;
using namespace clang::ast_matchers;

/*
 * Because it's is nearly impossible to change anything in the sourcecode in
 * asserts without great effort, we delete simple delete them (they shouldn't
 * affect the rest of the code, only check something)
 */
class AssertRemover : public MatchFinder::MatchCallback {
  private:
    Rewriter &ourRewriter;
    MatchFinder assertMatcher;

  public:
    explicit AssertRemover(Rewriter &ourRewriter) : ourRewriter(ourRewriter) {}

    virtual void run(const MatchFinder::MatchResult &Result);

    void removeAsserts(ASTContext &Context);
};

#endif // LIBTOOLINGAST_ASSERTREMOVER_H
