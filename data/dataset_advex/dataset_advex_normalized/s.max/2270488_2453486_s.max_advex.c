#include <stdio.h>

int func_0(char var_0[][5], char var_1, char var_2) {
    int var_3;
    int var_4;

    for (var_3 = 0; var_3 < 4; var_3++) {
        for (var_4 = 0; var_4 < 4; var_4++) {
            if (var_0[var_3][var_4] != var_1 && var_0[var_3][var_4] != var_2) {
                break;
            }
        }
        if (var_4 == 4) {
            return 1;
        }
    }

    for (var_3 = 0; var_3 < 4; var_3++) {
        for (var_4 = 0; var_4 < 4; var_4++) {
            if (var_0[var_4][var_3] != var_1 && var_0[var_4][var_3] != var_2) {
                break;
            }
        }
        if (var_4 == 4) {
            return 1;
        }
    }

    for (var_3 = 0; var_3 < 4; var_3++) {
        if (var_0[var_3][var_3] != var_1 && var_0[var_3][var_3] != var_2) {
            break;
        }
    }
    if (var_3 == 4) {
        return 1;
    } else {

        for (var_3 = 0; var_3 < 4; var_3++) {
            if (var_0[var_3][3 - var_3] != var_1 &&
                var_0[var_3][3 - var_3] != var_2) {
                break;
            }
        }

        if (var_3 == 4) {
            return 1;
        } else {

            return 0;
        }
    }
}

int func_1(char var_5[][5]) {
    int var_6;
    int var_7;

    for (var_6 = 0; var_6 < 4; var_6++) {
        for (var_7 = 0; var_7 < 4; var_7++) {
            if (var_5[var_6][var_7] == '.') {
                return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char **argv) {
    int var_8;
    int var_9;

    scanf("%d", &var_8);
    for (var_9 = 1; var_9 <= var_8; var_9++) {
        int var_10;
        char var_11[4][5];

        for (var_10 = 0; var_10 < 4; var_10++) {
            scanf("%s", var_11[var_10]);
        }

        printf("Case #%d: ", var_9);
        if (func_0(var_11, 'X', 'T')) {
            printf("X won");
        } else {
            if (func_0(var_11, 'O', 'T')) {
                printf("O won");
            } else {
                if (func_1(var_11)) {
                    printf("Draw");
                } else {
                    printf("Game has not completed");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
