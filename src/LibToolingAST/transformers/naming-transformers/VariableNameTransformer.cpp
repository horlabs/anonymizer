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

#include "../ControlDataFlow/CDFGraphQueryHandler.h"
#include "../RenamingGuide.h"

#include "VariableNameTransformer.h"

VariableNameTransformer::VariableNameTransformer(ASTContext &Context, Rewriter &OurRewriter)
        : Context(Context), OurRewriter(OurRewriter), sm(Context.getSourceManager()),
          DeclRefMap(new DeclRefMapping(&Context)), DRMB(DeclRefMap.get()) {
    DeclarationMatcher declarationMatcher = anyOf(varDecl().bind("varDecl"), fieldDecl().bind("fieldDecl"));
    StatementMatcher declRefMapStatementMatcher = anyOf(
            declStmt().bind("declStmt"),
            declRefExpr().bind("declRefExpr"),
            memberExpr().bind("memberExpr"));
    auto contructorMatcher = cxxCtorInitializer().bind("ctorinit");

    PreMatcher.addMatcher(declarationMatcher, &DRMB);
    PreMatcher.addMatcher(declRefMapStatementMatcher, &DRMB);
    PreMatcher.addMatcher(contructorMatcher, &DRMB);
    cfggraph = new ControlFlowGraphWithDataFlow(&Context);
}

void VariableNameTransformer::init(ASTContext &Context) {
    PreMatcher.matchAST(Context);
}

/* ******************* Collection Methods ******************* */

bool VariableNameTransformer::VisitNamedDecl(NamedDecl *nd) {
    auto srcloc = Context.getSourceManager().getSpellingLoc(nd->getLocStart());
    if (sm.isWrittenInMainFile(srcloc)) {
        // Save all named declarations to check for name conflicts
        this->alldeclarationnames.push_back(nd->getNameAsString());

        // Save variables that we can rewrite without problems
        if (auto d = dyn_cast<VarDecl>(nd)) {
#ifdef MYDEBUG
            llvm::outs() << "VarName:" << d->getQualifiedNameAsString() << ";"
                         << d->getIdentifier()->getName()
                         << ";\t Local Var?:" << d->isLocalVarDecl() << ";"
                         << d->isLocalVarDeclOrParm() << ";"
                         << d->hasExternalStorage() << "\n";
            llvm::outs() << "Type:"
                         << d->getType().getCanonicalType().getAsString()
                         << "\n";
#endif

            if (!d->hasExternalStorage()
                && d->getType().getCanonicalType().getAsString().find("const") == std::string::npos) {
                // We do not rewrite extern variables
                // and const variables (these are directly replaced in AST, no DeclRefExpr's).
                this->allusabledeclarations.push_back(nd);
            }
        }
        // Save functions that we can rewrite without problems
        if (auto f = dyn_cast<FunctionDecl>(nd)) {
            if (!f->isMain())
                this->allusabledeclarations.push_back(nd);
#ifdef MYDEBUG
            llvm::outs() << "FctName:" << f->getQualifiedNameAsString()
                         << "; With Def/Body:"
                         << f->isThisDeclarationADefinition() << "\n";
#endif
        }
    }
    return true;
}

/**
 * Visit all functions and store them in CFG graph.
 * @param f
 * @return
 */
bool VariableNameTransformer::VisitFunctionDecl(FunctionDecl *f) {
    bool inmainfile = sm.isInMainFile(Context.getSourceManager().getSpellingLoc(f->getLocation()));
    if (inmainfile) {
        cfggraph->addFunctionDecl(f);
    }
    return true;
}

/* ******************* Rewriting Methods ******************* */

/**
 * Replace a declaration name by a new name. We can rewrite variable and function declarations.
 * @return false if something goes wrong.
 */
