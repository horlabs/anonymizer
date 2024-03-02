#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;

    double var_2;
    double var_3;
    double var_4;
    double var_5;
    double var_6;
    double var_7;
    double var_8;

    scanf("%d", &var_0);
    for (var_1 = 1; var_1 <= var_0; var_1++) {
        scanf("%lf %lf %lf", &var_2, &var_3, &var_4);
        var_5 = 2;
        var_6 = 0;
        var_7 = 0;
        var_8 = 0;
        do {
            var_6 = var_8 + var_4 / var_5;
            var_7 = var_8 + var_2 / var_5 + var_4 / (var_5 + var_3);
            var_8 = var_8 + (var_2 / var_5);
            var_5 = var_5 + var_3;
        } while (var_6 > var_7);
        printf("Case #%d: %.7lf\n", var_1, var_6);
    }
    return 0;
}
