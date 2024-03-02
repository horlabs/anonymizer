#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;

    int var_7[100] = {0};
    int var_8;
    int var_9;
    scanf("%d", &var_0);

    for (var_1 = 0; var_1 < var_0; var_1++) {
        scanf("%d", &var_3);
        scanf("%d", &var_4);
        scanf("%d", &var_5);

        for (var_2 = 0; var_2 < var_3; var_2++) {
            scanf("%d", &var_6);
            var_8 = var_6 / 3;
            var_9 = var_6 % 3;

            if (var_8 == 0 && var_9 == 0 && var_5 != 0) {
                continue;
            } else {
                if (var_8 >= var_5) {
                    var_7[var_1]++;
                } else {
                    if (var_9 == 0 && var_4 > 0 && var_8 + 1 >= var_5 &&
                        var_8 + 1 <= 10) {

                        var_7[var_1]++;
                        var_4--;
                    } else {
                        if (var_9 == 1 && var_8 + 1 >= var_5 &&
                            var_8 + 1 <= 10) {

                            var_7[var_1]++;
                        } else {
                            if (var_9 == 2) {

                                if (var_8 + 1 >= var_5) {
                                    var_7[var_1]++;
                                } else {
                                    if (var_4 > 0 && var_8 + 2 >= var_5 &&
                                        var_8 + 2 <= 10) {
                                        var_4--;
                                        var_7[var_1]++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (var_1 = 0; var_1 < var_0; var_1++) {
        printf("Case #%d: %d\n", var_1 + 1, var_7[var_1]);
    }
    return 0;
}
