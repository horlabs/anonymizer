#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    FILE *var_0;
    FILE *var_1;

    var_0 = freopen("C-small-attempt0.in", "r", stdin);
    var_1 = freopen("C-small-attempt0.out", "w", stdout);

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
    int var_12[10];

    scanf("%d", &var_2);
    for (var_3 = 1; var_3 <= var_2; var_3++) {
        var_11 = 0;
        scanf("%d%d", &var_4, &var_5);
        if (var_5 < 21) {
            printf("Case #%d: 0\n", var_3);
            continue;
        } else {

            for (var_6 = var_4; var_6 < var_5; var_6++) {
                var_12[0] = var_6;
                var_9 = 0;
                var_10 = 1;
                while (var_12[0] = var_12[0] / 10) {
                    var_9++;
                    var_10 = var_10 * 10;
                }
                var_12[0] = var_6;
                for (var_8 = 1; var_8 <= var_9; var_8++) {
                    var_12[var_8] = var_12[var_8 - 1] / var_10 +
                                    10 * (var_12[var_8 - 1] % var_10);
                }

                for (var_7 = 0; var_7 < var_9; var_7++) {
                    for (var_8 = var_7 + 1; var_8 <= var_9; var_8++) {
                        if (var_12[var_8] == var_12[var_7]) {
                            var_12[var_8] = 0;
                        }
                    }
                }
                for (var_7 = 1; var_7 <= var_9; var_7++) {
                    if (var_12[var_7] <= var_6) {
                        var_12[var_7] = 0;
                        continue;
                    } else {
                        if (var_12[var_7] > var_5) {
                            var_12[var_7] = 0;
                            continue;
                        } else {
                            if (var_12[var_7] < var_4) {
                                var_12[var_7] = 0;
                                continue;
                            } else {
                                if (var_12[var_7] > 0) {
                                    var_11++;
                                    continue;
                                }
                            }
                        }
                    }
                }
            }

            printf("Case #%d: %d\n", var_3, var_11);
        }
    }

    fclose(var_0);
    fclose(var_1);

    return 0;
}
