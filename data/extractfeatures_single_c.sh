#!/bin/bash
RED='\033[0;31m'
NC='\033[0m' # No Color

# * * * SET UP PATHES HERE * * *
# SET UP THE PATH TO JAVA BASELINE JAR or use environment variables 
CMD_DIR_NAIVEBASELINE="${CMD_DIR_NAIVEBASELINEJAR}" #; exit # remove exit then





# get parent directory of data directory where this file is located
SCRIPTPATH=$(dirname $(readlink -f "$0"))
AUTHORSHIP_EVASION=$( dirname $SCRIPTPATH )
echo -e "${RED}Start extracting features${NC}"

### Now do feature extraction
COPY_PROJECT=true
GITHUB_FILENAMES=true
SUFFIX="c_only"
DATASET="c_only"
SUFFIX="2017"
DATASET="2017"
SUFFIX="github_imitation_rnn"
DATASET="github"
SRC="${AUTHORSHIP_EVASION}/data/dataset_${DATASET}/dataset_${SUFFIX}"
OUTPUT_DIR="${AUTHORSHIP_EVASION}/data/dataset_${DATASET}/libtoolingfeatures_${SUFFIX}"
mkdir -p $OUTPUT_DIR


CMD_DIR="${AUTHORSHIP_EVASION}/src/LibToolingAST/cmake-build-release/feature_extraction_single/"
CMD_DIR_LEXEMS="${AUTHORSHIP_EVASION}/src/LibToolingAST/cmake-build-release/feature_extraction/"
CLANG_LIB=$( llvm-config --libdir )
COMPILER_FLAG="-w -std=c99 -ferror-limit=1 -I${CLANG_LIB}/clang/5.0.0/include/ -I${AUTHORSHIP_EVASION}/src/LibToolingAST"
#-ferror-limit=1 
MAX_TIME=3000
MAX_JOBS=8


function make_pause {
# print * 90x
s=$(printf "%-90s" "*")
echo -e "${RED} ${s// /*} ${NC}"
# ask user to proceed
read -p "Press enter to continue"
}

