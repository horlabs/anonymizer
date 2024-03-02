#include <stdio.h>

int func_0(long long var_0) {
    int var_1;
    int var_2;

    int var_3[20];

    for (var_1 = 0; var_0 > 0; var_1++) {
        var_3[var_1] = var_0 % 10;
        var_0 = var_0 / 10;
    }

    for (var_2 = 0; var_2 < var_1 / 2; var_2++) {
        if (var_3[var_2] != var_3[var_1 - var_2 - 1]) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char **argv) {
    int var_4 = 0;
    int var_5;
    int var_6;

    long long var_7[100];

    for (var_6 = 1; var_6 <= 10000000; var_6++) {
        if (func_0(var_6) && func_0((long long)var_6 * var_6)) {
            var_7[var_4++] = (long long)var_6 * var_6;
        }
    }

    scanf("%d", &var_5);

    for (var_6 = 0; var_6 < var_5; var_6++) {
        int var_8 = 0;
        int var_9;

        long long var_10;
        long long var_11;

        scanf("%lld %lld", &var_10, &var_11);

        for (var_9 = 0; var_9 < var_4; var_9++) {
            if (var_7[var_9] >= var_10 && var_7[var_9] <= var_11) {
                var_8++;
            }
        }

        printf("Case #%d: %d\n", var_6 + 1, var_8);
    }

    return 0;
}
