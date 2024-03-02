#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1 = 0;
    for (scanf("%d", &var_0); var_0; var_0--, var_1++) {
        int var_2;
        int var_3;
        int var_4;

        int var_5;
        static int var_6[200];
        int var_7;
        int var_8 = 0;

        scanf("%d%d%d", &var_2, &var_3, &var_4);
        for (var_7 = 0; var_7 < var_2; var_7++) {
            scanf("%d", var_6 + var_7);
        }
        var_5 = var_3;
        for (var_7 = 0; var_7 < var_2; var_7++) {
            int var_9 = var_6[var_7];
            if ((var_9 % 3) == 0) {
                if (var_9 / 3 >= var_4) {
                    var_8++;

                } else {
                    if (var_5 && var_9 / 3 >= 1 && var_9 / 3 + 1 >= var_4) {
                        var_8++;
                        var_5--;
                    }
                }

            } else if ((var_9 % 3) == 1) {
                if (var_9 / 3 + 1 >= var_4) {
                    var_8++;
                }

            } else if ((var_9 % 3) == 2) {
                if (var_9 / 3 + 1 >= var_4) {
                    var_8++;

                } else {
                    if (var_5 && var_9 / 3 + 2 >= var_4) {
                        var_8++;
                        var_5--;
                    }
                }

            } else {
                fprintf(stderr, "This should not happen!\n");
                exit(1);
            }
        }
        printf("Case #%d: %d\n", var_1 + 1, var_8);
    }
    return 0;
}
