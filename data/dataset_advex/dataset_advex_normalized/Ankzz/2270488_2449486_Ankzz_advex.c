#include <stdio.h>

int main(int argc, char **argv) {
    int var_0 = -1;
    int var_1 = 0;
    char var_2[100];

    FILE *var_3 = fopen("B-small-attempt3.in", "r");

    FILE *var_4 = fopen("output.txt", "w");

    fscanf(var_3, "%d", &var_0);

    while (++var_1 <= var_0) {
        int var_5;
        int var_6;

        int var_7;
        int var_8;

        short var_9 = 1;
        int var_10[100][100];
        fscanf(var_3, "%d %d", &var_5, &var_6);

        for (var_7 = 0; var_7 < var_5; var_7++) {
            int var_11 = -1;
            for (var_8 = 0; var_8 < var_6; var_8++) {
                int var_12;
                fscanf(var_3, "%d", &var_12);
                var_10[var_7][var_8] = var_12;
                if (var_9) {
                    if (var_11 == -1) {
                        var_11 = var_12;
                    } else {
                        if (var_7 != 0 && var_8 != 0 && var_7 != var_5 - 1 &&
                            var_8 != var_6 - 1 && var_12 < var_11) {
                            var_9 = 0;
                        }
                    }
                }
            }
        }

        if (var_9) {
            for (var_7 = 0; var_7 < var_5; var_7++) {
                int var_13 = -1;
                for (var_8 = 0; var_8 < var_6; var_8++) {
                    int var_14 = var_10[var_8][var_7];
                    if (var_13 == -1) {
                        var_13 = var_14;
                    } else {
                        if (var_7 != 0 && var_8 != 0 && var_7 != var_5 - 1 &&
                            var_8 != var_6 - 1 && var_14 < var_13) {
                            var_9 = 0;
                            break;
                        }
                    }
                }
            }
        }

        if (var_9) {
            int var_15 = -1;
            var_7 = 0;
            {
                for (var_8 = 0; var_8 < var_6; var_8++) {
                    int var_16 = var_10[var_7][var_8];

                    if (var_15 == -1) {
                        var_15 = var_16;
                    } else {
                        if (var_15 != var_16) {
                            int var_17 = var_7;
                            for (; var_17 < var_5; var_17++) {
                                if (var_10[var_17][var_8] != var_16) {
                                    var_9 = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
            }

            if (var_9) {
                var_8--;
                for (; var_7 < var_5; var_7++) {
                    int var_18 = var_10[var_7][var_8];

                    if (var_15 == -1) {
                        var_15 = var_18;
                    } else {
                        if (var_15 != var_18) {
                            int var_19 = var_8;
                            for (; var_19 >= 0; var_19--) {
                                if (var_10[var_7][var_19] != var_18) {
                                    var_9 = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
            }

            if (var_9) {
                var_7--;
                for (; var_8 >= 0; var_8--) {
                    int var_20 = var_10[var_7][var_8];

                    if (var_15 == -1) {
                        var_15 = var_20;
                    } else {
                        if (var_15 != var_20) {
                            int var_21 = var_7;
                            for (; var_21 >= 0; var_21--) {
                                if (var_10[var_21][var_8] != var_20) {
                                    var_9 = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
            }

            if (var_9) {
                var_8 = 0;
                for (; var_7 > 0; var_7--) {
                    int var_22 = var_10[var_7][var_8];

                    if (var_15 == -1) {
                        var_15 = var_22;
                    } else {
                        if (var_15 != var_22) {
                            int var_23 = var_8;
                            for (; var_23 < var_6; var_23++) {
                                if (var_10[var_7][var_23] != var_22) {
                                    var_9 = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }

        fprintf(var_4, "Case #%d: %s\n", var_1, var_9 ? "YES" : "NO");
    }

    return 0;
}
