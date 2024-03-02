#include <stdio.h>

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
    for (var_3 = 1; var_3 <= var_0; ++var_3) {
        printf("Case #%d: ", var_3);
        scanf("%d%d", &var_1, &var_2);
        for (var_6 = 10; var_6 <= var_1; var_6 = var_6 * 10) {
            ;
        }
        if (var_6 == 10) {
            puts("0");
            continue;
        } else {

            var_6 = var_6 / 10;
            var_7 = 0;
            for (var_4 = var_1; var_4 < var_2; ++var_4) {
                int var_8 = 0;
                var_5 = var_4;
                while (1) {
                    var_5 = var_5 % var_6 * 10 + var_5 / var_6;
                    if (var_5 == var_4) {
                        break;
                    } else {

                        if (var_5 > var_4 && var_5 <= var_2) {
                            ++var_7;
                        }
                    }
                }
            }
            printf("%d\n", var_7);
        }
    }
    return 0;
}
