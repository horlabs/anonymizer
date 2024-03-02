#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int func_0(unsigned long long var_0) {
    char var_1[100];
    int var_2;
    int var_3;
    int var_4;

    sprintf(var_1, "%lu ", var_0);
    var_3 = strlen(var_1) - 1;
    var_4 = var_3 / 2;

    for (var_2 = 0; var_2 < var_4; var_2++) {
        if (var_1[var_2] != var_1[var_3 - 1 - var_2]) {
            return 0;
        }
    }
    return 1;
}

int main(int var_5, char **var_6) {
    int var_7;
    int var_8;
    int var_9;

    char var_10[10];
    unsigned long long var_11;
    unsigned long long var_12;
    unsigned long long var_13;
    unsigned long long var_14;
    unsigned long long var_15;

    assert(scanf("%d ", &var_7) == 1);
    for (var_8 = 1; var_8 <= var_7; var_8++) {
        var_9 = 0;
        assert(scanf("%lu %lu ", &var_11, &var_12) == 2);
        var_13 = ceil(sqrt(var_11));
        var_14 = floor(sqrt(var_12));

        for (var_15 = var_13; var_15 <= var_14; var_15++) {
            if (func_0(var_15) && func_0(var_15 * var_15)) {
                var_9++;
            }
        }

        printf("Case #%d: %d\n", var_8, var_9);
    }
    return 0;
}
