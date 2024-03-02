#include "FunctionRemovalTransformer.h"

/**
 * We remove functions by adding its source text to the caller location.
 * We do not handle Macro's here.
 */

/**
 * Visit all functions and store them in CFG graph. In addition, saves all
 * function declarations.
 * @param f
 * @return
 */
bool FunctionRemovalTransformer::VisitFunctionDecl(FunctionDecl *f) {
    bool inmainfile = sm.isInMainFile(f->getLocation());
    if (inmainfile) {
        cfggraph->addFunctionDecl(f);
        this->functiondeclarations.push_back(f);
    }
    return true;
}

/* ******************* Rewriting Methods ******************* */

void FunctionRemovalTransformer::replacecommand(
    ChooseLocationStrategy chooseLocationStrategy) {
    insertFctIntoBody(chooseLocationStrategy);
};

void FunctionRemovalTransformer::handlefctcall(
    const CallExpr *curcallexpr, const std::string &bodytext,
    const FunctionDecl *chosenFuncDecl,
    std::vector<std::pair<SourceRange, std::string>> &callinfos) {

    std::pair<SourceRange, std::string> returnvalue;

    /* Case 1: Alone: */
    // Check if CallExpr has full line scope == no other stmts in line or part
    // of others
    // => check if Call Expr's row != parent's row
    auto alone = isastandalonecall(curcallexpr);
    if (alone.first) {
        processstandalonecall(curcallexpr, bodytext, chosenFuncDecl,
                              alone.second, callinfos);
        return;
    }

    /* Case 2: Is variable assignment such as (int) x = fct-call(...) */
    auto assign = isavariableassignment(curcallexpr);
    if (assign.first) {
        processvariableassignment(curcallexpr, bodytext, chosenFuncDecl,
                                  assign.second, callinfos);
        return;
    }

    /* Case 3: Other. Fct call is probably inside another stmt */
    processothercall(curcallexpr, bodytext, chosenFuncDecl, callinfos);
}

// TODO what if decl without definition
// TODO check for name conflicts

/**
 * Will move the function code to each location where fct is called.
 * In this way, we can easily replace functions that represent some convenience
 * function for an author, e.g. computing the maximum. Note that this function
 * will also remove functions that are never used.
 * @param chooseLocationStrategy the strategy to find the function that we want
 * to move to the calling location
 * @return true if insertion was successful.
 */
bool FunctionRemovalTransformer::insertFctIntoBody(
    const ChooseLocationStrategy chooseLocationStrategy) {

    // I.a Assure that each function that we consider for replacment is not
    // called recursively
    auto usablefunctiondeclarations =
        getAllNonRecursiveFunctions(this->functiondeclarations);
    // I.b Assure that we only replace non-class functions. Constructors and
    // class methods should not be moved.
    usablefunctiondeclarations =
        getAllNonCXXMethodDecls(usablefunctiondeclarations);
    // I.c Assure we only consider functions with no or one return statement
    usablefunctiondeclarations =
        getAllSingleReturnFunctions(usablefunctiondeclarations);

    // II. Choose a function that we will remove
    FunctionDecl *chosenFuncDecl = computeSuitableFunctionToMove(
        usablefunctiondeclarations, chooseLocationStrategy);
    if (!chosenFuncDecl)
        return false;
    std::vector<const CallExpr *> calllocations =
        ControlDataFlowGraphQueryHandler::queryAllCallExprsToFunction(
            cfggraph, chosenFuncDecl);
    std::string returntype = chosenFuncDecl->getReturnType().getAsString();

    // III. Insert function code at each call location
    // We iterate over all call exprs, compute their new text and save it in
    // this vector. If something goes wrong, we have not rewritten anything. If
    // all call exprs are successful, we rewrite all call's.
    std::vector<std::pair<SourceRange, std::string>> callinfos;

    for (auto curcallexpr : calllocations) {

        // Get body text: in order to exclude {, we use getLocWithOffset(1),
        // since body starts with {.
        std::string bodytext = getSourceText(
            Context,
            chosenFuncDecl->getBody()->getLocStart().getLocWithOffset(1),
            chosenFuncDecl->getBody()->getLocEnd()); // incl. }, but { excl.

        // Now replace previous call stmt by a compound stmt that mimics the fct
        try {
#ifdef MYDEBUG
            llvm::outs() << "Process ..call:"
                         << getSourceText(Context, curcallexpr, false) << "\n";
#endif

            handlefctcall(curcallexpr, bodytext, chosenFuncDecl, callinfos);
        } catch (CodeTransformationException &ex) {
            // Note: If we want to skip the current call expr if s.th. goes
            // wrong, comment out return and do not remove fct definition below
            // if s.th. went wrong.
            return false;
        }
    }

    // Now rewrite all locations that we saved for rewriting. If the SourceRange
    // is just a point (getBegin == getEnd), then we insert the text before
    // since no range for replacmeent.
    for (auto callinfo : callinfos) {
        if (callinfo.first.getBegin() == callinfo.first.getEnd()) {
            OurRewriter.InsertTextBefore(callinfo.first.getBegin(),
                                         callinfo.second);
        } else {
            OurRewriter.ReplaceText(callinfo.first, callinfo.second);
        }
    }

    // Remove function definition, but check before, if template fct.
    auto ft = chosenFuncDecl->getDescribedFunctionTemplate();
    if (ft) {
        OurRewriter.RemoveText(ft->getSourceRange());
    } else {
        OurRewriter.RemoveText(chosenFuncDecl->getSourceRange());
    }

    return true;
}

