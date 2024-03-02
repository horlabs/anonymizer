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

    scanf("%d\n", &var_0);
    for (var_5 = 1; var_5 <= var_0; var_5++) {
        var_9 = 0;
        scanf("%d", &var_1);
        scanf("%d", &var_2);
        scanf("%d", &var_3);
        for (var_6 = 1; var_6 <= var_1; var_6++) {
            scanf("%d", &var_4);
            var_7 = var_4 / 3;
            var_8 = var_4 % 3;
            if (var_7 == 0) {
                if ((var_8 >= var_3) && (var_8 <= 1)) {
                    var_9++;
                } else {
                    if ((var_8 >= var_3) && (var_8 == 2) && var_2) {
                        var_9++;
                        var_2--;
                    }
                }
            } else {
                if (var_7 >= var_3) {
                    var_9++;
                } else {
                    if ((var_7 + 1) == var_3) {
                        if (var_8) {
                            var_9++;
                        } else {
                            if (var_2) {
                                var_9++;
                                var_2--;
                            }
                        }
                    } else {
                        if (((var_7 + 2) == var_3) && ((var_8 == 2) && var_2)) {
                            var_9++;
                            var_2--;
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n", var_5, var_9);
    }
    return 0;
}
