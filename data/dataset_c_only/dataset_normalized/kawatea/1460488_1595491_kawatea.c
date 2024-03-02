#include <stdio.h>

int func_0(int var_0, int var_1) {
    if (var_0 > var_1) {
        return var_0;
    } else {
        return var_1;
    }
}

int main(int argc, char **argv) {
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8;

    int var_9[100];
    int var_10[31][11] = {0};
    int var_11[101][101];

    for (var_6 = 0; var_6 <= 30; var_6++) {
        for (var_7 = 0; var_7 <= 10; var_7++) {
            if (var_6 % 3 == 0) {
                if (var_6 / 3 >= var_7) {
                    var_10[var_6][var_7] = var_10[var_6][var_7] | 1;
                }
            } else {
                for (var_8 = 10; var_8 >= 1; var_8--) {
                    if (var_8 * 3 - 1 >= var_6 && var_8 * 3 - 2 <= var_6) {
                        if (var_8 >= var_7) {
                            var_10[var_6][var_7] = var_10[var_6][var_7] | 1;
                        }

                        break;
                    }
                }
            }

            for (var_8 = 10; var_8 >= 2; var_8--) {
                if (var_8 * 3 - 2 >= var_6 && var_8 * 3 - 4 <= var_6) {
                    if (var_8 >= var_7) {
                        var_10[var_6][var_7] = var_10[var_6][var_7] | 2;
                    }

                    break;
                }
            }
        }
    }

    scanf("%d", &var_2);

    for (var_6 = 0; var_6 < var_2; var_6++) {
        scanf("%d %d %d", &var_3, &var_4, &var_5);

        for (var_7 = 0; var_7 < var_3; var_7++) {
            scanf("%d", &var_9[var_7]);
        }

        for (var_7 = 0; var_7 <= var_3; var_7++) {
            for (var_8 = 0; var_8 <= var_4; var_8++) {
                var_11[var_7][var_8] = 0;
            }
        }

        for (var_7 = 0; var_7 < var_3; var_7++) {
            for (var_8 = 0; var_8 < var_4; var_8++) {
                if (var_10[var_9[var_7]][var_5] & 1) {
                    var_11[var_7 + 1][var_8] = func_0(var_11[var_7 + 1][var_8],
                                                      var_11[var_7][var_8] + 1);
                } else {
                    var_11[var_7 + 1][var_8] =
                        func_0(var_11[var_7 + 1][var_8], var_11[var_7][var_8]);
                }

                if (var_10[var_9[var_7]][var_5] & 2) {
                    var_11[var_7 + 1][var_8 + 1] = func_0(
                        var_11[var_7 + 1][var_8 + 1], var_11[var_7][var_8] + 1);
                } else {
                    var_11[var_7 + 1][var_8 + 1] = func_0(
                        var_11[var_7 + 1][var_8 + 1], var_11[var_7][var_8]);
                }
            }

            if (var_10[var_9[var_7]][var_5] & 1) {
                var_11[var_7 + 1][var_4] =
                    func_0(var_11[var_7 + 1][var_4], var_11[var_7][var_4] + 1);
            } else {
                var_11[var_7 + 1][var_4] =
                    func_0(var_11[var_7 + 1][var_4], var_11[var_7][var_4]);
            }
        }

        printf("Case #%d: %d\n", var_6 + 1, var_11[var_3][var_4]);
    }

    return 0;
}
