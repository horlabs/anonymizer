#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int var_0;
int var_1;
int var_2;
int var_3[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
int var_4[1234];
int var_5;

int func_0(const void *var_6, const void *var_7) {
    return *(int *)var_6 - *(int *)var_7;
}
int func_1(int var_8) {
    int var_9;
    int var_10 = 0;
    var_5 = 0;
    for (var_9 = 1; var_9 < var_2; ++var_9) {
        var_4[var_5] =
            var_8 % var_3[var_9] * var_3[var_2 - var_9] + var_8 / var_3[var_9];
        if (var_4[var_5] >= var_0 && var_4[var_5] <= var_1 &&
            var_4[var_5] < var_8) {
            ++var_5;
        }
    }
    qsort(var_4, var_5, sizeof(int), func_0);
    var_10 = var_5 > 0;
    for (var_9 = 1; var_9 < var_5; ++var_9) {
        if (var_4[var_9] != var_4[var_9 - 1]) {
            ++var_10;
        }
    }

    return var_10;
}

int main(int argc, char **argv) {
    int var_11;
    int var_12;
    int var_13;
    int var_14 = 0;
    scanf("%d", &var_11);
    while (var_11--) {
        scanf("%d %d", &var_0, &var_1);
        for (var_12 = var_0, var_2 = 0; var_12 > 0;
             var_12 = var_12 / 10, ++var_2) {
            ;
        }
        for (var_12 = var_0, var_13 = 0; var_12 <= var_1; ++var_12) {
            var_13 = var_13 + func_1(var_12);
        }
        printf("Case #%d: %d\n", ++var_14, var_13);
    }

    return 0;
}
