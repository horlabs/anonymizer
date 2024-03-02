#include <math.h>
#include <stdio.h>
#include <stdlib.h>
char var_0[20];

int func_0(int var_1) {
    int var_2;
    int var_3;

    var_2 = 0;
    while (var_1) {
        var_0[var_2++] = var_1 % 10;
        var_1 = var_1 / 10;
    }
    var_2--;
    for (var_3 = 0; var_3 < var_2; var_3++, var_2--) {
        if (var_0[var_3] != var_0[var_2]) {
            return 0;
        }
    }
    return 1;
}

int func_1(long long var_4) {
    int var_5;
    int var_6;

    var_5 = 0;
    while (var_4) {
        var_0[var_5++] = var_4 % 10;
        var_4 = var_4 / 10;
    }
    var_5--;
    for (var_6 = 0; var_6 < var_5; var_6++, var_5--) {
        if (var_0[var_6] != var_0[var_5]) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv) {
    long long var_7;
    long long var_8;

    int var_9;
    int var_10;
    int *var_11;

    int var_12;
    int var_13;
    int var_14;

    var_11 = malloc(10000001 * sizeof(int));
    {
        if (!(var_11 != NULL)) {
            fprintf(stderr, "%s\n", "Out of memory!");
            exit(-1);
        }
    };

    var_11[0] = 1;
    for (var_14 = 1; var_14 <= 10000000; var_14++) {
        if (func_0(var_14) && func_1(((long long)var_14) * var_14)) {
            var_11[var_14] = var_11[var_14 - 1] + 1;
        } else {
            var_11[var_14] = var_11[var_14 - 1];
        }
    }
    scanf("%d", &var_9);
    for (var_10 = 1; var_10 <= var_9; var_10++) {
        scanf("%lld %lld", &var_7, &var_8);
        var_12 = ceil(sqrt((double)var_7));
        var_13 = sqrt((double)var_8);
        printf("Case #%d: %d\n", var_10, var_11[var_13] - var_11[var_12 - 1]);
    }
    return 0;
}