std::pair<bool, ast_type_traits::DynTypedNode>
FunctionRemovalTransformer::isastandalonecall(const CallExpr *curcallexpr) {
    ast_type_traits::DynTypedNode dtn =
        ast_type_traits::DynTypedNode::create(*curcallexpr);
    std::pair<bool, ast_type_traits::DynTypedNode> returnvalue;

    FullSourceLoc fullLoc(curcallexpr->getLocStart(), sm);
    unsigned rowcallexpr = fullLoc.getSpellingLineNumber();

    auto callexprparents = Context.getParents(*curcallexpr);
    bool isequal = false;
    for (auto par : callexprparents) {
        FullSourceLoc fullLocPar(par.getSourceRange().getBegin(), sm);
        unsigned rowcallexprpar = fullLocPar.getSpellingLineNumber();
        if (rowcallexpr == rowcallexprpar)
            isequal = true;
    }

    returnvalue.first = !isequal;
    returnvalue.second = dtn;
    return returnvalue;
}

void FunctionRemovalTransformer::processstandalonecall(
    const CallExpr *curcallexpr, const std::string &bodytext,
    const FunctionDecl *chosenFuncDecl, const ast_type_traits::DynTypedNode dtn,
    std::vector<std::pair<SourceRange, std::string>> &callinfos) {
    std::pair<SourceRange, std::string> returnvalue;

    // Parse function parameters and transfer them to variable declarations
    std::string vardecls = getvariablesfromparams(curcallexpr, chosenFuncDecl);

    // If Return Stmt is present in body, we cut it out.
    std::string regex = "return(.*)\\n";
    // split returns two parts: everything before "return" and everything after
    // "\n". Next, we combine both.
    std::vector<std::string> splits = split(bodytext, regex);
    std::stringstream newbodytext;
    for (auto s : splits)
        newbodytext << "" << s;
    returnvalue.second = "{" + vardecls + newbodytext.str();
    returnvalue.first = dtn.getSourceRange();

    callinfos.push_back(returnvalue);
}

/**
 * Determines if function is called as part of an assignment. If so, either it
 * is part of a variable declaration (then the parent is a VarDecl), or is it
 * just an assignment (then the parent is a BinaryOperator =).
 *
 * @param curcallexpr the current call expression
 * @return a pair of bool and DynTypedNode: bool is true if assignment.
 * DynTypedNode is curcallexpr's parent from the AST that we need for further
 * analysis and rewriting.
 */
