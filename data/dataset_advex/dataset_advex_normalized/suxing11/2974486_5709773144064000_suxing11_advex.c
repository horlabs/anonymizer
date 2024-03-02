#include <stdio.h>

double func_0(double var_0, double var_1, double var_2) {
    double var_3 = 2;
    double var_4 = 0;

    double var_5;
    double var_6;

    while (1) {
        var_5 = var_2 / var_3;
        var_6 = var_0 / var_3 + var_2 / (var_3 + var_1);
        if (var_6 > var_5) {
            var_4 = var_4 + var_5;
            break;
        } else {
            var_4 = var_4 + (var_0 / var_3);
            var_3 = var_3 + var_1;
        }
    }
    return var_4;
}

int main(int argc, char **argv) {
    int var_7 = 1;
    int var_8;

    double var_9;
    double var_10;
    double var_11;

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-out.txt", "w", stdout);
    scanf("%d", &var_8);
    while (var_8--) {
        scanf("%lf%lf%lf", &var_9, &var_10, &var_11);
        printf("Case #%d: %.7lf\n", var_7++, func_0(var_9, var_10, var_11));
    }
    return 0;
}
