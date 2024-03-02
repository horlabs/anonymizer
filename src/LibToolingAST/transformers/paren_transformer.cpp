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
#include "include/SourceTextHelper.h"

using namespace clang;

static llvm::cl::OptionCategory MyOptionCategory("Paren Transformer");

class ParenTransformer : public RecursiveASTVisitor<ParenTransformer> {
  private:
    ASTContext &Context;
    SourceManager &sm;
    Rewriter &OurRewriter;
    std::vector<SourceLocation> changedTypes{};
    std::vector<std::string> namespaces{};

  public:
    explicit ParenTransformer(ASTContext &Context, Rewriter &OurRewriter)
        : Context(Context), sm(Context.getSourceManager()),
          OurRewriter(OurRewriter){};

    bool VisitDeclStmt(DeclStmt *DS) {
        if (!sm.isWrittenInMainFile(DS->getLocStart()))
            return true;
        for (auto *curDecl : DS->decls()) {
            if (auto *varDecl = dyn_cast<VarDecl>(curDecl)) {
                auto nameStart = varDecl->getLocation();
                auto nameEnd = varDecl->getLocation().getLocWithOffset(
                    static_cast<int>(varDecl->getNameAsString().size()) - 1);
                auto before =
                    getSourceTextStable(Context, nameStart.getLocWithOffset(-1),
                                        nameStart.getLocWithOffset(-1));
                auto after =
                    getSourceTextStable(Context, nameEnd.getLocWithOffset(1),
                                        nameEnd.getLocWithOffset(1));
                const QualType &type = varDecl->getType();
                if (before == "(" && after == ")" && !(type->isPointerType())) {
                    OurRewriter.ReplaceText(
                        SourceRange(nameStart.getLocWithOffset(-1),
                                    nameEnd.getLocWithOffset(1)),
                        " " + varDecl->getNameAsString());
                } else if (varDecl->getInitStyle() ==
                           VarDecl::InitializationStyle::CallInit) {
                    if (getSourceTextStable(varDecl->getInit(), Context)
                                .str() == varDecl->getNameAsString() &&
                        varDecl->getLocation() ==
                            varDecl->getInit()->getExprLoc())
                        continue;
                    if (!type.isTrivialType(Context))
                        continue;
                    auto endLoc = varDecl->getLocEnd();
                    endLoc = endLoc.getLocWithOffset(
                        getSourceTextStable(Context, endLoc, endLoc).size());
                    auto range = SourceRange(varDecl->getLocation(), endLoc);
                    std::string newStr =
                        varDecl->getNameAsString() + " = " +
                        getSourceTextStable(varDecl->getInit(), Context).str();
                    OurRewriter.ReplaceText(range, newStr);
                }
            }
        }
        return true;
    }

    // ToDo: replace expr. like (a + b) without any further operands (like a =
    // (i+1); => a = i+1;)
    bool VisitParenExpr(ParenExpr *PE) {
        if (!sm.isWrittenInMainFile(PE->getLocStart()))
            return true;
        bool singleValue = isa<IntegerLiteral>(PE->getSubExpr());
        singleValue |= isa<FloatingLiteral>(PE->getSubExpr());
        singleValue |= isa<DeclRefExpr>(PE->getSubExpr());
        singleValue |=
            isa<CallExpr>(PE->getSubExpr()) &&
            (cast<CallExpr>(PE->getSubExpr())->getDirectCallee() == nullptr ||
             !cast<CallExpr>(PE->getSubExpr())
                  ->getDirectCallee()
                  ->isOverloadedOperator());
        singleValue |= isa<ArraySubscriptExpr>(PE->getSubExpr());
        if (!singleValue)
            for (auto parent : Context.getParents(*PE)) {
                if (parent.get<Expr>() == nullptr)
                    continue;
                if (isa<ParenExpr>(parent.get<Expr>()))
                    continue;
                if (isa<UnaryExprOrTypeTraitExpr>(parent.get<Expr>()))
                    return true;
                if (parent.get<BinaryOperator>() &&
                    !parent.get<BinaryOperator>()->isAssignmentOp())
                    return true;
                if (!isa<DeclRefExpr>(PE->getSubExpr()) &&
                    parent.get<BinaryOperator>()) {
                    auto *BO = parent.get<BinaryOperator>();
                    if (BO->isAssignmentOp() && BO->getRHS() == PE)
                        continue;
                    if (!BO->isComparisonOp())
                        return true;
                } else {
                    return true;
                }
            }
        std::string expr =
            " " +
            getSourceTextStable(Context, PE->getSubExpr()->getLocStart(),
                                PE->getSubExpr()->getLocEnd()) +
            " ";
        OurRewriter.ReplaceText(PE->getSourceRange(), expr);
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
    ParenTransformer transformer;
};

int main(int argc, const char **argv) {
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                      MyOptionCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                   OptionsParser.getSourcePathList());
    return Tool.run(&*clang::tooling::newFrontendActionFactory<
                     MyFrontendAction<MyASTConsumer>>());
}