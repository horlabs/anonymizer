#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int func_0(int);
int main(int argc, char **argv) {
    FILE *var_0;
    FILE *var_1;

    int var_2;
    int var_3 = 10;
    int var_4 = 120;
    int var_5;
    int var_6;
    int var_7;
    int var_8;

    var_0 = fopen("C-small-attempt0(1).in", "r");
    var_1 = fopen("output.txt", "w");
    fscanf(var_0, "%d", &var_5);
    for (var_7 = 1; var_7 <= var_5; var_7++) {
        fscanf(var_0, "%d %d", &var_3, &var_4);
        var_8 = 0;
        for (var_2 = var_3; var_2 <= var_4; var_2++) {
            if (func_0(var_2)) {
                var_6 = (int)sqrt((double)var_2);
                if (var_6 * var_6 == var_2) {
                    if (func_0(var_6)) {
                        var_8++;
                    }
                } else {
                    if (((var_6 + 1) * (var_6 + 1) == var_2) && func_0(var_6)) {
                        var_8++;
                    }
                }
            }
        }
        fprintf(var_1, "Case #%d: %d\n", var_7, var_8);
    }
    fclose(var_0);
    fclose(var_1);
    system("pause");
    return 0;
}

int func_0(int var_9) {
    int var_10;
    int var_11;
    int var_12 = 0;

    var_10 = var_9;
    while (var_9 > 0) {
        var_11 = var_9 % 10;
        var_12 = var_11 + var_12 * 10;
        var_9 = var_9 / 10;
    }
    if (var_10 == var_12) {
        return 1;
    } else {
        return 0;
    }
}
