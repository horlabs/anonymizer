#include <stdio.h>

const int var_0[10] = {1,      10,      100,      1000,      10000,
                       100000, 1000000, 10000000, 100000000, 1000000000};

static int func_0(int var_1, int var_2) {
    int var_3 = var_1 % 10;
    var_1 = var_1 / 10;
    if (var_3 == 0) {
        return var_1;
    } else {
        var_1 = var_1 + (var_0[var_2 - 1] * var_3);
        return var_1;
    }
}

static int func_1(int var_4, int var_5, int var_6) {
    int var_7;
    int var_8 = 0;
    int var_9 = 0;
    if (var_6 < var_5) {
        return 0;
    } else {
        for (var_9 = 0, var_7 = var_4; var_7; var_7 = var_7 / 10, var_9++) {
            ;
        }
        for (var_7 = func_0(var_4, var_9); var_7 != -1 && var_7 != var_4;
             var_7 = func_0(var_7, var_9)) {
            if (var_7 > var_4 && var_7 >= var_5 && var_7 <= var_6) {
                var_8++;
            }
        }
        return var_8;
    }
}

int main(int argc, char **argv) {
    int var_10;
    int var_11 = 0;
    for (scanf("%d", &var_10); var_10; var_10--, var_11++) {
        int var_12;
        int var_13;

        int var_14;
        int var_15 = 0;
        scanf("%d%d", &var_12, &var_13);
        for (var_14 = var_12; var_14 <= var_13; var_14++) {
            var_15 = var_15 + func_1(var_14, var_12, var_13);
        }
        printf("Case #%d: %d\n", var_11 + 1, var_15);
    }
    return 0;
}
