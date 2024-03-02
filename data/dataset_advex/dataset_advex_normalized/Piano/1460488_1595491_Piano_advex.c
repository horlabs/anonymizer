#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4[100];
    int var_5;
    int var_6;
    int var_7;
    int var_8;

    scanf("%d", &var_0);
    for (var_8 = 1; var_8 <= var_0; ++var_8) {
        scanf("%d%d%d", &var_1, &var_2, &var_3);
        for (var_5 = 0; var_5 < var_1; ++var_5) {
            scanf("%d", &var_7);
            for (var_6 = var_5; var_6 > 0; --var_6) {
                if (var_7 <= var_4[var_6 - 1]) {
                    break;
                } else {
                    var_4[var_6] = var_4[var_6 - 1];
                }
            }
            var_4[var_6] = var_7;
        }
        for (var_5 = 0; var_5 < var_1 && var_4[var_5] >= var_3 * 3 - 2;
             ++var_5) {
            ;
        }
        for (var_6 = 0; var_6 < var_2 && var_5 + var_6 < var_1 &&
                        var_4[var_5 + var_6] >= var_3 * 3 - 4;
             ++var_6) {
            if (var_3 == 1 && !var_4[var_5 + var_6]) {
                break;
            }
        }
        printf("Case #%d: %d\n", var_8, var_5 + var_6);
    }
    return 0;
}
