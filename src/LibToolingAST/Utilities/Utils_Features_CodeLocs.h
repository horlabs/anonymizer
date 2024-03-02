//
// Created by eq on 09.08.21 for feature-extraction-single-annotated
//

#ifndef LIBTOOLINGAST_UTILS_FEATURES_CODELOCS_H
#define LIBTOOLINGAST_UTILS_FEATURES_CODELOCS_H

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

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Utils.h"

using namespace clang;

typedef std::pair<std::pair<int, int>, std::pair<int, int>> FeatureCodeRange;
typedef std::pair<FeatureCodeRange, FeatureCodeRange> FeatureCodeRangeBigram;

/**
 * Returns the row and column number. If verbose is true, it will print the row
 * and column number. SAME as utils_transform.h, but copied to Utilities to be
 * used by feature-extraction without any dependencies to transformers
 * subproject.
 * @param sr source range
 * @param sm source manager
 * @param verbose true if row and col should be printed to console
 * @return pair of row and column
 */
std::pair<unsigned, unsigned> getRowColumn(SourceLocation sl, SourceManager &sm,
                                           bool verbose = false);

FeatureCodeRange getFeatureCodeRange(SourceLocation start, SourceLocation end,
                                     SourceManager &sm, const LangOptions &lo);

void insertinhashmap_codelocations(
    const std::string &str, const FeatureCodeRange &featcoderange,
    std::unordered_map<std::string, std::vector<FeatureCodeRange>>
        &map_codelocations);
void insertinhashmap_codelocations(
    const std::string &str, const FeatureCodeRangeBigram &featcoderange,
    std::unordered_map<std::string, std::vector<FeatureCodeRangeBigram>>
        &map_codelocations);

std::unordered_map<std::string, std::string> convert_codelocations_to_string(
    std::unordered_map<std::string, std::vector<FeatureCodeRange>> &map);
std::unordered_map<std::string, std::string> convert_codelocations_to_string(
    std::unordered_map<std::string, std::vector<FeatureCodeRangeBigram>> &map);

#include "Utils_Features_CodeLocs.inl"

#endif // LIBTOOLINGAST_UTILS_FEATURES_CODELOCS_H
