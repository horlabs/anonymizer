#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;

    scanf("%d", &var_0);

    for (var_1 = 1; var_1 <= var_0; var_1++) {
        double var_2 = 0;
        double var_3;
        double var_4;
        double var_5;

        scanf("%lf %lf %lf", &var_4, &var_3, &var_5);

        int var_6;
        var_6 = var_5 / var_4 - 2 / var_3;
        if (var_6 < 0) {
            var_6 = 0;
        }
        var_2 = var_5 / (2 + var_6 * var_3);

        while (var_6 > 0) {
            var_6--;
            var_2 = var_2 + (var_4 / (2 + var_6 * var_3));
        }

        printf("Case #%d: %.7lf\n", var_1, var_2);
    }

    return 0;
}
