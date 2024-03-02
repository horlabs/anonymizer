#include <stdio.h>

int var_0[10000000];

int func_0(int var_1) {
    int var_2[10] = {0};
    int var_3;
    int var_4;

    while (var_1) {
        var_2[var_1 % 10]++;
        var_1 = var_1 / 10;
    }
    var_3 = 0;
    for (var_4 = 9; var_4 >= 0; var_4--) {
        while (var_2[var_4]--) {
            var_3 = 10 * var_3 + var_4;
        }
    }
    return var_3;
}

int main(int argc, char **argv) {
    int var_5;
    int var_6;

    scanf("%d", &var_5);

    for (var_6 = 1; var_6 <= var_5; var_6++) {
        int var_7;
        int var_8;
        int var_9;
        int var_10 = 0;

        int var_11 = 0;
        int var_12 = 1;
        scanf("%d %d", &var_8, &var_9);
        int var_13 = var_8;

        while (var_13) {
            var_11++;
            var_12 = var_12 * 10;
            var_13 = var_13 / 10;
        }
        var_12 = var_12 / 10;

        for (var_7 = var_8; var_7 <= var_9; var_7++) {
            int var_14[10];
            int var_15 = 0;
            int var_16;

            var_13 = var_7;
            for (var_16 = 0; var_16 < var_11; var_16++) {
                var_13 = var_12 * (var_13 % 10) + var_13 / 10;
                if (var_13 < var_7 && !var_0[var_13] && var_13 >= var_8 &&
                    var_13 <= var_9) {
                    var_0[var_13] = 1;
                    var_14[var_15++] = var_13;
                    var_10++;
                }
            }
            for (var_16 = 0; var_16 < var_15; var_16++) {
                var_0[var_14[var_16]] = 0;
            }
        }
        printf("Case #%d: %d\n", var_6, var_10);
    }

    return 0;
}
