#ifndef LIBTOOLINGAST_FCTREMOVAL_TRANSFORMER_H
#define LIBTOOLINGAST_FCTREMOVAL_TRANSFORMER_H

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

#include "../Utilities/Utils.h"
#include "ASTFrontendActionTemplate.inl"
#include "ControlDataFlow/CDFGraphQueryHandler.h"
#include "ControlDataFlow/ControlFlowGraphWithDataFlow.h"
#include "RenamingGuide.h"
#include "utils_transform.h"
#include "clang/AST/ParentMap.h"
#include <string>

// enum Strategy {insertFctInBody = 3};
enum ChooseLocationStrategy { mincallnumber = 1, deepest = 2, minloc = 3 };

/**
 * We remove functions by adding its source text to the caller location.
 * We do not handle Macro's here.
 */
class FunctionRemovalTransformer
    : public RecursiveASTVisitor<FunctionRemovalTransformer> {
  public:
    ControlFlowGraphWithDataFlow *cfggraph;

    explicit FunctionRemovalTransformer(ASTContext &Context,
                                        Rewriter &OurRewriter)
        : Context(Context), OurRewriter(OurRewriter),
          sm(Context.getSourceManager()) {
        cfggraph = new ControlFlowGraphWithDataFlow(&Context);
    }

    ~FunctionRemovalTransformer() { delete cfggraph; }

    /* ******************* Collection Methods ******************* */

    /**
     * Visit all functions and store them in CFG graph. In addition, saves all
     * function declarations.
     * @param f
     * @return
     */
    bool VisitFunctionDecl(FunctionDecl *f);

    /* ******************* Rewriting Methods ******************* */

    void replacecommand(ChooseLocationStrategy chooseLocationStrategy);

    void
    handlefctcall(const CallExpr *curcallexpr, const std::string &bodytext,
                  const FunctionDecl *chosenFuncDecl,
                  std::vector<std::pair<SourceRange, std::string>> &callinfos);

  private:
    ASTContext &Context;
    Rewriter &OurRewriter;
    SourceManager &sm;

    std::vector<FunctionDecl *> functiondeclarations;

    enum fctcalltype { callalone = 1, callassignment = 2, callother = 3 };

    // TODO what if decl without definition
    // TODO check for name conflicts

    /**
     * Will move the function code to each location where fct is called.
     * In this way, we can easily replace functions that represent some
     * convenience function for an author, e.g. computing the maximum. Note that
     * this function will also remove functions that are never used.
     * @param chooseLocationStrategy the strategy to find the function that we
     * want to move to the calling location
     * @return true if insertion was successful.
     */
    bool insertFctIntoBody(const ChooseLocationStrategy chooseLocationStrategy);

    std::pair<bool, ast_type_traits::DynTypedNode>
    isastandalonecall(const CallExpr *curcallexpr);

    void processstandalonecall(
        const CallExpr *curcallexpr, const std::string &bodytext,
        const FunctionDecl *chosenFuncDecl,
        const ast_type_traits::DynTypedNode dtn,
        std::vector<std::pair<SourceRange, std::string>> &callinfos);

    /**
     * Determines if function is called as part of an assignment. If so, either
     * it is part of a variable declaration (then the parent is a VarDecl), or
     * is it just an assignment (then the parent is a BinaryOperator =).
     *
     * @param curcallexpr the current call expression
     * @return a pair of bool and DynTypedNode: bool is true if assignment.
     * DynTypedNode is curcallexpr's parent from the AST that we need for
     * further analysis and rewriting.
     */
    std::pair<bool, ast_type_traits::DynTypedNode>
    isavariableassignment(const CallExpr *curcallexpr);

    void processvariableassignment(
        const CallExpr *curcallexpr, const std::string &bodytext,
        const FunctionDecl *chosenFuncDecl,
        const ast_type_traits::DynTypedNode dtn,
        std::vector<std::pair<SourceRange, std::string>> &callinfos);

    void processothercall(
        const CallExpr *curcallexpr, const std::string &bodytext,
        const FunctionDecl *chosenFuncDecl,
        std::vector<std::pair<SourceRange, std::string>> &callinfos);

    std::string getvariablesfromparams(const CallExpr *curcallexpr,
                                       const FunctionDecl *chosenFuncDecl);

    /**
     * Exclude all functions that are called recursively.
     * @param usablefunctiondeclarations
     * @return
     */
    std::vector<FunctionDecl *> getAllNonRecursiveFunctions(
        std::vector<FunctionDecl *> usablefunctiondeclarations);

    /**
     * Exclude all class methods. In future, we could check if CallExpr is
     * inside that class, then we could move the method to the call location. To
     * move the code outside the class, we may need a more advanced analysis.
     * @param usablefunctiondeclarations
     * @return
     */
    std::vector<FunctionDecl *> getAllNonCXXMethodDecls(
        std::vector<FunctionDecl *> usablefunctiondeclarations);

    /**
     * This function excludes all functions with more than 1 return statement.
     * Why?
     * Later we will replace each return token by an expression where we save
     * the final value. However, skip this function if multiple return
     * statements are present in function body, since we cannot return to caller
     * anymore == we would need to use goto's to stop fct's code execution
     * reliably without any side effects.
     * @param usablefunctiondeclarations
     * @return
     */
    std::vector<FunctionDecl *> getAllSingleReturnFunctions(
        std::vector<FunctionDecl *> usablefunctiondeclarations);

    /**
     * Choose the function that we will move into the respective call location.
     *  Currently, we choose a function based on its call number or the max AST
     * depth of its calling location or we prefer functions that have less lines
     * of code.
     * @param usablefunctiondeclarations
     * @param chooseLocationStrategy either deepest = choose fct based on the
     * deepest caller in AST, any = min calls
     * @return
     */
    FunctionDecl *computeSuitableFunctionToMove(
        const std::vector<FunctionDecl *> &usablefunctiondeclarations,
        const ChooseLocationStrategy chooseLocationStrategy);
};

#endif // LIBTOOLINGAST_FCTREMOVAL_TRANSFORMER_H
