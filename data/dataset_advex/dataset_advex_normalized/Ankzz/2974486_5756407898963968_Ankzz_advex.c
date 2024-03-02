#include <stdio.h>

int main(int var_0, char *var_1[]) {
    FILE *var_2;
    FILE *var_3;

    var_2 = (var_0 <= 1) ? fopen("input.txt", "r+") : fopen(var_1[1], "r+");
    var_3 = fopen("output.txt", "w+");

    if (var_2) {
        int var_4;
        int var_5;
        int var_6;
        int var_7;

        fscanf(var_2, "%d", &var_4);
        for (var_5 = 0; var_5 < var_4; var_5++) {
            int var_8;
            int var_9[4];
            int var_10[4];
            int var_11;

            int var_12 = -1;
            int var_13 = -1;

            long long var_14 = 0;

            fscanf(var_2, "%d", &var_8);

            for (var_6 = 0; var_6 < 4; var_6++) {
                if (var_6 == var_8 - 1) {
                    fscanf(var_2, "%d %d %d %d", &var_9[0], &var_9[1],
                           &var_9[2], &var_9[3]);

                } else {
                    fscanf(var_2, "%d %d %d %d", &var_11, &var_11, &var_11,
                           &var_11);
                }
            }
            fscanf(var_2, "%d", &var_8);

            for (var_6 = 0; var_6 < 4; var_6++) {
                if (var_6 == var_8 - 1) {
                    fscanf(var_2, "%d %d %d %d", &var_10[0], &var_10[1],
                           &var_10[2], &var_10[3]);

                } else {
                    fscanf(var_2, "%d %d %d %d", &var_11, &var_11, &var_11,
                           &var_11);
                }
            }

            for (var_6 = 0; var_6 < 4; var_6++) {
                for (var_7 = 0; var_7 < 4; var_7++) {
                    if (var_9[var_6] == var_10[var_7]) {
                        var_12++;
                        if (var_13 == -1) {
                            var_13 = var_6;
                        } else {
                            break;
                        }
                    }
                }
                if (var_12 > 0) {
                    break;
                }
            }
            fprintf(var_3, "Case #%d: ", var_5 + 1);
            if (var_12 == 0) {
                fprintf(var_3, "%d\n", var_9[var_13]);
            } else {
                if (var_12 < 0) {
                    fprintf(var_3, "%s\n", "Volunteer cheated!");
                } else {
                    if (var_12 > 0) {
                        fprintf(var_3, "%s\n", "Bad magician!");
                    }
                }
            }
        }
    }

    return 0;
}
