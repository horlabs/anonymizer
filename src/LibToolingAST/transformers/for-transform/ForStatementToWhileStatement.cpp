#include "ForStatementToWhileStatement.h"
#include "RandomHelper.h"
#include "llvm/Support/CommandLine.h"
#include <sstream>

extern llvm::cl::opt<int> Seed;

void ForStatementToWhileStatementMatchHandler::run(
    const MatchFinder::MatchResult &Result) {
    auto &SM = Result.Context->getSourceManager();
    auto &LO = Result.Context->getLangOpts();
    if (const auto *ForS = Result.Nodes.getNodeAs<ForStmt>("forStmt")) {
        if (!SM.isInMainFile(ForS->getLocStart()))
            return;

        const auto Init = ForS->getInit();
        const auto Condition = ForS->getCond();
        const auto Inc = ForS->getInc();
        const auto Body = ForS->getBody();

        // We need to take care if some parts in a for statement are missing,
        // e.g. for(int i=0; i < n; ) ... is valid..
        std::string InitText, ConditionText, IncText;
        if (Init) {
            InitText = getSourceText(Init, SM, LO).str();
        }
        if (Condition) {
            ConditionText = getSourceText(Condition, SM, LO).str();
        } else {
            ConditionText = "1";
        }
        if (Inc) {
            IncText = getSourceText(Inc, SM, LO).str();
        }

        // Create body text, consider continue statements.
        std::string BodyText;
        if (const auto CS = dyn_cast<CompoundStmt>(Body)) {
            BodyText += "{ ";
            for (const auto S : CS->body()) {
                BodyText +=
                    handleContinueStatements(S, Result.Context, IncText);
            }
            BodyText += IncText + ";";
            BodyText += " }";
        } else {
            BodyText += "{ ";
            BodyText +=
                handleContinueStatements(Body, Result.Context, IncText) +
                IncText + ";";
            BodyText += " }";
        }

        std::stringstream sstream;
        sstream << "{ " << InitText << " while (" << ConditionText << ") "
                << BodyText << " }";
        Replacement Replace(SM, getCharSourceRange(ForS, SM, LO), sstream.str(),
                            LO);
        Replaces.push_back(Replace);
    }
}

void ForStatementToWhileStatementASTConsumer::HandleTranslationUnit(
    ASTContext &Ctx) {
    MatchFinder Finder;
    ForStatementToWhileStatementMatchHandler Handler;
    Finder.addMatcher(forStmt(hasBody(anything())).bind("forStmt"), &Handler);
    Finder.matchAST(Ctx);

    // Get all matches (replacements), randomly select a replacement, and
    // insert the replacement into the map.
    auto Replaces = Handler.getReplaces();
    if (!Replaces.empty()) {
        auto Replace = select_randomly(Replaces, Seed.getValue());
#ifdef MYDEBUG
        llvm::dbgs() << "Applying replacement " << Replace.toString() << "\n";
#endif
        llvm::Error Err = FileToReplaces[Replace.getFilePath()].add(Replace);
        if (Err) {
            llvm::errs() << "Transformation failed in " << Replace.getFilePath()
                         << "! " << llvm::toString(std::move(Err)) << "\n";
        }
    } else {
#ifdef MYDEBUG
        llvm::dbgs() << "Transformation not applicable"
                     << "\n";
#endif
        llvm::errs() << "Code 123: No transformations possible\n";
    }
}

string ForStatementToWhileStatementMatchHandler::handleContinueStatements(
    const Stmt *S, ASTContext *Ctx, const StringRef &IncText) {
    auto &SM = Ctx->getSourceManager();
    auto &LO = Ctx->getLangOpts();
    if (isa<ForStmt>(S) || isa<WhileStmt>(S) || isa<DoStmt>(S)) {
        // The Source text of loops can be used without modification, because
        // all subsequent continue statements belong to these loops.
        return getSourceText(S, SM, LO).str();
    } else if (const auto CS = dyn_cast<CompoundStmt>(S)) {
        // Decompose compound statements.
        string res = "{ ";
        for (const auto &CompoundMemberStmt : CS->body()) {
            res += handleContinueStatements(CompoundMemberStmt, Ctx, IncText);
            res += " ";
        }
        res += "}";
        return res;
    } else if (const auto IfS = dyn_cast<IfStmt>(S)) {
        // Decompose if statements.
        string res;
        const auto Cond = IfS->getCond();
        const auto Then = IfS->getThen();
        res += "if (" + getSourceText(Cond, SM, LO).str() + ") ";
        res += handleContinueStatements(Then, Ctx, IncText);
        if (const auto Else = IfS->getElse()) {
            res += "else ";
            res += handleContinueStatements(Else, Ctx, IncText);
        }
        return res;
    } else if (const auto ContStmt = dyn_cast<ContinueStmt>(S)) {
        // Place the increment expression before each continue statement. Create
        // new compound statement if needed.
        const auto Parents = Ctx->getParents(*ContStmt);
        const auto Parent = Parents[0];
        if (Parent.get<IfStmt>()) {
            return "{ " + IncText.str() + "; " +
                   getSourceText(ContStmt, SM, LO).str() + " }";
        } else {
            return IncText.str() + "; " + getSourceText(ContStmt, SM, LO).str();
        }
    } else {
        // Everything else: Use source text as it is.
        return getSourceText(S, SM, LO).str();
    }
}