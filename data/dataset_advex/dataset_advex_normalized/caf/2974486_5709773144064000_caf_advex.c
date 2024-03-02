#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double func_0(long long var_0, double var_1, double var_2) {
    if (var_0 > 0) {
        return var_1 / ((var_0 - 1) * var_2 + 2.0) +
               func_0(var_0 - 1, var_1, var_2);
    } else {
        return 0;
    }
}

void func_1(int var_3) {
    long long var_4;
    double var_5;
    double var_6;
    double var_7;

    double var_8 = 0.0;

    scanf("%lf %lf %lf", &var_5, &var_6, &var_7);

    var_4 = var_7 / var_5 - 2.0 / var_6;
    if (var_4 < 0) {
        var_4 = 0;
    }
    var_8 = func_0(var_4, var_5, var_6) + var_7 / (var_4 * var_6 + 2.0);

    printf("Case #%d: %.7f\n", var_3 + 1, var_8);
    return;
}

int main(int argc, char **argv) {
    int var_9;
    int var_10;

    scanf("%d", &var_9);

    for (var_10 = 0; var_10 < var_9; var_10++) {
        func_1(var_10);
    }

    return 0;
}
