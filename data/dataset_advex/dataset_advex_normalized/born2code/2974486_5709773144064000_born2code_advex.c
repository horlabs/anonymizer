#include <stdio.h>

void func_0(double var_0, double var_1, double var_2) {
    int var_3;
    int var_4;
    int var_5;

    double var_6;
    double var_7;

    var_7 = var_2 / 2.0;
    var_5 = 0;
    do {
        var_6 = var_7;
        var_7 = 0;
        for (var_3 = 0; var_3 < var_5; var_3++) {
            var_7 = var_7 + var_0 / (var_3 * var_1 + 2);
        }
        var_7 = var_7 + var_2 / (var_3 * var_1 + 2);
        var_5++;
    } while (var_7 <= var_6);
    printf("%f\n", var_6);
    return;
}

int main(int argc, char **argv) {
    int var_8;
    int var_9;

    double var_10;
    double var_11;
    double var_12;

    scanf("%d", &var_9);
    for (var_8 = 1; var_8 <= var_9; var_8++) {
        scanf("%lf%lf%lf", &var_10, &var_11, &var_12);
        printf("Case #%d: ", var_8);
        func_0(var_10, var_11, var_12);
    }
    return 0;
}
