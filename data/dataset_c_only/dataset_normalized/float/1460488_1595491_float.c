#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;

    int var_6;
    int var_7;

    scanf("%d", &var_0);
    for (var_4 = 1; var_4 <= var_0; var_4++) {
        var_7 = 0;
        scanf("%d %d %d", &var_1, &var_2, &var_3);
        for (var_5 = 0; var_5 < var_1; var_5++) {
            scanf("%d", &var_6);
            if (var_6 == 30) {
                var_7++;
                continue;
            } else {
                if (var_6 == 29 && var_3 <= 9) {
                    var_7++;
                    continue;
                } else {
                    if (var_6 == 0) {
                        if (var_3 == 0) {
                            var_7++;
                        }
                        continue;
                    }
                }
            }
            if ((var_6 % 3) == 0) {
                if (var_6 / 3 >= var_3) {
                    var_7++;
                } else {
                    if (var_6 / 3 + 1 >= var_3 && var_2 > 0) {
                        var_7++;
                        var_2--;
                    }
                }

            } else if ((var_6 % 3) == 1) {
                if (var_6 / 3 >= var_3 || var_6 / 3 + 1 >= var_3) {
                    var_7++;
                }

            } else if ((var_6 % 3) == 2) {
                if (var_6 / 3 >= var_3 || var_6 / 3 + 1 >= var_3) {
                    var_7++;
                } else {
                    if (var_6 / 3 + 2 >= var_3 && var_2 > 0) {
                        var_7++;
                        var_2--;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", var_4, var_7);
    }
    return 0;
}
