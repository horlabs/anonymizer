#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int func_0(int);
int func_1(int, int);

int main(int argc, char **argvvoid) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6[8];
    int var_7;
    int var_8;
    int var_9;
    int var_10;
    int var_11;

    FILE *var_12 = fopen("C-small-attempt0.in", "r");
    FILE *var_13 = fopen("out.txt", "w");

    fscanf(var_12, "%d", &var_9);

    for (var_0 = 0; var_0 < var_9; var_0++) {
        fscanf(var_12, "%d%d\n", &var_10, &var_11);
        for (var_5 = 0, var_3 = func_0(var_10), var_7 = var_10; var_7 < var_11;
             var_7++) {
            for (var_4 = 0, var_1 = 1; var_1 < var_3; var_1++) {
                var_8 = var_7 % func_1(10, var_1) * func_1(10, var_3 - var_1) +
                        var_7 / func_1(10, var_1);
                if (var_8 > var_7 && var_8 <= var_11) {
                    for (var_2 = 0; var_2 < var_4 && var_6[var_2] != var_8;
                         var_2++) {
                        ;
                    }
                    if (var_2 == var_4) {
                        var_6[var_4++] = var_8;
                        var_5 = var_5 + 1;
                    }
                }
            }
        }
        fprintf(var_13, "Case #%d: %d\n", var_0 + 1, var_5);
    }

    fclose(var_12);
    fclose(var_13);
    return 0;
}

int func_0(int var_14) { return var_14 ? 1 + func_0(var_14 / 10) : 0; }

int func_1(int var_15, int var_16) {
    int var_17;
    for (var_17 = var_15, var_15 = 1; --var_16 >= 0; var_15 = var_15 * var_17) {
        ;
    }
    return var_15;
}
