#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4;

    int var_5;
    int var_6;
    int var_7;

    int var_8;
    int var_9;
    int var_10;
    int var_11;

    int var_12;
    int var_13;
    int var_14;
    int var_15;

    char var_16[100];
    int var_17[10];

    scanf("%d", &var_0);

    for (var_12 = 1; var_12 <= var_0; var_12++) {
        scanf("%d%d", &var_14, &var_15);

        int var_18;

        if (var_14 < 10) {
            var_7 = 0;
        } else {
            if (var_14 < 100) {
                var_7 = 1;
            } else {
                if (var_14 < 1000) {
                    var_7 = 2;
                } else {
                    if (var_14 < 10000) {
                        var_7 = 3;
                    } else {
                        if (var_14 < 100000) {
                            var_7 = 4;
                        } else {
                            if (var_14 < 1000000) {
                                var_7 = 5;
                            } else {
                                if (var_14 < 10000000) {
                                    var_7 = 6;
                                }
                            }
                        }
                    }
                }
            }
        }

        var_13 = 0;
        if (var_7 > 0) {
            for (var_5 = var_14; var_5 <= var_15; var_5++) {
                var_11 = 10;
                memset(var_17, 0, 10 * sizeof(int));
                for (var_6 = 0; var_6 < var_7; var_6++) {
                    var_9 = var_5 % var_11;
                    var_10 = var_5 / var_11;
                    sprintf(var_16, "%d%d", var_9, var_10);
                    var_18 = atoi(var_16);
                    if ((var_18 > var_5) && (var_18 <= var_15) &&
                        (var_18 >= var_14)) {
                        int var_19 = 0;
                        for (var_8 = 0; var_8 < var_6; var_8++) {
                            if (var_17[var_8] == var_18) {
                                var_19 = 1;
                            }
                        }
                        if (!var_19) {

                            var_13++;
                            var_17[var_6] = var_18;
                        }
                    }

                    var_11 = var_11 * 10;
                }
            }
        }

        printf("Case #%d: %d\n", var_12, var_13);
    }
    return 0;
}
