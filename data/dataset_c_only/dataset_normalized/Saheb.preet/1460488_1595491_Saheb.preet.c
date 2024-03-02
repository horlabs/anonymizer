#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7 = 0;

    FILE *var_8;
    FILE *var_9;

    var_8 = fopen("B-small-attempt0.in", "r");
    if (var_8 == NULL) {
        printf("ERROR\n");
    } else {
        fscanf(var_8, "%d", &var_0);
        for (var_3 = 0; var_3 < var_0; var_3++) {
            var_7 = 0;
            fscanf(var_8, "%d", &var_5);
            fscanf(var_8, "%d", &var_1);
            fscanf(var_8, "%d", &var_2);
            for (var_4 = 0; var_4 < var_5; var_4++) {
                fscanf(var_8, "%d", &var_6);
                if (var_6 / 3 >= var_2) {
                    var_7++;
                } else {
                    if (var_6 % 3 > 0 && var_6 / 3 + 1 >= var_2) {
                        var_7++;
                    } else {
                        if ((var_1 > 0 && var_6 % 3 == 2 &&
                             var_6 / 3 + 2 >= var_2) ||
                            (var_1 > 0 && var_6 % 3 == 0 &&
                             var_6 / 3 + 1 == var_2 && var_6 > 0)) {
                            var_7++;
                            var_1--;
                        }
                    }
                }
            }
            var_9 = fopen("output2.out", "a");
            fprintf(var_9, "Case #%d: %d\n", var_3 + 1, var_7);
        }
    }
    return 0;
}
