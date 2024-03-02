#include <stdio.h>

int main(int var_0, char *var_1[]) {
    FILE *var_2;
    FILE *var_3;

    var_2 = (var_0 <= 1) ? fopen("input.txt", "r") : fopen(var_1[1], "r");
    var_3 = fopen("output.txt", "w+");

    if (var_2) {
        int var_4;
        int var_5;

        fscanf(var_2, "%d", &var_4);

        for (var_5 = 0; var_5 < var_4; var_5++) {
            int var_6;
            int var_7;

            int var_8;
            int var_9;

            int var_10 = 1;
            int var_11 = 0;
            int var_12;
            int var_13 = 10;

            fscanf(var_2, "%d %d", &var_6, &var_7);
            var_11 = var_6;
            while (var_11 = var_11 / 10) {
                var_10++;
                var_13 = var_13 * 10;
            }

            for (var_8 = var_6; var_8 <= var_7; var_8++) {
                int var_14 = var_13;
                while ((var_14 = var_14 / 10) >= 10) {
                    int var_15 =
                        (var_8 % var_14) * (var_13 / var_14) + (var_8 / var_14);
                    if (var_8 < var_15 && var_15 <= var_7 && var_15 >= var_6) {
                        var_11++;
                    }
                }
            }

            fprintf(var_3, "Case #%d: %d\n", var_5 + 1, var_11);
        }
        fclose(var_2);
    }
    fclose(var_3);
    return 0;
}
