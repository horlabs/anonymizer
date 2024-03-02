#! /usr/bin/env bash

SCRIPT_PATH="$(dirname $(realpath -s "$0"))"
LIBTOOLING_DIR="/home/$(id -u -n)/code/authorship-evasion/src/LibToolingAST"
INCLUDE_DIR="/home/$(id -u -n)/code/libs/clang+llvm-5.0.0-linux-x86_64-ubuntu16.04/lib/clang/5.0.0/include/"
BUILD_DIR="cmake-build-release"

MULTIDECL_TRANSFORMER="$LIBTOOLING_DIR/$BUILD_DIR/transformers/multidecl_transformer"
UNUSED_FUNC_TRANSFORMER="$LIBTOOLING_DIR/$BUILD_DIR/transformers/unused-stuff/unused_functions_transformer"
$SCRIPT_PATH/reformatBraces.py "$1"
$SCRIPT_PATH/add_main_return.py "$1"
sed -i '/#pragma omp/d' "$1"

file="$(clang-format -style="{SortIncludes: false, SpaceBeforeParens: Never}" "$1" | sed -E 's/#define (true|false)\(\(bool\)(0|1)\)/#define \1 ((bool)\2)/g')"
# if the old file should be backed up
#mv $1 $1.old
#file="$(echo "$file" | sed -e '1s/^/#include "tigress.h"\n/')"

if $(echo "$file" | grep -q "\(long long \)\{0,1\}int main(void)"); then
  file="$(echo "$file" | sed -e 's/\(long long \)\{0,1\}int main(void) {/void init_tigress() {}\n\1int main_fun(void);\nint main(int argc, char \*\*argv) {\ninit_tigress();\nmain_fun();\n}\n\1int main_fun(void) {/')"

elif $(echo "$file" | grep -q "\n\[ \t\] *int main()"); then
  file="$(echo "$file" | sed -e 's/int main() *{/void init_tigress() {}\nint main_fun();\nint main(int argc, char \*\*argv) {\ninit_tigress();\nmain_fun();\n}\nint main_fun() {/')"

elif $(echo "$file" | grep -q "\n[ \t]*\(void\|int\) main(int [a-zA-Z0-9_]\+, char \*\*[a-zA-Z0-9_]\+)"); then
  file="$(echo "$file" | sed -e 's/\n[ \t]*\(void\|int\) main(int \([a-zA-Z0-9_]\+\), char \*\*\([a-zA-Z0-9_]\+\)) {/void init_tigress() {}\n\1 main_fun(int, char\*\*);\nint main(int argc, char \*\*argv) {\ninit_tigress();\nmain_fun(argc, argv);\n}\n\1 main_fun(int \2, char \*\*\3) {/')"

elif $(echo "$file" | grep -q "\(void\|int\) main(int [a-zA-Z0-9_]\+,\( const\)\{0,1\} char\( const\)\{0,1\} \*\([a-zA-Z0-9_]\+\)\[\])"); then
  file="$(echo "$file" | sed -e 's/\(void\|int\) main(int \([a-zA-Z0-9_]\+\),\( const\)\{0,1\} char\( const\)\{0,1\} \*\([a-zA-Z0-9_]\+\)\[\]) {/void init_tigress() {}\n\1 main_fun(int, char\3 \*\[\]);\nint main(int argc, char \*\*argv) {\ninit_tigress();\nmain_fun(argc, argv);\n}\n\1 main_fun(int \2, char\3 \*\5\[\]) {/')"

elif $(echo "$file" | grep -q "void main()"); then
  file="$(echo "$file" | sed -e 's/void main() {/void init_tigress() {}\nvoid main_fun();\nint main(int argc, char \*\*argv) {\ninit_tigress();\nmain_fun();\n}\nvoid main_fun() {/')"

elif $(echo "$file" | grep -q "void main(void)"); then
  file="$(echo "$file" | sed -e 's/void main(void) {/void init_tigress() {}\nvoid main_fun(void);\nint main(int argc, char \*\*argv) {\ninit_tigress();\nmain_fun();\n}\nvoid main_fun(void) {/')"

elif $(echo "$file" | grep -q "void main(int argc, char \(const \)\{0,1\}\*argv\[\])"); then
  file="$(echo "$file" | sed -e 's/void main(int argc, char \(const \)\{0,1\}\*argv\[\]) {/void init_tigress() {}\nvoid main_fun(int, char \1\*\[\]);\nint main(int argc, char \*\*argv) {\ninit_tigress();\nmain_fun(argc, argv);\n}\nvoid main_fun(int argc, char \1\*argv\[\]) {/')"

