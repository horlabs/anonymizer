#ifndef AUTHORSHIP_EVASION_FORSTATEMENTTRANSFORM_H
#define AUTHORSHIP_EVASION_FORSTATEMENTTRANSFORM_H

// #include "clang/AST/ASTConsumer.h"
#include "clang/Tooling/Refactoring.h"

using namespace std;
using namespace llvm::cl;
using namespace clang;
using namespace clang::tooling;

enum Strategies {
    S_RandomStrategy,
    S_ForStmtToWhileStmt,
    S_ConvertForRangeStmt
};

/// A frontend action that creates replacements for adding or removing
/// compound statements.
class ForStmtTransformationAction {
  public:
    explicit ForStmtTransformationAction(
        map<string, Replacements> &FileToReplaces)
        : FileToReplaces(FileToReplaces) {}

    unique_ptr<ASTConsumer> newASTConsumer();

  private:
    map<string, Replacements> &FileToReplaces;
};

#endif // AUTHORSHIP_EVASION_FORSTATEMENTTRANSFORM_H
