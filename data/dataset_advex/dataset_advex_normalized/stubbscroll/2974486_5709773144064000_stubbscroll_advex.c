#include <stdio.h>

void func_0() {
    double var_0;
    double var_1;
    double var_2;
    double var_3 = 1.0E+100;
    double var_4;
    double var_5 = 2;

    int var_6;
    scanf("%lf %lf %lf", &var_0, &var_1, &var_2);
    var_4 = 0;
    var_3 = var_2 / var_5;
    for (var_6 = 1; var_6 < 2000000000; var_6++) {
        var_4 = var_4 + (var_0 / var_5);
        var_5 = var_5 + var_1;
        if (var_3 <= var_4 + var_2 / var_5) {
            break;
        } else {
            var_3 = var_4 + var_2 / var_5;
        }
    }

    printf("%.10f\n", var_3);
    return;
}

int main(int argc, char **argv) {
    int var_7;
    int var_8 = 1;

    scanf("%d", &var_7);
    while (var_7--) {
        printf("Case #%d: ", var_8++);
        func_0();
    }
    return 0;
}