std::pair<bool, ast_type_traits::DynTypedNode>
FunctionRemovalTransformer::isavariableassignment(const CallExpr *curcallexpr) {
    ast_type_traits::DynTypedNode dtn =
        ast_type_traits::DynTypedNode::create(*curcallexpr);

    // Variable Assignment:
    // Either we declare a new variable with the function's output => VarDecl as
    // parent, or we fill an existing variable => BinaryOperator '=' as parent.
    std::vector<const BinaryOperator *> bls;
    goUpstairsInAST<BinaryOperator>(dtn, bls, 1, &Context);

    std::vector<const VarDecl *> vls;
    goUpstairsInAST<VarDecl>(dtn, vls, 1, &Context);

    std::pair<bool, ast_type_traits::DynTypedNode> returnvalue;
    returnvalue.first = true;
    if (!vls.empty()) {
        returnvalue.second = ast_type_traits::DynTypedNode::create(*vls[0]);
    } else if (!bls.empty() && bls[0]->isAssignmentOp()) {
        // A binary operator, check that it is an assignment, not e.g. a plus
        // operator...
        returnvalue.second = ast_type_traits::DynTypedNode::create(*bls[0]);
    } else {
        returnvalue.first = false;
    }
    return returnvalue;
}

void FunctionRemovalTransformer::processvariableassignment(
    const CallExpr *curcallexpr, const std::string &bodytext,
    const FunctionDecl *chosenFuncDecl, const ast_type_traits::DynTypedNode dtn,
    std::vector<std::pair<SourceRange, std::string>> &callinfos) {
    std::pair<SourceRange, std::string> returnvalue;

    // a. Short Check: if we have an assignment, it is not possible that func is
    // void.
    if (chosenFuncDecl->getReturnType().getAsString() == "void") {
        llvm::errs() << "ReturnType is void, although assignment\n";
        throw CodeTransformationException();
    }

    // b. Parse function parameters and transfer them to variable declarations
    std::string vardecls = getvariablesfromparams(curcallexpr, chosenFuncDecl);

    // c. Compute the variable that saves the prior return value
    std::string prebodytext, newbodytext, newreturnname;

    auto vls = dtn.get<VarDecl>();
    if (vls) {
        std::string newreturntype = vls->getType().getAsString();
        newreturnname = vls->getQualifiedNameAsString();
        // A small check if return type of function matches with variable's type
        // that saves the return value
        if (newreturntype != chosenFuncDecl->getReturnType().getAsString()) {
            llvm::errs() << "Warning: Return and Var Type Mismatch:"
                         << newreturntype << "&"
                         << chosenFuncDecl->getReturnType().getAsString()
                         << "\n";
        }
        prebodytext = newreturntype + " " + newreturnname + ";\n";
    }
    auto bls = dtn.get<BinaryOperator>();
    if (bls) {
        // type is empty, since variable was already declared at some point
        // before.
        newreturnname = getSourceText(Context, bls->getLHS(), false);
    }

    // c. Return Stmt.
    newbodytext = ReplaceString(bodytext, "return", newreturnname + " =");
    returnvalue.second = prebodytext + "{" + vardecls + newbodytext;
    returnvalue.first = dtn.getSourceRange();

    callinfos.push_back(returnvalue);
}

