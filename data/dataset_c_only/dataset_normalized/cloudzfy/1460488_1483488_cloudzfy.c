#include <stdio.h>
#include <string.h>

int var_0[2000010];
int main(int argc, char **argv) {
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

    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    scanf("%d", &var_2);
    for (var_1 = 1; var_1 <= var_2; var_1++) {
        scanf("%d%d", &var_3, &var_4);
        memset(var_0, 0, sizeof var_0);
        var_11 = 0;
        var_8 = 1;
        for (var_5 = 1; var_5 < 10; var_5++) {
            var_8 = var_8 * 10;
            if (var_3 / var_8 == 0) {
                break;
            }
        }
        var_8 = var_8 / 10;
        var_7 = var_5;
        for (var_5 = var_3; var_5 <= var_4; var_5++) {
            int var_12 = 1;
            var_9 = var_5;
            var_0[var_9] = 1;
            for (var_6 = 0; var_6 < var_7; var_6++) {
                var_10 = var_8 * (var_9 % 10) + var_9 / 10;
                if (var_10 == var_9) {
                    break;
                } else {
                    if (var_10 <= var_4 && var_10 >= var_3) {
                        if (!var_0[var_10]) {
                            var_12++;
                        }
                        var_0[var_10] = 1;
                    }
                    var_9 = var_10;
                }
            }
            var_11 = var_11 + ((var_12 - 1) * var_12 / 2);
        }
        printf("Case #%d: %d\n", var_1, var_11);
    }
    return 0;
}