bool VariableNameTransformer::replacecommand(commandlineoption cmdoption) {
    std::string from_declname = cmdoption.from_declname; // ""; //"g_M";
    std::string into_declname = cmdoption.into_declname; //"bettertest";
    decl_selection declselection = cmdoption.declselection; //similar_occurence;
    int target_occurence_count = cmdoption.target_occurence_count; //8;
    int seed = cmdoption.seed;

    /*** A. Get declaration that will be renamed ***/
    std::vector<NamedDecl *> from_decls;
    if (!from_declname.empty()) {
        // Specified a name that we want to replace, find it in the list of definitions
        if (!getDeclForName(from_declname, from_decls))
            return false;
    } else {
        // we have not defined a name, we can select an arbitrary variable, but
        // check if we specified specific selection rules

        assert(declselection == select_randomly || declselection == similar_occurence);
        switch (declselection) {
        case select_randomly: {
            randomlySortVector<NamedDecl *>(allusabledeclarations, seed);
            auto seldecl = *(allusabledeclarations.begin());
            from_declname = seldecl->getNameAsString();
            if (!getDeclForName(from_declname, from_decls))
                return false;
            break;
        }
        case similar_occurence:
            // ok, we have a little bit to do, get for all declarations the
            // occurence count, this function will save suitable decl in
            // from_declname
            if (!computeOccurenceCount(from_declname, target_occurence_count))
                return false;
            if (!getDeclForName(from_declname, from_decls))
                return false;
            break;
        }
    }

#ifdef MYDEBUG
    llvm::outs() << "\t->Replace Name:" << from_declname
                 << " found; Only Decl:" << from_decls.size() << "x \n";
#endif

    /*** B. Get new name ***/
    if (into_declname.empty()) {
        into_declname = determineIntoVarName(from_decls[0], seed);
    }
    // Check that target name is not already used
    if (checkForNameConflict(into_declname))
        return false;

    /*** C. Rename all occurences of the declaration ***/
    for (auto from_decl : from_decls) {

        /*** C.1 Rename all occurences of a variable ***/
        if (auto from_vardecl = dyn_cast<VarDecl>(from_decl)) {
            if (!renamevariabledecl(from_vardecl, into_declname))
                return false;
        }
        /*** C.2 Rename all occurences of a fct ***/
        else if (auto from_fctdecl = dyn_cast<FunctionDecl>(from_decl)) {
            if (!renamefunctiondecl(from_fctdecl, into_declname))
                return false;
        } else {
            llvm::errs() << "Warning.."
                         << "Unsupported decl type occured\n";
        }
    }

    return true;
}

/**
 * Get all declarations that have the name which we want to replace.
 * @param string_from_varname
 * @param from_decls
 * @return false if we get an error. Saves the declarations in the from_decls
 * vector (call by reference).
 */
bool VariableNameTransformer::getDeclForName(
    std::string &string_from_varname, std::vector<NamedDecl *> &from_decls) {

    // Specified a name that we want to replace, find it in the list of definitions
    for (auto declelem : this->allusabledeclarations) {
        if (declelem->getNameAsString() == string_from_varname) {
            from_decls.push_back(declelem);
        }
    }
    // if from_decls are still empty, we could not find a declaration with given name
    if (from_decls.empty()) {
        llvm::errs() << "Error: Could not find the name: " << string_from_varname << "\n";
        return false;
    }
    return true;
}

/**
 * Checks if there is a name conflict for input_varname, if so returns true, otherwise false
 * @param input_varname
 * @return true if name conflict
 */
bool VariableNameTransformer::checkForNameConflict(std::string &input_varname) {
    for (auto nameddecl : this->alldeclarationnames) {
        if (nameddecl == input_varname) {
            llvm::errs() << "Error: Specified Name Already Exists (at least somewhere): "
                         << input_varname << "\n";
            return true;
        }
    }
    return false;
}

/**
 * Rewrites all variable declarations with the target name.
 * @param from_decl
 * @return
 */
bool VariableNameTransformer::renamevariabledecl(const VarDecl *from_decl, const std::string &into_declname) {
    // For each declaration with the matched name, find its occurences in source text via DeclRefExpr;
    // but we may have visited/saved a Decl that is never used. Then it could be that we get an exception
    // since the graph does not contain any DeclRefExpr, thus no DeclEdge and no Decl in the graph. This is no error.
    if (from_decl->getNameAsString().empty())
        return false;
    try {
        std::vector<const Expr *> declrefexprs = DeclRefMap->getVarDeclToDeclRefExprs(from_decl);
        std::sort(declrefexprs.begin(), declrefexprs.end());
        declrefexprs.erase(std::unique(declrefexprs.begin(), declrefexprs.end()), declrefexprs.end());
        std::vector<SourceRange> renamedRanges{};

        for (auto curdeclrefexpr : declrefexprs) {
            auto range = curdeclrefexpr->getSourceRange();
            range.setBegin(Context.getSourceManager().getSpellingLoc(range.getBegin()));
            range.setEnd(Context.getSourceManager().getSpellingLoc(range.getEnd()));
            if (std::find(renamedRanges.begin(), renamedRanges.end(), range) !=
                renamedRanges.end())
                continue;
            renamedRanges.push_back(range);
            // For each occurence, rename it into target name

#ifdef MYDEBUG
            llvm::outs() << "\t--Var-Rename-->" << getSourceText(Context, curdeclrefexpr, false) << "\n";
#endif
            if (isa<MemberExpr>(curdeclrefexpr)) {
                range = cast<MemberExpr>(curdeclrefexpr)->getMemberNameInfo().getSourceRange();
                range.setBegin(Context.getSourceManager().getSpellingLoc(range.getBegin()));
                range.setEnd(Context.getSourceManager().getSpellingLoc(range.getEnd()));
                if (cast<MemberExpr>(curdeclrefexpr)->getMemberNameInfo().getName().getAsString() !=
                    getSourceTextStable(Context, range.getBegin(), range.getEnd())) {
                    continue;
                }
            }
            OurRewriter.ReplaceText(range, into_declname);
        }

        if (auto fdecl = dyn_cast<FieldDecl>(from_decl)) {
            auto inits = DeclRefMap->getFieldDeclToCXXCtorInitializers(fdecl);

            for (auto curInit : inits) {
                OurRewriter.ReplaceText(
                        SourceRange(Context.getSourceManager().getSpellingLoc(curInit->getMemberLocation()),
                                    Context.getSourceManager().getSpellingLoc(
                                            curInit->getMemberLocation().getLocWithOffset(
                                                    fdecl->getNameAsString().size() - 1))), into_declname);
            }
        }

    } catch (CFGException &e) {
#ifdef MYDEBUG
        llvm::errs() << "Note: Could not find a Decl in graph for:"
                     << getSourceText(Context, from_decl, false)
                     << " but everything is fine?! \n";
#endif
    }

    // Now: Rename declaration
    // Rewrite e.g. g_M = 0; or structblabla(100, 200);
    unsigned vardeclnamelength = (unsigned) from_decl->getNameAsString().length();
    OurRewriter.ReplaceText(Context.getSourceManager().getSpellingLoc(from_decl->getLocation()), vardeclnamelength,
                            into_declname);

    return true;
}

