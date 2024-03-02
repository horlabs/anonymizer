#include <math.h>
#include <stdio.h>

int var_0[10000000 + 1];

int func_0(long long var_1) {
    int var_2[1000];
    int var_3 = 0;
    int var_4;

    while (var_1) {
        var_2[var_3++] = var_1 % 10;
        var_1 = var_1 / 10;
    }

    for (var_4 = 0; 2 * var_4 < var_3 - 1; var_4++) {
        if (var_2[var_4] != var_2[var_3 - var_4 - 1]) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char **argv) {
    long long var_5;
    int var_6 = 0;
    var_0[0] = 0;
    for (var_5 = 1; var_5 <= 10000000; var_5++) {
        if (func_0(var_5) && func_0(var_5 * var_5)) {

            var_6++;
        }
        var_0[var_5] = var_6;
    }
    int var_7;
    int var_8;

    scanf("%d", &var_8);
    for (var_7 = 1; var_7 <= var_8; var_7++) {
        long long var_9;
        long long var_10;

        scanf("%lld %lld", &var_9, &var_10);
        var_9 = sqrt(var_9 - 1);
        var_10 = sqrt(var_10);
        printf("Case #%d: %d\n", var_7, var_0[var_10] - var_0[var_9]);
    }
    return 0;
}
