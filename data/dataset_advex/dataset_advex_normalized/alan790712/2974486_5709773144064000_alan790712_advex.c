#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int var_0;
int var_1;
double var_2;
double var_3;
double var_4;
double func_0(double var_5, double var_6) {
    double var_7;
    int var_8;
    int var_9;

    double var_10;
    double var_11 = var_6;
    while (var_5 + 1e-8 <= var_6) {
        var_7 = (var_5 + var_6) / 2;
        for (var_9 = 0;; ++var_9) {
            for (var_8 = var_10 = 0; var_8 < var_9; ++var_8) {
                var_10 = var_10 + (var_2 / (2. + var_3 * var_8));
            }
            if ((var_10 >= var_7) ||
                (var_7 - var_10) * (2.0 + var_3 * var_9) >= var_4) {
                break;
            }
        }
        if (var_10 >= var_7) {
            var_5 = var_7 + 1e-8;
        } else {
            if (var_7 < var_11) {
                var_11 = var_7;
            }
            var_6 = var_7 - 1e-8;
        }
    }
    return var_11;
}

int main(int argc, char **argv) {
    scanf("%d", &var_1);
    for (var_0 = 1; var_0 <= var_1; ++var_0) {
        scanf("%lf %lf %lf", &var_2, &var_3, &var_4);
        printf("Case #%d: %.7lf\n", var_0, func_0(0.0, var_4 / 2.0));
    }

    return 0;
}
