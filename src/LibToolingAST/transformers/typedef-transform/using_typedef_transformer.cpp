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

#include "../ASTFrontendActionTemplate.inl"
#include "../include/SourceTextHelper.h"

using namespace clang;

static llvm::cl::OptionCategory MyOptionCategory("Using Typedef Transformer");

class UsingTypedefTransformer
    : public RecursiveASTVisitor<UsingTypedefTransformer> {
  private:
    ASTContext &Context;
    SourceManager &sm;
    Rewriter &OurRewriter;
    std::vector<SourceLocation> changedTypes{};
    std::vector<std::string> namespaces{};

  public:
    explicit UsingTypedefTransformer(ASTContext &Context, Rewriter &OurRewriter)
        : Context(Context), sm(Context.getSourceManager()),
          OurRewriter(OurRewriter){};

    /**
     * Remove multiple declarations of namespaces used by this file
     * @param UDD
     * @return true
     */
    bool VisitUsingDirectiveDecl(UsingDirectiveDecl *UDD) {
        if (sm.isWrittenInMainFile(UDD->getLocStart())) {
            if (std::find(namespaces.begin(), namespaces.end(),
                          UDD->getNominatedNamespace()->getNameAsString()) !=
                namespaces.end()) {
                int offset = static_cast<int>(UDD->getNominatedNamespace()->getNameAsString().size());
                removeLines(SourceRange(UDD->getLocStart(), UDD->getIdentLocation().getLocWithOffset(offset)));
                return true;
            }
            namespaces.push_back(UDD->getNominatedNamespace()->getNameAsString());
        }
        return true;
    }

    bool VisitTypeAliasDecl(TypeAliasDecl *TAD) {
        if (sm.isWrittenInMainFile(TAD->getLocation())) {
            if (!TAD->isUsed() && !TAD->isReferenced()) {
                if (TAD->getDescribedAliasTemplate()) {
                    auto *AT = TAD->getDescribedAliasTemplate();
                    removeLines(AT->getSourceRange());
                } else {
                    removeLines(SourceRange(TAD->getLocStart(), TAD->getTypeSourceInfo()->getTypeLoc().getLocEnd()));
                }
                return true;
            }
            if (TAD->getDescribedAliasTemplate()) {
                return true;
            }
            OurRewriter.ReplaceText(
                TAD->getSourceRange(),
                "typedef " + TAD->getTypeSourceInfo()->getType().getAsString() +
                    " " + TAD->getNameAsString());
        }

        return true;
    }

    void removeLines(const SourceRange range) const {
        auto options = Rewriter::RewriteOptions();
        options.RemoveLineIfEmpty = true;
        auto removeRange = SourceRange(range.getBegin(), range.getEnd().getLocWithOffset(1));
        OurRewriter.RemoveText(removeRange, options);
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
    UsingTypedefTransformer transformer;
};

int main(int argc, const char **argv) {
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                      MyOptionCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                   OptionsParser.getSourcePathList());
    return Tool.run(&*clang::tooling::newFrontendActionFactory<
                     MyFrontendAction<MyASTConsumer>>());
}