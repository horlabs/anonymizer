#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argvvoid) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7[128];

    FILE *var_8 = fopen("B-small-attempt0.in", "r");
    FILE *var_9 = fopen("out.txt", "w");

    fscanf(var_8, "%d\n", &var_3);

    for (var_0 = 0; var_2 = 0, var_0 < var_3; var_0++) {

        fscanf(var_8, "%d\n%d\n%d\n", &var_4, &var_5, &var_6);

        for (var_1 = 0; var_1 < var_4; var_1++) {
            fscanf(var_8, "%d\n", &var_7[var_1]);
            if ((var_7[var_1] % 3) == 0) {
                if (var_7[var_1] / 3 >= var_6) {
                    var_2++;
                } else {
                    if (var_5 > 0 && var_7[var_1] / 3 > 0 &&
                        var_7[var_1] / 3 < 10 &&
                        var_7[var_1] / 3 + 1 >= var_6) {
                        var_5--;
                        var_2++;
                    }
                }

            } else if ((var_7[var_1] % 3) == 1) {
                if (var_7[var_1] / 3 + 1 >= var_6) {
                    var_2++;
                }

            } else if ((var_7[var_1] % 3) == 2) {
                if (var_7[var_1] / 3 + 1 >= var_6) {
                    var_2++;
                } else {
                    if (var_5 > 0 && var_7[var_1] / 3 < 9 &&
                        var_7[var_1] / 3 + 2 >= var_6) {
                        var_5--;
                        var_2++;
                    }
                }
            }
        }
        fprintf(var_9, "Case #%d: %d\n", var_0 + 1, var_2);
    }

    fclose(var_8);
    fclose(var_9);
    return 0;
}
