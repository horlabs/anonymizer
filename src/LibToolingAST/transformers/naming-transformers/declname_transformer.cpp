#ifndef CLANG_LIBS
#define CLANG_LIBS
#include "llvm/Support/CommandLine.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "clang/Rewrite/Core/Rewriter.h"
#endif

#include "../utils_transform.h"
#include "VariableNameTransformer.h"
#include <string>
#include <queue>
#include <set>
#include <limits>
#include "../ASTFrontendActionTemplate.inl"
#include "../ControlDataFlow/CDFGraphQueryHandler.h"

using namespace clang;
//#define MYDEBUG 1


// TODO check for name conflicts -- better check for name conflict, e.g. if name conflict in same scope?
// but less important since code jam files have a limited length, so our current check should be sufficient so far.

// TODO test CFG with function parameters with fcts with multiple params .. could create problems...
// since stmt contains multiple Decl's and we have edges to all CallExprs from this stmt...

static llvm::cl::OptionCategory MyOptionCategory("Variable Name Transformer");

static llvm::cl::opt<std::string> OurCMDOption1("from_declname", llvm::cl::cat(MyOptionCategory));
static llvm::cl::opt<std::string> OurCMDOption2("into_declname", llvm::cl::cat(MyOptionCategory));
static llvm::cl::opt<int> OurCMDOption3("seed", llvm::cl::cat(MyOptionCategory));


/**
 * Variable / Function Name Transformer.
 * We do not rename extern variables, only if defined in same file...
 *
 * Rename   x   into   y,       where x, y = {random, user-defined}
 * If x is random, we can select the variable/function whose count is most similar to the occurence count of the target.
 *
 * TODO class rewriting is not supported, yet.
 */


/* ****************** ************** **************** */

class MyASTConsumer : public ASTConsumer {
public:

    explicit MyASTConsumer(ASTContext &Context, Rewriter &OurRewriter) : Visitor(Context, OurRewriter) {
        cmdoption.from_declname = static_cast<std::string>(OurCMDOption1.getValue());
        cmdoption.into_declname = static_cast<std::string>(OurCMDOption2.getValue());
        cmdoption.declselection = static_cast<decl_selection >(1); //OurCMDOption3.getValue());
        cmdoption.target_occurence_count = static_cast<int>(0); // OurCMDOption4.getValue());
        cmdoption.seed = static_cast<int>(OurCMDOption3.getValue());
    }

    void HandleTranslationUnit(ASTContext &Context) override {
        Visitor.TraverseDecl(Context.getTranslationUnitDecl());
        Visitor.init(Context);
        Visitor.replacecommand(cmdoption);
    }

private:
    commandlineoption cmdoption;
    VariableNameTransformer Visitor;
};

int main(int argc, const char **argv) {
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv, MyOptionCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(), OptionsParser.getSourcePathList());
    return Tool.run(&*clang::tooling::newFrontendActionFactory<MyFrontendAction<MyASTConsumer>>());
}