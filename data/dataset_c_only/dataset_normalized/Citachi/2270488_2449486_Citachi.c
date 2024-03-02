#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *var_0;
    FILE *var_1;

    int var_2[10][10];
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8;
    int var_9;
    int var_10 = 0;

    var_0 = fopen("B-small-attempt1.in", "r");
    var_1 = fopen("output.txt", "w");
    fscanf(var_0, "%d", &var_3);
    for (var_9 = 1; var_9 <= var_3; var_9++) {
        var_10 = 0;
        fscanf(var_0, "%d %d", &var_4, &var_5);
        for (var_6 = 0; var_6 < var_4; var_6++) {
            for (var_7 = 0; var_7 < var_5; var_7++) {
                fscanf(var_0, "%d", &var_2[var_6][var_7]);
            }
        }
        for (var_6 = 0; var_6 < var_4; var_6++) {
            var_8 = var_2[var_6][0];

            for (var_7 = 0; var_7 < var_5; var_7++) {
                if (var_2[var_6][var_7] != 0) {
                    var_2[var_6][var_7] = (int)abs(var_8 - var_2[var_6][var_7]);
                }
            }
        }

        for (var_7 = 0; var_7 < var_5; var_7++) {
            var_8 = var_2[0][var_7];
            for (var_6 = 0; var_6 < var_4; var_6++) {
                if (var_2[var_6][var_7] != 0) {
                    var_2[var_6][var_7] = (int)abs(var_8 - var_2[var_6][var_7]);
                }
            }
        }

        for (var_6 = 0; var_6 < var_4; var_6++) {
            var_8 = var_2[var_6][var_5 - 1];
            if (var_8 == 0) {
                continue;
            } else {
                for (var_7 = 0; var_7 < var_5; var_7++) {
                    if (var_2[var_6][var_7] != 0) {
                        var_2[var_6][var_7] =
                            (int)abs(var_8 - var_2[var_6][var_7]);
                    }
                }
            }
        }

        for (var_7 = 0; var_7 < var_5; var_7++) {
            var_8 = var_2[var_4 - 1][var_7];
            if (var_8 == 0) {
                continue;
            } else {
                for (var_6 = 0; var_6 < var_4; var_6++) {
                    if (var_2[var_6][var_7] != 0) {
                        var_2[var_6][var_7] =
                            (int)abs(var_8 - var_2[var_6][var_7]);
                    }
                }
            }
        }

        for (var_6 = 1; var_6 < var_4 - 1; var_6++) {
            for (var_7 = 1; var_7 < var_5 - 1; var_7++) {
                if (var_2[var_6][var_7] != 0) {
                    var_10 = 1;
                    break;
                }
            }
        }
        if (var_10 == 0) {
            fprintf(var_1, "Case #%d: YES\n", var_9);
        } else {
            fprintf(var_1, "Case #%d: NO\n", var_9);
        }
    }
    fclose(var_0);
    fclose(var_1);
    system("pause");
    return 0;
}