void FunctionRemovalTransformer::processothercall(
    const CallExpr *curcallexpr, const std::string &bodytext,
    const FunctionDecl *chosenFuncDecl,
    std::vector<std::pair<SourceRange, std::string>> &callinfos) {

    // a. Parse function parameters and transfer them to variable declarations
    std::string vardecls = getvariablesfromparams(curcallexpr, chosenFuncDecl);

    // b. Get new location where we will compute the function body.
    // -> We need the node that contains the whole cmd line.
    ast_type_traits::DynTypedNode startnode;
    FullSourceLoc fullLoc(curcallexpr->getLocStart(), sm);
    if (!getParentOfWholeCommandLine(
            ast_type_traits::DynTypedNode::create(*curcallexpr), startnode,
            fullLoc.getSpellingLineNumber(), Context, sm)) {
        llvm::errs() << "No start node at current row found\n";
        throw CodeTransformationException();
    }

    if (startnode.get<Decl>()) {
        if (auto cxxMDecl = startnode.get<CXXMethodDecl>())
            startnode = ast_type_traits::DynTypedNode::create(
                *(*cxxMDecl->getBody()->child_begin()));
        else if (auto funcDecl = startnode.get<FunctionDecl>())
            startnode = ast_type_traits::DynTypedNode::create(
                *(*funcDecl->getBody()->child_begin()));
    }

    // c. check that function does not change any parameters between new
    // location and prior call location Recap: e.g. we have printf(..., bla(x),
    // foo(x)) and function changes input param x by call by reference. If we
    // move the fct computation of foo just before printf, then bla could be
    // affected.

    // c-1 determine if any fct parameters are references or pointers.
    std::vector<const ParmVarDecl *> paramswithsideeffect;
    std::vector<const DeclRefExpr *> argswithsideeffect;
    for (unsigned i = 0; i < chosenFuncDecl->parameters().size(); i++) {
        const ParmVarDecl *cparm = chosenFuncDecl->parameters()[i];
        if ((isa<ReferenceType>(cparm->getType()) ||
             isa<PointerType>(cparm->getType())) &&
            !cparm->getType().getNonReferenceType().isConstQualified()) {
            paramswithsideeffect.push_back(cparm);
            auto arg = curcallexpr->getArg(i);
            arg = arg->IgnoreCasts();
            if (isa<UnaryOperator>(arg)) {
                arg = cast<UnaryOperator>(arg)->getSubExpr();
            }

            while (auto arraysub = dyn_cast<ArraySubscriptExpr>(arg)) {
                arg = arraysub->getBase()->IgnoreCasts();
                if (isa<UnaryOperator>(arg)) {
                    arg = cast<UnaryOperator>(arg)->getSubExpr();
                }
            }

            if (auto declrefexprarg = dyn_cast<DeclRefExpr>(arg)) {
                argswithsideeffect.push_back(declrefexprarg);
            } else if (auto cxxOp = dyn_cast<CXXOperatorCallExpr>(
                           arg)) { // todo: fast hack until now
                if (isa<DeclRefExpr>(cxxOp->getArg(0))) {
                    argswithsideeffect.push_back(
                        cast<DeclRefExpr>(cxxOp->getArg(i)));
                }
            } else {
                curcallexpr->getArg(i)->dumpColor();
                llvm::errs()
                    << "->"
                    << getSourceText(Context, curcallexpr->getArg(i), false)
                    << " not a DeclRefExpr\n";
                throw CodeTransformationException();
            }
        }
    }

    const Stmt *startnodestmt = startnode.get<Stmt>();
    if (!startnodestmt) {
        startnode.dump(llvm::errs(), sm);
        llvm::errs() << "\nWarning: Found start node for whole command is not "
                        "a stmt, which "
                        "is unusual. Actually, "
                     << "everything is a stmt in CFG, expect function "
                        "parameters so far\n";
        throw CodeTransformationException();
    }

    // c-2 We use a simple, but effective heuristic. We check if parameter is
    // used somewhere else in the current row.
    // TODO Actually we should check if parameter is somewhere used between call
    // location and new location after transformation.
    std::vector<const DeclRefExpr *> declrexpr;
    recursiveStmtTVisit<DeclRefExpr>(startnodestmt, declrexpr);

    for (auto curargwithsideeffect : argswithsideeffect) {

        for (auto de : declrexpr) {
            if (de == curargwithsideeffect)
                continue;
            if (de->getFoundDecl() == curargwithsideeffect->getFoundDecl()) {
                // now we could have a problem.
#define MYDEBUG
#ifdef MYDEBUG
                FullSourceLoc fullLoc4de(de->getLocStart(), sm);
                llvm::errs() << chosenFuncDecl->getNameAsString() << "\n";
                llvm::outs() << "Rewriting is not safe due to:"
                             << getSourceText(Context, de, false);
                getRowColumn(de->getLocStart(), sm, true);
#endif
#undef MYDEBUG
                throw CodeTransformationException();
            }
        }
    }
    // d. New fct text at row before
    std::string newreturnname = RenamingGuide::getRandomStringWith(5);
    std::pair<SourceRange, std::string> returnvalue;

    std::string prebodytext = chosenFuncDecl->getReturnType().getAsString() +
                              " " + newreturnname + ";\n";
    std::string newbodytext =
        ReplaceString(bodytext, "return", newreturnname + " =");

    for (auto parent : Context.getParents(startnode)) {
        if (parent.get<IfStmt>() &&
            parent.get<IfStmt>()->getCond() == startnodestmt) {
            startnode = parent;
        }
    }
    returnvalue.first = SourceRange(startnode.getSourceRange().getBegin(),
                                    startnode.getSourceRange().getBegin());
    returnvalue.second = prebodytext + "{" + vardecls + newbodytext + "\n";
    callinfos.push_back(returnvalue);

    // e. new text at call location
    std::pair<SourceRange, std::string> returnvalue2;
    std::string callline = getSourceText(Context, curcallexpr->getLocStart(),
                                         curcallexpr->getLocEnd());
    std::string newcallline = ReplaceString(
        callline, getSourceText(Context, curcallexpr, false), newreturnname);

    returnvalue2.second = newcallline;
    returnvalue2.first = curcallexpr->getSourceRange();
    callinfos.push_back(returnvalue2);
}

