#include <math.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8;
    int var_9;

    char var_10[4][4];

    var_1 = 1;
    for (scanf("%d", &var_0); var_1 <= var_0; var_1++) {
        var_2 = var_3 = var_4 = 0;
        for (var_5 = 0; var_5 < 4; var_5++) {
            for (var_6 = 0; var_6 < 4; var_6++) {
                do {
                    var_10[var_5][var_6] = getchar();
                } while (!(var_10[var_5][var_6] == '.' ||
                           var_10[var_5][var_6] == 'T' ||
                           var_10[var_5][var_6] == 'O' ||
                           var_10[var_5][var_6] == 'X'));

                if (var_10[var_5][var_6] == '.') {
                    var_2 = 1;
                }
            }
        }

        for (var_5 = 0; var_5 < 4; var_5++) {
            var_7 = var_8 = var_9 = 0;
            for (var_6 = 0; var_6 < 4; var_6++) {
                if (var_10[var_5][var_6] == 'T') {
                    var_9 = 1;
                } else {
                    if (var_10[var_5][var_6] == 'X') {
                        var_7++;
                    } else {
                        if (var_10[var_5][var_6] == 'O') {
                            var_8++;
                        }
                    }
                }
            }
            if ((var_7 == 4) || (var_7 == 3 && var_9 == 1)) {
                var_3 = 1;
            }
            if ((var_8 == 4) || (var_8 == 3 && var_9 == 1)) {
                var_4 = 1;
            }
        }

        for (var_6 = 0; var_6 < 4; var_6++) {
            var_7 = var_8 = var_9 = 0;
            for (var_5 = 0; var_5 < 4; var_5++) {
                if (var_10[var_5][var_6] == 'T') {
                    var_9 = 1;
                } else {
                    if (var_10[var_5][var_6] == 'X') {
                        var_7++;
                    } else {
                        if (var_10[var_5][var_6] == 'O') {
                            var_8++;
                        }
                    }
                }
            }
            if ((var_7 == 4) || (var_7 == 3 && var_9 == 1)) {
                var_3 = 1;
            }
            if ((var_8 == 4) || (var_8 == 3 && var_9 == 1)) {
                var_4 = 1;
            }
        }
        var_7 = var_8 = var_9 = 0;
        for (var_6 = 0; var_6 < 4; var_6++) {
            if (var_10[var_6][var_6] == 'T') {
                var_9 = 1;
            } else {
                if (var_10[var_6][var_6] == 'X') {
                    var_7++;
                } else {
                    if (var_10[var_6][var_6] == 'O') {
                        var_8++;
                    }
                }
            }
        }
        if ((var_7 == 4) || (var_7 == 3 && var_9 == 1)) {
            var_3 = 1;
        }
        if ((var_8 == 4) || (var_8 == 3 && var_9 == 1)) {
            var_4 = 1;
        }

        var_7 = var_8 = var_9 = 0;
        for (var_6 = 3; var_6 >= 0; var_6--) {
            if (var_10[var_6][3 - var_6] == 'T') {
                var_9 = 1;
            } else {
                if (var_10[var_6][3 - var_6] == 'X') {
                    var_7++;
                } else {
                    if (var_10[var_6][3 - var_6] == 'O') {
                        var_8++;
                    }
                }
            }
        }
        if ((var_7 == 4) || (var_7 == 3 && var_9 == 1)) {
            var_3 = 1;
        }
        if ((var_8 == 4) || (var_8 == 3 && var_9 == 1)) {
            var_4 = 1;
        }

        printf("Case #%d: ", var_1);
        if (var_3 == 1) {
            printf("X won\n");
        } else {
            if (var_4 == 1) {
                printf("O won\n");
            } else {
                if (var_2 == 1) {
                    printf("Game has not completed\n");
                } else {
                    printf("Draw\n");
                }
            }
        }
    }
    return 0;
}
