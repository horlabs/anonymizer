#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;

    scanf("%d", &var_0);

    for (var_1 = 1; var_1 <= var_0; var_1++) {
        int var_2;
        int var_3;
        int var_4;
        int var_5 = 0;
        int var_6 = 0;

        scanf("%d %d %d", &var_2, &var_3, &var_4);
        while (var_2--) {
            int var_7;
            int var_8;

            scanf("%d", &var_8);

            var_7 = (var_8 + 2) / 3;

            if (var_8 > 28 || var_8 < 2) {
                if (var_7 >= var_4) {
                    var_6++;
                }
                continue;
            } else {

                if (var_7 >= var_4) {
                    var_6++;
                } else {
                    if (var_7 + 1 >= var_4 && (var_8 % 3) != 1) {
                        var_5++;
                    }
                }
            }
        }
        if (var_5 >= var_3) {
            var_6 = var_6 + var_3;
        } else {
            var_6 = var_6 + var_5;
        }

        printf("Case #%d: %d\n", var_1, var_6);
    }

    return 0;
}
