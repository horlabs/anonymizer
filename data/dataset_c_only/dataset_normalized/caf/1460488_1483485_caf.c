#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func_0(int var_0) {
    static const char *const var_1 = "abcdefghijklmnopqrstuvwxyz";
    static const char *const var_2 = "ynficwlbkuomxsevzpdrjgthaq";
    const char *const var_3 = strchr(var_2, var_0);

    if (var_3) {
        return var_1[var_3 - var_2];
    } else {
        return var_0;
    }
}

void func_1(int var_4) {
    int var_5;

    printf("Case #%d: ", var_4 + 1);

    do {
        var_5 = getchar();

        if (var_5 == EOF) {
            break;
        } else {

            if (isupper(var_5)) {
                putchar(toupper(func_0(tolower(var_5))));
            } else {
                putchar(func_0(var_5));
            }
        }
    } while (var_5 != '\n');
    return;
}

int main(int argc, char **argv) {
    int var_6;
    int var_7;
    int var_8;

    scanf("%d", &var_6);
    do {
        var_8 = getchar();
    } while (var_8 != EOF && var_8 != '\n');

    for (var_7 = 0; var_7 < var_6; var_7++) {
        func_1(var_7);
    }

    return 0;
}
