#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int var_0;
int var_1;
int var_2[120][120];
int var_3;
int var_4;
int var_5;
int var_6;
int var_7;
int var_8;
int var_9[120];
int var_10[120];
int var_11;
int var_12;

int func_0() {
    var_8 = 1000;
    var_5 = 1000;
    var_6 = 1000;
    var_7 = 1000;

    for (var_12 = 0; var_12 < var_3; var_12++) {
        if (var_10[var_12] < var_5) {
            var_8 = var_10[var_12];
            for (var_11 = 0; var_11 < var_4; var_11++) {
                if (var_2[var_12][var_11] == var_10[var_12]) {
                    continue;
                } else {
                    break;
                }
            }
            if (var_11 == var_4) {
                var_5 = var_10[var_12];
                var_6 = var_12;
                var_7 = 1000;
            }
        }
    }
    for (var_11 = 0; var_11 < var_4; var_11++) {
        if (var_9[var_11] < var_5) {
            var_8 = var_9[var_11];
            for (var_12 = 0; var_12 < var_3; var_12++) {
                if (var_2[var_12][var_11] == var_9[var_11]) {
                    continue;
                } else {
                    break;
                }
            }
            if (var_12 == var_3) {
                var_5 = var_9[var_11];
                var_6 = 1000;
                var_7 = var_11;
            }
        }
    }
    if ((var_7 == 1000) && (var_6 == 1000)) {
        return 0;
    }
    if ((var_6 < 1000) && (var_8 != var_10[var_6])) {
        return 0;
    }
    if ((var_7 < 1000) && (var_8 != var_9[var_7])) {
        return 0;
    }

    if (var_6 < 1000) {
        var_3--;
        for (var_11 = 0; var_11 < var_4; var_11++) {
            var_2[var_6][var_11] = var_2[var_3][var_11];
        }
        var_10[var_6] = var_10[var_3];
        for (var_11 = 0; var_11 < var_4; var_11++) {
            var_9[var_11] = 1000;
            for (var_12 = 0; var_12 < var_3; var_12++) {
                if (var_2[var_12][var_11] < var_9[var_11]) {
                    var_9[var_11] = var_2[var_12][var_11];
                }
            }
        }
        return 1;
    } else {
        if (var_7 < 1000) {
            var_4--;
            for (var_12 = 0; var_12 < var_3; var_12++) {
                var_2[var_12][var_7] = var_2[var_12][var_4];
            }
            var_9[var_7] = var_9[var_4];
            for (var_12 = 0; var_12 < var_3; var_12++) {
                var_10[var_12] = 1000;
                for (var_11 = 0; var_11 < var_4; var_11++) {
                    if (var_2[var_12][var_11] < var_10[var_12]) {
                        var_10[var_12] = var_2[var_12][var_11];
                    }
                }
            }
            return 1;
        }
    }
}

int main(int argc, char **argv) {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

    scanf("%d", &var_0);
    for (var_1 = 1; var_1 <= var_0; var_1++) {
        printf("Case #%d: ", var_1);
        scanf("%d%d", &var_3, &var_4);
        for (var_12 = 0; var_12 < var_3; var_12++) {
            for (var_11 = 0; var_11 < var_4; var_11++) {
                scanf("%d", &var_2[var_12][var_11]);
            }
        }

        for (var_12 = 0; var_12 < var_3; var_12++) {
            var_10[var_12] = 1000;
            for (var_11 = 0; var_11 < var_4; var_11++) {
                if (var_2[var_12][var_11] < var_10[var_12]) {
                    var_10[var_12] = var_2[var_12][var_11];
                }
            }
        }
        for (var_11 = 0; var_11 < var_4; var_11++) {
            var_9[var_11] = 1000;
            for (var_12 = 0; var_12 < var_3; var_12++) {
                if (var_2[var_12][var_11] < var_9[var_11]) {
                    var_9[var_11] = var_2[var_12][var_11];
                }
            }
        }

        while (var_3 && var_4) {
            if (func_0()) {
                continue;
            } else {
                break;
            }
        }

        if (var_3 && var_4) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}
