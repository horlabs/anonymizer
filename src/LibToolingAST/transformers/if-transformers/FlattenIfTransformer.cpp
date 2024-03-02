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
class FlattenIfTransformer : public RecursiveASTVisitor<FlattenIfTransformer> {
  private:
    ASTContext &Context;
    SourceManager &sm;
    Rewriter &OurRewriter;

    std::vector<const IfStmt *> ifs;

  public:
    explicit FlattenIfTransformer(ASTContext &Context, Rewriter &OurRewriter)
        : Context(Context), sm(Context.getSourceManager()),
          OurRewriter(OurRewriter){};

    /**
     * Until now, only if without else is supported
     * @param IF
     * @return
     */
    // ToDo: Maybe make this recursively and save all processed ifs?
    //  maybe flatten also in the situation of statements after the if by
    //  copying in the then clause and create an else
    bool VisitIfStmt(const IfStmt *IF) {
        if (!sm.isWrittenInMainFile(IF->getLocStart()))
            return true;
        // ToDo: Handle else
        if (IF->getElse())
            return true;

        auto then = IF->getThen();
        bool onlyIfInThen = true;
        const IfStmt *innerIf = nullptr;
        if (isa<CompoundStmt>(then)) {
            int num = 0;
            for (auto child : then->children()) {
                num++;
                if (!isa<IfStmt>(child) || cast<IfStmt>(child)->getElse() != nullptr) {
                    onlyIfInThen = false;
                    break;
                }
                innerIf = cast<IfStmt>(child);
            }
            if (num > 1) {
                onlyIfInThen = false;
            }
        } else if (isa<IfStmt>(then)) {
            innerIf = cast<IfStmt>(then);
            onlyIfInThen = cast<IfStmt>(then)->getElse() == nullptr;
        } else {
            onlyIfInThen = false;
        }
        if (!onlyIfInThen || innerIf == nullptr)
            return true;

        ifs.emplace_back(IF);

        return true;
    }

    void flatteningIfs() {

        std::vector<const IfStmt *> processed;

        for (auto it = ifs.rbegin(); it != ifs.rend(); it++) {

            auto IF = *it;
            auto then = IF->getThen();
            const IfStmt *innerIf = nullptr;
            if (isa<CompoundStmt>(then)) {
                for (auto child : then->children()) {
                    innerIf = cast<IfStmt>(child);
                }
            } else if (isa<IfStmt>(then)) {
                innerIf = cast<IfStmt>(then);
            } else {
                assert(false);
            }

            std::string rewritten;
            llvm::raw_string_ostream sstream(rewritten);
            sstream << "(";
            IF->getCond()->printPretty(sstream, nullptr, PrintingPolicy(Context.getLangOpts()));
            sstream << ") && (";
            if (std::find(processed.begin(), processed.end(), innerIf) != processed.end()) {
                sstream << OurRewriter.getRewrittenText(innerIf->getCond()->getSourceRange());
            } else {
                innerIf->getCond()->printPretty(sstream, nullptr, PrintingPolicy(Context.getLangOpts()));
            }
            sstream << ")";
            processed.emplace_back(IF);

            auto opts = Rewriter::RewriteOptions();
            opts.RemoveLineIfEmpty = true;

            auto innerCondEnd = innerIf->getThen()->getLocStart();
            if (!isa<CompoundStmt>(innerIf->getThen())) {
                innerCondEnd = innerCondEnd.getLocWithOffset(-1);
            }
            OurRewriter.RemoveText(SourceRange(innerIf->getLocStart(), innerCondEnd), opts);
            if (isa<CompoundStmt>(innerIf->getThen())) {
                OurRewriter.RemoveText(innerIf->getThen()->getLocEnd(), 1, opts);
            }
            OurRewriter.ReplaceText(IF->getCond()->getSourceRange(), sstream.str());
        }
    }
};

/* ****************** ************** **************** */

class MyASTConsumer : public ASTConsumer {
  public:
    explicit MyASTConsumer(ASTContext &Context, Rewriter &OurRewriter)
        : transformer(Context, OurRewriter) {}

    void HandleTranslationUnit(ASTContext &Context) override {
        transformer.TraverseDecl(Context.getTranslationUnitDecl());
        transformer.flatteningIfs();
    }

  private:
    FlattenIfTransformer transformer;
};

int main(int argc, const char **argv) {
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                      MyOptionCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                   OptionsParser.getSourcePathList());
    return Tool.run(&*clang::tooling::newFrontendActionFactory<
                     MyFrontendAction<MyASTConsumer>>());
}