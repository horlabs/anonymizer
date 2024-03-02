#ifndef LIBTOOLINGAST_DECLSCOPEBUILDER_H
#define LIBTOOLINGAST_DECLSCOPEBUILDER_H

#ifndef CLANG_LIBS
#define CLANG_LIBS

#include "clang/AST/RecursiveASTVisitor.h"
#include "llvm/Support/CommandLine.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"

#endif

using namespace clang;

class DeclScopeBuilder : public RecursiveASTVisitor<DeclScopeBuilder> {
  private:
    ASTContext &Context;
    SourceManager &sm;
    /*
     * For now scope only in function-context, not for classes and without
     * globals ToDo: DeclContext helpful?
     */
    std::stack<const Stmt *> scopeStack;
    std::vector<std::shared_ptr<std::vector<NamedDecl *>>> scopes;
    std::shared_ptr<std::vector<NamedDecl *>> globalScope;
    std::map<const Stmt *, std::shared_ptr<std::vector<NamedDecl *>>> scopeMap;
    std::map<const NamedDecl *, std::shared_ptr<std::vector<NamedDecl *>>> declMap;

    std::map<const Stmt *, long> scopeDepth;

    void appendScope(const Stmt *stmt);

public:
    explicit DeclScopeBuilder(ASTContext &Context) : Context(Context), sm(Context.getSourceManager()) {
        globalScope = std::make_shared<std::vector<NamedDecl *>>();
    };

    bool VisitVarDecl(VarDecl *vd);

    bool VisitDeclStmt(DeclStmt *ds);

    bool VisitForStmt(ForStmt *fs);

    bool VisitCXXForRangeStmt(CXXForRangeStmt *S);

    bool VisitDoStmt(DoStmt *ds);

    bool VisitFunctionDecl(FunctionDecl *fd);

    bool VisitWhileStmt(WhileStmt *ws);

    bool VisitCompoundStmt(CompoundStmt *cs);

    void addScope(const Stmt *stmt);

    void insertDecl(NamedDecl *namedDecl);

    void printScopes();

    void buildScopeMap();

    std::vector<NamedDecl *> getScopeForDecl(const NamedDecl *);

    void printAdresses();

    bool VisitLambdaExpr(LambdaExpr *S);
};

#endif // LIBTOOLINGAST_DECLSCOPEBUILDER_H
