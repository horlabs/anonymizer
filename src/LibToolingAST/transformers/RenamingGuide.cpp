#include "RenamingGuide.h"
#include <algorithm>
#include <ctime>
#include <random>


std::string RenamingGuide::getRandomStringWith(int length, int seed) {
    // Adapted fct from stackoverflow
    const char charset[] =
//                        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::random_device dev;

    std::mt19937 engine(dev());
    engine.seed(seed);
    // -1 for starting with index 0, another -1 for the \0 at the end => -2
    std::uniform_int_distribution<int> dist(0, sizeof(charset) - 2);

    auto randchar = [&charset, &dist, &engine]() -> char {
        return charset[dist(engine)];
    };
    std::string str(length, 0);
    std::generate_n(str.begin(), length, randchar);
    return str;
}