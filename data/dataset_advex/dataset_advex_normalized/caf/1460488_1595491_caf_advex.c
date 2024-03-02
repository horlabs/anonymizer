#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func_0(int var_0) {
    int var_1;
    int var_2;
    int var_3;
    int var_4;

    int var_5;
    int var_6;

    int var_7 = 0;

    scanf("%d %d %d", &var_2, &var_3, &var_4);

    var_5 = var_4 > 0 ? 3 * var_4 - 2 : 0;
    var_6 = var_4 > 1 ? 3 * var_4 - 4 : var_4;

    for (var_1 = 0; var_1 < var_2; var_1++) {
        int var_8;
        scanf("%d", &var_8);

        if (var_4 > 10) {
            continue;
        } else {

            if (var_8 >= var_5) {

                var_7++;
            } else {
                if (var_3 > 0 && var_8 >= var_6) {

                    var_7++;
                    var_3--;
                }
            }
        }
    }

    printf("Case #%d: %d\n", var_0 + 1, var_7);
    return;
}

int main(int argc, char **argv) {
    int var_9;
    int var_10;

    scanf("%d", &var_9);

    for (var_10 = 0; var_10 < var_9; var_10++) {
        func_0(var_10);
    }

    return 0;
}
