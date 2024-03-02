#include <assert.h>
#include <stdio.h>
#include <string.h>

void func_0(int var_0, double var_1, double var_2, double var_3) {
    double var_4 = 0;
    double var_5 = 2;

    while ((var_3 / var_5) > (var_3 / (var_5 + var_2) + (var_1 / var_5))) {
        var_4 = var_4 + var_1 / var_5;
        var_5 = var_5 + var_2;
    }

    var_4 = var_4 + var_3 / var_5;
    printf("Case #%d: %.7lf\n", var_0, var_4);
    return;
}

int main(int var_6, char **var_7) {
    int var_8;
    int var_9;

    double var_10;
    double var_11;
    double var_12;

    assert(scanf("%d ", &var_8) == 1);
    for (var_9 = 1; var_9 <= var_8; var_9++) {
        assert(scanf("%lf %lf %lf ", &var_10, &var_11, &var_12) == 3);
        func_0(var_9, var_10, var_11, var_12);
    }
    return 0;
}
