#ifndef LIBTOOLINGAST_DECLNAME_TRANSFORMER_H
#define LIBTOOLINGAST_DECLNAME_TRANSFORMER_H

#include "../ControlDataFlow/ControlFlowGraphWithDataFlow.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"

#include "../ControlDataFlow/DeclRefMapping/DeclRefMapping.h"

using namespace clang;
using namespace clang::ast_matchers;

enum decl_selection { select_randomly = 1, similar_occurence = 2 };

struct commandlineoption {
    std::string from_declname;
    std::string into_declname;
    decl_selection declselection;
    int target_occurence_count;
    int seed;
};

/**
 * Builds DeclRefMapping by storing matched VarDecls, DeclStmts and DeclRefExprs.
 */
class DeclRefMappingBuilder : public MatchFinder::MatchCallback {
  public:
    explicit DeclRefMappingBuilder(DeclRefMapping *DeclRefMap)
        : DeclRefMap(DeclRefMap) {}

    virtual void run(const MatchFinder::MatchResult &Result);

  private:
    DeclRefMapping *DeclRefMap;
};

/**
 * Variable / Function Name Transformer.
 * We do not rename extern variables, only if defined in same file...
 *
 * Rename   x   into   y,       where x, y = {random, user-defined}
 * If x is random, we can select the variable/function whose count is most
 * similar to the occurence count of the target.
 *
 * TODO class rewriting is not supported, yet.
 */
class VariableNameTransformer : public RecursiveASTVisitor<VariableNameTransformer> {
  public:
    ControlFlowGraphWithDataFlow *cfggraph;

    explicit VariableNameTransformer(ASTContext &Context, Rewriter &OurRewriter);

    ~VariableNameTransformer() { delete cfggraph; }

    void init(ASTContext &Context);
    /* ******************* Collection Methods ******************* */

    bool VisitNamedDecl(NamedDecl *nd);

    /**
     * Visit all functions and store them in CFG graph.
     * @param f
     * @return
     */
    bool VisitFunctionDecl(FunctionDecl *f);

    /* ******************* Rewriting Methods ******************* */

    /**
     * Replace a declaration name by a new name. We can rewrite variable and function declarations.
     * @return false if something goes wrong.
     */
    bool replacecommand(commandlineoption cmdoption);

    /**
     * Get all declarations that have the name which we want to replace.
     * @param string_from_varname
     * @param from_decls
     * @return false if we get an error. Saves the declarations in the from_decls vector (call by reference).
     */
    bool getDeclForName(std::string &string_from_varname, std::vector<NamedDecl *> &from_decls);


    /**
     * Checks if there is a name conflict for input_varname, if so returns true, otherwise false
     * @param input_varname
     * @return true if name conflict
     */
    bool checkForNameConflict(std::string &input_varname);

    /**
     * Rewrites all variable declarations with the target name.
     * @param from_decl
     * @return
     */
    bool renamevariabledecl(const VarDecl *from_decl, const std::string &into_declname);

    /**
     * Rewrites all function declarations that have the target name.
     * @param from_decl
     * @return
     */
    bool renamefunctiondecl(const FunctionDecl *from_decl, const std::string &into_declname);

    /**
     * Compute a new name for a variable or function.
     * @param d
     * @return
     */
    std::string determineIntoVarName(NamedDecl *d, int seed);

    /**
     * Computes the occurence number for each usable declaration. To this end,
     * it counts all the references to a variable or function declaration. For
     * instance, if two declarations have the same name (so that they are in
     * other scopes), we will add both counts, since we will replace both
     * declarations later. Saves declaration name that we should replace based
     * on the occurence count in the member from_varname
     * @param from_declname call by reference, changed into the name that fits
     * the most
     * @param target_occurence_count the occurence count that represents the
     * target count
     * @return false if error
     */
    bool computeOccurenceCount(std::string &from_declname, int target_occurence_count);


private:
    ASTContext &Context;
    Rewriter &OurRewriter;
    SourceManager &sm;
    MatchFinder PreMatcher;

    std::unique_ptr<DeclRefMapping> DeclRefMap;
    DeclRefMappingBuilder DRMB;

    // All 'safe' declarations that we can rewrite without major problems, e.g. we do not rewrite extern variables
    std::vector<NamedDecl *> allusabledeclarations;
    // All declaration names that were visited during the AST traversal,
    // also includes declarations that we won't rewrite.
    std::vector<std::string> alldeclarationnames;
};

#endif // LIBTOOLINGAST_DECLNAME_TRANSFORMER_H
