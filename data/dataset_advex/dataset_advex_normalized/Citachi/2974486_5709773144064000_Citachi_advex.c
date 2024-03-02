#include <stdio.h>

int main(int argc, char **argv) {
    float var_0;
    float var_1;
    float var_2;

    float var_3;
    float var_4;
    float var_5;

    float var_6;
    float var_7;
    float var_8;

    int var_9;
    int var_10;
    int var_11;

    FILE *var_12;
    FILE *var_13;

    var_12 = fopen("B-small-attempt0.in", "r");
    var_13 = fopen("cookie_out.txt", "w");
    fscanf(var_12, "%d", &var_11);

    var_10 = 1;
    while (var_10 <= var_11) {

        var_4 = var_2;

        fscanf(var_12, "%f %f %f", &var_0, &var_1, &var_2);
        var_3 = var_7 = var_8 = 0.0;
        var_6 = 2.0;

        if (var_2 < var_0) {
            var_3 = var_2 / var_6;
        }

        else {
            var_5 = 0;
            var_3 = var_0 / var_6;
            var_7 = var_0 / var_6 + var_2 / (var_6 + var_1);
            var_5 = var_5 + var_0;

            var_9 = 0;
            while (var_5 < var_2) {
                var_8 = var_7;
                var_6 = var_6 + var_1;
                var_3 = var_3 + var_0 / var_6;
                var_7 = var_3 + var_2 / (var_6 + var_1);
                var_5 = var_5 + var_0;

                if (var_7 > var_8) {
                    var_3 = var_8;

                    var_9 = 1;
                    break;
                }
            }
            if (!var_9) {
                var_3 = var_7;
            }
        }
        if (var_10 == var_11) {
            fprintf(var_13, "Case #%d: %f", var_10, var_3);
        } else {
            fprintf(var_13, "Case #%d: %f\n", var_10, var_3);
        }
        var_10++;
    }

    fclose(var_12);
    fclose(var_13);
    return 0;
}
