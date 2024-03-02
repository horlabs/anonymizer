#include <stdio.h>
#include <stdlib.h>

int func_0(const void *var_0, const void *var_1) {
    if (*(int *)var_0 > *(int *)var_1) {
        return -1;
    } else {
        if (*(int *)var_0 < *(int *)var_1) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main(int argc, char **argv) {
    int var_2;
    int var_3 = 1;

    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8;

    int var_9;
    int var_10[100];
    int var_11;

    scanf("%d", &var_2);
    while (var_2--) {
        scanf("%d %d %d", &var_4, &var_5, &var_6);
        for (var_9 = 0; var_9 < var_4; var_9++) {
            scanf("%d", &var_10[var_9]);
        }
        qsort(var_10, var_4, sizeof(int), func_0);
        var_7 = var_6 - 1;
        var_8 = var_6 - 2;
        if (var_7 < 0) {
            var_7 = 0;
        }
        if (var_8 < 0) {
            var_8 = 0;
        }
        for (var_11 = var_9 = 0; var_9 < var_4; var_9++) {
            if (var_10[var_9] >= var_6 + var_7 + var_7) {
                var_11++;
            } else {
                if (var_5 && var_10[var_9] >= var_6 + var_8 + var_8) {
                    var_11++;
                    var_5--;
                }
            }
        }
        printf("Case #%d: %d\n", var_3++, var_11);
    }
    return 0;
}
