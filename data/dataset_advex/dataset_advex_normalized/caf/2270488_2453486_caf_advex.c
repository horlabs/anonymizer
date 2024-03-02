#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int func_0(char var_0) { return var_0 == 'X' || var_0 == 'T'; }

static int func_1(char var_1) { return var_1 == 'O' || var_1 == 'T'; }

static void func_2(int var_2) {
    char var_3[4][4];
    int var_4;
    int var_5;

    int var_6 = 0;
    int var_7 = 0;
    int var_8 = 0;

    int var_9 = 1;
    int var_10 = 1;
    int var_11 = 1;
    int var_12 = 1;

    scanf(" %4c %4c %4c %4c", var_3[0], var_3[1], var_3[2], var_3[3]);

    for (var_4 = 0; var_4 < 4; var_4++) {

        int var_13 = 1;
        int var_14 = 1;
        int var_15 = 1;
        int var_16 = 1;

        for (var_5 = 0; var_5 < 4; var_5++) {
            var_6 = var_6 || var_3[var_4][var_5] == '.';

            var_13 = var_13 && func_0(var_3[var_5][var_4]);
            var_14 = var_14 && func_1(var_3[var_5][var_4]);

            var_15 = var_15 && func_0(var_3[var_4][var_5]);
            var_16 = var_16 && func_1(var_3[var_4][var_5]);
        }

        var_7 = var_7 || var_13 || var_15;
        var_8 = var_8 || var_14 || var_16;

        var_9 = var_9 && func_0(var_3[var_4][var_4]);
        var_10 = var_10 && func_1(var_3[var_4][var_4]);

        var_11 = var_11 && func_0(var_3[3 - var_4][var_4]);
        var_12 = var_12 && func_1(var_3[3 - var_4][var_4]);
    }

    var_7 = var_7 || var_9 || var_11;
    var_8 = var_8 || var_10 || var_12;

    printf("Case #%d: %s\n", var_2 + 1,
           var_7   ? "X won"
           : var_8 ? "O won"
           : var_6 ? "Game has not completed"
                   : "Draw");
    return;
}

int main(int argc, char **argv) {
    int var_17;
    int var_18;

    scanf("%d", &var_17);

    for (var_18 = 0; var_18 < var_17; var_18++) {
        func_2(var_18);
    }

    return 0;
}
