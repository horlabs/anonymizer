#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argvvoid) {
    int var_0;
    int var_1;
    int var_2;

    double var_3;
    double var_4;
    double var_5;
    double var_6;
    double var_7;
    double var_8;
    double var_9;
    double var_10;
    double var_11;
    double var_12;

    FILE *var_13 = fopen("B-small-attempt0.in", "r");
    FILE *var_14 = fopen("out.txt", "w");

    fscanf(var_13, "%d", &var_0);

    for (var_1 = 0; var_1 < var_0; var_1++) {
        fscanf(var_13, "%lf%lf%lf", &var_3, &var_4, &var_5);
        var_11 = 0.0;
        var_6 = 2.0;
        var_8 = 0.0;
        do {
            var_9 = (var_5 - var_11) / var_6;
            var_10 = 0.0;
            var_12 = var_11;
            var_7 = var_6;
            var_2 = 0;

            do {
                var_10 = var_10 + ((var_3 - var_12) / var_7);
                var_12 = ((var_3 - var_12) / var_7) * var_7 - var_3;
                var_7 = var_7 + var_4;
                if (var_10 + (var_5 - var_12) / var_7 < var_9) {
                    var_2 = 1;
                }
            } while (!var_2 && var_10 < var_9);

            if (var_2) {
                var_10 = (var_3 - var_11) / var_6;
                var_11 = var_10 * var_6 - var_3;
                var_8 = var_8 + var_10;
                var_6 = var_6 + var_4;
            } else {
                var_8 = var_8 + ((var_5 - var_11) / var_6);
            }
        } while (var_2);
        fprintf(var_14, "Case #%d: %lf\n", var_1 + 1, var_8);
    }

    fclose(var_13);
    fclose(var_14);
    return 0;
}
