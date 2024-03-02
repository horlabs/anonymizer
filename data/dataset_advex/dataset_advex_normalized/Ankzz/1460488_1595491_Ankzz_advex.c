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
            int var_9;
            int var_10;

            int var_11 = 0;
            int var_12 = 0;

            fscanf(var_2, "%d %d %d", &var_8, &var_9, &var_10);

            for (var_6 = 0; var_6 < var_8; var_6++) {
                int var_13;
                int var_14;
                int var_15;

                short var_16 = 0;

                fscanf(var_2, "%d", &var_13);

                for (var_14 = 3, var_15 = var_10;
                     var_14 > 1 && var_15 <= var_13; var_14 = var_7) {

                    var_14 = (var_13 - var_15) / 2;
                    var_7 = (var_14 > var_15) ? var_14 - var_15 + 1
                                              : var_15 - var_14;

                    if (var_7 > 2) {
                        if (var_14 < var_15) {
                            break;
                        } else {
                            var_15++;
                        }
                    } else {
                        if (var_7 == 2) {
                            if (var_12 < var_9) {
                                var_12++;
                                var_11++;
                                var_16 = 1;
                            } else {
                                if (var_14 < var_15) {
                                    break;
                                }
                            }

                            var_15++;
                        } else {
                            if (!var_16) {
                                var_11++;
                                var_16 = 0;
                            } else {
                                var_12--;
                            }

                            break;
                        }
                    }
                }
            }
            fprintf(var_3, "Case #%d: %d\n", var_5 + 1, var_11);
        }
    }

    return 0;
}