/**
 * Rewrites all function declarations that have the target name.
 * @param from_decl
 * @return
 */
bool VariableNameTransformer::renamefunctiondecl(const FunctionDecl *from_decl, const std::string &into_declname) {

    unsigned fctdeclnamelength = (unsigned) from_decl->getNameAsString().length();

    // If function definition and declaration are separated, we will visit the references twice,
    // since we have two Decl for a function. Only rewrite references to function decl with defintion:
    if (from_decl->isThisDeclarationADefinition()) {
        std::vector<const CallExpr *> callexprrefs =
                ControlDataFlowGraphQueryHandler::queryAllCallExprsToFunction(cfggraph, from_decl);

        for (auto curcallexpr : callexprrefs) {
            // For each occurence, rename it into target name
#ifdef MYDEBUG
            llvm::outs() << "\t--Fct-Rename-->" << getSourceText(Context, curcallexpr->getLocStart(),
                                                                 curcallexpr->getLocStart().getLocWithOffset(
                                                                         fctdeclnamelength - 1)) << "\n";
#endif

            // Rewriting is simple. We get the start location of call via getLocStart and use the length of
            // the function name to get the range where we insert the new function name.
            OurRewriter.ReplaceText(Context.getSourceManager().getSpellingLoc(curcallexpr->getExprLoc()),
                                    fctdeclnamelength, into_declname);
        }
    }

    // Now: Rename declaration
    // func->getLocation() represents the start of the function name
    OurRewriter.ReplaceText(Context.getSourceManager().getSpellingLoc(from_decl->getLocation()), fctdeclnamelength,
                            into_declname);

    return true;
}

/**
 * Compute a new name for a variable or function.
 * @param d
 * @return
 */
std::string VariableNameTransformer::determineIntoVarName(NamedDecl *d, int seed) {

    assert(isa<VarDecl>(d) || isa<FunctionDecl>(d));

    std::string targetname;
    if (auto vard = dyn_cast<VarDecl>(d)) {
        // the target name is arbitrary, we rename it randomly
        std::string typeasstring = vard->getType().getAsString();

        // Take the first letter of type and add an Var
        targetname = RenamingGuide::getRandomStringWith(3, seed) + typeasstring.substr(0, 1) + "_Var";
    } else if (auto fctd = dyn_cast<FunctionDecl>(d)) {
        std::string typeasstring = fctd->getReturnType().getAsString();
        targetname = "do_" + typeasstring.substr(0, 3) + RenamingGuide::getRandomStringWith(3, seed) + "_fct";
    }

    return targetname;
}

/**
 * Computes the occurence number for each usable declaration. To this end, it counts all the references
 * to a variable or function declaration. For instance, if two declarations have the same name (so that they are
 * in other scopes), we will add both counts, since we will replace both declarations later.
 * Saves declaration name that we should replace based on the occurence count in the member from_varname
 * @param from_declname call by reference, changed into the name that fits the most
 * @param target_occurence_count the occurence count that represents the target count
 * @return false if error
 */
