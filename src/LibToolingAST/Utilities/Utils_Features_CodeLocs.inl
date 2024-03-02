/**
 * This function prints two hashmaps of [string, T] and [string,[T,T,...]] in
 * the format such that we can read it in Python. T can be an arbitrary type,
 * e.g. int or float.
 * @param map
 * @param map2
 * @param InFile
 */
template <typename T>
void printhashmap_codelocs(const std::unordered_map<std::string, T> &map,
                           std::unordered_map<std::string, std::string> &map2,
                           const std::string &InFile) {
    // First, print the user name and the current file
    llvm::outs() << extract_name(split_path(InFile)[1]) << " "
                 << split_path(InFile)[1] << " [";

    // Go over all elements; we use firstelem
    // so that we do not set a comma when printing the first element:
    bool firstelem = true;
    for (auto const &ent1 : map) {

        std::string ent2string;
        std::stringstream ss;
        if (map2.find(ent1.first) != map2.end()) {
            ent2string = map2[ent1.first];
        }

        // ent1.first is the key, ent1.second is its value
        if (firstelem) {
            llvm::outs() << "[" << ent1.first << ", " << ent1.second << ", "
                         << "[" + ent2string + "]"
                         << "]"
                         << "";
            firstelem = false;
        } else {
            llvm::outs() << ", [" << ent1.first << ", " << ent1.second << ", "
                         << "[" + ent2string + "]"
                         << "]"
                         << "";
        }
    }

    // Print last ] to close list of all types
    llvm::outs() << "] \n";
}