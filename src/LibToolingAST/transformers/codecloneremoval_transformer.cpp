#ifndef CLANG_LIBS
#define CLANG_LIBS

#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"

#endif

#include "ASTFrontendActionTemplate.inl"
#include "RenamingGuide.h"
#include "include/SourceTextHelper.h"
#include "clang/Analysis/CloneDetection.h"

using namespace clang;

static llvm::cl::OptionCategory
    MyOptionCategory("Code Clone Removal Transformer");

class CollectVarNames : public RecursiveASTVisitor<CollectVarNames> {
private:
  ASTContext &Context;
  SourceManager &sm;
  std::vector<const VarDecl *> varDecls;
  bool usable = true;

public:
  explicit CollectVarNames(ASTContext &Context)
      : Context(Context), sm(Context.getSourceManager()){};

  bool VisitDeclRefExpr(const DeclRefExpr *D) {
    if (!sm.isWrittenInMainFile(D->getLocStart()))
      return true;
    if (!sm.isWrittenInMainFile(D->getDecl()->getLocStart()))
      return true;
    if (!isa<VarDecl>(D->getDecl()))
      return true;
    auto decl = cast<VarDecl>(D->getDecl());
    if (std::find(varDecls.begin(), varDecls.end(), decl) != varDecls.end())
      return true;
    varDecls.emplace_back(decl);
    return true;
  }

  bool VisitBreakStmt(const BreakStmt *S) {
    if (!sm.isWrittenInMainFile(S->getLocStart()))
      return true;
    usable = false;
    return true;
  }

  bool VisitContinueStmt(const ContinueStmt *S) {
    if (!sm.isWrittenInMainFile(S->getLocStart()))
      return true;
    usable = false;
    return true;
  }

  bool VisitReturnStmt(const ReturnStmt *S) {
    if (!sm.isWrittenInMainFile(S->getLocStart()))
      return true;
    usable = false;
    return true;
  }

  bool isUsable() { return usable; }

  std::vector<std::string> getParams() {
    std::vector<std::string> params;

    for (auto &elem : varDecls) {
      params.emplace_back(elem->getType().getAsString() + " &" +
                          elem->getNameAsString());
    }

    return params;
  }

  std::vector<std::string> getNames() {
    std::vector<std::string> names;

    for (auto &elem : varDecls) {
      names.emplace_back(elem->getNameAsString());
    }

    return names;
  }

  void printNames() {
    for (auto &elem : varDecls) {
      auto name = elem->getNameAsString();
      llvm::errs() << name << "\n";
    }
  }

  void reset() {
    varDecls.clear();
    usable = true;
  }
};

/**
 * remove (some) code clones by replacing with a newly created function
 */
class CodeCloneRemovalTransformer
    : public RecursiveASTVisitor<CodeCloneRemovalTransformer> {
private:
  ASTContext &Context;
  SourceManager &sm;
  Rewriter &OurRewriter;
  CloneDetector Detector;
  CollectVarNames collector;

  std::vector<const FunctionDecl *> funcs;

public:
  explicit CodeCloneRemovalTransformer(ASTContext &Context,
                                       Rewriter &OurRewriter)
      : Context(Context), sm(Context.getSourceManager()),
        OurRewriter(OurRewriter), Detector(), collector(Context){};

  bool VisitFunctionDecl(const FunctionDecl *D) {
    if (!sm.isWrittenInMainFile(D->getLocStart()))
      return true;
    if (!D->hasBody())
      return true;
    Detector.analyzeCodeBody(D);
    funcs.emplace_back(D);
    return true;
  }

  void getClones() {
    std::vector<SmallVector<StmtSequence, 8>> AllCloneGroups;

    Detector.findClones(AllCloneGroups, RecursiveCloneTypeIIConstraint(),
                        MinGroupSizeConstraint(2), MinComplexityConstraint(10),
                        MatchingVariablePatternConstraint(),
                        MinGroupSizeConstraint(2),
                        OnlyLargestCloneConstraint());

    for (const CloneDetector::CloneGroup &Group : AllCloneGroups) {
      if (Group.front().front() == nullptr)
        continue;
      if (Context.getParents(*Group.front().front())[0].get<CompoundStmt>() ==
          nullptr)
        continue;
      if (Group.front().size() <= 1)
        continue;
      bool usable = true;
      for (auto elem : Group.front()) {
        if (isa<Stmt>(elem)) {
          collector.TraverseStmt(const_cast<Stmt *>(elem));
        } else {
          llvm::errs() << "Not a stmt\n";
        }
        if (isa<BreakStmt>(elem) || isa<ContinueStmt>(elem) ||
            isa<ReturnStmt>(elem)) {
          usable = false;
        }
        //                elem->dumpColor();
      }
      if (!usable || !collector.isUsable()) {
        collector.reset();
        continue;
      }
      // ToDo: Check if such a function exists
      std::string newFunction = "void ";
      std::string functionName = RenamingGuide::getRandomStringWith(10);
      newFunction += functionName;
      newFunction += "(";

      auto params = collector.getParams();
      for (auto &param : params) {
        newFunction += param + ", ";
      }
      newFunction = newFunction.substr(0, newFunction.size() - 2);

      newFunction += ") ";
      if (!isa<CompoundStmt>(Group.front().front())) {
        newFunction += "{\n";
      }
      newFunction += getSourceTextStable(Context, Group.front().getStartLoc(),
                                         Group.front().getEndLoc());
      bool needSemicolon = true;
      if (newFunction.back() != ';') {
        newFunction += ";";
        needSemicolon = false;
      }
      if (!isa<CompoundStmt>(Group.front().front())) {
        newFunction += "\n}";
      }
      newFunction += "\n\n";
      OurRewriter.InsertTextBefore(funcs.front()->getLocStart(), newFunction);
      collector.reset();
      for (auto clone : Group) {
        for (auto elem : clone) {
          if (isa<Stmt>(elem)) {
            collector.TraverseStmt(const_cast<Stmt *>(elem));
          } else {
            llvm::errs() << "Not a stmt\n";
          }
        }
        std::string call = functionName + "(";
        for (auto &name : collector.getNames()) {
          call += name + ", ";
        }
        call = call.substr(0, call.size() - 2);
        call += ")";
        if (needSemicolon)
          call += ";";
        OurRewriter.ReplaceText(clone.getSourceRange(), call);
        collector.reset();
      }
    }
  }
};

/* ****************** ************** **************** */

class MyASTConsumer : public ASTConsumer {
public:
  explicit MyASTConsumer(ASTContext &Context, Rewriter &OurRewriter)
      : transformer(Context, OurRewriter) {}

  void HandleTranslationUnit(ASTContext &Context) override {
    transformer.TraverseDecl(Context.getTranslationUnitDecl());
    transformer.getClones();
  }

private:
  CodeCloneRemovalTransformer transformer;
};

int main(int argc, const char **argv) {
  clang::tooling::CommonOptionsParser OptionsParser(argc, argv,
                                                    MyOptionCategory);
  clang::tooling::ClangTool Tool(OptionsParser.getCompilations(),
                                 OptionsParser.getSourcePathList());
  return Tool.run(&*clang::tooling::newFrontendActionFactory<
                   MyFrontendAction<MyASTConsumer>>());
}