std::string FunctionRemovalTransformer::getvariablesfromparams(
    const CallExpr *curcallexpr, const FunctionDecl *chosenFuncDecl) {
    std::stringstream sstream;

    // Now for each function parameter, create the local assignment
    for (unsigned i = 0; i < curcallexpr->getNumArgs(); i++) {
        const Expr *carg = curcallexpr->getArg(i);
        const ParmVarDecl *cparm = chosenFuncDecl->parameters()[i];

        // TODO If caller just passes a variable, we can directly substitute the
        // function parameter by the name from caller. Otherwise, we create a
        // new variable within the new CompoundStmt.
        //                std::vector<const DeclRefExpr*> curdeclrefexprs;
        //                recursiveStmtTVisit<DeclRefExpr>(carg,
        //                curdeclrefexprs); std::vector<const BinaryOperator*>
        //                curbinops; recursiveStmtTVisit<BinaryOperator>(carg,
        //                curbinops); if(curdeclrefexprs.size() == 1 &&
        //                curbinops.empty()){ ...

        // We could use getSourceText(Context, cparm, false) directly, but if we
        // have a function with templates, we would get the template type and
        // here we want to get the real type.
        sstream << "" << cparm->getType().getAsString() << " "
                << cparm->getQualifiedNameAsString() << " = "
                << getSourceText(Context, carg, false) << ";\n";
    }
    return sstream.str();
}

/**
 * Exclude all functions that are called recursively.
 * @param usablefunctiondeclarations
 * @return
 */
std::vector<FunctionDecl *>
FunctionRemovalTransformer::getAllNonRecursiveFunctions(
    std::vector<FunctionDecl *> usablefunctiondeclarations) {
    // shallow copy is ok here.

    for (long i = (usablefunctiondeclarations.size() - 1); i >= 0; i--) {
        auto f = usablefunctiondeclarations[i];
        if (!f->isMain() && f->isThisDeclarationADefinition()) {
            //                #ifdef MYDEBUG
            //                llvm::outs() << "Check Fct for Recursion:" <<
            //                getUniqueFunctionNameAsString(f) << "\n"; #endif

            ast_type_traits::DynTypedNode curfct =
                ast_type_traits::DynTypedNode::create(*(f));

            std::vector<const CallExpr *> callexprrefs =
                ControlDataFlowGraphQueryHandler::queryAllCallExprsToFunction(
                    cfggraph, f);

            for (auto curcallexpr : callexprrefs) {
                // Check if call expr is inside current function = recursive
                // calling.
                ast_type_traits::DynTypedNode curcalledfct =
                    ast_type_traits::DynTypedNode::create(*(curcallexpr));
                if (CheckIsChildOf(curcalledfct, curfct, &Context)) {
#ifdef MYDEBUG
                    llvm::outs() << "~~>Remove recursive fct:"
                                 << getUniqueFunctionNameAsString(f) << "\n";
#endif
                    // fct is called recursively, remove it from set of usable
                    // functions
                    usablefunctiondeclarations.erase(
                        usablefunctiondeclarations.begin() + i);
                    break;
                }
            }
        } else {
            // we do not process function declarations without definition
            usablefunctiondeclarations.erase(
                usablefunctiondeclarations.begin() + i);
        }
    }

    return usablefunctiondeclarations;
}

/**
 * Exclude all class methods. In future, we could check if CallExpr is inside
 * that class, then we could move the method to the call location. To move the
 * code outside the class, we may need a more advanced analysis.
 * @param usablefunctiondeclarations
 * @return
 */
