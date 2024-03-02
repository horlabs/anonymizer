#include <math.h>
#include <stdio.h>

int main(int argc, char **argvvoid) {
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

    int var_14[10];
    scanf("%d", &var_0);
    for (var_8 = 1; var_8 <= var_0; var_8++) {
        scanf("%d", &var_1);
        scanf("%d", &var_2);

        var_9 = var_2;
        var_5 = 0;
        var_6 = 1;
        while (var_9) {
            var_9 = var_9 / 10;
            var_5++;
            var_6 = var_6 * 10;
        }
        var_6 = var_6 / 10;

        var_10 = 0;
        for (var_3 = var_1; var_3 < var_2; var_3++) {
            var_4 = var_3;
            var_11 = var_13 = 0;
            for (var_9 = 1; var_9 < var_5; var_9++) {
                var_7 = var_4 % 10;
                var_4 = var_4 / 10;
                var_4 = var_4 + (var_7 * var_6);
                if ((var_3 < var_4) && (var_4 <= var_2)) {
                    var_12 = 1;
                    for (var_11 = 0; var_11 < var_13; var_11++) {
                        if (var_4 == var_14[var_11]) {
                            var_12 = 0;
                        }
                    }
                    if (var_12) {
                        var_14[var_13] = var_4;
                        var_13++;
                        var_10++;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", var_8, var_10);
    }
    return 0;
}
