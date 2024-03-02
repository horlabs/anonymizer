#include <stdio.h>

int main(int argc, char **argv) {
    int var_0[4][4];
    int var_1[4][4];

    FILE *var_2;
    FILE *var_3;

    var_2 = fopen("A-small-attempt2.in", "r");
    var_3 = fopen("magic_out.txt", "w");
    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8;
    int var_9;
    int var_10;
    int var_11;

    fscanf(var_2, "%d", &var_11);

    var_10 = 1;
    while (var_10 <= var_11) {
        fscanf(var_2, "%d", &var_4);

        for (var_6 = 0; var_6 < 4; var_6++) {

            fscanf(var_2, "%d %d %d %d", &var_0[var_6][0], &var_0[var_6][1],
                   &var_0[var_6][2], &var_0[var_6][3]);
        }
        fscanf(var_2, "%d", &var_5);
        for (var_6 = 0; var_6 < 4; var_6++) {
            fscanf(var_2, "%d %d %d %d", &var_1[var_6][0], &var_1[var_6][1],
                   &var_1[var_6][2], &var_1[var_6][3]);
        }
        var_8 = 0;
        for (var_6 = 0; var_6 < 4; var_6++) {
            for (var_7 = 0; var_7 < 4; var_7++) {
                if (var_0[var_4 - 1][var_6] == var_1[var_5 - 1][var_7]) {
                    var_8++;

                    var_9 = var_0[var_4 - 1][var_6];
                }
            }
        }

        if (var_10 == var_11) {
            if (var_8 == 1) {
                fprintf(var_3, "Case #%d: %d", var_10, var_9);
            } else {
                if (var_8 > 1) {
                    fprintf(var_3, "Case #%d: Bad magician!", var_10);
                }

                else {
                    fprintf(var_3, "Case #%d: Volunteer cheated!", var_10);
                }
            }

        } else {
            if (var_8 == 1) {
                fprintf(var_3, "Case #%d: %d\n", var_10, var_9);
            } else {
                if (var_8 > 1) {
                    fprintf(var_3, "Case #%d: Bad magician!\n", var_10);
                }

                else {
                    fprintf(var_3, "Case #%d: Volunteer cheated!\n", var_10);
                }
            }
        }

        var_10++;
    }
    fclose(var_2);
    fclose(var_3);
    return 0;
}
