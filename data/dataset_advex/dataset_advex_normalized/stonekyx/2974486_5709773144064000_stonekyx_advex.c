#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double func_0(int var_0, double var_1, double var_2, double var_3) {
    int var_4;
    double var_5 = 0;
    for (var_4 = 0; var_4 < var_0; var_4++) {
        var_5 = var_5 + (var_1 / (2. + var_2 * var_4));
    }
    return var_5 + var_3 / (2.0 + var_0 * var_2);
}

int func_1(double var_6, double var_7, double var_8) {
    int var_9 = (var_7 * var_8 - 2 * var_6) / (var_7 * var_6);
    if (var_9 < 0) {
        var_9 = 0;
    }
    return var_9;
}

int main(int argc, char **argv) {
    int var_10;
    int var_11 = 0;

    for (scanf("%d", &var_10); var_10; var_10--) {
        double var_12;
        double var_13;
        double var_14;

        scanf("%lf%lf%lf", &var_12, &var_13, &var_14);
        printf("Case #%d: %.7lf\n", ++var_11,
               func_0(func_1(var_12, var_13, var_14), var_12, var_13, var_14));
    }
    return 0;
}
