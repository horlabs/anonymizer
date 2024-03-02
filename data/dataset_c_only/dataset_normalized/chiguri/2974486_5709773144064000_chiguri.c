#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long double var_0[100000];
double var_1;
double var_2;
double var_3;

int main(int argc, char **argvvoid) {
    int var_4;
    int var_5;

    int var_6;
    int var_7;

    scanf("%d", &var_4);
    for (var_5 = 1; var_5 <= var_4; ++var_5) {
        double var_8 = 2.0;
        double var_9;
        scanf("%lf %lf %lf", &var_1, &var_2, &var_3);

        var_0[0] = 0.0;
        var_9 = var_3 / 2;

        printf("Case #%d: ", var_5);
        for (var_7 = 1; var_7 < 100000; ++var_7) {
            double var_10;
            var_0[var_7] = var_1 / var_8 + var_0[var_7 - 1];
            if (var_0[var_7] > var_9) {
                break;
            } else {
                var_8 = 2.0 + var_2 * var_7;
                var_10 = var_0[var_7] + var_3 / var_8;
                if (var_10 < var_9) {
                    var_9 = var_10;
                }
            }
        }
        printf("%llf\n", var_9);
    }

    return 0;
}
