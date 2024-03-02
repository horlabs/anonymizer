#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    freopen("B-small-attempt0.in.txt", "r", stdin);
    freopen("B-small-attempt0.out.txt", "w", stdout);
    int var_0;
    int var_1;

    double var_2;
    double var_3;
    double var_4;
    double var_5;
    double var_6;
    double var_7;

    scanf("%d", &var_1);
    for (var_0 = 1; var_0 <= var_1; var_0++) {
        scanf("%lf%lf%lf", &var_2, &var_3, &var_4);
        var_5 = 0;
        var_7 = 0;
        var_6 = 2;
        while (1) {
            if (var_7 + var_2 >= var_4) {
                var_5 = var_5 + ((var_4 - var_7) / var_6);
                break;
            } else {
                var_5 = var_5 + (var_2 / var_6);
                var_7 = var_7 + var_2;
                if ((var_4 - var_7 + var_2) / (var_6 + var_3) <
                    (var_4 - var_7) / var_6) {
                    var_7 = var_7 - var_2;
                    var_6 = var_6 + var_3;
                } else {
                    var_5 = var_5 + ((var_4 - var_7) / var_6);
                    break;
                }
            }
        }
        printf("Case #%d: %.7f\n", var_0, var_5);
    }
    return 0;
}
