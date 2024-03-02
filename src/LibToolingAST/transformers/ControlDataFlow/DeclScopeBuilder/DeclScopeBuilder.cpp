#include "DeclScopeBuilder.h"

using namespace clang;

// ToDo: include c++ namespaces

void DeclScopeBuilder::appendScope(const Stmt *stmt) {
    if (!scopeStack.empty() && stmt == scopeStack.top())
        return;
    while (!scopeStack.empty() &&
           sm.isBeforeInTranslationUnit(scopeStack.top()->getLocEnd(),
                                        stmt->getLocEnd())) {
        scopeStack.pop();
    }

    scopeDepth[stmt] = scopeStack.size(); // ToDo: remove?

    if (scopeStack.empty()) {
        scopeStack.push(stmt);
        scopeMap[stmt] =
            std::make_shared<std::vector<NamedDecl *>>(*globalScope.get());
    }
    if (stmt == scopeStack.top())
        return;

    auto outerScope = scopeMap[scopeStack.top()];
    scopeMap[stmt] =
        std::make_shared<std::vector<NamedDecl *>>(*outerScope.get());

    scopeStack.push(stmt);
}

void DeclScopeBuilder::addScope(const Stmt *stmt) { appendScope(stmt); }

void DeclScopeBuilder::insertDecl(NamedDecl *namedDecl) {
    while (!scopeStack.empty() &&
           sm.isBeforeInTranslationUnit(scopeStack.top()->getLocEnd(),
                                        namedDecl->getLocEnd())) {
        scopeStack.pop();
    }
    if (scopeStack.empty()) {
        globalScope->push_back(namedDecl);
        if (declMap.find(namedDecl) != declMap.end())
            return;
        declMap[namedDecl] = globalScope;
        return;
    }
    auto scope = scopeMap[scopeStack.top()];
    scope->push_back(namedDecl);
    if (declMap.find(namedDecl) != declMap.end())
        return;
    declMap[namedDecl] = scope;
}

void DeclScopeBuilder::printScopes() {
    llvm::errs() << "=============[ Scopes ]=============\n";
    for (auto &scopeTuple : scopeMap) {
        llvm::errs().indent(2);
        llvm::errs() << "=======[ Code in Scope ]========\n";
        scopeTuple.first->dumpPretty(Context);
        llvm::errs().indent(2);
        llvm::errs() << "=======[ Names in Scope ]=======\n";
        for (auto *namedDecl : *scopeTuple.second.get()) {
            llvm::errs().indent(4);
            if (auto *valDecl = dyn_cast<ValueDecl>(namedDecl)) {
                llvm::errs() << valDecl->getType().getAsString() << " ";
            }
            llvm::errs() << namedDecl->getNameAsString();
            llvm::errs() << "\n";
        }
        llvm::errs().indent(2);
        llvm::errs() << "========[ End of Scope ]========\n";
    }
    llvm::errs() << "===========[ End Scopes ]===========\n";
}

bool DeclScopeBuilder::VisitVarDecl(VarDecl *vd) {
    if (sm.isWrittenInMainFile(vd->getLocStart())) {
        for (auto &parent : Context.getParents(*vd)) {
            if (parent.get<Decl>() &&
                isa<TranslationUnitDecl>(parent.get<Decl>())) {
                while (!scopeStack.empty()) {
                    scopeStack.pop();
                }
                assert(scopeStack.empty());
                insertDecl(vd);
            }
        }
    }
    return true;
}

bool DeclScopeBuilder::VisitDeclStmt(DeclStmt *ds) {
    if (sm.isWrittenInMainFile(ds->getLocStart())) {
        for (auto &decl : ds->decls()) {
            if (auto *namedDecl = dyn_cast<NamedDecl>(decl)) {
                insertDecl(namedDecl);
            } else {
                llvm::errs() << "Not NamedDecl: \n";
                decl->dumpColor();
                llvm::errs() << "---\n";
                assert(false);
            }
        }
    }
    return true;
}

bool DeclScopeBuilder::VisitForStmt(ForStmt *fs) {
    if (sm.isWrittenInMainFile(fs->getLocStart())) {
        // llvm::errs() << "ForStmt\n";
        addScope(fs);
    }

    return true;
}

bool DeclScopeBuilder::VisitCXXForRangeStmt(CXXForRangeStmt *S) {
    if (sm.isWrittenInMainFile(S->getLocStart())) {
        addScope(S);
    }

    return true;
}

bool DeclScopeBuilder::VisitDoStmt(DoStmt *ds) {
    if (sm.isWrittenInMainFile(ds->getLocStart())) {
        addScope(ds);
    }
    return true;
}

bool DeclScopeBuilder::VisitLambdaExpr(LambdaExpr *S) {
    if (sm.isWrittenInMainFile(S->getLocStart())) {
        if (S->getBody() == nullptr)
            return true;
        addScope(S->getBody());
        auto *M = S->getCallOperator();
        for (auto *param : M->parameters()) {
            insertDecl(param);
        }
        // ToDo: Handle Capture
    }
    return true;
}

bool DeclScopeBuilder::VisitFunctionDecl(FunctionDecl *fd) {
    if (sm.isWrittenInMainFile(fd->getLocStart())) {
        if (!fd->hasBody())
            return true;
        addScope(fd->getBody());
        for (auto *param : fd->parameters()) {
            insertDecl(param);
        }
    }

    return true;
}

bool DeclScopeBuilder::VisitWhileStmt(WhileStmt *ws) {
    if (sm.isWrittenInMainFile(ws->getLocStart())) {
        addScope(ws);
    }
    return true;
}

bool DeclScopeBuilder::VisitCompoundStmt(CompoundStmt *cs) {
    if (sm.isWrittenInMainFile(cs->getLocStart())) {
        addScope(cs);
    }
    return true;
}

void DeclScopeBuilder::buildScopeMap() {
    TraverseDecl(Context.getTranslationUnitDecl());
}

std::vector<NamedDecl *>
DeclScopeBuilder::getScopeForDecl(const NamedDecl *namedDecl) {
    if (declMap.empty()) {
        buildScopeMap();
    }
    if (declMap.find(namedDecl) == declMap.end()) {
        namedDecl->dumpColor();
        llvm::errs() << namedDecl->isImplicit() << "\n";
        if (namedDecl->getParentFunctionOrMethod()) {
            if (auto *FD = dyn_cast<FunctionDecl>(
                    namedDecl->getParentFunctionOrMethod())) {
                llvm::errs()
                    << "TemplInitiation: " << FD->isTemplateInstantiation()
                    << "\n";
                llvm::errs() << "TemplSpezialization: "
                             << FD->isFunctionTemplateSpecialization() << "\n";
                FD->dumpColor();
            }
        }
    }
    assert(declMap.find(namedDecl) != declMap.end() && "NamedDecl not in map");
    return *declMap[namedDecl].get();
}

void DeclScopeBuilder::printAdresses() {
    llvm::errs() << "Adresses scopes:\n";
    for (auto it = declMap.begin(); it != declMap.end(); it++) {
        llvm::errs() << it->first << "\n";
    }
    llvm::errs() << "==========\n";
}
