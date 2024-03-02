#include "ForStatementTransform.h"
#include "ConvertForRangeStatement.h"
#include "ForStatementToWhileStatement.h"

extern opt<Strategies> Strategy;

std::unique_ptr<ASTConsumer> ForStmtTransformationAction::newASTConsumer() {
    if (Strategy == Strategies::S_ForStmtToWhileStmt)
        return llvm::make_unique<ForStatementToWhileStatementASTConsumer>(
            FileToReplaces);
    else if (Strategy == Strategies::S_ConvertForRangeStmt)
        return llvm::make_unique<ConvertForRangeStatementASTConsumer>(
            FileToReplaces);
    else {
        return llvm::make_unique<ForStatementToWhileStatementASTConsumer>(
            FileToReplaces);
    }
}
