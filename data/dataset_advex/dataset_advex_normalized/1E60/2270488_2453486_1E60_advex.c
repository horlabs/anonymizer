#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func_0(char var_0[4][4], char var_1) {
    int var_2;
    int var_3;

    for (var_3 = 0; var_3 < 4; var_3++) {

        for (var_2 = 0; var_2 < 4; var_2++) {
            if (var_0[var_2][var_3] != 'T' && var_0[var_2][var_3] != var_1) {
                break;
            }
        }
        if (var_2 == 4) {
            return 1;
        }
    }
    for (var_2 = 0; var_2 < 4; var_2++) {

        for (var_3 = 0; var_3 < 4; var_3++) {
            if (var_0[var_2][var_3] != 'T' && var_0[var_2][var_3] != var_1) {
                break;
            }
        }
        if (var_3 == 4) {
            return 1;
        }
    }

    for (var_2 = 0; var_2 < 4; var_2++) {
        if (var_0[var_2][var_2] != 'T' && var_0[var_2][var_2] != var_1) {
            break;
        }
    }
    if (var_2 == 4) {
        return 1;
    } else {
        for (var_2 = 0; var_2 < 4; var_2++) {
            if (var_0[var_2][3 - var_2] != 'T' &&
                var_0[var_2][3 - var_2] != var_1) {
                break;
            }
        }
        if (var_2 == 4) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main(int var_4, char **var_5) {
    int var_6;
    int var_7;

    int var_8;
    int var_9;

    scanf("%d\n", &var_7);
    for (var_6 = 1; var_6 <= var_7; var_6++) {
        char var_10[4][4];
        for (var_9 = 0; var_9 < 4; var_9++) {
            for (var_8 = 0; var_8 < 4; var_8++) {
                scanf("%c ", &var_10[var_8][var_9]);
            }
        }

        int var_11 = 0;
        for (var_9 = 0; var_9 < 4; var_9++) {
            for (var_8 = 0; var_8 < 4; var_8++) {
                if (var_10[var_8][var_9] == '.') {
                    var_11 = 1;
                }
            }
        }
        char var_12[100];
        int var_13 = func_0(var_10, 'X');
        int var_14 = func_0(var_10, 'O');

        assert(!(var_13 && var_14));
        if (var_13) {
            sprintf(var_12, "X won");
        } else {
            if (var_14) {
                sprintf(var_12, "O won");
            } else {
                if (var_11) {
                    sprintf(var_12, "Game has not completed");
                } else {
                    sprintf(var_12, "Draw");
                }
            }
        }
        printf("Case #%d: %s\n", var_6, var_12);
    }
    return 0;
}
