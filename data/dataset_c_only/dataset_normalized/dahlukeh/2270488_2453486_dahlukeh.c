#include <stdio.h>
#include <stdlib.h>
void func_0();
int func_1(int var_0, int var_1, int var_2);

int var_3[4][4];

int var_4[] = {0, 1, 1, -1};
int var_5[] = {1, 1, 0, 1};

int main(int argc, char **argv) {
    freopen("ain.txt", "r", stdin);
    freopen("aout.txt", "w", stdout);
    int var_6;
    scanf("%d ", &var_6);
    int var_7;
    for (var_7 = 0; var_7 < var_6; var_7++) {
        printf("Case #%d: ", var_7 + 1);
        func_0();
    }
    return 0;
}

void func_0() {
    int var_8;
    int var_9;
    int var_10;

    int var_11 = 1;
    for (var_8 = 0; var_8 < 4; var_8++) {
        for (var_9 = 0; var_9 < 4; var_9++) {
            char var_12;
            int var_13;
            scanf("%c ", &var_12);
            if (var_12 == 'X') {
                var_13 = 0;
            } else {
                if (var_12 == 'O') {
                    var_13 = 1;
                } else {
                    if (var_12 == 'T') {
                        var_13 = 2;
                    } else {
                        var_11 = 0;
                        var_13 = 3;
                    }
                }
            }
            var_3[var_8][var_9] = var_13;
        }
    }
    for (var_8 = 0; var_8 < 4; var_8++) {
        for (var_9 = 0; var_9 < 4; var_9++) {
            for (var_10 = 0; var_10 < 4; var_10++) {
                int var_14 = func_1(var_9, var_8, var_10);
                if (var_14 == 0) {
                    printf("X won\n");
                    return;
                } else {
                    if (var_14 == 1) {
                        printf("O won\n");
                        return;
                    }
                }
            }
        }
    }
    if (var_11) {
        printf("Draw\n");
    } else {
        printf("Game has not completed\n");
    }
    return;
    return;
}

int func_1(int var_0, int var_1, int var_2) {
    int var_15;
    int var_16 = 2;
    for (var_15 = 0; var_15 < 4; var_15++) {
        if (var_0 >= 4 || var_1 >= 4 || var_0 < 0 || var_1 < 0) {
            return 2;
        } else {
            if (var_3[var_1][var_0] == 3) {
                return 2;
            } else {
                if (var_3[var_1][var_0] != 2) {
                    if (var_16 == 2 || var_16 == var_3[var_1][var_0]) {
                        var_16 = var_3[var_1][var_0];
                    } else {
                        return 2;
                    }
                }
                var_0 = var_0 + var_4[var_2];
                var_1 = var_1 + var_5[var_2];
            }
        }
    }
    return var_16;
}
