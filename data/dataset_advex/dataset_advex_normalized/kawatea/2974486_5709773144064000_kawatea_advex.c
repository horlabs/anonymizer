#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;

    scanf("%d", &var_0);

    for (var_1 = 0; var_1 < var_0; var_1++) {
        double var_2;
        double var_3;
        double var_4;
        double var_5 = 0;
        double var_6 = 2;
        double var_7 = 1.0E+9;
        double var_8;

        scanf("%lf %lf %lf", &var_2, &var_3, &var_4);

        for (var_8 = 0; var_8 < 100000; var_8++) {
            if (var_5 + var_4 / var_6 < var_7) {
                var_7 = var_5 + var_4 / var_6;
            }

            var_5 = var_5 + (var_2 / var_6);
            var_6 = var_6 + var_3;
        }

        printf("Case #%d: %.12lf\n", var_1 + 1, var_7);
    }

    return 0;
}
