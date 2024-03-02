#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int var_0;
int var_1;
double var_2;
double var_3;
double var_4;
double var_5;
double var_6;
double var_7;
double var_8;
double var_9;
double var_10;

int main(int argc, char **argv) {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

    scanf("%d", &var_0);
    for (var_1 = 1; var_1 <= var_0; var_1++) {
        printf("Case #%d: ", var_1);
        scanf("%lf%lf%lf", &var_2, &var_3, &var_4);
        var_8 = 2;
        var_10 = var_4 / var_8;
        var_9 = 0;

        while (1) {
            if ((var_9 + var_2 / var_8 + var_4 / (var_8 + var_3)) >= var_10) {
                break;
            } else {
                var_10 = var_9 + var_2 / var_8 + var_4 / (var_8 + var_3);

                var_9 = var_9 + (var_2 / var_8);
                var_8 = var_8 + var_3;
            }
        }

        printf("%.7lf\n", var_10);
    }

    return 0;
}
