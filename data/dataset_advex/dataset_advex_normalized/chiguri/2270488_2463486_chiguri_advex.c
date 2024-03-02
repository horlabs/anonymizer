#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char var_0[10];

int func_0(int var_1) {
    int var_2;
    int var_3;

    sprintf(var_0, "%d", var_1);
    var_2 = strlen(var_0) - 1;
    for (var_3 = 0; var_3 <= var_2 - var_3; ++var_3) {
        if (var_0[var_3] != var_0[var_2 - var_3]) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argvvoid) {
    int var_4;
    int var_5;
    int var_6;

    int var_7;
    int var_8;

    int var_9;
    int var_10;
    int var_11;

    int var_12;

    scanf("%d", &var_4);
    for (var_9 = 1; var_9 <= var_4; ++var_9) {
        scanf("%d %d", &var_5, &var_6);
        var_12 = 0;
        var_7 = (int)sqrt((double)var_5);
        var_8 = (int)sqrt((double)var_6);
        for (var_10 = var_7; var_10 <= var_8; ++var_10) {
            if (func_0(var_10)) {
                var_11 = var_10 * var_10;
                if (var_5 <= var_11 && var_11 <= var_6 && func_0(var_11)) {
                    ++var_12;
                }
            }
        }

        printf("Case #%d: %d\n", var_9, var_12);
    }

    return 0;
}
