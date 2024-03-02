#ifndef CLANG_LIBS
#define CLANG_LIBS

#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"

#endif

#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"

#include "../../ASTFrontendActionTemplate.inl"
#include "../../include/SourceTextHelper.h"
#include "RemoveEmptyFunctions.h"

using namespace clang;
using namespace clang::ast_matchers;

static llvm::cl::OptionCategory MyOptionCategory("Empty Function Transformer");

class EmptyFunctionMatcher : public MatchFinder::MatchCallback {
  private:
    std::vector<StringRef> &emptyFunctions;

  public:
    explicit EmptyFunctionMatcher(std::vector<StringRef> &emptyFunctions) : emptyFunctions(emptyFunctions) {};

    void run(const MatchFinder::MatchResult &Result) override {
        ASTContext *Context = Result.Context;
        auto &Manager = Context->getSourceManager();

        const auto *FD = Result.Nodes.getNodeAs<FunctionDecl>("function");
        if (FD && Manager.isWrittenInMainFile(Manager.getSpellingLoc(FD->getLocStart()))) {
            emptyFunctions.push_back(FD->getName());
        }
    }
};

class EmptyFunctionsTransformer : public RecursiveASTVisitor<EmptyFunctionsTransformer> {
  private:
    ASTContext &Context;
    SourceManager &sm;
    Rewriter &OurRewriter;
    std::vector<StringRef> &emptyFunctions;
  public:
    explicit EmptyFunctionsTransformer(ASTContext &Context, Rewriter &OurRewriter,
                                       std::vector<StringRef> &emptyFunctions) : Context(Context),
                                                                                 sm(Context.getSourceManager()),
                                                                                 OurRewriter(OurRewriter),
                                                                                 emptyFunctions(emptyFunctions) {};

    bool VisitFunctionDecl(const FunctionDecl *FD) {
        if (sm.isWrittenInMainFile(FD->getLocStart())) {
            if (std::find(emptyFunctions.begin(), emptyFunctions.end(), FD->getName()) != emptyFunctions.end()) {
                auto text = getSourceTextStable(Context, sm.getSpellingLoc(FD->getLocStart()),
                                                sm.getSpellingLoc(FD->getLocEnd()));
                auto options = Rewriter::RewriteOptions();
                options.RemoveLineIfEmpty = true;
                if (FD->isThisDeclarationADefinition())
                    OurRewriter.RemoveText(FD->getSourceRange());
                else
                    OurRewriter.RemoveText(FD->getLocStart(), text.size() + 1, options);
            }
        }

        return true;
    }

    bool VisitCallExpr(const CallExpr *Call) {
        if (sm.isWrittenInMainFile(Call->getLocStart()) && Call->getDirectCallee()) {
            const auto &name = Call->getDirectCallee()->getName();
            if (std::find(emptyFunctions.begin(), emptyFunctions.end(), name) != emptyFunctions.end()) {
                auto callText = getSourceTextStable(Context, sm.getSpellingLoc(Call->getLocStart()),
                                                    sm.getSpellingLoc(Call->getLocEnd()));
                bool deleteLine = true;
                for (const auto &parent : Context.getParents(*Call)) {
                    if (!parent.get<CompoundStmt>()) deleteLine = false;
                }
                auto options = Rewriter::RewriteOptions();
                options.RemoveLineIfEmpty = true;

                if (deleteLine)
                    OurRewriter.RemoveText(Call->getLocStart(), callText.size() + 1, options);
                else
                    OurRewriter.RemoveText(Call->getSourceRange());
            }
        }

        return true;
    }

};

/* ****************** ************** **************** */

class MyASTConsumer : public ASTConsumer {
  public:

    explicit MyASTConsumer(ASTContext &Context, Rewriter &OurRewriter) : matcherCallback(emptyFunctions),
                                                                         transformer(Context, OurRewriter,
                                                                                     emptyFunctions) {
    }

    void HandleTranslationUnit(ASTContext &Context) override {
        DeclarationMatcher functionMatcher = functionDecl(
                hasBody(compoundStmt(has(compoundStmt(unless(hasAnySubstatement(stmt()))))))
        ).bind("function");
        MatchFinder FunctionFinder;
        FunctionFinder.addMatcher(functionMatcher, &matcherCallback);
        FunctionFinder.matchAST(Context);
        transformer.TraverseDecl(Context.getTranslationUnitDecl());
    }

  private:
    std::vector<StringRef> emptyFunctions;
    EmptyFunctionMatcher matcherCallback;
    EmptyFunctionsTransformer transformer;
};

int main(int argc, const char **argv) {
  clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                    MyOptionCategory);
  clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                 OptionsParser.getSourcePathList());
  return Tool.run(&*clang::tooling::newFrontendActionFactory<
                   MyFrontendAction<MyASTConsumer>>());
}