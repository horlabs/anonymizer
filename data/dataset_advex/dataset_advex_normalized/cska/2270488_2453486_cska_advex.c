#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argvvoid) {
    char var_0[5];
    char *var_1[4] = {"X won", "O won", "Draw", "Game has not completed"};

    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7[4][4];
    int var_8;

    FILE *var_9 = fopen("A-small-attempt0.in", "r");
    FILE *var_10 = fopen("out.txt", "w");

    fscanf(var_9, "%d", &var_8);

    for (var_4 = 0; var_4 < var_8; var_4++) {
        for (var_2 = 0; var_2 < 4; var_2++) {
            fscanf(var_9, "%s", var_0);
            for (var_3 = 0; var_3 < 4; var_3++) {
                var_7[var_2][var_3] =
                    var_0[var_3] == 'X'
                        ? 10
                        : (var_0[var_3] == 'O' ? 100
                                               : (var_0[var_3] == 'T' ? 5 : 0));
            }
        }

        for (var_6 = var_2 = 0; var_2 < 4 && !var_6; var_2++) {
            for (var_5 = var_3 = 0; var_3 < 4;
                 var_5 = var_5 + var_7[var_2][var_3++]) {
                ;
            }
            if (var_5 == 40 || var_5 == 35 || var_5 == 400 || var_5 == 305) {
                for (var_3 = 0; var_3 < 4 && var_7[var_2][var_3] == 5;
                     var_3++) {
                    ;
                }
                var_6 = var_7[var_2][var_3] == 10 ? 1 : 2;
            }
        }

        for (var_2 = 0; var_2 < 4 && !var_6; var_2++) {
            for (var_5 = var_3 = 0; var_3 < 4;
                 var_5 = var_5 + var_7[var_3++][var_2]) {
                ;
            }
            if (var_5 == 40 || var_5 == 35 || var_5 == 400 || var_5 == 305) {
                for (var_3 = 0; var_3 < 4 && var_7[var_3][var_2] == 5;
                     var_3++) {
                    ;
                }
                var_6 = var_7[var_3][var_2] == 10 ? 1 : 2;
            }
        }

        for (var_5 = var_2 = 0; var_2 < 4 && !var_6; var_2++) {
            var_5 = var_5 + var_7[var_2][var_2];
        }
        if (!var_6 &&
            (var_5 == 40 || var_5 == 35 || var_5 == 400 || var_5 == 305)) {
            for (var_3 = 0; var_3 < 4 && var_7[var_3][var_3] == 5; var_3++) {
                ;
            }
            var_6 = var_7[var_3][var_3] == 10 ? 1 : 2;
        }

        for (var_5 = var_2 = 0; var_2 < 4 && !var_6; var_2++) {
            var_5 = var_5 + var_7[var_2][4 - 1 - var_2];
        }
        if (!var_6 &&
            (var_5 == 40 || var_5 == 35 || var_5 == 400 || var_5 == 305)) {
            for (var_3 = 0; var_3 < 4 && var_7[var_3][var_3] == 5; var_3++) {
                ;
            }
            var_6 = var_7[var_3][4 - 1 - var_3] == 10 ? 1 : 2;
        }

        if (!var_6) {
            for (var_3 = 4, var_2 = 0; var_2 < 4 && var_3 == 4; var_2++) {
                for (var_3 = 0; var_3 < 4 && var_7[var_2][var_3] != 0;
                     var_3++) {
                    ;
                }
            }
            var_6 = var_2 == 4 ? 3 : 4;
        }

        fprintf(var_10, "Case #%d: %s\n", var_4 + 1, var_1[var_6 - 1]);
    }

    fclose(var_9);
    fclose(var_10);
    return 0;
}
