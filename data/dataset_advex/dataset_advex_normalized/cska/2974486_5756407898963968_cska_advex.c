#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argvvoid) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6[4][4];
    int var_7;
    int var_8;
    int var_9[16];

    FILE *var_10 = fopen("A-small-attempt0.in", "r");
    FILE *var_11 = fopen("out.txt", "w");

    fscanf(var_10, "%d", &var_0);

    for (var_3 = 0; var_3 < var_0; var_3++) {
        for (var_1 = 0; var_1 < 16; var_9[var_1++] = 0) {
            ;
        }
        for (var_4 = 0; var_4 < 2; var_4++) {
            fscanf(var_10, "%d", &var_5);
            for (var_1 = 0; var_1 < 4; var_1++) {
                for (var_2 = 0; var_2 < 4; var_2++) {
                    fscanf(var_10, "%d", &var_6[var_1][var_2]);
                }
            }
            for (var_1 = 0; var_1 < 4; var_1++) {
                var_9[var_6[var_5 - 1][var_1] - 1] =
                    var_9[var_6[var_5 - 1][var_1] - 1] + 1;
            }
        }
        for (var_7 = var_1 = 0; var_1 < 16; var_1++) {
            if (var_9[var_1] == 2) {
                var_7 = var_7 + 1;
                var_8 = var_1 + 1;
            }
        }
        fprintf(var_11, "Case #%d: ", var_3 + 1);
        if (var_7 == 1) {
            fprintf(var_11, "%d\n", var_8);
        } else {
            fprintf(var_11, "%s\n",
                    var_7 > 1 ? "Bad magician!" : "Volunteer cheated!");
        }
    }

    fclose(var_10);
    fclose(var_11);
    return 0;
}
