#include <stdio.h>

char var_0[5][5];
int var_1;

int func_0(char var_2) {
    int var_3;
    int var_4;
    int var_5[4] = {0};
    int var_6[4] = {0};

    int var_7 = 0;
    int var_8 = 0;

    for (var_3 = 0; var_3 < 4; var_3++) {
        if (var_0[var_3][var_3] == var_2 || var_0[var_3][var_3] == 'T') {
            var_7++;
        }
        if (var_0[var_3][3 - var_3] == var_2 ||
            var_0[var_3][3 - var_3] == 'T') {
            var_8++;
        }
        for (var_4 = 0; var_4 < 4; var_4++) {
            if (var_0[var_3][var_4] == var_2 || var_0[var_3][var_4] == 'T') {
                var_6[var_3]++;
            }
            if (var_0[var_4][var_3] == var_2 || var_0[var_4][var_3] == 'T') {
                var_5[var_3]++;
            }
        }
    }
    for (var_3 = 0; var_3 < 4; var_3++) {
        if (var_6[var_3] == 4 || var_5[var_3] == 4) {
            return 1;
        }
    }
    if (var_7 == 4 || var_8 == 4) {
        return 1;
    } else {
        return 0;
    }
}

int func_1() {
    int var_9;
    int var_10;
    int var_11 = 0;

    for (var_9 = 0; var_9 < 4; var_9++) {
        for (var_10 = 0; var_10 < 4; var_10++) {
            var_11 = var_11 + (var_0[var_9][var_10] == '.');
        }
    }
    if (func_0('X')) {
        return 0;
    } else {
        if (func_0('O')) {
            return 1;
        } else {
            if (var_11 == 0) {
                return 2;
            } else {
                return 3;
            }
        }
    }
}

int main(int argc, char **argv) {
    int var_12;
    int var_13;
    int var_14 = 1;

    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.txt", "w", stdout);

    char var_15[][50] = {"X won", "O won", "Draw", "Game has not completed"};
    scanf("%d", &var_12);
    while (var_12--) {
        for (var_13 = 0; var_13 < 4; var_13++) {
            scanf("%s", var_0[var_13]);
        }
        printf("Case #%d: %s\n", var_14++, var_15[func_1()]);
    }
    return 0;
}
