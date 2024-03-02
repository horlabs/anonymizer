#include <stdio.h>

int main(int argc, char **argv) {
    unsigned int var_0;
    unsigned int var_1;
    unsigned int var_2;
    unsigned int var_3 = 0;
    unsigned int var_4 = 0;
    unsigned int var_5 = 0;
    unsigned int var_6;
    unsigned int var_7 = 1;
    unsigned int var_8;
    unsigned int var_9 = 1;
    unsigned int var_10;

    FILE *var_11;
    FILE *var_12;

    var_11 = fopen("C-small-attempt2.in", "r");
    var_12 = fopen("output.txt", "w");
    fscanf(var_11, "%d", &var_10);
    while (var_9 <= var_10) {
        fscanf(var_11, "%d %d", &var_0, &var_1);
        var_2 = var_0;
        while (var_2 != 0) {
            var_5++;
            var_2 = var_2 / 10;
        }
        while (var_0 < var_1) {
            var_6 = var_5;
            var_3 = var_0;
            while (var_6 != 0) {
                var_7 = 1;
                for (var_8 = 1; var_8 <= var_5 - 1; var_8++) {
                    var_7 = var_7 * 10;
                }
                var_3 = var_3 / 10 + (var_3 % 10) * var_7;
                var_6--;
                if (var_3 <= var_1 && var_3 > var_0) {
                    var_4++;
                }
            }

            var_0++;
        }

        fprintf(var_12, "Case #%d: %d\n", var_9, var_4);
        var_9++;
        var_4 = 0;
        var_5 = 0;
    }
    fclose(var_11);
    fclose(var_12);
    return 0;
}
