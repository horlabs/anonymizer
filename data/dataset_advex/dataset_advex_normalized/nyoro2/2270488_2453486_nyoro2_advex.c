#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;

    int var_4[4][4];
    char var_5[8];
    int var_6;
    int var_7;
    int var_8[10];
    int var_9;

    fscanf(stdin, "%d\n", &var_0);
    for (var_1 = 0; var_1 < var_0; var_1++) {

        var_9 = 0;
        for (var_3 = 0; var_3 < 4; var_3++) {
            fgets(var_5, sizeof var_5, stdin);

            for (var_2 = 0; var_2 < 4; var_2++) {
                if (var_5[var_2] == ('O')) {
                    var_4[var_3][var_2] = 1;
                } else if (var_5[var_2] == ('X')) {
                    var_4[var_3][var_2] = 2;
                } else if (var_5[var_2] == ('T')) {
                    var_4[var_3][var_2] = 3;
                } else {
                    var_4[var_3][var_2] = 0;
                    var_9 = 1;
                }
            }
        }
        fgets(var_5, sizeof var_5, stdin);

        for (var_7 = 0; var_7 < 10; var_7++) {
            var_8[var_7] = 3;
        }
        for (var_3 = 0; var_3 < 4; var_3++) {
            for (var_2 = 0; var_2 < 4; var_2++) {
                var_8[var_3] = var_8[var_3] & var_4[var_3][var_2];
                var_8[var_3 + 4] = var_8[var_3 + 4] & var_4[var_2][var_3];
            }
            var_8[8] = var_8[8] & var_4[var_3][var_3];
            var_8[9] = var_8[9] & var_4[var_3][3 - var_3];
        }
        var_6 = 0;
        for (var_7 = 0; var_7 < 10; var_7++) {

            var_6 = var_6 | var_8[var_7];
        }

        fprintf(stdout, "Case #%d: ", var_1 + 1);
        if (var_6 & 1) {
            fprintf(stdout, "O won");
        } else {
            if (var_6 & 2) {
                fprintf(stdout, "X won");
            } else {
                if (var_9) {
                    fprintf(stdout, "Game has not completed");
                } else {
                    fprintf(stdout, "Draw");
                }
            }
        }
        fprintf(stdout, "\n");
    }

    return 0;
}
