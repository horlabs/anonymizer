#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *var_0;
    FILE *var_1;

    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8;
    int var_9;
    int var_10 = 0;

    char var_11[4][4];
    var_0 = fopen("A-small-attempt1(1).in", "r");
    var_1 = fopen("output.txt", "w");
    fscanf(var_0, "%d", &var_4);

    for (var_9 = 1; var_9 <= var_4; var_9++) {
        for (var_2 = 0; var_2 < 4; var_2++) {
            fscanf(var_0, "%s", var_11[var_2]);
        }
        var_10 = 0;
        var_7 = var_8 = 4;
        for (var_2 = 0; var_2 < 4; var_2++) {
            var_5 = var_6 = 4;
            for (var_3 = 0; var_3 < 4; var_3++) {
                if (var_11[var_2][var_3] == 'X' ||
                    var_11[var_2][var_3] == 'T') {
                    var_5 = var_5 - 1;
                }
                if (var_11[var_2][var_3] == 'O' ||
                    var_11[var_2][var_3] == 'T') {
                    var_6 = var_6 - 1;
                }
                if (var_2 == var_3) {
                    if (var_11[var_2][var_3] == 'X' ||
                        var_11[var_2][var_3] == 'T') {
                        var_7 = var_7 - 1;
                    } else {
                        if (var_11[var_2][var_3] == 'O' ||
                            var_11[var_2][var_3] == 'T') {
                            var_8 = var_8 - 1;
                        }
                    }
                }
            }
            if (var_5 == 0) {
                fprintf(var_1, "Case #%d: X won\n", var_9);
                break;
            } else {
                if (var_6 == 0) {
                    fprintf(var_1, "Case #%d: O won\n", var_9);
                    break;
                }
            }
        }
        if (var_7 == 0) {
            fprintf(var_1, "Case #%d: X won\n", var_9);
            continue;
        } else {
            if (var_8 == 0) {
                fprintf(var_1, "Case #%d: O won\n", var_9);
                continue;

            } else {
                if (var_5 == 0 || var_6 == 0) {
                    continue;
                }
            }
        }
        var_7 = var_8 = 4;
        for (var_3 = 0; var_3 < 4; var_3++) {
            var_5 = var_6 = 4;
            for (var_2 = 0; var_2 < 4; var_2++) {
                if (var_11[var_2][var_3] == 'X' ||
                    var_11[var_2][var_3] == 'T') {
                    var_5 = var_5 - 1;
                }
                if (var_11[var_2][var_3] == 'O' ||
                    var_11[var_2][var_3] == 'T') {
                    var_6 = var_6 - 1;
                }
                if (var_11[var_2][var_3] == '.') {
                    var_10 = 1;
                }
                if ((var_2 + var_3) == 3) {
                    if (var_11[var_2][var_3] == 'X' ||
                        var_11[var_2][var_3] == 'T') {
                        var_7 = var_7 - 1;
                    }
                    if (var_11[var_2][var_3] == 'O' ||
                        var_11[var_2][var_3] == 'T') {
                        var_8 = var_8 - 1;
                    }
                }
            }
            if (var_5 == 0) {
                fprintf(var_1, "Case #%d: X won\n", var_9);
                break;
            } else {
                if (var_6 == 0) {
                    fprintf(var_1, "Case #%d: O won\n", var_9);
                    break;
                }
            }
        }
        if (var_7 == 0) {
            fprintf(var_1, "Case #%d: X won\n", var_9);
            continue;
        } else {
            if (var_8 == 0) {
                fprintf(var_1, "Case #%d: O won\n", var_9);
                continue;

            } else {
                if (var_5 == 0 || var_6 == 0) {
                    continue;
                }
            }
        }
        if (var_10 == 1) {
            fprintf(var_1, "Case #%d: Game has not completed\n", var_9);
        } else {
            fprintf(var_1, "Case #%d: Draw\n", var_9);
        }
    }
    fclose(var_0);
    fclose(var_1);
    system("pause");
    return 0;
}