elif $(echo "$file" | grep -q "^ *main()"); then
  file="$(echo "$file" | sed -e 's/main() {/void init_tigress() {}\nint main_fun();\nint main(int argc, char \*\*argv) {\ninit_tigress();\nmain_fun();\n}\nmain_fun() {/')"

elif $(echo "$file" | grep -q "\(void\|int\) main(int [a-zA-Z0-9_]\+, char \*\*[a-zA-Z0-9_]\+, char \*\*[a-zA-Z0-9_]\+)"); then
  file="$(echo "$file" | sed -e 's/\(void\|int\) main(int \([a-zA-Z0-9_]\+\), char \*\*\([a-zA-Z0-9_]\+\), char \*\*[a-zA-Z0-9_]\+) {/void init_tigress() {}\n\1 main_fun(int, char\*\*);\nint main(int argc, char \*\*argv) {\ninit_tigress();\nmain_fun(argc, argv);\n}\n\1 main_fun(int \2, char \*\*\3) {/')"

elif $(echo "$file" | grep -q "void main(int argc, char \(const \)\{0,1\}\*argv\[\])"); then
  file="$(echo "$file" | sed -e 's/void main(int argc, char \(const \)\{0,1\}\*argv\[\]) {/void init_tigress() {}\nvoid main_fun(int, char \1\*\[\]);\nint main(int argc, char \*\*argv) {\ninit_tigress();\nmain_fun(argc, argv);\n}\nvoid main_fun(int argc, char \1\*argv\[\]) {/')"

# special cases
elif $(echo "$file" | grep -q "int main(int argv, char \*\*args)"); then
  file="$(echo "$file" | sed -e 's/int main(int argv, char \*\*args) {/void init_tigress() {}\nint main_fun(int, char\*\*);\nint main(int argc, char \*\*argv) {\ninit_tigress();\nmain_fun(argc, argv);\n}\nint main_fun(int argv, char \*\*args) {/')"

elif $(echo "$file" | grep -q "int main(int [a-zA-Z0-9_]\+, char \*argv\[\], char \*[a-zA-Z0-9_]\+\[\])"); then
  file="$(echo "$file" | sed -e 's/int main(int \([a-zA-Z0-9_]\+\), char \*argv\[\], char \*[a-zA-Z0-9_]\+\[\]) {/void init_tigress() {}\nint main_fun(int, char\*\[\]);\nint main(int argc, char \*\*argv) {\ninit_tigress();\nmain_fun(argc, argv);\n}\nint main_fun(int \1, char \*argv\[\]) {/')"
elif $(echo "$file" | grep -q "int mainf(int argc, char \*\*argv)"); then
  file="$(echo "$file" | sed -e 's/int mainf(int argc, char \*\*argv) {/void init_tigress() {}\nint mainf(int argc, char \*\*argv) {\ninit_tigress();\n/')"
fi

file="$(echo "$file" | sed -e 's/void init_tigress() {}/#ifndef _INIT_TIGRESS_\n#define _INIT_TIGRESS_\nvoid init_tigress() {}\n#endif/')"


if [[ "$1" == *"2270488_2449486_1E60."* ]]; then
    file="$(echo "$file" | sed -e 's/int Goal\[M\]\[N\], Board\[M\]\[N\];/int Goal\[M\]\[100\], Board\[M\]\[100\];/')"
fi

if [[ $1 == *"2270488_2463486_kawatea."* ]]; then
    file="$(echo "$file" | sed -e 's/long long a\[100\];/long long a\[100\] = \{ 0 \};/')"
fi

if [[ "$file" == *"sqrt("* ]] && [[ "$file" != *"math.h"* ]]; then
    file=$'#include <math.h>\n'"$file"
fi
#if [[ $file == *"strlen("* ]] && [[ $file != *"string.h"* ]]; then
#    file=$'#include <string.h>\n'$file
#fi
echo "$file" > "$1"

#file=$("$UNUSED_FUNC_TRANSFORMER" -strategy=remove_function -all "$1" -- -I"$INCLUDE_DIR" 2>/dev/null)
#echo "$file" > "$1"

