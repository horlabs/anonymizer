#include "ConvertForRangeStatement.h"
#include "RandomHelper.h"
#include "SourceTextHelper.h"
#include "llvm/Support/CommandLine.h"
#include <sstream>

extern llvm::cl::opt<int> Seed;

void ConvertForRangeStatementMatchHandler::run(
    const MatchFinder::MatchResult &Result) {
    auto &SM = Result.Context->getSourceManager();
    auto &LO = Result.Context->getLangOpts();
    if (const auto *ForRangeStmt =
            Result.Nodes.getNodeAs<CXXForRangeStmt>("forRangeStmt")) {

        const auto RangeInit = ForRangeStmt->getRangeInit();
        // TODO Handle braced-init-lists. Currently we assume RangeInit is an
        // expression.
        string RangeInitText = "(" + getSourceText(RangeInit, SM, LO).str() + ")";
        // Two cases dependent on the type of the expression.
        string BeginExpr = "begin_expr";
        string EndExpr = "end_expr";
        if (const auto X = dyn_cast<DeclRefExpr>(RangeInit)) {
            if (const auto CAT = dyn_cast<ConstantArrayType>(X->getType())) {
                BeginExpr = "__range";
                EndExpr = "__range + " + CAT->getSize().toString(10, false);
            } else if (isa<RecordType>(X->getType()->getCanonicalTypeInternal())) {
                // TODO Check wether begin() and end() exists in scope of class
                BeginExpr = "__range.begin()";
                EndExpr = "__range.end()";
            } else {
                return;
            }
        } else {
            // TODO handle other cases.
            return;
        }
        // taken from the for range statement
        string Stmt = getSourceText(ForRangeStmt->getBody(), SM, LO).str();
        string ForRangeDeclaration =
            getSourceText(ForRangeStmt->getLoopVariable(), SM, LO).str();
        // remove colon (:) from string.
        ForRangeDeclaration.pop_back();

        stringstream sstream;
        sstream << "auto && __range = " << RangeInitText << "; ";
        sstream << "for (auto __begin = " << BeginExpr << ", "
                << "__end = " << EndExpr << "; ";
        sstream << "__begin != __end"
                << "; ";
        sstream << "++__begin) ";
        sstream << "{" << ForRangeDeclaration << " = *__begin; " << Stmt << "}";
        Replacement Replace(SM, getCharSourceRange(ForRangeStmt, SM, LO),
                            sstream.str(), LO);
        Replaces.push_back(Replace);
    }
}

void ConvertForRangeStatementASTConsumer::HandleTranslationUnit(
        ASTContext &Ctx) {
    MatchFinder Finder;
    ConvertForRangeStatementMatchHandler Handler;
    Finder.addMatcher(cxxForRangeStmt().bind("forRangeStmt"), &Handler);
    Finder.matchAST(Ctx);

    // Get all matches (replacements), randomly select a replacement, and
    // insert the replacement into the map.
    auto Replaces = Handler.getReplaces();
    if (!Replaces.empty()) {
        const auto &Replace = select_randomly(Replaces, Seed.getValue());
#ifdef DEBUG
        llvm::dbgs() << "Applying replacement " << Replace.toString() << "\n";
#endif
        llvm::Error Err = FileToReplaces[Replace.getFilePath()].add(Replace);
        if (Err) {
            llvm::errs() << "Transformation failed in " << Replace.getFilePath()
                         << "! " << llvm::toString(move(Err)) << "\n";
        }
    } else {
#ifdef DEBUG
        llvm::dbgs() << "Transformation not applicable"
                     << "\n";
#endif
        llvm::errs() << "Code 123: No transformations possible\n";
    }
}
