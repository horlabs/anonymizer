#include "DeclRefMapping.h"



DeclRefMapping::DeclRefMapping(ASTContext *Context) : sm(Context->getSourceManager()) {};


bool DeclRefMapping::insert_declref(const DeclRefExpr* d) {

    // get Decl to DeclRefExpr
    if(auto ddecl = dyn_cast<VarDecl>(d->getDecl())){
//        auto slkey = getkeySourceLocation(ddecl->getLocStart());

        if(declrefmap.find(ddecl) != declrefmap.end()){
            // d is already in
            if (std::find(declrefmap[ddecl].begin(), declrefmap[ddecl].end(), d) ==
                    declrefmap[ddecl].end()) {
                declrefmap[ddecl].push_back(d);
            }
//            sourcelocationtovardecls[slkey].push_back(ddecl);
        } else {
//            std::vector<const DeclRefExpr*> dvec;
//            dvec.push_back(d);
//            declrefmap[ddecl] = dvec;
            declrefmap[ddecl] = std::vector<const Expr*>{d};
//            sourcelocationtovardecls[slkey] = std::vector<const VarDecl*> {ddecl};
        }

        return true;
    } else {
        return false;
    }

}

bool DeclRefMapping::insert_memberexpr(const MemberExpr *m) {
    // get Decl to MemberExpr
    if (auto fdecl = dyn_cast<FieldDecl>(m->getMemberDecl())) {
        auto ddecl = cast<VarDecl>(fdecl);
//        auto slkey = getkeySourceLocation(ddecl->getLocStart());

        if (declrefmap.find(ddecl) != declrefmap.end()) {
            // d is already in
            if (std::find(declrefmap[ddecl].begin(), declrefmap[ddecl].end(), m) ==
                    declrefmap[ddecl].end()) {
                declrefmap[ddecl].push_back(m);
            }
//            sourcelocationtovardecls[slkey].push_back(ddecl);
        } else {
//            std::vector<const DeclRefExpr*> dvec;
//            dvec.push_back(d);
//            declrefmap[ddecl] = dvec;
            declrefmap[ddecl] = std::vector<const Expr *>{m};
//            sourcelocationtovardecls[slkey] = std::vector<const
//            VarDecl*> {ddecl};
        }

        return true;
    } else {
        return false;
    }
}

bool DeclRefMapping::insert_ctorinit(const CXXCtorInitializer *c) {
    // get Decl to ctor
    auto ddecl = cast<VarDecl>(c->getMember());
//        auto slkey = getkeySourceLocation(ddecl->getLocStart());

    if (ctormap.find(ddecl) != ctormap.end()) {
        // d is already in
        if (std::find(ctormap[ddecl].begin(), ctormap[ddecl].end(), c) ==
                ctormap[ddecl].end()) {
            ctormap[ddecl].push_back(c);
        }
    } else {
        ctormap[ddecl] = std::vector<const CXXCtorInitializer *>{c};
    }

    return true;
}

bool DeclRefMapping::insert_vardecl(const VarDecl* d){
    auto slkey = getRowColumn(d->getLocStart(), sm, false);

    if(sourcelocationtovardecls.find(slkey) != sourcelocationtovardecls.end()){
        // sl is already in
        if (std::find(sourcelocationtovardecls[slkey].begin(),sourcelocationtovardecls[slkey].end(),d)
                 == sourcelocationtovardecls[slkey].end()) {
            sourcelocationtovardecls[slkey].push_back(d);
        }
    } else {
        sourcelocationtovardecls[slkey] = std::vector<const VarDecl*> {d};
    }
    return true;
}


std::vector<const Expr*> DeclRefMapping::getVarDeclToDeclRefExprs(const VarDecl* ddecl){

    if(declrefmap.find(ddecl) != declrefmap.end()){
        // d is already in
        return declrefmap[ddecl];
    } else {
        std::vector<const Expr*> dvec;
        return dvec;
    }

}


std::vector<const CXXCtorInitializer *> DeclRefMapping::getFieldDeclToCXXCtorInitializers(const FieldDecl *ddecl) {
    auto *vdecl = cast<VarDecl>(ddecl);

    if (ctormap.find(vdecl) != ctormap.end()) {
        // d is already in
        return ctormap[vdecl];
    } else {
        std::vector<const CXXCtorInitializer *> dvec;
        return dvec;
    }
}

bool DeclRefMapping::insert_declstmt(const DeclStmt* ds) {

    if(declstmttovardecls.find(ds) == declstmttovardecls.end()) {
        declstmttovardecls[ds] = std::vector<const VarDecl*> {};
    }

    // Iterate over all variable declarations of current declaration statement
    for (DeclStmt::const_decl_iterator db = ds->decl_begin(), de = ds->decl_end(); db != de; ++db) {
        const Decl *vd = *db;
        if (auto vardecl = dyn_cast<VarDecl>(vd)) {
            if (std::find(declstmttovardecls[ds].begin(),declstmttovardecls[ds].end(),vardecl)
                     == declstmttovardecls[ds].end()) {
                declstmttovardecls[ds].push_back(vardecl);
            }
        }
    }

    return true;
}

const DeclStmt* DeclRefMapping::getVarDeclToDeclStmt(const VarDecl* vd){

    // Iterate over DeclStmt to VarDecl Hashmap and find key

    for(std::map<const DeclStmt*, std::vector<const VarDecl*>>::iterator iter = declstmttovardecls.begin();
        iter != declstmttovardecls.end(); ++iter)
    {
        const DeclStmt* k =  iter->first;
        auto v = iter->second;

        for(auto e : v){
            if (e==vd){
                return k;
            }
        }

    }

    return nullptr;
}

std::vector<const VarDecl*> DeclRefMapping::getDeclStmtToVarDecls(const DeclStmt* ds){
    if(declstmttovardecls.find(ds) != declstmttovardecls.end()){
        // d is already in
        return declstmttovardecls[ds];
    } else {
        return std::vector<const VarDecl*>{};
    }
}


std::vector<const VarDecl*> DeclRefMapping::getSourceLocationToVarDecls(SourceLocation sl){
    auto slkey = getRowColumn(sl, sm, false);
    return getSourceLocationToVarDecls(slkey);
}

std::vector<const VarDecl*> DeclRefMapping::getSourceLocationToVarDecls(std::pair<unsigned,unsigned> slkey){

    if(sourcelocationtovardecls.find(slkey) != sourcelocationtovardecls.end()){
        // sl is already in
        auto slarr = sourcelocationtovardecls[slkey];

        // Sort w.r.t to row, column
        struct Local {
            explicit Local(SourceManager* sml) { sm = sml; }
            bool operator () ( const VarDecl* lhs, const VarDecl* rhs ){
                FullSourceLoc fullLocLhs_saved(lhs->getLocEnd(), *sm);
                FullSourceLoc fullLocRhs_saved(rhs->getLocEnd(), *sm);

                if(fullLocLhs_saved.getSpellingLineNumber() == fullLocRhs_saved.getSpellingLineNumber())
                    return fullLocLhs_saved.getSpellingColumnNumber() < fullLocRhs_saved.getSpellingColumnNumber();

                return fullLocLhs_saved.getSpellingLineNumber() < fullLocRhs_saved.getSpellingLineNumber();
            }

            const SourceManager* sm;
        };
        std::sort( slarr.begin( ), slarr.end( ), Local(&sm));
        return slarr;
    } else {
        return std::vector<const VarDecl*>{};
    }
}
