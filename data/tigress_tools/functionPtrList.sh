#!/usr/bin/env bash
SCRIPT_PATH="$(dirname $(realpath -s "$0"))"

list=$(grep -Pzo "(static)? *(inline)? *(long|unsigned|signed)? *[a-zA-Z0-9_]+[ *]+[a-zA-Z0-9\$_]+\([^};]*?\) *\{" $1 | tr -d '\0' | tr '\n' ' ' | sed 's/ \+/ /g' | sed "s/{/{\n/g" | grep -v "static *inline" | grep -v "#pragma " | sort | uniq )
#qsort=$(grep "qsort\(.*\)" $1)
#qsort=${qsort##*, }
#qsort=${qsort##*&}
#qsort=${qsort%%)*}
#echo "$qsort"
lines_without="$(cat $1 | tr '\n' ' ')"
while read -r line;
do
    line="$(echo $line | sed -e 's/[]\/$*.^[]/\\&/g')"
    line="${line%%(*}"
    lines_without="$(echo $lines_without | sed "s/$line//g")"
done <<< "$list"
qsort="$($SCRIPT_PATH/get_qsort_callback.py "$1")"
if [ "$qsort" = ",NULL" ] || [ "$qsort" = ",null" ] || [ "$qsort" = ",const void *" ]; then
    qsort=""
fi
funcs=""
while read -r line; do
    orig="$line"
    line=${line#* }
    line=${line%%(*}
    line=${line##* }
    line=$(echo $line | sed 's/^\**//g')
    if [ "$line" != "main" ] && [ "$line" != "mainf" ] && [ -z "$(grep -Ff <(printf "%s\n" ${line}) <(printf "%s\n" ${qsort//,/ }))" ] && [ "$line" != "init_extern" ] && [ -n "$(echo $lines_without | grep "*$line\b")" ]; then
        funcs+="$line,"
    fi
    if [[ "$orig" == *"..."* ]];
    then
        funcs+="$line,"
    fi
    # echo "$line"
done <<< "$list"
funcs=${funcs%*,}
echo "$funcs"
