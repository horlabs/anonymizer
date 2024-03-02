#include "TypeMapping.h"
#include "../include/SourceTextHelper.h"

TypeMapping::TypeMapping(ASTContext &Context) : Context(Context) {
    init(Context);
}

void TypeMapping::init(ASTContext &Context) {
    TraverseDecl(Context.getTranslationUnitDecl());
}

bool TypeMapping::VisitTypeLoc(TypeLoc TL) {
    if (!Context.getSourceManager().isWrittenInMainFile(TL.getLocStart()))
        return true;

    auto range = typeMap.equal_range(TL.getType().getAsString());
    for (auto it = range.first; it != range.second; it++) {
        if (it->second == TL)
            return true;
    }
    auto type = TL.getType();
    auto typeName = type.getAsString();
    if (type->isClassType()) {
        typeName = type->getAs<RecordType>()->getDecl()->getNameAsString();
    }
    // ToDo: use getSourceTextStable to get rid of things like "struct Edge" and
    // only get "Edge"?
    typeMap.insert(std::make_pair(typeName, TL));
    return true;
}

std::vector<TypeLoc> TypeMapping::getTypeToTypeLocs(QualType T) {
    if (T->isReferenceType()) {
        T = T.getNonReferenceType();
    }
    if (T->isPointerType()) {
        T = T->getPointeeType();
    }
    T.removeLocalConst();
    return getTypeNameToTypeLoc(T.getAsString());
}

std::vector<TypeLoc> TypeMapping::getTypeToTypeLocs(const Type *T) {
    if (T)
        return getTypeNameToTypeLoc(T->getTypeClassName());
    return std::vector<TypeLoc>();
}

std::vector<TypeLoc> TypeMapping::getTypeNameToTypeLoc(const std::string name) {
    if (typeMap.count(name) == 0)
        return std::vector<TypeLoc>();
    auto range = typeMap.equal_range(name);
    std::vector<TypeLoc> ret{};
    for (auto it = range.first; it != range.second; it++) {
        ret.emplace_back(it->second);
    }
    return ret;
}
