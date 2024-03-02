#include "Utils_Features_CodeLocs.h"

std::pair<unsigned, unsigned> getRowColumn(SourceLocation sl, SourceManager &sm,
                                           bool verbose) {
    FullSourceLoc fullLoc(sl, sm);
    std::pair<unsigned, unsigned> returnval;
    returnval.first = fullLoc.getSpellingLineNumber();
    returnval.second = fullLoc.getColumnNumber();
    if (verbose)
        llvm::outs() << "(r:" << returnval.first << ",c:" << returnval.second
                     << ")\n";
    return returnval;
}

FeatureCodeRange getFeatureCodeRange(SourceLocation start, SourceLocation end,
                                     SourceManager &sm, const LangOptions &lo) {
    SourceLocation LocStart = start;
    SourceLocation LocEnd = end;
    SourceLocation LocEndEnd = Lexer::getLocForEndOfToken(LocEnd, 0, sm, lo);
    SourceRange Range(LocStart, LocEndEnd);

    CharSourceRange r = CharSourceRange::getTokenRange(Range);

    auto rw1 = getRowColumn(r.getBegin(), sm, false);
    auto rw2 = getRowColumn(r.getEnd(), sm, false);
    FeatureCodeRange fww(rw1, rw2);
    return fww;
}

void insertinhashmap_codelocations(
    const std::string &str, const FeatureCodeRange &featcoderange,
    std::unordered_map<std::string, std::vector<FeatureCodeRange>>
        &map_codelocations) {

    if (map_codelocations.find("\"" + str + "\"") != map_codelocations.end()) {
        // str is already in
        map_codelocations["\"" + str + "\""].push_back(featcoderange);
    } else {
        std::vector<FeatureCodeRange> fx;
        fx.push_back(featcoderange);
        map_codelocations["\"" + str + "\""] = fx;
    }
}

void insertinhashmap_codelocations(
    const std::string &str, const FeatureCodeRangeBigram &featcoderange,
    std::unordered_map<std::string, std::vector<FeatureCodeRangeBigram>>
        &map_codelocations) {

    if (map_codelocations.find(str) != map_codelocations.end()) {
        // str is already in
        map_codelocations[str].push_back(featcoderange);
    } else {
        std::vector<FeatureCodeRangeBigram> fx;
        fx.push_back(featcoderange);
        map_codelocations[str] = fx;
    }
}

std::unordered_map<std::string, std::string> convert_codelocations_to_string(
    std::unordered_map<std::string, std::vector<FeatureCodeRange>> &map) {
    std::unordered_map<std::string, std::string> output;
    for (auto const &ent1 : map) {

        std::stringstream ss;
        std::vector<FeatureCodeRange> ent2 = ent1.second;
        bool isfirst2 = true;
        for (auto const &ent2codelocs : ent2) {
            if (!isfirst2) {
                ss << ",";
            }
            isfirst2 = false;
            ss << "[[" << ent2codelocs.first.first << ","
               << ent2codelocs.first.second << "],["
               << ent2codelocs.second.first << "," << ent2codelocs.second.second
               << "]]";
        }
        std::string ent2string = ss.str();
        output[ent1.first] = ent2string;
    }
    return output;
}

std::unordered_map<std::string, std::string> convert_codelocations_to_string(
    std::unordered_map<std::string, std::vector<FeatureCodeRangeBigram>> &map) {
    std::unordered_map<std::string, std::string> output;
    for (auto const &ent1 : map) {

        std::stringstream ss;
        std::vector<FeatureCodeRangeBigram> ent2 = ent1.second;
        bool isfirst2 = true;
        for (auto const &ent2codelocs : ent2) {
            if (!isfirst2) {
                ss << ",";
            }
            isfirst2 = false;
            ss << "[[[" << ent2codelocs.first.first.first << ","
               << ent2codelocs.first.first.second << "],["
               << ent2codelocs.first.second.first << ","
               << ent2codelocs.first.second.second << "]],[["
               << ent2codelocs.second.first.first << ","
               << ent2codelocs.second.first.second << "],["
               << ent2codelocs.second.second.first << ","
               << ent2codelocs.second.second.second << "]]]";
        }
        std::string ent2string = ss.str();
        output[ent1.first] = ent2string;
    }
    return output;
}