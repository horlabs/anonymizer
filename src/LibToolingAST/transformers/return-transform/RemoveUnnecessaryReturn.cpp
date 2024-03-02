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
#include "../include/SourceTextHelper.h"

using namespace clang;

static llvm::cl::OptionCategory MyOptionCategory("Main Transformer");

/**
 * remove unnecessary returns
 */
class RemoveUnnecessaryReturnTransformer
    : public RecursiveASTVisitor<RemoveUnnecessaryReturnTransformer> {
  private:
    ASTContext &Context;
    SourceManager &sm;
    Rewriter &OurRewriter;

  public:
    explicit RemoveUnnecessaryReturnTransformer(ASTContext &Context,
                                                Rewriter &OurRewriter)
        : Context(Context), sm(Context.getSourceManager()),
          OurRewriter(OurRewriter){};

    /**
     * Returns true, if after the initial return statement no further statement except another return
     * would be executed if the initial statement will be removed
     * This means, that without the initial statement, no other statement in the function will be executed
     */
    bool isLastStatement(const Stmt *stmt) {
        auto *compParent = Context.getParents(*stmt)[0].get<CompoundStmt>();
        auto *parent = Context.getParents(*stmt)[0].get<IfStmt>();
        if (compParent) {
            if (getNextStmt(compParent) == nullptr && Context.getParents(*compParent)[0].get<FunctionDecl>())
                return true;
            parent = Context.getParents(*compParent)[0].get<IfStmt>();
        }
        if (parent == nullptr)
            return false;

        auto next = getNextStmt(parent);
        if (next != nullptr && !isa<ReturnStmt>(next))
            return false;
        if (next == nullptr) {
            return isLastStatement(parent);
        }
        return true;
    }

    bool VisitReturnStmt(const ReturnStmt *RET) {
        if (!sm.isWrittenInMainFile(RET->getLocStart()))
            return true;
        // only for void-functions
        if (RET->getRetValue())
            return true;

        if (!isLastStatement(RET))
            return true;
        auto removeRange = SourceRange(RET->getLocStart(), RET->getLocStart().getLocWithOffset(7));
        // ToDo: if empty if/else clause, remove the whole clause (recursively)
        //  else is easy, for if we need to negate the condition and replace the else with a new if
        auto *compParent = Context.getParents(*RET)[0].get<CompoundStmt>();
        auto *parent = Context.getParents(*RET)[0].get<IfStmt>();
        if (compParent) {
            parent = Context.getParents(*compParent)[0].get<IfStmt>();
        }
        if (parent != nullptr && parent->getElse() == nullptr) {
            int num = 0;
            if (isa<CompoundStmt>(parent->getThen())) {
                for (auto it = parent->getThen()->child_begin(); it != parent->getThen()->child_end(); it++) {
                    num++;
                }
            } else {
                num = 1;
            }
            if (num <= 1) {
                removeRange.setBegin(parent->getLocStart());
                if (isa<CompoundStmt>(parent->getThen())) {
                    removeRange.setEnd(parent->getThen()->getLocEnd());
                }
            }
        }

        auto opts = Rewriter::RewriteOptions();
        opts.RemoveLineIfEmpty = true;
        OurRewriter.RemoveText(removeRange, opts);

        return true;
    }

    const Stmt *getNextStmt(const Stmt *stmt) {
        for (auto node : Context.getParents(*stmt)) {
            auto parent = node.get<Stmt>();
            if (parent == nullptr)
                continue;
            bool returnNext = false;
            for (auto child : parent->children()) {
                if (child == stmt) {
                    returnNext = true;
                } else if (returnNext) {
                    return child;
                }
            }
        }
        return nullptr;
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
    RemoveUnnecessaryReturnTransformer transformer;
};

int main(int argc, const char **argv) {
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                      MyOptionCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                   OptionsParser.getSourcePathList());
    return Tool.run(&*clang::tooling::newFrontendActionFactory<
                     MyFrontendAction<MyASTConsumer>>());
}