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

static llvm::cl::OptionCategory MyOptionCategory("If Else Transformer");

/**
 * Add else to if if the then-clause will end the function or the program
 */
class SwitchTransformer : public RecursiveASTVisitor<SwitchTransformer> {
  private:
    ASTContext &Context;
    SourceManager &sm;
    Rewriter &OurRewriter;

  public:
    explicit SwitchTransformer(ASTContext &Context, Rewriter &OurRewriter)
        : Context(Context), sm(Context.getSourceManager()),
          OurRewriter(OurRewriter){};

    bool VisitIfStmt(const IfStmt *IF) {
        if (sm.isWrittenInMainFile(IF->getLocStart()) && IF->getElse() == nullptr) {
            const Stmt *last = IF->getThen();
            if (isa<CompoundStmt>(last)) {
                for (auto child : IF->getThen()->children()) {
                    last = child;
                }
            }
            if (isa<ContinueStmt>(last) || isa<BreakStmt>(last) || isa<ReturnStmt>(last) ||
                (isa<CallExpr>(last) && cast<CallExpr>(last)->getDirectCallee()->isNoReturn())) {
                for (auto parent : Context.getParents(*IF)) {
                    if (parent.get<Stmt>()) {
                        last = parent.get<Stmt>();
                        if (isa<CompoundStmt>(last)) {
                            for (auto child : parent.get<Stmt>()->children()) {
                                last = child;
                            }
                        } else {
                            continue;
                        }
                        if (last == IF)
                            continue;
                        auto endLoc = parent.get<Stmt>()->getLocEnd();
                        if (getSourceTextStable(Context, endLoc, endLoc) ==
                            "}") {
                            endLoc = endLoc.getLocWithOffset(-1);
                        }
                        while (getSourceTextStable(Context, endLoc, endLoc)
                                   .empty()) {
                            endLoc = endLoc.getLocWithOffset(-1);
                        }
                        endLoc = endLoc.getLocWithOffset(1);
                        auto length = getSourceTextStable(Context, IF->getThen()->getLocEnd(),
                                                          IF->getThen()->getLocEnd()).size();
                        auto ifEndLoc = IF->getThen()->getLocEnd().getLocWithOffset(length);
                        while (!getSourceTextStable(Context, ifEndLoc, ifEndLoc).empty() && getSourceTextStable(Context, ifEndLoc, ifEndLoc) != ";") {
                            ifEndLoc = ifEndLoc.getLocWithOffset(1);
                        }
                        if (getSourceTextStable(Context, ifEndLoc, ifEndLoc) != ";") {
                            ifEndLoc = ifEndLoc.getLocWithOffset(1);
                        } else {
                            OurRewriter.RemoveText(ifEndLoc, 1);
                        }
                        OurRewriter.InsertText(ifEndLoc, "else {\n");
                        OurRewriter.InsertText(endLoc, "\n}");
                    }
                }
            }
        }
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
    }

  private:
    SwitchTransformer transformer;
};

int main(int argc, const char **argv) {
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                      MyOptionCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                   OptionsParser.getSourcePathList());
    return Tool.run(&*clang::tooling::newFrontendActionFactory<
                     MyFrontendAction<MyASTConsumer>>());
}