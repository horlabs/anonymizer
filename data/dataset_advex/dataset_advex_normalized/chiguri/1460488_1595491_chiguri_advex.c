#include <stdio.h>

char var_0[400];

int main(int argc, char **argvvoid) {
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8;

    int var_9;

    scanf("%d", &var_1);

    for (var_7 = 1; var_7 <= var_1; ++var_7) {
        var_5 = 0;
        var_6 = 0;

        scanf("%d %d %d", &var_2, &var_3, &var_4);
        for (var_8 = 0; var_8 < var_2; ++var_8) {
            scanf("%d", &var_9);
            if (var_9 == 0) {
                if (var_4 == 0) {
                    ++var_5;
                }
            } else {
                if (var_9 == 1) {
                    if (var_4 <= 1) {
                        ++var_5;
                    }
                } else {
                    if (var_4 * 3 - 2 <= var_9) {
                        ++var_5;
                    } else {
                        if (var_4 * 3 - 4 <= var_9) {
                            ++var_6;
                        }
                    }
                }
            }
        }
        if (var_3 > var_6) {
            var_5 = var_5 + var_6;
        } else {
            var_5 = var_5 + var_3;
        }

        printf("Case #%d: %d\n", var_7, var_5);
    }

    return 0;
}
