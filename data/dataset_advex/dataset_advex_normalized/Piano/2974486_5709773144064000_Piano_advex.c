#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;

    scanf("%d", &var_0);
    for (var_1 = 1; var_1 <= var_0; ++var_1) {
        double var_2;
        double var_3;
        double var_4;
        double var_5 = 2.;
        double var_6 = 0.;

        scanf("%lf%lf%lf", &var_2, &var_3, &var_4);
        while (1) {
            if (var_4 / var_5 <= var_2 / var_5 + var_4 / (var_5 + var_3)) {
                break;
            } else {
                var_6 = var_6 + (var_2 / var_5);
                var_5 = var_5 + var_3;
            }
        }
        var_6 = var_6 + (var_4 / var_5);
        printf("Case #%d: %.7f\n", var_1, var_6);
    }
    return 0;
}
