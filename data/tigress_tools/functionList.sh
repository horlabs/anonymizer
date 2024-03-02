#!/usr/bin/env bash
SCRIPT_PATH="$(dirname $(realpath -s "$0"))"

list=$(grep -Pzo "\n(static)? *(inline)? *((long|unsigned|signed) )*[a-zA-Z0-9_]+[ *]+[a-zA-Z0-9\$_]+\([^};]*?\) *\{" "$1" | tr -d '\0' | tr '\n' ' ' | sed 's/ \+/ /g' | sed "s/{/{\n/g" | grep -v "static *inline" | grep -v "#pragma " | sort | uniq )
#qsort=$(grep "qsort\(.*\)" $1)
#qsort=${qsort##*, }
#qsort=${qsort##*&}
#qsort=${qsort%%)*}
#echo "$qsort"
ignore_funcs="wstr_keycompare,bftreeSdsKeyCompare,dictSdsDestructor,dictSdsHash,dictSdsKeyCompare"
qsort="$($SCRIPT_PATH/get_qsort_callback.py "$1")"
if [ "$qsort" = ",NULL" ] || [ "$qsort" = ",null" ] || [ "$qsort" = ",const void *" ]; then
    qsort=""
fi
funcs=""
while read -r line; do
    if [[ "$line" == *"..."* ]];
    then
        continue
    fi
    line=${line#* }
    line=${line%%(*}
    line=${line##* }
    line=$(echo $line | sed 's/^\**//g')
    if [ "$line" != "main" ] && [ "$line" != "mainf" ] && [ "$line" != "if" ] && [ -z "$(grep -Ff <(printf "%s\n" ${line}) <(printf "%s\n" ${qsort//,/ }))" ] && [ "$line" != "init_extern" ]; then
        if [ "$line" = "" ] || [[ $(echo ${ignore_funcs} | grep -w $line) ]];
        then
            continue
        fi
        funcs+="$line,"
    fi
    # echo "$line"
done <<< "$list"
funcs=${funcs%*,}

if [ "$funcs" = "" ];
then
    exit 1
else
    echo "$funcs"
fi
