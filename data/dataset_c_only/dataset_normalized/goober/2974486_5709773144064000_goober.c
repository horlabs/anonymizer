#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    scanf("%d", &var_0);
    for (int var_1 = 1; var_1 <= var_0; var_1++) {
        double var_2;
        double var_3;
        double var_4;

        scanf("%lf %lf %lf", &var_2, &var_3, &var_4);

        double var_5 = 2;
        double var_6 = var_4 / var_5;
        double var_7 = 0;
        for (;;) {
            var_7 = var_7 + (var_2 / var_5);
            var_5 = var_5 + var_3;
            if (var_6 <= var_7 + var_4 / var_5) {
                break;
            } else {
                var_6 = var_7 + var_4 / var_5;
            }
        }
        printf("Case #%d: %.7lf\n", var_1, var_6);
    }
    return 0;
}
