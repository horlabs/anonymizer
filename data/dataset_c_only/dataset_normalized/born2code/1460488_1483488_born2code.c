#include <math.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long func_0(unsigned long long var_0, int var_1) {
    unsigned long long var_2;
    unsigned long long var_3;
    unsigned long long var_4;

    var_2 = pow(10, var_1 - 1);
    var_3 = var_0 % var_2;
    var_4 = var_0 / var_2;
    var_3 = var_3 * 10 + var_4;
    return var_3;
}

int func_1(unsigned long long var_5) {
    int var_6 = 0;
    while (var_5) {
        var_6++;
        var_5 = var_5 / 10;
    }
    return var_6;
}

int main(int argc, char **argv) {
    unsigned long long var_7;
    unsigned long long var_8;
    unsigned long long var_9;
    unsigned long long var_10;
    unsigned long long var_11;

    unsigned long long var_12;
    unsigned long long var_13;
    unsigned long long var_14;
    unsigned long long var_15;
    unsigned long long var_16;

    scanf("%ld", &var_7);
    for (var_12 = 1; var_12 <= var_7; var_12++) {
        scanf("%ld%ld", &var_8, &var_9);
        var_15 = func_1(var_8);
        var_14 = 0;
        for (var_10 = var_8 + 1; var_10 <= var_9; var_10++) {
            for (var_16 = var_8; var_16 < var_10; var_16++) {
                var_11 = func_0(var_16, var_15);
                var_13 = 0;
                while (var_11 != var_10 && var_13 < var_15 - 1) {
                    var_11 = func_0(var_11, var_15);
                    var_13++;
                }
                if (var_13 < var_15 - 1) {
                    var_14++;
                }
            }
        }
        printf("Case #%ld: %ld\n", var_12, var_14);
    }

    return 0;
}
