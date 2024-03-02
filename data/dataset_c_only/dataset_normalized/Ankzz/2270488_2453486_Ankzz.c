#include <stdio.h>

int main(int argc, char **argv) {
    int var_0 = -1;
    int var_1 = 0;
    char var_2[100];

    FILE *var_3 = fopen("A-small-attempt0.in", "r");

    FILE *var_4 = fopen("output.txt", "w");

    fscanf(var_3, "%d", &var_0);

    while (++var_1 <= var_0) {
        int var_5 = 0;
        int var_6 = 0;

        char var_7[4][5];
        char var_8 = 0;
        char var_9 = 0;

        for (; var_5 < 4; var_5++) {
            fscanf(var_3, "%s", &var_7[var_5]);
            var_8 = (var_7[var_5][0] == 'T') ? 0 : var_7[var_5][0];
            for (var_6 = 0; var_6 < 4; var_6++) {
                char var_10 = var_7[var_5][var_6];
                if (var_8 > 0) {
                    if (var_8 != var_10 && var_10 != 'T') {
                        var_8 = -1;
                    }
                } else {
                    if (var_10 != 'T' && var_8 == 0) {
                        var_8 = var_10;
                    }
                }
                if (var_10 == '.') {
                    var_9 = 1;
                }
            }
            if (var_8 > 0 && var_8 != '.') {
                var_5++;
                break;
            }
        }
        while (var_5 < 4) {
            fscanf(var_3, "%s", var_2);

            var_5++;
        }

        if (var_8 <= 0 || var_8 == '.') {
            for (var_5 = 0; var_5 < 4; var_5++) {
                var_8 = (var_7[0][var_5] == 'T') ? 0 : var_7[0][var_5];

                for (var_6 = 1; var_6 < 4; var_6++) {
                    char var_11 = var_7[var_6][var_5];

                    if (var_8 > 0) {
                        if (var_8 != var_11 && var_11 != 'T') {
                            var_8 = -1;
                        }
                    } else {
                        if (var_11 != 'T' && var_8 == 0) {
                            var_8 = var_11;
                        }
                    }
                }

                if (var_8 > 0 && var_8 != '.') {
                    break;
                }
            }
        }

        if (var_8 <= 0 || var_8 == '.') {
            var_8 = 0;
            for (var_5 = 0; var_5 < 4; var_5++) {
                char var_12 = var_7[var_5][var_5];

                if (var_8 > 0) {
                    if (var_8 != var_12 && var_12 != 'T') {
                        var_8 = -1;
                    }
                } else {
                    if (var_12 != 'T' && var_8 == 0) {
                        var_8 = var_12;
                    }
                }
            }
        }

        if (var_8 <= 0 || var_8 == '.') {
            var_8 = 0;
            for (var_5 = 0; var_5 < 4; var_5++) {
                char var_13 = var_7[var_5][3 - var_5];

                if (var_8 > 0) {
                    if (var_8 != var_13 && var_13 != 'T') {
                        var_8 = -1;
                    }
                } else {
                    if (var_13 != 'T' && var_8 == 0) {
                        var_8 = var_13;
                    }
                }
            }
        }

        if (var_8 > 0 && var_8 != '.') {
            fprintf(var_4, "Case #%d: %c won\n", var_1, var_8);
        } else {
            fprintf(var_4, "Case #%d: %s\n", var_1,
                    var_9 ? "Game has not completed" : "Draw");
        }
    }

    return 0;
}
