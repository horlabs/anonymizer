#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int func_0(int var_0, int var_1, int var_2) {
    int var_3;
    int var_4 = 1;
    int var_5 = 1;
    int var_6;

    var_6 = var_2 - var_1;
    while (var_6--) {
        var_4 = var_4 * 10;
    }
    while (var_1--) {
        var_5 = var_5 * 10;
    }
    var_3 = (var_0 % var_4) * var_5 + (var_0 / var_4);
    return var_3;
}

int main(int var_7, char **var_8) {
    int var_9;
    int var_10;
    int var_11;
    int var_12;
    int var_13;
    int var_14;
    int var_15;
    int var_16;
    int var_17;
    int var_18;

    int var_19;

    assert(scanf("%d", &var_11) == 1);
    for (var_12 = 1; var_12 <= var_11; var_12++) {
        var_17 = 0;
        assert(scanf("%d %d", &var_9, &var_10) == 2);
        for (var_13 = var_9; var_13 <= var_10; var_13++) {
            var_19 = 0;
            var_15 = floor(log10(var_13)) + 1;
            for (var_16 = 1; var_16 < var_15; var_16++) {
                var_18 = func_0(var_13, var_16, var_15);
                if (var_18 >= var_9 && var_18 <= var_10 && var_18 > var_13 &&
                    var_18 != var_19) {

                    var_17++;
                    var_19 = var_18;
                }
            }
        }
        printf("Case #%d: %d\n", var_12, var_17);
    }
    return 0;
}
