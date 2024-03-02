#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    char var_1[4][5];
    char var_2[10];
    char var_3[10];
    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8;
    int var_9;
    int var_10;

    int var_11;
    int var_12;

    scanf("%d", &var_0);

    for (var_4 = 0; var_4 < var_0; var_4++) {
        var_12 = 0;
        var_11 = 0;

        for (var_5 = 0; var_5 < 4; var_5++) {
            scanf("%s", var_1[var_5]);
        }

        for (var_5 = 0; var_5 < 4; var_5++) {
            var_7 = 0;
            var_8 = 0;
            var_9 = 0;
            for (var_6 = 0; var_6 < 4; var_6++) {
                if (var_1[var_5][var_6] == ('X')) {
                    var_7++;
                } else if (var_1[var_5][var_6] == ('O')) {
                    var_8++;
                } else if (var_1[var_5][var_6] == ('T')) {
                    var_9++;
                } else if (var_1[var_5][var_6] == ('.')) {
                    var_11 = 1;
                }
            }

            if (var_7 == 4 || (var_7 == 3 && var_9 == 1)) {
                var_2[var_4] = 'X';
                var_12 = 1;
                break;
            } else {
                if (var_8 == 4 || (var_8 == 3 && var_9 == 1)) {
                    var_2[var_4] = 'O';
                    var_12 = 1;
                    break;
                }
            }
        }

        for (var_5 = 0; var_5 < 4; var_5++) {
            if (var_12 == 1) {
                break;
            } else {

                var_7 = 0;
                var_8 = 0;
                var_9 = 0;
                for (var_6 = 0; var_6 < 4; var_6++) {

                    if (var_1[var_6][var_5] == ('X')) {
                        var_7++;
                    } else if (var_1[var_6][var_5] == ('O')) {
                        var_8++;
                    } else if (var_1[var_6][var_5] == ('T')) {
                        var_9++;
                    } else if (var_1[var_6][var_5] == ('.')) {
                        var_11 = 1;
                    }
                }

                if (var_7 == 4 || (var_7 == 3 && var_9 == 1)) {
                    var_2[var_4] = 'X';
                    var_12 = 1;
                    break;
                } else {
                    if (var_8 == 4 || (var_8 == 3 && var_9 == 1)) {
                        var_2[var_4] = 'O';
                        var_12 = 1;
                        break;
                    }
                }
            }
        }

        var_7 = 0;
        var_8 = 0;
        var_9 = 0;
        for (var_5 = 0; var_5 < 4; var_5++) {
            if (var_12 == 1) {
                break;
            } else {

                if (var_1[var_5][var_5] == ('X')) {
                    var_7++;
                } else if (var_1[var_5][var_5] == ('O')) {
                    var_8++;
                } else if (var_1[var_5][var_5] == ('T')) {
                    var_9++;
                } else if (var_1[var_5][var_5] == ('.')) {
                    var_11 = 1;
                }
            }
        }
        if (var_7 == 4 || (var_7 == 3 && var_9 == 1)) {
            var_2[var_4] = 'X';
            var_12 = 1;
        }
        if (var_8 == 4 || (var_8 == 3 && var_9 == 1)) {
            var_2[var_4] = 'O';
            var_12 = 1;
        }

        var_7 = 0;
        var_8 = 0;
        var_9 = 0;
        for (var_5 = 0; var_5 < 4; var_5++) {
            if (var_12 == 1) {
                break;
            } else {

                if (var_1[var_5][3 - var_5] == ('X')) {
                    var_7++;
                } else if (var_1[var_5][3 - var_5] == ('O')) {
                    var_8++;
                } else if (var_1[var_5][3 - var_5] == ('T')) {
                    var_9++;
                } else if (var_1[var_5][3 - var_5] == ('.')) {
                    var_11 = 1;
                }
            }
        }

        if (var_7 == 4 || (var_7 == 3 && var_9 == 1)) {
            var_2[var_4] = 'X';
            var_12 = 1;
        }
        if (var_8 == 4 || (var_8 == 3 && var_9 == 1)) {
            var_2[var_4] = 'O';
            var_12 = 1;
        }

        if (var_12 == 0) {
            if (var_11 == 1) {
                var_2[var_4] = 'G';
            } else {
                var_2[var_4] = 'D';
            }
        }
    }

    for (var_4 = 0; var_4 < var_0; var_4++) {
        printf("Case #%d: ", var_4 + 1);
        if (var_2[var_4] == ('X')) {
            printf("X won\n");
        } else if (var_2[var_4] == ('O')) {
            printf("O won\n");
        } else if (var_2[var_4] == ('D')) {
            printf("Draw\n");
        } else if (var_2[var_4] == ('G')) {
            printf("Game has not completed\n");
        }
    }
    return 0;
}
