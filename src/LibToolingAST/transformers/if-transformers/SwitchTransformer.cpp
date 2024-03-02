#ifndef CLANG_LIBS
#define CLANG_LIBS

#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"

#endif

#include <regex>
#include <vector>
#include "../ASTFrontendActionTemplate.inl"
#include "../include/SourceTextHelper.h"

using namespace clang;

static llvm::cl::OptionCategory MyOptionCategory("SwitchTransformer");

/**
 * Convert switch-statements into a sequence of if-else
 * Note that nested switch statements may not be handled correctly and some
 * constellations with multiple breaks and break and fallthrough in one case
 * etc.
 *
 * WARNING
 * This transformer assumes compound statements for all enclosing if/for/while/.. statements of the switch.
 * Therefore, it is highly recommend to first execute the braces_transformer!
 */
class SwitchTransformer : public RecursiveASTVisitor<SwitchTransformer> {
  private:
    ASTContext &Context;
    SourceManager &sm;
    Rewriter &OurRewriter;
    std::vector<const SwitchStmt*> rewritten{};
  public:
    explicit SwitchTransformer(ASTContext &Context, Rewriter &OurRewriter)
        : Context(Context), sm(Context.getSourceManager()),
          OurRewriter(OurRewriter){};

    std::string createRewriteString(const SwitchStmt *SW) {
        rewritten.emplace_back(SW);
        std::string rewrite;
        std::vector <std::string> conds;
        std::string current;
        std::string switchCond;
        std::string prependStmt;
        llvm::raw_string_ostream swstream(switchCond);
        SW->getCond()->printPretty(swstream, nullptr, PrintingPolicy(Context.getLangOpts()));
        swstream.flush();
        auto swCond = SW->getCond();
        if (isa<ImplicitCastExpr>(swCond)) {
            swCond = swCond->IgnoreImpCasts();
        }
        if (isa<BinaryOperator>(swCond) && cast<BinaryOperator>(swCond)->isAssignmentOp()) {
            prependStmt = switchCond + ";\n";
            switchCond.clear();
            llvm::raw_string_ostream sstream(switchCond);
            cast<BinaryOperator>(swCond)->getLHS()
                                        ->printPretty(sstream, nullptr, PrintingPolicy(Context.getLangOpts()));
        }
        int openBrackets = 0;
        for (auto child : SW->getBody()->children()) {
            if (auto caseStmt = dyn_cast<CaseStmt>(child)) {
                std::vector <std::string> localConds;
                while (isa<CaseStmt>(caseStmt->getSubStmt())) {
                    std::string cond;
                    llvm::raw_string_ostream sstream(cond);
                    sstream << "(" << switchCond << ") == (";
                    caseStmt->getLHS()->printPretty(sstream, nullptr, PrintingPolicy(Context.getLangOpts()));
                    sstream << ")";
                    sstream.flush();
                    localConds.emplace_back(cond);
                    conds.emplace_back(cond);
                    caseStmt = cast<CaseStmt>(caseStmt->getSubStmt());
                }
                std::string code;
                llvm::raw_string_ostream sstream(code);
                bool breaking = false;
                if (isa<CompoundStmt>(caseStmt->getSubStmt())) {
                    const Stmt *last = nullptr;
                    for (auto ch : caseStmt->getSubStmt()->children()) {
                        last = ch;
                        if (isa<BreakStmt>(last) || isa<ReturnStmt>(last) || isa<ContinueStmt>(last)) {
                            breaking = true;
                            break;
                        }
                    }
                    if (isa<BreakStmt>(last)) {
                        sstream << getSourceTextStable(Context,
                                                    caseStmt->getSubStmt()->getLocStart().getLocWithOffset(1),
                                                    last->getLocStart().getLocWithOffset(-1));
                    } else {
                        sstream << getSourceTextStable(Context,
                                                    caseStmt->getSubStmt()->getLocStart().getLocWithOffset(1),
                                                    caseStmt->getSubStmt()->getLocEnd().getLocWithOffset(-1));
                    }
                } else if (isa<BreakStmt>(caseStmt->getSubStmt())) {
                    breaking = true;
                } else if (isa<SwitchStmt>(caseStmt->getSubStmt())) {
                    sstream << this->createRewriteString(cast<SwitchStmt>(caseStmt->getSubStmt()));
                } else {
                    if (isa<ReturnStmt>(caseStmt->getSubStmt()) || isa<ContinueStmt>(caseStmt->getSubStmt())) {
                        breaking = true;
                    }
                    caseStmt->getSubStmt()->printPretty(sstream, nullptr, PrintingPolicy(Context.getLangOpts()));
                    auto tmpStr = sstream.str();
                    while (tmpStr.back() == '\n') {
                        tmpStr.pop_back();
                    }
                    if (tmpStr.back() != ';' && tmpStr.back() != '}') {
                        sstream << ";";
                    }
                }
                sstream.flush();
                std::string cond;
                llvm::raw_string_ostream condStream(cond);
                condStream << "(" << switchCond << ") == (";
                caseStmt->getLHS()->printPretty(condStream, nullptr, PrintingPolicy(Context.getLangOpts()));
                condStream << ")";
                condStream.flush();
                localConds.emplace_back(cond);
                conds.emplace_back(cond);
                cond.clear();
                for (const auto &c : conds) {
                    if (!cond.empty()) cond += " || ";
                    cond += c;
                }
                code = current + code;
                current = "if (";
                current += cond;
                current += ") {\n";
                current += code;
                openBrackets++;

                if (breaking) {
                    if (!rewrite.empty()) {
                        rewrite.append(" else ");
                    }
                    while (openBrackets > 0) {
                        if (current.back() != '\n') {
                            current += "\n";
                        }
                        current += "}";
                        openBrackets--;
                    }
                    rewrite.append(current);
                    conds.clear();
                    current.clear();
                }
            } else if (isa<DefaultStmt>(child)) {
                auto defaultStmt = cast<DefaultStmt>(child);
                auto subStmt = defaultStmt->getSubStmt();
                std::string code;
                llvm::raw_string_ostream sstream(code);
                sstream << "{\n";
                openBrackets++;
                while (isa<CaseStmt>(subStmt)) {
                    subStmt = cast<CaseStmt>(subStmt)->getSubStmt();
                }
                if (isa<CompoundStmt>(subStmt)) {
                    const Stmt *last = nullptr;
                    for (auto ch : subStmt->children()) {
                        last = ch;
                        if (isa<BreakStmt>(last)) break;
                    }
                    if (isa<BreakStmt>(last)) {
                        sstream << getSourceTextStable(Context,
                                                    subStmt->getLocStart().getLocWithOffset(1),
                                                    last->getLocStart().getLocWithOffset(-1));
                    } else {
                        sstream << getSourceTextStable(Context,
                                                    subStmt->getLocStart().getLocWithOffset(1),
                                                    subStmt->getLocEnd().getLocWithOffset(-1));
                    }
                } else if (!isa<BreakStmt>(subStmt)) {
                    subStmt->printPretty(sstream, nullptr, PrintingPolicy(Context.getLangOpts()));
                    auto tmpStr = sstream.str();
                    while (tmpStr.back() == '\n') {
                        tmpStr.pop_back();
                    }
                    if (tmpStr.back() != ';' && tmpStr.back() != '}') {
                        sstream << ";";
                    }
                }
                sstream.flush();
                current += code;
            } else if (isa<BreakStmt>(child)) {
                if (current.empty() && conds.empty()) continue;
                if (!rewrite.empty()) {
                    rewrite.append(" else ");
                }
                while (openBrackets > 0) {
                    if (current.back() != '\n') {
                        current += "\n";
                    }
                    current += "}";
                    openBrackets--;
                }
                rewrite.append(current);
                conds.clear();
                current.clear();
            } else if (isa<ReturnStmt>(child)) {
                if (current.empty() && conds.empty()) continue;
                if (!rewrite.empty()) {
                    rewrite.append(" else ");
                }
                std::string code;
                llvm::raw_string_ostream sstream(code);
                child->printPretty(sstream, nullptr, PrintingPolicy(Context.getLangOpts()));
                sstream.flush();
                current += code;
                while (openBrackets > 0) {
                    if (current.back() != '\n') {
                        current += "\n";
                    }
                    current += "}";
                    openBrackets--;
                }
                rewrite.append(current);
                conds.clear();
                current.clear();
            } else if (isa<GotoStmt>(child)) {
                if (current.empty() && conds.empty()) continue;
                if (!rewrite.empty()) {
                    rewrite.append(" else ");
                }
                std::string code;
                llvm::raw_string_ostream sstream(code);
                child->printPretty(sstream, nullptr, PrintingPolicy(Context.getLangOpts()));
                sstream.flush();
                current += code;
                while (openBrackets > 0) {
                    if (current.back() != '\n') {
                        current += "\n";
                    }
                    current += "}";
                    openBrackets--;
                }
                rewrite.append(current);
                conds.clear();
                current.clear();
            } else {
                llvm::raw_string_ostream sstream(current);
                child->printPretty(sstream, nullptr, PrintingPolicy(Context.getLangOpts()));
                sstream.flush();
                if (current.back() != ';' && current.back() != '}') {
                    current += ';';
                }
            }
            if (!current.empty() && current.back() != '\n') current += "\n";
        }
        if (!current.empty()) {
            if (!rewrite.empty()) {
                rewrite.append(" else ");
            }
            while (openBrackets > 0) {
                if (current.back() != '\n') {
                    current += "\n";
                }
                current += "}";
                openBrackets--;
            }
            rewrite.append(current);
        }
        // ToDo: Only quick hack, need to check if this changes the control flow
        rewrite = std::regex_replace(rewrite, std::regex("break;"), "");
        rewrite = prependStmt + rewrite;
        return rewrite;
    }

    bool VisitSwitchStmt(const SwitchStmt *SW) {
        if (sm.isWrittenInMainFile(SW->getLocStart()) && std::find(rewritten.begin(), rewritten.end(), SW) == rewritten.end()) {
            std::string rewrite = this->createRewriteString(SW);
            OurRewriter.ReplaceText(SW->getSourceRange(), rewrite);
        }
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
    SwitchTransformer transformer;
};

int main(int argc, const char **argv) {
    clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                      MyOptionCategory);
    clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                   OptionsParser.getSourcePathList());
    return Tool.run(&*clang::tooling::newFrontendActionFactory<
                     MyFrontendAction<MyASTConsumer>>());
}