function run {
    SRC="$1"
    shift
    COPY_PROJECT=$1
    shift
    # TODO: get this from path
    GITHUB_FILENAMES=$1
    shift
    TOOL="$1"
    shift
    FILE="$1"
    shift
    # TODO: get from path if tigress or not and depending on this decide
    #if [ `wc -m $FILE | cut -d " " -f 1` -lt 900 ]; then
    #    return
    #fi
    if [ $COPY_PROJECT = true ];
    then
        SUBPATH="${FILE#"$SRC"}"
        #echo subpath0 "$SUBPATH" >&2
        PROJECT="$(echo $SUBPATH | cut -d"/" -f1-4)"
        ORIG_DIR="<path to github dump>"
        TMP="$(mktemp -d)"
        FILENAME="$TMP${FILE#"$SRC"}"
        #echo subpath1 "$SUBPATH" >&2
        if [ $GITHUB_FILENAMES = true ];
        then
            #echo "github filenames" >&2
            FILENAME="$(basename $FILE)"
            AUTHOR="$(echo $PROJECT | cut -d"/" -f1-2)"
            #echo author $AUTHOR >&2
            PROJECT="$(echo $FILENAME | cut -d"_" -f1 | sed "s;-SL-;/;g" | sed "s;-US-;_;g")"
            P2="$(echo $FILENAME | cut -d"_" -f2 | sed "s;-SL-;/;g" | sed "s;-US-;_;g")"
            EXTENSION="${FILENAME##*.}"
            PROJECT="$AUTHOR/$PROJECT"
            ORIG_DIR="$ORIG_DIR$PROJECT/$P2.$EXTENSION"
            SUBPATH="$PROJECT/$P2.$EXTENSION"
            FILENAME="$TMP$(dirname $SUBPATH)/$FILENAME"
        else
            ORIG_DIR="$ORIG_DIR${FILE#"$SRC"}"
            #echo subpath3 "$SUBPATH" >&2
        fi
        #echo file $FILE >&2
        #echo src $SRC >&2
        #echo orig "$ORIG_DIR" >&2
        #echo project "$PROJECT" >&2
        #echo subpath "$SUBPATH" >&2
        ORIG_DIR="$(dirname "$ORIG_DIR")"
        ORIG_DIR="$(echo "$ORIG_DIR" | sed 's/ /_/g')"
        FILTERED_DIR="/code-imitator/data/dataset_github/dataset_github_filtered$PROJECT"
        MACROS_DIR="$(echo $FILTERED_DIR | sed 's;github_filtered;github_filtered_macrosremoved;')"
        #echo filtered "$FILTERED_DIR" >&2
        #echo macros "$MACROS_DIR" >&2
        wd="$TMP$SUBPATH"
        TMP_DIR="$TMP$PROJECT"
        #echo tmpdir $TMP_DIR >&2
        mkdir -p "$TMP_DIR"
        TMP_DIR=${TMP_DIR%/*}
        #echo tmpdir $TMP_DIR >&2
        cp -r $FILTERED_DIR $TMP_DIR
        cp -r $MACROS_DIR $TMP_DIR
        cp $FILE "$FILENAME"
        #exit 1
        #echo orig "$ORIG_DIR" >&2
    else
        wd="$FILE"
    fi
    if grep -q "o___" "$FILE" ;
    then
        DEFINES="-DEXTRACTING"
    else
        DEFINES="-DEXTRACTING -include nocstd.h"
    fi
    if pcregrep --buffer-size $(expr 1024 "*" 1024 "*" 50) -M  "typedef [^;]* bool;" "$FILE" ;
    then
        DEFINES="$DEFINES -DBOOLTYPE"
    else
        if [[ ! "$FILE" = *bmpfile.h ]] ;
        then
            DEFINES="$DEFINES -DBOOLTYPE"
        fi
        DEFINES="-Dbool=_Bool -Dfalse=0 -Dtrue=1 $DEFINES"
    fi
    #wd="$(dirname "$2")"
    
    wd="$(dirname $wd)"
    #echo wd $wd >&2
    #echo "cd" "$ORIG_DIR" "&&" "$@" "-working-directory" "$ORIG_DIR" ${DEFINES} >&2
    if [ COPY_PROJECT ];
    then
        FILE="$FILENAME"
    fi
    #echo file $FILE >&2
    (cd "$wd" && "$TOOL" "$FILE" "$@" "-working-directory" "$wd" ${DEFINES})
    RET=$?
    # echo $RET >&2
    if [ ! $RET -eq 0 ]; then
        #rm "$FILE"
        echo > /dev/null
    fi
    if [ COPY_PROJECT ];
    then
        rm -rf $TMP
    fi
}

function run_lexems {
    SRC="$1"
    shift
    COPY_PROJECT=$1
    shift
    GITHUB_FILENAMES=$1
    shift
    TOOL="$1"
    shift
    FILE="$1"
    shift
    #if [ `wc -m $FILE | cut -d " " -f 1` -lt 900 ]; then
    #    return
    #fi
    if [ $COPY_PROJECT = true ];
    then
        SUBPATH="${FILE#"$SRC"}"
        PROJECT="$(echo $SUBPATH | cut -d"/" -f1-4)"
        ORIG_DIR="<collected github dump>"
        TMP="$(mktemp -d)"
        FILENAME="$TMP${FILE#"$SRC"}"
        if [ $GITHUB_FILENAMES = true ];
        then
            FILENAME="$(basename $FILE)"
            AUTHOR="$(echo $PROJECT | cut -d"/" -f1-2)"
            #echo author $AUTHOR >&2
            PROJECT="$(echo $FILENAME | cut -d"_" -f1 | sed "s;-SL-;/;g" | sed "s;-US-;_;g")"
            P2="$(echo $FILENAME | cut -d"_" -f2 | sed "s;-SL-;/;g" | sed "s;-US-;_;g")"
            EXTENSION="${FILENAME##*.}"
            PROJECT="$AUTHOR/$PROJECT"
            ORIG_DIR="$ORIG_DIR$PROJECT/$P2.$EXTENSION"
            SUBPATH="$PROJECT/$P2.$EXTENSION"
            FILENAME="$TMP$(dirname $SUBPATH)/$FILENAME"
        else
            ORIG_DIR="$ORIG_DIR${FILE#"$SRC"}"
        fi
        #echo orig "$ORIG_DIR" >&2
        #echo project "$PROJECT" >&2
        #echo subpath "$SUBPATH" >&2
        ORIG_DIR="$(dirname "$ORIG_DIR")"
        ORIG_DIR="$(echo "$ORIG_DIR" | sed 's/ /_/g')"
        FILTERED_DIR="/code-imitator/data/dataset_github/dataset_github_filtered$PROJECT"
        MACROS_DIR="$(echo $FILTERED_DIR | sed 's;github_filtered;github_filtered_macrosremoved;')"
        #echo filtered "$FILTERED_DIR" >&2
        #echo macros "$MACROS_DIR" >&2
        wd="$TMP$SUBPATH"
        TMP_DIR="$TMP$PROJECT"
        #echo tmpdir $TMP_DIR >&2
        mkdir -p "$TMP_DIR"
        TMP_DIR=${TMP_DIR%/*}
        #echo tmpdir $TMP_DIR >&2
        cp -r $FILTERED_DIR $TMP_DIR
        cp -r $MACROS_DIR $TMP_DIR
        cp $FILE "$FILENAME"
        #exit 1
        #echo orig "$ORIG_DIR" >&2
    else
        wd="$FILE"
    fi
    wd="$(dirname $wd)"
    #echo orig "$ORIG_DIR" >&2
    #wd="$(dirname "$2")"
    #echo "cd" "$ORIG_DIR" "&&" "$@" "-working-directory" "$ORIG_DIR" ${DEFINES} >&2
    if [ COPY_PROJECT ];
    then
        FILE="$FILENAME"
    fi
    
    (cd "$wd" && "$TOOL" "$FILE" "$@" -working-directory="$wd")
    RET=$?
    # echo $RET >&2
    if [ ! $RET -eq 0 ]; then
        #rm "$FILE"
        echo > /dev/null
    fi
    if [ COPY_PROJECT ];
    then
        rm -rf $TMP
    fi
}


# I. Get all features
echo -e "${RED}EXTRACT FEATURES...${NC}"
TOOL="feature_extraction_single"
#DEFINES="-DEXTRACTING -include nocstd.h -Dtrue=1 -Dfalse=0"
OPTIONS="-ast_node_bigram=True -ast_node_types=True -ast_node_types_avg_dep=True -max_depth_ast_node=True -code_in_ast_leaves=True -code_in_ast_leaves_avg_dep=True -lexical_features=True"

export -f run
find "${SRC}/" -type f -name "*.c" -o -name "*.cpp" -o -name "*.h" | parallel --bar --timeout ${MAX_TIME} -j ${MAX_JOBS} run "$SRC" $COPY_PROJECT $GITHUB_FILENAMES "${CMD_DIR}${TOOL}" "{}" "${OPTIONS}" -- "${COMPILER_FLAG}" "${DEFINES}" > ${OUTPUT_DIR}/"features_temp.dat"
    
#make_pause

# II. Split features to invidual files
echo -e "${RED}SPLIT FEATURES TO INDIVIDUAL FILES...${NC}"

# fct takes output file name, greps for it in feature extraction output, removes it from output and pipes filtered lines into output file:
function split { # takes one parameter
	PATTERN="$1 ::--::"
	cat ${OUTPUT_DIR}/"features_temp.dat" | grep "${PATTERN}" | sed "s/^\(${PATTERN}\)//" > ${OUTPUT_DIR}/$1

    # sort in-place with -o
    sort -o ${OUTPUT_DIR}/$1 ${OUTPUT_DIR}/$1
}  


PAT="ast_node_types.dat"
split $PAT

PAT="ast_node_types_avg_dep.dat"
split $PAT

PAT="max_depth_ast_node.dat"
split $PAT

PAT="ast_node_bigram.dat"
split $PAT

PAT="code_in_ast_leaves.dat"
split $PAT

PAT="code_in_ast_leaves_avg_dep.dat"
split $PAT

PAT="lexical_features.dat"
split $PAT

#rm ${OUTPUT_DIR}/"features_temp.dat"

#make_pause

# III. Extract lexems
echo -e "${RED}NEXT, GET LEXEMS...${NC}"
export -f run_lexems
find "${SRC}/" -type f -name "*.c" -o -name "*.cpp" -o -name "*.h" | parallel --bar --timeout ${MAX_TIME} -j ${MAX_JOBS}\
    run_lexems "$SRC" $COPY_PROJECT $GITHUB_FILENAMES "${CMD_DIR_LEXEMS}get_lexems_features" "{}" -- "${COMPILER_FLAG}" > ${OUTPUT_DIR}/"lexems_features.dat"

sort -o ${OUTPUT_DIR}/"lexems_features.dat" ${OUTPUT_DIR}/"lexems_features.dat"

make_pause

# IV. Extract lexical and layout features via the Java Implementation
echo -e "${RED}FINALLY, GET LEXICAL - LAYOUT FEATURES FROM USENIX' PAPER JAVA IMPLEMENTATION...${NC}"

java -jar "${CMD_DIR_NAIVEBASELINE}" ${SRC} ${OUTPUT_DIR}/"lexical_features.arff"
