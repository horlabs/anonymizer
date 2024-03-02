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

static llvm::cl::OptionCategory
    MyOptionCategory("Compound Assignment Transformer");

/**
 * Replace compund assignments with normal assignments and binary operators
 * Also do this with unary increment and decrement (wrt postfix and prefix and
 * their sideeffects)
 *
 * ToDo: For now, only a few cases are implemented (only such occuring in the
 * dataset)
 */
class CompundAssignmentTransformer
    : public RecursiveASTVisitor<CompundAssignmentTransformer> {
  private:
    ASTContext &Context;
    SourceManager &sm;
    Rewriter &OurRewriter;
    std::vector<const Expr *> processedExpr;

  public:
    explicit CompundAssignmentTransformer(ASTContext &Context,
                                          Rewriter &OurRewriter)
        : Context(Context), sm(Context.getSourceManager()),
          OurRewriter(OurRewriter){};

    bool VisitCompoundAssignOperator(const CompoundAssignOperator *CAO) {
        if (sm.isWrittenInMainFile(CAO->getLocStart())) {
            auto parent = Context.getParents(*CAO)[0];
            while (parent.get<ParenExpr>())
                parent = Context.getParents(parent)[0];
            if (parent.get<CompoundAssignOperator>()) return true;
            auto sides = handleOperator(CAO);
            if (sides.first.empty() and sides.second.empty())
                return true;
            auto rewritten = "(" + sides.first + ") = (" + sides.second + ")";
            OurRewriter.ReplaceText(CAO->getSourceRange(), rewritten);
        }
        return true;
    }

    std::pair<std::string, std::string>
    handleOperator(const CompoundAssignOperator *CAO) {
        if (std::find(processedExpr.begin(), processedExpr.end(), CAO) !=
            processedExpr.end())
            return std::make_pair("", "");
        processedExpr.emplace_back(CAO);
        std::string op;
        switch (CAO->getOpcode()) {
            case BinaryOperatorKind::BO_AddAssign:
                op = "+";
                break;
            case BinaryOperatorKind::BO_AndAssign:
                op = "&";
                break;
            case BinaryOperatorKind::BO_DivAssign:
                op = "/";
                break;
            case BinaryOperatorKind::BO_MulAssign:
                op = "*";
                break;
            case BinaryOperatorKind::BO_OrAssign:
                op = "|";
                break;
            case BinaryOperatorKind::BO_RemAssign:
                op = "%";
                break;
            case BinaryOperatorKind::BO_ShlAssign:
                op = "<<";
                break;
            case BinaryOperatorKind::BO_ShrAssign:
                op = ">>";
                break;
            case BinaryOperatorKind::BO_SubAssign:
                op = "-";
                break;
            case BinaryOperatorKind::BO_XorAssign:
                op = "^";
                break;
            default:;
        }
        std::string lhs{};
        llvm::raw_string_ostream lhsStream(lhs);
        std::string rhs{};
        llvm::raw_string_ostream rhsStream(rhs);

        auto lhsExpr = CAO->getLHS();
        while (auto paren = dyn_cast<ParenExpr>(lhsExpr))
            lhsExpr = paren->getSubExpr();

        rhsStream << "(";
        if (auto lhsCAO = dyn_cast<CompoundAssignOperator>(lhsExpr)) {
            auto sides = handleOperator(lhsCAO);
            lhsStream << sides.first;
            rhsStream << sides.second;
        } else {
            lhsExpr->printPretty(lhsStream, nullptr, PrintingPolicy(Context.getLangOpts()));
            rhsStream << lhsStream.str();
        }
        lhsStream.flush();
        rhsStream << ")";

        rhsStream << " " << op << " (";
        auto rhsExpr = CAO->getRHS();
        while (auto paren = dyn_cast<ParenExpr>(rhsExpr))
            rhsExpr = paren->getSubExpr();
        if (auto rhsCAO = dyn_cast<CompoundAssignOperator>(rhsExpr)) {
            auto sides = handleOperator(rhsCAO);
            rhsStream << "(" << sides.first << ") = (" << sides.second << ")";
        } else {
            rhsExpr->printPretty(rhsStream, nullptr, PrintingPolicy(Context.getLangOpts()));
        }
        rhsStream << ")";
        rhsStream.flush();
        return std::make_pair(lhs, rhs);
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
    CompundAssignmentTransformer transformer;
};

int main(int argc, const char **argv) {
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                      MyOptionCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                   OptionsParser.getSourcePathList());
    return Tool.run(&*clang::tooling::newFrontendActionFactory<
                     MyFrontendAction<MyASTConsumer>>());
}