#ifndef CLANG_LIBS
#define CLANG_LIBS

#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"

#endif

#include "ASTFrontendActionTemplate.inl"

#include "FunctionRemovalTransformer.h"

using namespace clang;
#define MYDEBUG 1

// TODO See 3 Todo's in insertFctIntoBody
// TODO Implement LocationStrategy in both strategy cases == adding, removing
// fct.
// TODO check if callbyref, callbypointer needs consideration in fct removing
// TODO strategy 3: accept case where function call is the only command in a
// line...

static llvm::cl::OptionCategory
    MyOptionCategory("Function Removal Transformer");

static llvm::cl::opt<int> OurCMDOption1("chooseLocationStrategy",
                                        llvm::cl::cat(MyOptionCategory));

/* ****************** ************** **************** */

class MyASTConsumer : public ASTConsumer {
  public:
    explicit MyASTConsumer(ASTContext &Context, Rewriter &OurRewriter)
        : Visitor(Context, OurRewriter) {}

    void HandleTranslationUnit(ASTContext &Context) override {
        Visitor.TraverseDecl(Context.getTranslationUnitDecl());

        auto chooseLocationStrategy =
            static_cast<ChooseLocationStrategy>(OurCMDOption1.getValue());
        Visitor.replacecommand(chooseLocationStrategy);
    }

  private:
    //    commandlineoption cmdoption;
    FunctionRemovalTransformer Visitor;
};

int main(int argc, const char **argv) {
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                      MyOptionCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                   OptionsParser.getSourcePathList());
    return Tool.run(&*clang::tooling::newFrontendActionFactory<
                     MyFrontendAction<MyASTConsumer>>());
}
