#include <stdio.h>

long long func_0(long long var_0) {
    long long var_1 = 0;
    while (var_0 > 0) {
        var_1 = (10 * var_1) + (var_0 % 10);
        var_0 = var_0 / 10;
    }
    return var_1;
}

long long var_2[39];

int main(int argc, char **argv) {
    int var_3 = 0;
    for (long long var_4 = 1; var_4 <= 10000000; var_4++) {
        if (var_4 != func_0(var_4)) {
            continue;
        } else {
            long long var_5 = var_4 * var_4;
            if (var_5 != func_0(var_5)) {
                continue;
            } else {
                var_2[var_3++] = var_4 * var_4;
            }
        }
    }
    int var_6;
    scanf("%d", &var_6);
    for (int var_7 = 1; var_7 <= var_6; var_7++) {
        long long var_8;
        long long var_9;

        scanf("%lld %lld", &var_8, &var_9);
        int var_10 = 0;
        for (int var_11 = 0; var_11 < var_3; var_11++) {
            if (var_2[var_11] >= var_8 && var_2[var_11] <= var_9) {
                var_10++;
            }
        }
        printf("Case #%d: %d\n", var_7, var_10);
    }
    return 0;
}
