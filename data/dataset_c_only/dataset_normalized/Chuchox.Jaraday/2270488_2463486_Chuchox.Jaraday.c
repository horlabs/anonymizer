#include <math.h>
#include <stdio.h>

int func_0(long long var_0);

int main(int argc, char **argvvoid) {
    long long var_1;
    long long var_2;
    long long var_3;
    long long var_4;

    long long var_5;
    long long var_6;
    long long var_7;
    long long var_8;
    long long var_9;

    scanf("%I64d", &var_1);
    for (var_2 = 1; var_2 <= var_1; var_2++) {
        scanf("%I64d %I64d", &var_5, &var_6);

        var_7 = sqrt(var_5);
        var_8 = sqrt(var_6);
        if (var_7 * var_7 < var_5) {
            var_7++;
        }

        var_9 = 0;
        for (var_3 = var_7; var_3 <= var_8; var_3++) {
            if (func_0(var_3) && func_0(var_3 * var_3)) {

                var_9++;
            }
        }

        printf("Case #%I64d: %I64d\n", var_2, var_9);
    }
    return 0;
}

int func_0(long long var_0) {
    long long var_10[110];
    long long var_11;
    long long var_12;

    var_11 = 0;
    while (var_0) {
        var_10[var_11] = var_0 % 10;
        var_0 = var_0 / 10;
        var_11++;
    }
    var_12 = var_11 - 1;
    var_11 = 0;
    while (var_11 <= (var_12 - var_11)) {
        if (var_10[var_11] != var_10[var_12 - var_11]) {
            return 0;
        } else {
            var_11++;
        }
    }
    return 1;
}
