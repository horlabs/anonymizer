#include <stdio.h>

int main(int argc, char **argv) {
    int var_0[8];
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

    scanf("%d", &var_2);
    for (var_3 = 1; var_3 <= var_2; var_3++) {
        scanf("%d%d", &var_4, &var_5);
        var_8 = var_4;
        var_6 = var_13 = 0;
        while (var_8 > 0) {
            var_8 = var_8 / 10;
            var_6++;
        }
        var_7 = 1;
        for (var_9 = 1; var_9 < var_6; var_9++) {
            var_7 = var_7 * 10;
        }
        for (var_9 = var_4; var_9 <= var_5; var_9++) {
            var_8 = var_9;
            var_0[0] = var_9;
            var_1 = 1;
            for (var_10 = 1; var_10 < var_6; var_10++) {
                var_8 = (var_8 % 10) * var_7 + var_8 / 10;
                if (var_8 > var_5) {
                    continue;
                } else {
                    if (var_8 <= var_9) {
                        continue;
                    } else {
                        var_12 = 1;
                        for (var_11 = 0; var_11 < var_1; var_11++) {
                            if (var_0[var_11] == var_8) {
                                var_12 = 0;
                                break;
                            }
                        }
                        if (var_12) {
                            var_0[var_1++] = var_8;
                            var_13++;
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n", var_3, var_13);
    }
    return 0;
}
