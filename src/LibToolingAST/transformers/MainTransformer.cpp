#ifndef CLANG_LIBS
#define CLANG_LIBS

#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"

#endif

#include "ASTFrontendActionTemplate.inl"
#include "include/SourceTextHelper.h"

using namespace clang;

static llvm::cl::OptionCategory MyOptionCategory("Main Transformer");

/**
 * add parameters and return to main-function if not already exists
 */
class MainTransformer : public RecursiveASTVisitor<MainTransformer> {
  private:
    ASTContext &Context;
    SourceManager &sm;
    Rewriter &OurRewriter;

  public:
    explicit MainTransformer(ASTContext &Context, Rewriter &OurRewriter)
        : Context(Context), sm(Context.getSourceManager()),
          OurRewriter(OurRewriter){};

    bool VisitFunctionDecl(const FunctionDecl *FD) {
        if (sm.isWrittenInMainFile(FD->getLocStart())) {
            if (FD->isMain()) {
                if (FD->getNumParams() == 0) {
                    OurRewriter.InsertTextAfter(
                        FD->getLocation().getLocWithOffset(5),
                        "int argc, char** argv");
                }
                bool hasReturn = false;
                for (auto child : FD->getBody()->children()) {
                    if (isa<ReturnStmt>(child)) {
                        hasReturn = true;
                        break;
                    }
                }
                if (!hasReturn) {
                    OurRewriter.InsertTextBefore(FD->getBody()->getLocEnd(),
                                                 "return 0;\n");
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
    MainTransformer transformer;
};

int main(int argc, const char **argv) {
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                      MyOptionCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                   OptionsParser.getSourcePathList());
    return Tool.run(&*clang::tooling::newFrontendActionFactory<
                     MyFrontendAction<MyASTConsumer>>());
}