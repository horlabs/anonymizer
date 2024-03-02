#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    long long var_2;
    long long var_3;
    long long var_4;
    long long var_5;
    long long var_6;
    long long var_7;
    char var_8[16];
    int var_9;
    int var_10;

    int var_11;
    int var_12;

    int var_13;

    fscanf(stdin, "%d\n", &var_1);
    for (var_0 = 0; var_0 < var_1; var_0++) {
        fscanf(stdin, "%lld %lld", &var_2, &var_3);

        fprintf(stdout, "Case #%d: ", var_0 + 1);
        var_6 = sqrt((double)var_2) - 1;
        var_7 = sqrt((double)var_3) - 1;

        var_4 = var_6 + 1;
        var_4 = var_4 * var_4;
        if (var_4 < var_2) {
            var_6++;
            var_4 = var_4 + (var_6 * 2 + 1);
        }
        var_13 = 0;

        for (var_5 = var_6 + 1; var_5 <= var_7 + 1; var_5++) {
            sprintf(var_8, "%lld", var_4);
            var_10 = strlen(var_8);
            for (var_9 = 0; var_9 < var_10 / 2; var_9++) {
                if (var_8[var_9] != var_8[var_10 - var_9 - 1]) {
                    break;
                }
            }
            if (var_9 >= var_10 / 2) {
                sprintf(var_8, "%ld", var_5);
                var_12 = strlen(var_8);
                for (var_11 = 0; var_11 < var_12 / 2; var_11++) {
                    if (var_8[var_11] != var_8[var_12 - var_11 - 1]) {
                        break;
                    }
                }
                if (var_11 >= var_12 / 2) {

                    var_13++;
                }
            }
            var_4 = var_4 + (var_5 * 2 + 1);
        }
        fprintf(stdout, "%d", var_13);
        fprintf(stdout, "\n");
    }

    return 0;
}