bool VariableNameTransformer::computeOccurenceCount(std::string &from_declname, int target_occurence_count) {
    // For all declaration, count all references to this decl: hashmap with decl name as key, occurences as value.
    std::unordered_map<std::string, int> htmap;

    for (auto curnameddecl : this->allusabledeclarations) {
        int curocccount = 1; // we count the declaration itself as well

        // A. Get occurence count
        try {
            if (auto vardecl = dyn_cast<VarDecl>(curnameddecl)) {
                // A.1 Variable Declaration
                std::vector<const DeclRefExpr *> declrefexprs =
                        ControlDataFlowGraphQueryHandler::queryAllStmtsForDecl(cfggraph, vardecl);
                curocccount += int(declrefexprs.size());

            } else if (auto fctdecl = dyn_cast<FunctionDecl>(curnameddecl)) {
                // A.2 Fct Declaration, if only declaration without body, we count it as one more occurence.
                if (fctdecl->isThisDeclarationADefinition()) {
                    std::vector<const CallExpr *> callexprrefs =
                            ControlDataFlowGraphQueryHandler::queryAllCallExprsToFunction(cfggraph, fctdecl);
                    curocccount += int(callexprrefs.size());
                } else {
                    curocccount++;
                }

            } else {
                // A.3 Just to be sure...
                llvm::errs() << "Warning.." << "Unsupported decl type occured in computeOccurenceCount\n";
            }
        } catch (CFGException &e) {
            // may occur if we visit a declaration that is never used,
            // so that the cfggraph does not contain the decl.
        }

        // B. Save occurence count in hash map
//            const bool is_in = htmap.find() != htmap.end();
        if (htmap.count(curnameddecl->getQualifiedNameAsString()) == 0) {
            // not included, yet
            htmap[curnameddecl->getQualifiedNameAsString()] = curocccount;
        } else {
            htmap[curnameddecl->getQualifiedNameAsString()] += curocccount;
        }
    }

//        for(auto const &ent: htmap){
//            llvm::outs() << "Occurences:\t" << ent.first << ":" << ent.second << "\n";
//        }

    // C. Now compute the decl that has the most similar occurence count to target count by using anonym. fct.
    // Min( abs(Each hashmap value - target occurence) )
    std::pair<std::string, int> bestmatch("", std::numeric_limits<int>::max());
    for (auto ht : htmap) {
        if (abs(ht.second - target_occurence_count) < bestmatch.second) {
            bestmatch.first = ht.first;
            bestmatch.second = abs(ht.second - target_occurence_count);
        }
    }
    if (bestmatch.first.empty()) {
        llvm::errs() << "Occurence Selection Strategy failed.. could not find a suitable Decl\n";
        return false;
    }

#ifdef MYDEBUG
    llvm::outs() << "Best Match found:" << bestmatch.first << " with diff: " << bestmatch.second << "\n";
#endif

    from_declname = bestmatch.first;
    return true;
}

void DeclRefMappingBuilder::run(const MatchFinder::MatchResult &Result) {
    ASTContext *Context = Result.Context;
    SourceManager &Manager = Context->getSourceManager();

    const VarDecl *VD = Result.Nodes.getNodeAs<VarDecl>("varDecl");
    if (VD && Context->getSourceManager().isWrittenInMainFile(Manager.getSpellingLoc(VD->getLocStart()))) {
        DeclRefMap->insert_vardecl(VD);
    }

    const FieldDecl *FD = Result.Nodes.getNodeAs<FieldDecl>("fieldDecl");
    if (FD && Context->getSourceManager().isWrittenInMainFile(Manager.getSpellingLoc(FD->getLocStart()))) {
        DeclRefMap->insert_vardecl(cast<VarDecl>(FD));
    }

    const DeclStmt *DS = Result.Nodes.getNodeAs<DeclStmt>("declStmt");
    if (DS && Context->getSourceManager().isWrittenInMainFile(Manager.getSpellingLoc(DS->getLocStart()))) {
        DeclRefMap->insert_declstmt(DS);
    }

    const DeclRefExpr *DRE = Result.Nodes.getNodeAs<DeclRefExpr>("declRefExpr");
    if (DRE && Context->getSourceManager().isWrittenInMainFile(Manager.getSpellingLoc(DRE->getLocStart()))) {
        DeclRefMap->insert_declref(DRE);
    }

    const auto *ME = Result.Nodes.getNodeAs<MemberExpr>("memberExpr");
    if (ME && (Manager.isWrittenInMainFile(ME->getMemberDecl()->getLocStart()) || 
            Manager.isWrittenInMainFile(Manager.getExpansionLoc(ME->getMemberDecl()->getLocStart())))
    ) {
        DeclRefMap->insert_memberexpr(ME);
    }

    const auto *CI = Result.Nodes.getNodeAs<CXXCtorInitializer>("ctorinit");
    if (CI && Context->getSourceManager().isWrittenInMainFile(CI->getSourceLocation()) && CI->isWritten()) {
        DeclRefMap->insert_ctorinit(CI);
    }
}
