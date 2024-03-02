#! /usr/bin/env bash

SCRIPT_PATH="$(dirname $(realpath -s $0))"
LIBTOOLING_DIR="/home/$(id -u -n)/code/authorship-evasion/src/LibToolingAST"
INCLUDE_DIR="/home/$(id -u -n)/code/libs/clang+llvm-5.0.0-linux-x86_64-ubuntu16.04/lib/clang/5.0.0/include/"
BUILD_DIR="cmake-build-release"

MULTIDECL_TRANSFORMER="$LIBTOOLING_DIR/$BUILD_DIR/transformers/multidecl_transformer"

file="$(clang-format $1)"
# if the old file should be backed up
#mv $1 $1.old
#file="$(echo "$file" | sed -e '1s/^/#include "tigress.h"\n/')"

if $(echo "$file" | grep -q "int main(void)"); then
  file="$(echo "$file" | sed -e 's/int main(void) {/void init_tigress() {}\nint main_fun(int, char\*\*);\nint main(int argc, char \*\*argv) {\ninit_tigress();\nmain_fun(argc, argv);\n}\nint main_fun(int argc, char \*\*argv) {/')"
elif $(echo "$file" | grep -q "int main()"); then
  file="$(echo "$file" | sed -e 's/int main() {/void init_tigress() {}\nint main_fun(int, char\*\*);\nint main(int argc, char \*\*argv) {\ninit_tigress();\nmain_fun(argc, argv);\n}\nint main_fun(int argc, char \*\*argv) {/')"
elif $(echo "$file" | grep -q "int main(int argc, char \*\*argv)"); then
  file="$(echo "$file" | sed -e 's/int main(int argc, char \*\*argv) {/void init_tigress() {}\nint main_fun(int, char\*\*);\nint main(int argc, char \*\*argv) {\ninit_tigress();\nmain_fun(argc, argv);\n}\nint main_fun(int argc, char \*\*argv) {/')"
elif $(echo "$file" | grep -q "int main(int argc, char \*argv\[\])"); then
  file="$(echo "$file" | sed -e 's/int main(int argc, char \*argv\[\]) {/void init_tigress() {}\nint main_fun(int, char\*\*);\nint main(int argc, char \*\*argv) {\ninit_tigress();\nmain_fun(argc, argv);\n}\nint main_fun(int argc, char \*\*argv) {/')"
fi


file="$(echo "$file" | cat $SCRIPT_PATH/allFunctions.c - )"
file="$(echo "$file" | sed "s/assert(/(/g" | sed "/#include <.*>/d" | cat <(echo '#include "superheader.h"') - | sed "s/fscanf(stdin, */scanf(/g" | sed "s/fprintf(stdout, */printf(/g")"

if [[ $1 == *"2270488_2449486_1E60."* ]]; then
    file="$(echo "$file" | sed -e 's/int Goal\[M\]\[N\], Board\[M\]\[N\];/int Goal\[M\]\[100\], Board\[M\]\[100\];/')"
fi

if [[ $1 == *"2270488_2463486_kawatea."* ]]; then
    file="$(echo "$file" | sed -e 's/long long a\[100\];/long long a\[100\] = \{ 0 \};/')"
fi

#if [[ $file == *"sqrt("* ]] && [[ $file != *"math.h"* ]]; then
#    file=$'#include <math.h>\n'$file
#fi
#if [[ $file == *"strlen("* ]] && [[ $file != *"string.h"* ]]; then
#    file=$'#include <string.h>\n'$file
#fi
echo "$file" > $1
file="$($MULTIDECL_TRANSFORMER $1 -- -w -I $LIBTOOLING_DIR -I $INCLUDE_DIR)"
file="$(echo "$file" | clang-format)"
# write to the same or another file
echo "$file" > $1
