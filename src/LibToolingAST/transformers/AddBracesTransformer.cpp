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

static llvm::cl::OptionCategory MyOptionCategory("Add braces Transformer");

/**
 * Add braces to every if, else, while, for, do-while
 * clang-tidy can do this too, but removes in some cases needed semicolons
 */
class AddBracesTransformer : public RecursiveASTVisitor<AddBracesTransformer> {
  private:
    ASTContext &Context;
    SourceManager &sm;
    Rewriter &OurRewriter;

  public:
    explicit AddBracesTransformer(ASTContext &Context, Rewriter &OurRewriter)
        : Context(Context), sm(Context.getSourceManager()),
          OurRewriter(OurRewriter){};

    bool VisitIfStmt(const IfStmt *IF) {
        if (!sm.isWrittenInMainFile(IF->getLocStart()))
            return true;
        if (!isa<CompoundStmt>(IF->getThen())) {
            addBraces(IF->getThen()->getLocStart(), IF->getThen()->getLocEnd());
        }
        if (IF->getElse() != nullptr && !isa<CompoundStmt>(IF->getElse())) {
            addBraces(IF->getElse()->getLocStart(), IF->getElse()->getLocEnd());
        }
        return true;
    }

    bool VisitForStmt(const ForStmt *FOR) {
        if (!sm.isWrittenInMainFile(FOR->getLocStart()))
            return true;
        if (isa<CompoundStmt>(FOR->getBody()))
            return true;

        addBraces(FOR->getBody()->getLocStart(), FOR->getLocEnd());

        return true;
    }

    bool VisitDoStmt(const DoStmt *DO) {
        if (!sm.isWrittenInMainFile(DO->getLocStart()))
            return true;
        if (isa<CompoundStmt>(DO->getBody()))
            return true;

        addBraces(DO->getBody()->getLocStart(), DO->getBody()->getLocEnd());

        return true;
    }

    bool VisitWhileStmt(const WhileStmt *WHILE) {
        if (!sm.isWrittenInMainFile(WHILE->getLocStart()))
            return true;
        if (isa<CompoundStmt>(WHILE->getBody()))
            return true;

        addBraces(WHILE->getBody()->getLocStart(), WHILE->getLocEnd());

        return true;
    }

    void addBraces(SourceLocation startLoc, SourceLocation endLoc) {
        startLoc = sm.getExpansionLoc(startLoc);
        int length = getSourceTextStable(Context, startLoc, endLoc).size();
        endLoc = startLoc.getLocWithOffset(length + 1);
        OurRewriter.InsertTextBefore(startLoc, "{");
        OurRewriter.InsertTextAfter(endLoc, "\n}");
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
    AddBracesTransformer transformer;
};

int main(int argc, const char **argv) {
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                      MyOptionCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                   OptionsParser.getSourcePathList());
    return Tool.run(&*clang::tooling::newFrontendActionFactory<
                     MyFrontendAction<MyASTConsumer>>());
}
