#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int var_0, char **var_1) {
    int var_2;
    int var_3;

    scanf("%d\n", &var_3);
    for (var_2 = 1; var_2 <= var_3; var_2++) {
        double var_4;
        double var_5;
        double var_6;

        double var_7 = 0.0;
        double var_8 = 2.0;
        scanf("%lf %lf %lf\n", &var_4, &var_5, &var_6);
        while (1) {
            double var_9;
            double var_10;
            double var_11;

            var_9 = var_6 / var_8;
            var_10 = var_4 / var_8;
            var_11 = var_6 / (var_8 + var_5);
            if (var_9 < (var_10 + var_11)) {
                var_7 = var_7 + var_9;
                break;
            } else {
                var_8 = var_8 + var_5;
                var_7 = var_7 + var_10;
            }
        }
        printf("Case #%d: %.8lf\n", var_2, var_7);
    }
    return 0;
}
