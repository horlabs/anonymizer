#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int func_0(int *var_0) {
    int var_1;
    int var_2;

    int var_3;
    for (var_1 = 0; var_1 < 4; ++var_1) {
        var_3 = 1;
        for (var_2 = 0; var_2 < 4; ++var_2) {
            if (!var_0[var_1 * 4 + var_2]) {
                var_3 = 0;
                break;
            }
        }
        if (var_3) {
            return 1;
        }
    }
    for (var_1 = 0; var_1 < 4; ++var_1) {
        var_3 = 1;
        for (var_2 = 0; var_2 < 4; ++var_2) {
            if (!var_0[var_2 * 4 + var_1]) {
                var_3 = 0;
                break;
            }
        }
        if (var_3) {
            return 1;
        }
    }

    var_3 = 1;
    for (var_1 = 0; var_1 < 4; ++var_1) {
        if (!var_0[var_1 * 4 + var_1]) {
            var_3 = 0;
            break;
        }
    }
    if (var_3) {
        return 1;
    } else {

        for (var_1 = 0; var_1 < 4; ++var_1) {
            var_3 = 1;
            if (!var_0[var_1 * 4 + (3 - var_1)]) {
                var_3 = 0;
                break;
            }
        }

        return var_3;
    }
}

int main(int argc, char **argvvoid) {
    int var_4;
    int var_5;
    int var_6;
    int var_7;

    char var_8[6];
    int var_9[4][4];
    int var_10[4][4];
    int var_11;
    int var_12;

    scanf("%d", &var_4);
    for (var_5 = 1; var_5 <= var_4; ++var_5) {
        gets(var_8);
        var_11 = 0;
        var_12 = 0;
        for (var_6 = 0; var_6 < 4; ++var_6) {
            gets(var_8);
            for (var_7 = 0; var_7 < 4; ++var_7) {
                if (var_8[var_7] == 'X') {
                    var_9[var_6][var_7] = 1;
                    var_10[var_6][var_7] = 0;
                } else {
                    if (var_8[var_7] == 'O') {
                        var_9[var_6][var_7] = 0;
                        var_10[var_6][var_7] = 1;
                    } else {
                        if (var_8[var_7] == 'T') {
                            var_9[var_6][var_7] = 1;
                            var_10[var_6][var_7] = 1;
                        } else {
                            var_9[var_6][var_7] = 0;
                            var_10[var_6][var_7] = 0;
                            var_11 = 1;
                        }
                    }
                }
            }
        }

        printf("Case #%d: ", var_5);
        if (func_0((int *)var_9)) {
            printf("X won\n");
        } else {
            if (func_0((int *)var_10)) {
                printf("O won\n");
            } else {
                if (var_11) {
                    printf("Game has not completed\n");
                } else {
                    printf("Draw\n");
                }
            }
        }
    }

    return 0;
}
