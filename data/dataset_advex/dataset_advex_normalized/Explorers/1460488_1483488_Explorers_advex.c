#include <math.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4[50] = {0};

    long long var_5;
    long long var_6;
    long long var_7;
    long long var_8;
    long long var_9;
    long long var_10;
    long long var_11;
    long long var_12;

    scanf("%d", &var_0);

    for (var_1 = 0; var_1 < var_0; var_1++) {
        scanf("%ld %ld", &var_5, &var_6);
        var_2 = func_0(var_5);

        for (var_7 = var_5; var_7 < var_6; var_7++) {

            for (var_3 = var_2 - 1; var_3 >= 1; var_3--) {
                var_9 = pow(10, var_3);
                var_8 = pow(10, var_2 - var_3);

                var_11 = var_7 / var_8;
                var_10 = var_7 % var_8;
                var_12 = var_10 * var_9 + var_11;

                if (func_0(var_12) != var_2) {
                    continue;
                } else {

                    if (var_12 > var_7 && var_12 <= var_6) {

                        var_4[var_1]++;
                    }
                }
            }
        }
    }
    for (var_1 = 0; var_1 < var_0; var_1++) {
        printf("Case #%d: %d\n", var_1 + 1, var_4[var_1]);
    }
    return 0;
}

int func_0(long long var_13) {
    if (var_13 < 10) {
        return 1;
    } else {
        return 1 + func_0(var_13 / 10);
    }
}
