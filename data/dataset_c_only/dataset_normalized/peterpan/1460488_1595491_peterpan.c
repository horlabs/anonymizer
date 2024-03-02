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
    int var_8;
    int var_9;

    scanf("%d", &var_0);
    for (var_1 = 1; var_1 <= var_0; var_1++) {
        scanf("%d", &var_2);
        scanf("%d", &var_3);
        scanf("%d", &var_4);
        var_9 = 0;
        for (var_8 = 0; var_8 < var_2; var_8++) {
            scanf("%d", &var_5);
            var_6 = var_5 % 3;
            var_7 = var_5 / 3;
            if (var_6 != 0) {
                var_7++;
            }
            if (var_7 >= var_4) {
                var_9++;
            } else {
                if (var_3 > 0 && var_7 + 1 >= var_4 &&
                    (var_6 == 2 || (var_6 == 0 && var_7 - 1 >= 0))) {
                    var_9++;
                    var_3--;
                }
            }
        }
        printf("Case #%d: %d\r\n", var_1, var_9);
    }
    return 0;
}
