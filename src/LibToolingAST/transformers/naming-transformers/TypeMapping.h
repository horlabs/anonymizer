#ifndef LIBTOOLINGAST_TYPEMAPPING_H
#define LIBTOOLINGAST_TYPEMAPPING_H

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

class TypeMapping : public RecursiveASTVisitor<TypeMapping> {
  public:
    explicit TypeMapping(ASTContext &Context);

    void init(ASTContext &Context);

    bool VisitTypeLoc(TypeLoc TL);

    std::vector<TypeLoc> getTypeToTypeLocs(const Type *T);

    std::vector<TypeLoc> getTypeToTypeLocs(QualType T);

    std::vector<TypeLoc> getTypeNameToTypeLoc(const std::string name);

  private:
    std::multimap<const std::string, TypeLoc> typeMap;
    ASTContext &Context;
};

#endif // LIBTOOLINGAST_TYPEMAPPING_H
