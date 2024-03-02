#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4;

    double var_5;
    double var_6;
    double var_7;
    double var_8;
    double var_9;
    double var_10;
    double var_11;
    double var_12;

    scanf("%d", &var_0);
    for (var_4 = 1; var_4 <= var_0; var_4++) {
        scanf("%lf %lf %lf", &var_5, &var_6, &var_7);
        var_11 = var_7 / 2.00;
        for (var_1 = 1;; var_1++) {
            var_12 = var_7 / (2 + var_1 * var_6);
            for (var_2 = 0; var_2 < var_1; var_2++) {
                var_12 = var_12 + (var_5 / (2 + var_2 * var_6));
            }
            if (var_12 > var_11) {
                break;
            } else {
                var_11 = var_12;
            }
        }
        printf("Case #%d: %.7lf\n", var_4, var_11);
    }
    return 0;
}
