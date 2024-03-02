#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func_0(int var_0, int var_1) {
    if (var_0 == 0) {
        assert(!var_1);
        return 0;
    } else {
        if (!var_1) {
            if (var_0 % 3 == 0) {
                return var_0 / 3;
            } else {
                return var_0 / 3 + 1;
            }
        } else {
            if (var_0 % 3 == 2) {
                return var_0 / 3 + 2;
            } else {
                return var_0 / 3 + 1;
            }
        }
        assert(0);
    }
}

int var_2;

void func_1(int *var_3, int var_4, int var_5, int var_6, int var_7) {
    int var_8 = *var_3;
    if (var_4 == 0) {
        assert(var_5 == 0);

        if (var_2 < var_7) {
            var_2 = var_7;
        }
    } else {

        if (var_4 > var_5) {

            int var_9;
            var_9 = (func_0(var_8, 0) >= var_6) ? 1 : 0;
            func_1(var_3 + 1, var_4 - 1, var_5, var_6, var_7 + var_9);
        }
        if (var_5 > 0 && var_8 >= 2) {

            int var_10;
            var_10 = (func_0(var_8, 1) >= var_6) ? 1 : 0;
            func_1(var_3 + 1, var_4 - 1, var_5 - 1, var_6, var_7 + var_10);
        }
    }
    return;
}

int main(int argc, char **argvvoid) {
    int var_11;
    int var_12;

    scanf("%d\n", &var_11);
    for (var_12 = 1; var_12 <= var_11; var_12++) {
        int var_13;
        int var_14;
        int var_15;

        int var_16;
        int var_17[100];
        memset(var_17, 0, sizeof var_17);
        scanf("%d %d %d ", &var_13, &var_14, &var_15);
        for (var_16 = 0; var_16 < var_13; var_16++) {
            scanf("%d ", &var_17[var_16]);
        }
        var_2 = 0;
        func_1(var_17, var_13, var_14, var_15, 0);
        printf("Case #%d: %d\n", var_12, var_2);
    }
    return 0;
}
