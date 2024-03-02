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
            float var_8;
            float var_9;
            float var_10;

            double var_11 = 0;
            float var_12 = 2;
            fscanf(var_2, "%f %f %f", &var_8, &var_9, &var_10);

            while (var_10) {
                double var_13 = 0;
                double var_14 = 0;

                double var_15 = 0;

                var_13 = (double)(var_8 / var_12);

                var_14 = (double)(var_10 / var_12);

                if (var_13 >= var_14) {
                    var_11 = var_11 + var_14;

                    break;
                } else {
                    var_15 = (double)(var_10 / (var_12 + var_9));

                    if ((var_14 + var_11) <= (var_11 + var_13 + var_15)) {

                        var_11 = var_11 + var_14;

                        break;
                    } else {

                        var_11 = var_11 + var_13;

                        var_12 = var_12 + var_9;
                    }
                }
            }

            fprintf(var_3, "Case #%d: %.7f\n", var_5 + 1, var_11);
        }
    }

    return 0;
}
