#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func_0(long long var_0) {
    char var_1[100];
    sprintf(var_1, "%lld", var_0);
    int var_2;
    int var_3;

    var_3 = strlen(var_1);
    int var_4 = 1;
    for (var_2 = 0; var_2 < var_3; var_2++) {
        if (var_1[var_2] != var_1[var_3 - 1 - var_2]) {
            var_4 = 0;
        }
    }
    return var_4;
}

int main(int var_5, char **var_6) {
    int var_7;
    int var_8;

    long long var_9;
    long long var_10;
    long long var_11;
    long long var_12;
    long long var_13;
    long long var_14;

    double var_15;
    double var_16;

    scanf("%d\n", &var_8);
    for (var_7 = 1; var_7 <= var_8; var_7++) {
        int var_17 = 0;
        scanf("%lld %lld\n", &var_9, &var_10);
        var_15 = (double)var_9;
        var_16 = (double)var_10;
        var_11 = sqrt(var_15) - 1;
        var_12 = sqrt(var_16) + 1;
        if (var_11 < 1) {
            var_11 = 1;
        }
        for (var_13 = var_11; var_13 <= var_12; var_13++) {
            var_14 = var_13 * var_13;
            if ((var_9 <= var_14 && var_14 <= var_10) &&
                (func_0(var_13) && func_0(var_14))) {
                var_17++;
            }
        }
        printf("Case #%d: %d\n", var_7, var_17);
    }
    return 0;
}
