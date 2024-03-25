#! /usr/bin/env bash

SCRIPT_PATH="$(dirname $(realpath -s "$0"))"
LIBTOOLING_DIR="/home/$(id -u -n)/code/authorship-evasion/src/LibToolingAST"
BUILD_DIR="cmake-build-release"

UNUSED_TRANSFORMER="$LIBTOOLING_DIR/$BUILD_DIR/transformers/unused-stuff/unused_functions_transformer"
EMPTYFUNC="$LIBTOOLING_DIR/$BUILD_DIR/transformers/preparing/functions/empty_function_transformer"
nocstd="$LIBTOOLING_DIR/nocstd.h"
RAND=false
RENAME=false
ADVANCED=false

while [ -n "$1" ]; do
    case "$1" in
        --random) RAND=true ;;
        --rename) RENAME=true ;;
        --advanced) ADVANCED=true ;;
        *) break ;;
    esac
    shift
done

filename="$(realpath -s "$1")"
filedir="$(dirname $filename)"
filedir="${filedir#"/tmp/obfus"}"
filedir="$(echo "$filedir" | cut -d '/' -f1-4)"
fileindir="${filename#filedir}"
tmpdir="$(mktemp -d)"
ORIG_DIR="<collected github dump>${filedir}"
cp -r "$ORIG_DIR" "$tmpdir"
ORIG_DIR="/tmp/macros2${filedir}"
cp -r "$ORIG_DIR" "$tmpdir"
file="$(basename "$1")"
include_dir="$(dirname "$filename")"
tmpfile="$tmpdir/${file%.*}.tmp.c"
cp "$filename" "$tmpdir/$file"
pushd "$tmpdir">/dev/null

#qsort=$(grep "qsort\(.*\)" "$filename")
#qsort=${qsort##*, }
#qsort=${qsort##*&}
#qsort=",${qsort%%)*}"
qsort=",$($SCRIPT_PATH/get_qsort_callback.py "$filename")"
if [ "$qsort" = "," ] || [ "$qsort" = ",NULL" ] || [ "$qsort" = ",null" ] || [ "$qsort" = ",voidVar" ] || [ "$qsort" = ",intVar," ] || [ "$qsort" = ",const void *" ]; then
    qsort=""
fi

SEED=1337
extern_funcs="abs,atoi,__assert_fail,ceil,__ctype_b_loc,exit,fclose,fgetc,fgets,floor,fopen,fprintf,fputc,free,freopen,fscanf,getc,getchar,gets,itoa,log10,malloc,memmove,memset,pow,printf,putc,putchar,puts,qsort,scanf,sprintf,sqrt,sqrtl,sscanf,stderr,stdin,stdout,strchr,strcmp,strcpy,strlen,strtoul,system,tolower,toupper,_IO_getc,_IO_putc"
if [ "$RAND" = true ] ; then
    SEED=0
    extern_funcs=$(echo $extern_funcs | tr ',' '\n' | shuf | tr '\n' ',')
fi

if [ "$ADVANCED" = true ] ; then
    $SCRIPT_PATH/pad_strings.py $SEED "$filename" > "$tmpfile"
    $SCRIPT_PATH/fmt_args.py "$tmpfile"
    VSTACKSIZE=48
else
    cp "$filename" "$tmpfile"
    VSTACKSIZE=68
fi

$SCRIPT_PATH/remove_static.py "$tmpfile"
$SCRIPT_PATH/remove_static.py "$tmpdir/$file"
out="${file%.*}.obf.c"
opaque_structs="env"
funcs="$($SCRIPT_PATH/functionList.sh "$file")"
func_ptrs=",$($SCRIPT_PATH/functionPtrList.sh "$file")"
if [ "$func_ptrs" = "," ]; then
    func_ptrs=""
fi

IFS=',' read -ra PTRS <<< "$func_ptrs"
for ptr in "${PTRS[@]}";
do
    funcs="$(echo $funcs | sed "s/\b$ptr\b//g")"
done
funcs=$(echo $funcs | sed "s/,\+/,/g")
funcs=$(echo $funcs | sed "s/,$//g")

if $(grep -q "typedef [^;]* bool;" $tmpfile) ;
then
    echo "BOOL"
    defines="$defines -DBOOLTYPE"
fi
if [[ "$funcs" == *"itoa"* ]];
then
    defines="$defines -DITOA"
fi

if [[ "$funcs" == *"min"* ||  "$funcs" == *"max"* ]] || grep -q "static inline [^(]\+ \(min\|max\)" "$file";
then
    defines="$defines -DMIN_MAX"
fi
main="main"
main_0="main_0,"
if $(grep -vq "int main(" $tmpfile) ;
then
    #echo "No main in $filename"
    #echo $funcs
    main="mainf"
    main_0=""
