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

static llvm::cl::OptionCategory MyOptionCategory("Void Return Transformer");

/**
 * add return at the end of each void function
 */
class VoidReturnTransformer
    : public RecursiveASTVisitor<VoidReturnTransformer> {
  private:
    ASTContext &Context;
    SourceManager &sm;
    Rewriter &OurRewriter;

  public:
    explicit VoidReturnTransformer(ASTContext &Context, Rewriter &OurRewriter)
        : Context(Context), sm(Context.getSourceManager()),
          OurRewriter(OurRewriter){};

    bool VisitFunctionDecl(const FunctionDecl *FD) {
        if (!sm.isWrittenInMainFile(FD->getLocStart()))
            return true;
        if (FD->isDefaulted())
            return true;
        if (!FD->hasBody())
            return true;
        if (!FD->getReturnType()->isVoidType())
            return true;

        const Stmt *last = nullptr;
        for (auto child : FD->getBody()->children()) {
            last = child;
        }
        if (last == nullptr || isa<ReturnStmt>(last))
            return true;

        OurRewriter.InsertText(FD->getBody()->getLocEnd(), "return;\n");

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
    VoidReturnTransformer transformer;
};

int main(int argc, const char **argv) {
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                      MyOptionCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                   OptionsParser.getSourcePathList());
    return Tool.run(&*clang::tooling::newFrontendActionFactory<
                     MyFrontendAction<MyASTConsumer>>());
}