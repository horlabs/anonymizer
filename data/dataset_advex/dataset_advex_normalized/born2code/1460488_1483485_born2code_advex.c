#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char func_0(char var_0) {
    if (var_0 == ('a')) {
        return 'y';

    } else if (var_0 == ('b')) {
        return 'h';

    } else if (var_0 == ('c')) {
        return 'e';

    } else if (var_0 == ('d')) {
        return 's';

    } else if (var_0 == ('e')) {
        return 'o';

    } else if (var_0 == ('f')) {
        return 'c';

    } else if (var_0 == ('g')) {
        return 'v';

    } else if (var_0 == ('h')) {
        return 'x';

    } else if (var_0 == ('i')) {
        return 'd';

    } else if (var_0 == ('j')) {
        return 'u';

    } else if (var_0 == ('k')) {
        return 'i';

    } else if (var_0 == ('l')) {
        return 'g';

    } else if (var_0 == ('m')) {
        return 'l';

    } else if (var_0 == ('n')) {
        return 'b';

    } else if (var_0 == ('o')) {
        return 'k';

    } else if (var_0 == ('p')) {
        return 'r';

    } else if (var_0 == ('q')) {
        return 'z';

    } else if (var_0 == ('r')) {
        return 't';

    } else if (var_0 == ('s')) {
        return 'n';

    } else if (var_0 == ('t')) {
        return 'w';

    } else if (var_0 == ('u')) {
        return 'j';

    } else if (var_0 == ('v')) {
        return 'p';

    } else if (var_0 == ('w')) {
        return 'f';

    } else if (var_0 == ('x')) {
        return 'm';

    } else if (var_0 == ('y')) {
        return 'a';

    } else if (var_0 == ('z')) {
        return 'q';
    }
    return ' ';
}
int main(int argc, char **argv) {
    int var_1;
    int var_2;
    int var_3;
    int var_4;

    char var_5[200];
    char var_6[200];

    scanf("%d", &var_1);
    scanf("%*c");
    for (var_2 = 1; var_2 <= var_1; var_2++) {
        gets(var_5);
        for (var_3 = 0; var_5[var_3] != '\0'; var_3++) {
            var_6[var_3] = func_0(var_5[var_3]);
        }
        var_6[var_3] = '\0';
        printf("Case #%d: %s\n", var_2, var_6);
    }
    return 0;
}