std::vector<FunctionDecl *> FunctionRemovalTransformer::getAllNonCXXMethodDecls(
    std::vector<FunctionDecl *> usablefunctiondeclarations) {
    for (long i = (usablefunctiondeclarations.size() - 1); i >= 0; i--) {
        if (isa<CXXMethodDecl>(usablefunctiondeclarations[i])) {
#ifdef MYDEBUG
            llvm::outs() << "~~>Remove CXXMethodDecl:"
                         << getUniqueFunctionNameAsString(
                                usablefunctiondeclarations[i])
                         << "\n";
#endif
            usablefunctiondeclarations.erase(
                usablefunctiondeclarations.begin() + i);
        }
    }
    return usablefunctiondeclarations;
}

/**
 * This function excludes all functions with more than 1 return statement.
 * Why?
 * Later we will replace each return token by an expression where we save the
 * final value. However, skip this function if multiple return statements are
 * present in function body, since we cannot return to caller anymore == we
 * would need to use goto's to stop fct's code execution reliably without any
 * side effects.
 * @param usablefunctiondeclarations
 * @return
 */
std::vector<FunctionDecl *>
FunctionRemovalTransformer::getAllSingleReturnFunctions(
    std::vector<FunctionDecl *> usablefunctiondeclarations) {

    for (long i = (usablefunctiondeclarations.size() - 1); i >= 0; i--) {
        auto f = usablefunctiondeclarations[i];

        std::vector<const ReturnStmt *> curreturnstmts;
        recursiveStmtTVisit<ReturnStmt>(f->getBody(), curreturnstmts);

        if (f->getReturnType().getAsString() == "void" &&
            !curreturnstmts.empty()) {
            // Void function can have a return statement such as return;
            usablefunctiondeclarations.erase(
                usablefunctiondeclarations.begin() + i);
            continue;
        }

        if (f->getReturnType().getAsString() != "void" &&
            curreturnstmts.size() > 1) {
#ifdef MYDEBUG
            llvm::outs() << "~~>Remove fct with multiple ReturnStmt's:"
                         << getUniqueFunctionNameAsString(f) << "\n";
#endif
            usablefunctiondeclarations.erase(
                usablefunctiondeclarations.begin() + i);
        }

    } // end for-loop
    return usablefunctiondeclarations;
}

/**
 * Choose the function that we will move into the respective call location.
 *  Currently, we choose a function based on its call number or the max AST
 * depth of its calling location or we prefer functions that have less lines of
 * code.
 * @param usablefunctiondeclarations
 * @param chooseLocationStrategy either deepest = choose fct based on the
 * deepest caller in AST, any = min calls
 * @return
 */
FunctionDecl *FunctionRemovalTransformer::computeSuitableFunctionToMove(
    const std::vector<FunctionDecl *> &usablefunctiondeclarations,
    const ChooseLocationStrategy chooseLocationStrategy) {

    assert(chooseLocationStrategy == mincallnumber ||
           chooseLocationStrategy == minloc ||
           chooseLocationStrategy == deepest);

    unsigned long mincount = std::numeric_limits<int>::max();
    int max_depth = 0;
    FunctionDecl *chosenFuncDecl = nullptr;

    for (auto f : usablefunctiondeclarations) {
        std::vector<const CallExpr *> callexprrefs =
            ControlDataFlowGraphQueryHandler::queryAllCallExprsToFunction(
                cfggraph, f);

        if (chooseLocationStrategy == mincallnumber &&
            callexprrefs.size() < mincount) {
            mincount = callexprrefs.size();
            chosenFuncDecl = f;
            continue;
        }

        if (chooseLocationStrategy == minloc &&
            callexprrefs.size() < mincount) {
            //                TODO
            mincount = callexprrefs.size();
            chosenFuncDecl = f;
            continue;
        }

        if (chooseLocationStrategy == deepest) {
            std::string inFile = sm.getFilename(f->getLocation());
            for (auto callexprref : callexprrefs) {
                int currentdepth = getdepthfornode(
                    Context.getParents(*callexprref), &Context, 0, inFile);
                if (currentdepth > max_depth) {
                    max_depth = currentdepth;
                    chosenFuncDecl = f;
                }
            }
        }
    }

#ifdef MYDEBUG
    if (chosenFuncDecl)
        llvm::outs() << "**** Will take:"
                     << chosenFuncDecl->getQualifiedNameAsString()
                     << " with:" << mincount << " calls / " << max_depth
                     << " depth ****\n";
#endif

    return chosenFuncDecl;
}