fi
libs="-lm -ldl
tigress -c -D_Float128=double $defines -w $libs -I"$include_dir" -I/code-imitator/src/LibToolingAST/ \
    -L/code-imitator/src/LibToolingAST/cmake-build-release \
    -include nocstd.h -include microsoft_specific.h -lnocstd -lm \
    --Seed=$SEED --Statistics=0 --Verbosity=0 --Environment=x86_64:Linux:Clang:5.0 \
    --Transform=InitEncodeExternal \
        --Functions=$main \
        --InitEncodeExternalSymbols=$extern_funcs \
        --Skip=false \
    --Transform=InitEntropy \
        --InitEntropyKinds=vars \
        --Functions=init_tigress \
        --Skip=false \
    --Transform=InitOpaque \
        --Functions=init_tigress \
        --InitOpaqueStructs=$opaque_structs \
        --Skip=false \
    --Transform=RandomFuns \
        --RandomFunsName=SECRET \
        --RandomFunsFunctionCount=3 \
        --RandomFunsCodeSize=20 \
        --RandomFunsLoopSize=5 \
        --Skip=false \
    --Transform=EncodeLiterals \
        --Functions=$funcs,$main,${main_0}/SECRET.*/$qsort$func_ptrs \
        --EncodeLiteralsKinds=string \
        --EncodeLiteralsEncoderName=stringEncoder \
        --Skip=false \
    --Transform=Merge \
        --MergeFlatten=false \
        --MergeName=MERGED \
        --Functions=$funcs,/SECRET.*/,${main_0} \
        --Skip=false \
    --Transform=Virtualize \
        --VirtualizeDispatch=switch \
        --VirtualizeStackSize=$VSTACKSIZE \
        --VirtualizeOperands=mixed \
        --VirtualizeMaxDuplicateOps=2 \
        --VirtualizeSuperOpsRatio=0.1 \
        --VirtualizeMaxMergeLength=3 \
        --Functions=MERGED,stringEncoder$qsort$func_ptrs \
        --Skip=false \
    --Transform=EncodeLiterals \
        --Functions=$main,MERGED,stringEncoder$qsort$func_ptrs \
    	--EncodeLiteralsKinds=integer \
        --Skip=false \
    --Transform=EncodeExternal \
        --Functions=MERGED$qsort$func_ptrs \
        --EncodeExternalSymbols=$extern_funcs \
        --Skip=false \
    --Transform=CleanUp \
        --CleanUpKinds=* \
        --Skip=false \
    --out="$out" "$tmpfile" > /dev/null
retVal=$?
if [ $retVal -ne 0 ]; then
    #cat "$tmpfile"
#    echo "$defines"
#    clang $defines "$tmpfile"
    #rm -rf "$tmpdir"
    echo "ERROR (tigress)"
    echo "File: " $filename
    echo "Funcs: " $funcs
    echo "Ptrs: " $func_ptrs
    echo "Callbacks: " $qsort
    exit $retVal
fi
#working randomfuns: size=10, defaults, virtualize stacksize=54; 20, 56; FunsCount=3, LoopSize=5, 30, 124
# working for one round empty functions removing: StackSize 151
# possible dispatch options: direct, switch, indirect, ifnest (veeeery slow), linear (veeeeeeeeeeeery slow), binary (very slow, too), interpolation

# remove empty functions
if [ "$ADVANCED" = true ]; then
    file="$(cat "$out" 2>/dev/null | perl -pe 's| *\/\*.*?\*\/||g')"
    echo "$file" > "$out"
    sizebefore=$(echo "$file" | wc -m)
    file="$($EMPTYFUNC "$out" -- 2>/dev/null)"
    echo "$file" > "$out"
    sizeafter=$(echo "$file" | wc -m)
    while [ "$sizebefore" -gt "$sizeafter" ]
    do
        sizebefore=$sizeafter
        file="$($EMPTYFUNC "$out" -- 2>/dev/null)"
        echo "$file" > "$out"
        sizeafter=$(echo "$file" | wc -m)
    done

    file="$(cat "$out" 2>/dev/null | perl -pe 's| *\/\*.*?\*\/||g')"
    echo "$file" > "$out"
    # remove unused functions (extern from headers)
    file="$($UNUSED_TRANSFORMER -all -strategy=remove_function "$out" -- 2>/dev/null)"
    file="$(echo "$file" | sed -e '/^$/d')"
    file="$(echo "$file" | sed -z 's/__attribute__((\(__[a-z]\+__\((\([0-9]\(,[ \n]*\)\?\)*)\)\?\(,[ \n]*\)\?\)*))//g')"
    file="$(echo "$file" | sed 's/\(char *\*\) *[0-9]\+/\1/g')"
    file="$(echo "$file" | sed -E 's/(__restrict|const|__format|__stream|__filename|__modes|__endptr|(__)?base|__dest|__ptr|__nptr|__x|__y| num|__memb|rc|__status|__size|__command|__compar|__n|__s|__c)[0-9]*//g')"
    file="$(echo "$file" | sed 's/*str/*/g' | sed 's/ \+/ /g')"
    echo -n "$file" > "$out"

    # rename labels, vars and functions
    $SCRIPT_PATH/rewrite_tigress.py "$out"
    file="$(cat "$out" 2>/dev/null | perl -pe 's| *\/\*.*?\*\/||g' | sed -e '/^$/d')"
    echo "$file" > "$out"
fi

# clean up directory
if [ "$RENAME" = false ]; then
    filename=$(echo "$filename" | sed -e 's/.c$/.obf.c/g')
fi
mv "$out" "$filename"
popd >/dev/null
rm -rf "$tmpdir"
#date
