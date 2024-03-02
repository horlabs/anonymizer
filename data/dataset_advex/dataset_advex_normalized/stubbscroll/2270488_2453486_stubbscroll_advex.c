#include <stdio.h>

char var_0[6][6];

int func_0(int var_1, int var_2, int var_3, int var_4, char var_5) {
    int var_6;
    int var_7;

    for (var_7 = var_6 = 0; var_6 < 4; var_6++) {
        if (var_0[var_1][var_2] == var_5 || var_0[var_1][var_2] == 'T') {
            var_7++;
        }
        var_1 = var_1 + var_3;
        var_2 = var_2 + var_4;
    }
    return var_7 == 4;
}

int func_1(char var_8) {
    int var_9;
    for (var_9 = 0; var_9 < 4; var_9++) {
        if (func_0(0, var_9, 1, 0, var_8)) {
            return 1;
        } else {
            if (func_0(var_9, 0, 0, 1, var_8)) {
                return 1;
            }
        }
    }
    if (func_0(0, 0, 1, 1, var_8)) {
        return 1;
    } else {
        if (func_0(0, 3, 1, -1, var_8)) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main(int argc, char **argv) {
    int var_10;
    int var_11;
    int var_12;
    int var_13;
    int var_14 = 1;

    scanf("%d", &var_10);
    while (var_10--) {
        for (var_11 = 0; var_11 < 4; var_11++) {
            scanf("%s", var_0[var_11]);
        }
        printf("Case #%d: ", var_14++);
        if (func_1('O')) {
            puts("O won");
        } else {
            if (func_1('X')) {
                puts("X won");
            } else {
                for (var_11 = var_13 = 0; var_11 < 4; var_11++) {
                    for (var_12 = 0; var_12 < 4; var_12++) {
                        if (var_0[var_11][var_12] == '.') {
                            var_13 = 1;
                        }
                    }
                }
                if (var_13) {
                    puts("Game has not completed");
                } else {
                    puts("Draw");
                }
            }
        }
    }
    return 0;
}
