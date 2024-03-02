#include <math.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1[100] = {0};
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;

    scanf("%d", &var_0);

    for (var_5 = 0; var_5 < var_0; var_5++) {
        scanf("%d %d", &var_2, &var_3);

        for (var_6 = var_2; var_6 <= var_3; var_6++) {
            if (func_0(var_6) == 0) {
                continue;
            } else {
                if ((var_4 = func_1(var_6)) == 0) {
                    continue;
                } else {
                    if (func_0(var_4) != 0) {
                        var_1[var_5]++;
                    }
                }
            }
        }
    }

    for (var_5 = 0; var_5 < var_0; var_5++) {
        printf("Case #%d: %d\n", var_5 + 1, var_1[var_5]);
    }
    return 0;
}

int func_0(int var_7) {
    int var_8 = 0;
    int var_9 = var_7;

    while (var_9 != 0) {
        var_8 = var_8 * 10 + (var_9 % 10);
        var_9 = var_9 / 10;
    }

    if (var_8 == var_7) {
        return 1;
    } else {
        return 0;
    }
}

int func_1(int var_10) {
    double var_11;
    double var_12;

    var_11 = sqrt(var_10);

    var_12 = var_11 - (int)var_11;

    if (var_12 == 0.0) {
        return var_11;
    } else {
        return 0;
    }
}
