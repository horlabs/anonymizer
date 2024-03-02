#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    scanf("%d", &var_0);
    for (int var_1 = 1; var_1 <= var_0; var_1++) {
        int var_2;
        int var_3;

        scanf("%d %d", &var_2, &var_3);
        int var_4 = 0;
        int var_5 = 1;
        int var_6 = 1;
        for (int var_7 = var_2; var_7 >= 10; var_7++) {
            var_5 = var_5 * 10;
            var_6++;
            var_7 = var_7 / 10;
        }
        for (int var_8 = var_2; var_8 <= var_3; var_8++) {
            int var_9 = var_8;
            int var_10[var_6];
            for (int var_11 = 0; var_11 < var_6; var_11++) {
                var_10[var_11] = var_9;
                var_9 = (var_9 % 10) * var_5 + (var_9 / 10);
                if (var_9 <= var_8 || var_9 > var_3 || var_9 / var_5 == 0) {
                    continue;
                } else {
                    for (int var_12 = 0; var_12 < var_11; var_12++) {
                        if (var_10[var_12] == var_9) {
                            goto bad;
                        }
                    }
                    var_4++;
                bad:;
                }
            }
        }
        printf("Case #%d: %d\n", var_1, var_4);
    }
    return 0;
}
