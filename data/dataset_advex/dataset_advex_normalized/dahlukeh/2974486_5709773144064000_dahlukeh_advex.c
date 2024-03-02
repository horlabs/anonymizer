#include <math.h>
#include <stdio.h>

double var_0;
double var_1;
double var_2;

void func_0() {
    scanf("%lf %lf %lf ", &var_0, &var_1, &var_2);
    double var_3 = (var_1 * var_2 - var_1 * var_0) / var_0;
    double var_4 = 0.0;
    double var_5 = 2.0;
    while (var_5 < var_3) {
        var_4 = var_4 + (var_0 / var_5);
        var_5 = var_5 + var_1;
    }
    var_4 = var_4 + (var_2 / var_5);
    printf("%.7f\n", var_4);
    return;
}

int main(int argc, char **argv) {
    int var_6;
    int var_7;

    scanf("%d ", &var_6);
    for (var_7 = 0; var_7 < var_6; var_7++) {
        printf("Case #%d: ", var_7 + 1);
        func_0();
    }
    return 0;
}
