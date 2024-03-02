#include <stdio.h>

char var_0[5][5];
int main(int argc, char **argv) {
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6[5];
    int var_7[5];
    int var_8[5];
    int var_9[5];
    int var_10;
    int var_11;
    int var_12;
    int var_13;

    scanf("%d", &var_1);
    for (var_2 = 1; var_2 <= var_1; var_2++) {
        for (var_3 = 0; var_3 < 4; var_3++) {
            scanf("%s", var_0[var_3]);
        }
        var_5 = -1;
        for (var_3 = 0; var_3 < 4; var_3++) {
            var_6[var_3] = var_7[var_3] = var_8[var_3] = var_9[var_3] = 0;
            for (var_4 = 0; var_4 < 4; var_4++) {
                if (var_0[var_3][var_4] == 'X') {
                    var_6[var_3]++;
                } else {
                    if (var_0[var_3][var_4] == 'O') {
                        var_7[var_3]++;
                    }
                }
                if (var_0[var_4][var_3] == 'X') {
                    var_8[var_3]++;
                } else {
                    if (var_0[var_4][var_3] == 'O') {
                        var_9[var_3]++;
                    }
                }
                if (var_0[var_3][var_4] == 'T') {
                    var_6[var_3]++;
                    var_7[var_3]++;
                }
                if (var_0[var_4][var_3] == 'T') {
                    var_8[var_3]++;
                    var_9[var_3]++;
                }
                if (var_0[var_4][var_3] == '.') {
                    var_5 = 2;
                }
            }
        }
        var_10 = var_11 = var_12 = var_13 = 0;
        for (var_3 = 0; var_3 < 4; var_3++) {
            if (var_0[var_3][var_3] == 'X') {
                var_10++;
            } else {
                if (var_0[var_3][var_3] == 'O') {
                    var_11++;
                } else {
                    if (var_0[var_3][var_3] == 'T') {
                        var_10++;
                        var_11++;
                    }
                }
            }
            if (var_0[var_3][3 - var_3] == 'X') {
                var_12++;
            } else {
                if (var_0[var_3][3 - var_3] == 'O') {
                    var_13++;
                } else {
                    if (var_0[var_3][3 - var_3] == 'T') {
                        var_12++;
                        var_13++;
                    }
                }
            }
        }
        for (var_3 = 0; var_3 < 4; var_3++) {
            if (var_6[var_3] == 4 || var_8[var_3] == 4) {
                var_5 = 0;
            } else {
                if (var_7[var_3] == 4 || var_9[var_3] == 4) {
                    var_5 = 1;
                }
            }
        }
        if (var_10 == 4 || var_12 == 4) {
            var_5 = 0;
        } else {
            if (var_11 == 4 || var_13 == 4) {
                var_5 = 1;
            }
        }
        printf("Case #%d: ", var_2);
        if (var_5 == -1) {
            printf("Draw\n");
        } else {
            if (var_5 == 0) {
                printf("X won\n");
            } else {
                if (var_5 == 1) {
                    printf("O won\n");
                } else {
                    if (var_5 == 2) {
                        printf("Game has not completed\n");
                    }
                }
            }
        }
    }
    return 0;
}
