#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;

    double var_4;
    double var_5;
    double var_6;
    double var_7;
    double var_8;
    double var_9;
    double var_10;

    scanf("%d", &var_0);
    for (var_1 = 1; var_1 <= var_0; var_1++) {
        scanf("%lf %lf %lf", &var_4, &var_5, &var_6);

        var_2 = 0;
        var_9 = 0;
        var_8 = 2.0;
        var_10 = var_9 + var_6 / var_8;
        var_3 = 0;
        while (var_3 < 100) {
            var_9 = var_9 + (var_4 / var_8);
            var_2++;
            var_8 = var_8 + var_5;
            var_7 = var_9 + var_6 / var_8;
            if (var_7 < var_10) {
                var_10 = var_7;
                if (var_3) {
                    fprintf(stderr, "Reseting counter.\n");
                }
                var_3 = 0;
            } else {
                var_3++;
            }
        }
        printf("Case #%d: %.7lf\n", var_1, var_10);
    }

    return 0;
}
