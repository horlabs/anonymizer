#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void func_0(int var_0[], int var_1, int var_2, int var_3) {
    int var_4 = var_2 - var_1 + 1;
    int var_5 = var_3 - var_2;
    int var_6[var_4 + 1];
    int var_7[var_5 + 1];

    int var_8;
    int var_9;
    int var_10;

    for (var_8 = 0; var_8 < var_4; var_8++) {
        var_6[var_8] = var_0[var_1 + var_8];
    }
    for (var_9 = 0; var_9 < var_5; var_9++) {
        var_7[var_9] = var_0[var_2 + var_9 + 1];
    }

    var_8 = 0;
    var_9 = 0;
    for (var_10 = var_1; var_10 <= var_3; var_10++) {
        if (var_8 < var_4 && var_9 < var_5) {
            if (var_6[var_8] <= var_7[var_9]) {
                var_0[var_10] = var_6[var_8];
                var_8++;
            } else {
                var_0[var_10] = var_7[var_9];
                var_9++;
            }
        } else {
            if (var_8 < var_4) {
                var_0[var_10] = var_6[var_8];
                var_8++;
            } else {
                var_0[var_10] = var_7[var_9];
                var_9++;
            }
        }
    }
    return;
}

void func_1(int var_11[], int var_12, int var_13) {
    if (var_12 < var_13) {
        int var_14 = (var_12 + var_13) / 2;
        func_1(var_11, var_12, var_14);
        func_1(var_11, var_14 + 1, var_13);
        func_0(var_11, var_12, var_14, var_13);
    }
    return;
}

int main(int argc, char **argv) {
    FILE *var_15;
    FILE *var_16;

    var_15 = freopen("B-small-attempt0.in", "r", stdin);
    var_16 = freopen("B-small-attempt0.out", "w", stdout);

    int var_17;
    int var_18;
    int var_19;

    scanf("%d", &var_17);
    int var_20;
    int var_21;
    int var_22;
    int var_23;
    int var_24[100000];
    int var_25;

    for (var_18 = 1; var_18 <= var_17; var_18++) {
        var_23 = 0;
        scanf("%d%d%d", &var_20, &var_21, &var_22);
        for (var_19 = 0; var_19 < var_20; var_19++) {
            scanf("%d", &var_24[var_19]);
        }
        func_1(var_24, 0, var_20 - 1);

        for (var_19 = var_20 - 1; var_19 >= 0; var_19--) {
            if (var_24[var_19] == 0) {
                if (var_22 == 0) {
                    var_23++;
                }
                continue;
            } else {

                if ((var_24[var_19] % 3) == 0) {
                    var_25 = var_24[var_19] / 3;
                    if (var_25 >= var_22) {
                        var_23++;
                    } else {
                        if (var_21) {
                            var_25++;
                            if (var_25 >= var_22) {
                                var_23++;
                                var_21--;
                            }
                        }
                    }
                    continue;
                } else {

                    if ((var_24[var_19] % 3) == 1) {
                        var_25 = (var_24[var_19] + 2) / 3;
                        if (var_25 >= var_22) {
                            var_23++;
                        }
                        continue;
                    } else {

                        if ((var_24[var_19] % 3) == 2) {
                            var_25 = (var_24[var_19] + 1) / 3;
                            if (var_25 >= var_22) {
                                var_23++;
                            } else {
                                if (var_21) {
                                    var_25++;
                                    if (var_25 >= var_22) {
                                        var_23++;
                                        var_21--;
                                    }
                                }
                            }
                            continue;
                        }
                    }
                }
            }
        }

        printf("Case #%d: %d\n", var_18, var_23);
    }

    fclose(var_15);
    fclose(var_16);

    return 0;
}
