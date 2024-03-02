#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;

    int var_2;
    int var_3;
    int var_4;

    int var_5;
    int var_6;
    char var_7[10][10];
    int var_8;
    int var_9;
    int var_10;

    double var_11;
    double var_12;
    double var_13;
    double var_14;

    double var_15;

    unsigned long long var_16;

    scanf("%d", &var_6);

    for (var_2 = 1; var_2 <= var_6; var_2++) {
        scanf("%lf%lf%lf", &var_11, &var_12, &var_13);

        var_15 = 0;
        var_14 = 2.0;

        if (var_13 <= var_11) {
            printf("Case #%d: %.07lf\n", var_2, var_13 / var_14);
            continue;
        } else {

            while (var_15 + var_13 / var_14 >
                   var_15 + var_11 / var_14 + var_13 / (var_14 + var_12)) {
                var_15 = var_15 + (var_11 / var_14);
                var_14 = var_14 + var_12;
            }

            printf("Case #%d: %.07lf\n", var_2, var_15 + var_13 / var_14);
        }
    }
    return 0;
}
