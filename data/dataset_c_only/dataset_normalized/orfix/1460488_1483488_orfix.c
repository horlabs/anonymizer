#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argvvoid) {
    int var_0 = 0;
    int var_1;

    scanf("%d\n", &var_1);

    while (var_0 < var_1) {
        int var_2 = 0;
        int var_3;
        int var_4;
        int var_5;

        scanf("%d %d\n", &var_4, &var_5);

        for (var_3 = var_4; var_3 <= var_5; var_3++) {
            int var_6;
            int var_7;
            int var_8;
            int var_9;

            int var_10 = 10;
            int var_11 = floor(log10(var_3) + 1);
            int var_12[10] = {0};

            for (var_6 = 1; var_6 < var_11; var_6++, var_10 = var_10 * 10) {
                var_7 = var_3 / var_10;
                var_8 = var_3 % var_10;
                var_9 = var_7 + (var_8 * pow(10, var_11 - var_6));

                if (var_3 < var_9 && var_9 <= var_5) {
                    int var_13 = 0;

                    for (; var_13 < var_6; var_13++) {
                        if (var_9 == var_12[var_13]) {
                            var_9 = 0;
                            break;
                        }
                    }
                    if (var_9) {
                        var_12[var_6 - 1] = var_9;
                        var_2++;
                    }
                }
            }
        }

        printf("Case #%d: %d\n", ++var_0, var_2);
    }

    return 0;
}
