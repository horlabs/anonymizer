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

static llvm::cl::OptionCategory MyOptionCategory("Comma Transformer");

/**
 * Convert comma-operators in mutliple statements if possible
 * Some edge cases are not supported and will remain unchanged
 */
class CommaTransformer : public RecursiveASTVisitor<CommaTransformer> {
  private:
    ASTContext &Context;
    SourceManager &sm;
    Rewriter &OurRewriter;
    std::vector<const BinaryOperator *> processed;

  public:
    explicit CommaTransformer(ASTContext &Context, Rewriter &OurRewriter)
        : Context(Context), sm(Context.getSourceManager()),
          OurRewriter(OurRewriter){};

    bool VisitBinaryOperator(const BinaryOperator *BO) {
        if (sm.isWrittenInMainFile(BO->getLocStart())) {
            if (std::find(processed.begin(), processed.end(), BO) !=
                processed.end())
                return true;
            if (BO->getOpcode() != BinaryOperatorKind::BO_Comma)
                return true;
            bool addCompoundStmt = false;
            auto parents = Context.getParents(*BO);
            bool loop = true;
            while (loop) {
                loop = false;
                for (auto parent : parents) {
                    if (parent.get<ExprWithCleanups>()) {
                        parents = Context.getParents(parent);
                        loop = true;
                        break;
                    }
                    // ToDo: Transform some of these special cases?
                    if (auto ifStmt = parent.get<IfStmt>()) {
                        addCompoundStmt = true;
                        if (ifStmt->getCond() == BO)
                            return true;
                    }
                    if (auto condOp = parent.get<ConditionalOperator>()) {
                        return true;
                    }
                    if (auto whileStmt = parent.get<WhileStmt>()) {
                        addCompoundStmt = true;
                        if (whileStmt->getCond() == BO)
                            return true;
                    }
                    if (auto forStmt = parent.get<ForStmt>()) {
                        addCompoundStmt = true;
                        processed.emplace_back(BO);
                        auto curBO = BO;
                        while (isa<BinaryOperator>(curBO->getLHS()) &&
                               cast<BinaryOperator>(curBO->getLHS())
                                       ->getOpcode() ==
                                   BinaryOperatorKind::BO_Comma) {
                            curBO = cast<BinaryOperator>(curBO->getLHS());
                            processed.emplace_back(curBO);
                        }
                        curBO = BO;
                        while (isa<BinaryOperator>(curBO->getRHS()) &&
                               cast<BinaryOperator>(curBO->getRHS())
                                       ->getOpcode() ==
                                   BinaryOperatorKind::BO_Comma) {
                            curBO = cast<BinaryOperator>(curBO->getRHS());
                            processed.emplace_back(curBO);
                        }
                        if (forStmt->getCond() == BO)
                            return true;
                        if (forStmt->getInit() == BO)
                            return true;
                        if (forStmt->getInc() == BO)
                            return true;
                    }
                    if (auto pExpr = parent.get<ParenExpr>()) {
                        if ((Context.getParents(parent)[0].get<BinaryOperator>() &&
                            Context.getParents(parent)[0].get<BinaryOperator>()->getOpcode() !=
                            BinaryOperatorKind::BO_Comma)) {
                            return true;
                        } else if (Context.getParents(parent)[0].get<ConditionalOperator>()) {
                            return true;
                        } else {
                            OurRewriter.RemoveText(pExpr->getLParen(), 1);
                            OurRewriter.RemoveText(pExpr->getRParen(), 1);
                        }
                    }
                    if (parent.get<CompoundStmt>())
                        addCompoundStmt = false;
                    if (auto binParent = parent.get<BinaryOperator>()) {
                        if (binParent->getOpcode() ==
                            BinaryOperatorKind::BO_Comma)
                            addCompoundStmt = false;
                    }
                }
            }
            /// Token length
            auto tokenLength =
                static_cast<int>(getSourceTextStable(Context, BO->getLocEnd(),
                                                     BO->getLocEnd())
                                     .size()) +
                1;
            OurRewriter.ReplaceText(
                SourceRange(BO->getOperatorLoc(), BO->getOperatorLoc()), ";\n");
            if (addCompoundStmt) {
                OurRewriter.InsertTextBefore(BO->getLocStart(), "{\n");
                OurRewriter.InsertTextAfter(
                    BO->getLocEnd().getLocWithOffset(tokenLength), "\n}");
            }
        }
        return true;
    }

    std::string rewriteComma(const BinaryOperator *BO) {
        processed.emplace_back(BO);
        std::string rewritten;
        llvm::raw_string_ostream sstream{rewritten};
        if (isa<BinaryOperator>(BO->getLHS()) &&
            cast<BinaryOperator>(BO->getLHS())->getOpcode() ==
                BinaryOperatorKind::BO_Comma) {
            sstream << rewriteComma(cast<BinaryOperator>(BO->getLHS()));
        } else {
            BO->getLHS()->printPretty(sstream, nullptr,
                                      PrintingPolicy(Context.getLangOpts()));
        }
        sstream << ";\n";
        if (isa<BinaryOperator>(BO->getRHS()) &&
            cast<BinaryOperator>(BO->getRHS())->getOpcode() ==
                BinaryOperatorKind::BO_Comma) {
            sstream << rewriteComma(cast<BinaryOperator>(BO->getRHS()));
        } else {
            BO->getRHS()->printPretty(sstream, nullptr,
                                      PrintingPolicy(Context.getLangOpts()));
        }
        return sstream.str();
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
    CommaTransformer transformer;
};

int main(int argc, const char **argv) {
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                      MyOptionCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                   OptionsParser.getSourcePathList());
    return Tool.run(&*clang::tooling::newFrontendActionFactory<
                     MyFrontendAction<MyASTConsumer>>());
}