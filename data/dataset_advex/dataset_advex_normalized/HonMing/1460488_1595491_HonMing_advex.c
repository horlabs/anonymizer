#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
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

    scanf("%d", &var_0);

    for (var_8 = 1; var_8 <= var_0; var_8++) {
        var_10 = 0;
        var_11 = 0;
        scanf("%d%d%d", &var_2, &var_4, &var_3);
        for (var_5 = 0; var_5 < var_2; var_5++) {
            scanf("%d", &var_9);
            if ((var_9 + 2) / 3 >= var_3) {
                var_10++;
            } else {
                if ((var_9 + 4) / 3 >= var_3) {
                    if (var_9 == 0 && var_3 != 0) {
                    } else {
                        var_11++;
                    }
                }
            }
        }
        if (var_4 >= var_11) {
            var_10 = var_10 + var_11;
        } else {
            var_10 = var_10 + var_4;
        }

        printf("Case #%d: %d\n", var_8, var_10);
    }
    return 0;
}
