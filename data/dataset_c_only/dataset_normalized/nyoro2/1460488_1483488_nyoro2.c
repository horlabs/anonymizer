#include <stdio.h>

int func_0(int var_0) {
    int var_1;
    int var_2 = 0;
    while (var_0 > 0) {
        var_0 = var_0 / 10;
        var_2++;
    }
    return var_2;
}

void func_1(int var_3, int *var_4, int var_5) {
    int var_6;
    for (var_6 = var_5 - 1; var_6 >= 0; var_6--) {
        var_4[var_6] = var_3 % 10;
        var_3 = var_3 / 10;
    }
    return;
}

int func_2(int *var_7, int *var_8, int var_9) {
    int var_10;
    for (var_10 = 0; var_10 < var_9; var_10++) {
        if (var_7[var_10] > var_8[var_10]) {
            return 1;
        } else {
            if (var_7[var_10] < var_8[var_10]) {
                return -1;
            }
        }
    }
    return 0;
}

void func_3(int *var_11, int var_12) {
    int var_13;
    for (var_13 = 0; var_13 < var_12; var_13++) {
        fputc('0' + var_11[var_13], stderr);
    }
    return;
}

int main(int argc, char **argv) {
    int var_14;
    int var_15;
    int var_16;
    int var_17;
    int var_18;
    int var_19;

    int var_20;
    int var_21;

    int var_22;
    int var_23;
    int var_24;

    int var_25;
    int var_26[16];
    int var_27[16];
    int var_28[16];
    int var_29[16];

    fscanf(stdin, "%d\n", &var_14);
    for (var_15 = 0; var_15 < var_14; var_15++) {
        fscanf(stdin, "%d %d\n", &var_20, &var_21);

        var_25 = func_0(var_20);

        func_1(var_20, var_28, var_25);
        func_1(var_21, var_29, var_25);
        var_23 = 0;
        var_24 = 0;
        for (var_16 = var_20; var_16 <= var_21; var_16++) {
            func_1(var_16, var_26, var_25);
            for (var_19 = 1; var_19 <= (var_25 / 2); var_19++) {
                int var_30 = var_19;
                if (var_26[var_19] == 0) {
                    continue;
                } else {
                    for (var_18 = 0; var_18 < var_25; var_18++) {
                        var_27[var_18] = var_26[var_30++];
                        if (var_30 >= var_25) {
                            var_30 = 0;
                        }
                    }
                    if ((func_2(var_26, var_27, var_25) != 0) &&
                        ((func_2(var_27, var_28, var_25) >= 0) &&
                         (func_2(var_27, var_29, var_25) <= 0))) {

                        if (var_19 * 2 == var_25) {
                            var_23++;

                        } else {
                            var_24++;
                        }
                    }
                }
            }
        }
        var_22 = var_23 / 2 + var_24;

        fprintf(stdout, "Case #%d: %d\n", var_15 + 1, var_22);
    }

    return 0;
}
