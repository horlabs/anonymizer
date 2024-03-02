#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func_0(int var_0) {
    if (var_0 < 10) {
        return 1;
    } else {

        if (var_0 < 100) {
            return (var_0 % 11) == 0;
        } else {

            if (var_0 < 1000) {
                return (var_0 / 100) == (var_0 % 10);
            } else {

                return 0;
            }
        }
    }
}

int func_1(int var_1) {
    int var_2 = sqrt(var_1);

    if (var_2 * var_2 == var_1) {
        return var_2;
    } else {

        return 0;
    }
}

void func_2(int var_3) {
    int var_4;
    int var_5;

    int var_6;
    int var_7 = 0;

    scanf("%d%d", &var_4, &var_5);

    for (var_6 = var_4; var_6 <= var_5; var_6++) {
        int var_8;

        if (func_0(var_6) && (var_8 = func_1(var_6)) && func_0(var_8)) {
            var_7++;
        }
    }

    printf("Case #%d: %d\n", var_3 + 1, var_7);
    return;
}

int main(int argc, char **argv) {
    int var_9;
    int var_10;

    scanf("%d", &var_9);

    for (var_10 = 0; var_10 < var_9; var_10++) {
        func_2(var_10);
    }

    return 0;
}
