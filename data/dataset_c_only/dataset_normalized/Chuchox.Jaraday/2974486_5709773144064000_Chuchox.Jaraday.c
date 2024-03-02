#include <stdio.h>

int main(int argc, char **argvvoid) {
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
    double var_11;
    double var_12;

    scanf("%d\n", &var_0);
    for (var_1 = 1; var_1 <= var_0; var_1++) {

        scanf("%lf %lf %lf\n", &var_4, &var_5, &var_6);

        var_7 = 2.0;
        var_10 = 0.0;

        var_11 = 0.0;
        var_10 = 0.0;
        var_12 = var_6;
        do {
            var_8 = var_6 / var_7;
            var_9 = var_4 / var_7;
            var_11 = var_10 + var_8;
            var_10 = var_10 + var_9;
            var_7 = var_7 + var_5;

            if (var_12 < var_11) {
                break;
            } else {
                var_12 = var_11;
            }
        } while (1);

        printf("Case #%d: %.7lf\n", var_1, var_12);
    }

    return 0;
}
