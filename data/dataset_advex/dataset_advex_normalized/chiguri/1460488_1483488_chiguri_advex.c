#include <stdio.h>
#include <string.h>

int var_0;
int var_1;

int func_0(int var_2) {
    int var_3 = 0;
    int var_4 = var_2;

    while (1) {
        var_4 = var_4 / var_0 + (var_4 % var_0) * 10;
        if (var_2 == var_4) {
            break;
        } else {
            if (var_4 > var_1) {
                continue;
            } else {
                if (var_2 < var_4) {
                    ++var_3;
                }
            }
        }
    }

    return var_3;
}

int main(int argc, char **argvvoid) {
    int var_5;
    int var_6;

    int var_7;
    int var_8;

    int var_9;

    scanf("%d", &var_5);
    for (var_7 = 1; var_7 <= var_5; ++var_7) {
        var_9 = 0;

        scanf("%d %d", &var_6, &var_1);
        var_0 = 1;
        for (var_8 = var_6 / 10; var_8 > 0; var_8 = var_8 / 10) {
            var_0 = var_0 * 10;
        }

        for (var_8 = var_6; var_8 < var_1; ++var_8) {
            var_9 = var_9 + func_0(var_8);
        }

        printf("Case #%d: %d\n", var_7, var_9);
    }

    return 0;
}
