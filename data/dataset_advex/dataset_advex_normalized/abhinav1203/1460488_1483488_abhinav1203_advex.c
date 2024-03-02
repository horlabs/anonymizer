#include <stdio.h>
#include <stdlib.h>

int func_0(const void *var_0, const void *var_1) {
    if (*(int *)var_0 < *(int *)var_1) {
        return -1;
    } else {
        return 1;
    }
}
int func_1(int var_2) {
    int var_3 = 0;
    while (var_2 > 0) {
        var_3++;
        var_2 = var_2 / 10;
    }
    return var_3;
}
int func_2(int var_4) {
    int var_5 = 1;
    int var_6;

    for (var_6 = 0; var_6 < var_4; var_6++) {
        var_5 = var_5 * 10;
    }
    return var_5;
}
int main(int argc, char **argv) {
    int var_7;
    int var_8;
    int var_9;
    int var_10;
    int var_11;
    int var_12;
    int var_13;
    int var_14;
    int var_15[100];
    int var_16 = 1;

    scanf("%d", &var_7);
    while (var_7--) {
        scanf("%d %d", &var_8, &var_9);
        var_14 = 0;
        for (var_10 = var_8; var_10 <= var_9; var_10++) {
            var_15[0] = var_10;
            var_12 = func_1(var_10);
            var_13 = func_2(var_12 - 1);
            for (var_11 = 1; var_11 < var_12; var_11++) {
                var_15[var_11] =
                    var_15[var_11 - 1] / 10 + var_15[var_11 - 1] % 10 * var_13;
            }
            qsort(var_15, var_12, sizeof(int), &func_0);
            for (var_11 = 0; var_11 < var_12; var_11++) {
                if (var_15[var_11] >= var_8 && var_15[var_11] <= var_9 &&
                    (var_11 == 0 || var_15[var_11] != var_15[var_11 - 1]) &&
                    var_15[var_11] != var_10) {
                    var_14++;
                }
            }
        }
        printf("Case #%d: %d\n", var_16, var_14 / 2);
        var_16++;
    }
    return 0;
}
