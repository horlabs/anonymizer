#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3 = 0;

    long long var_4[39];
    for (var_2 = 1; var_2 <= 2001002; ++var_2) {
        char var_5[21] = {};
        long long var_6 = (long long)var_2 * var_2;
        long long var_7 = (long long)var_2 * var_2;

        int var_8 = 0;
        while (var_7) {
            var_5[var_8++] = var_7 % 10 + '0';
            var_7 = var_7 / 10;
        }
        sscanf(var_5, "%I64d", &var_7);
        if (var_6 == var_7) {
            char var_9[21] = {};
            var_7 = var_2;
            var_8 = 0;
            while (var_7) {
                var_9[var_8++] = var_7 % 10 + '0';
                var_7 = var_7 / 10;
            }
            sscanf(var_9, "%I64d", &var_7);
            if (var_2 == var_7) {
                var_4[var_3++] = var_6;
            }
        }
    }
    scanf("%d", &var_0);
    for (var_1 = 1; var_1 <= var_0; ++var_1) {
        long long var_10;
        long long var_11;

        int var_12;
        int var_13;
        int var_14;
        int var_15;
        int var_16;

        scanf("%I64d%I64d", &var_10, &var_11);
        for (var_12 = 0, var_13 = 39; var_12 < var_13;) {
            var_14 = (var_12 + var_13) / 2;
            if (var_4[var_14] == var_10) {
                var_12 = var_14;
                break;
            } else {
                if (var_4[var_14] < var_10) {
                    var_12 = var_14 + 1;
                } else {
                    var_13 = var_14;
                }
            }
        }
        var_15 = var_12;
        for (var_12 = 0, var_13 = 39; var_12 < var_13;) {
            var_14 = (var_12 + var_13) / 2;
            if (var_4[var_14] <= var_11) {
                var_12 = var_14 + 1;
            } else {
                var_13 = var_14;
            }
        }
        var_16 = var_12;
        printf("Case #%d: %d\n", var_1, var_16 - var_15);
    }
    return 0;
}
