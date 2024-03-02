#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3[4];
    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8;

    scanf("%d", &var_0);
    for (var_4 = 0; var_4 < var_0; var_4++) {
        scanf("%d", &var_1);
        for (var_5 = 0; var_5 < (var_1 - 1) * 4; var_5++) {
            scanf("%d", &var_6);
        }
        for (; var_5 < 4 * var_1; var_5++) {
            scanf("%d", &var_3[var_5 - (var_1 - 1) * 4]);
        }
        for (; var_5 < 16; var_5++) {
            scanf("%d", &var_6);
        }
        scanf("%d", &var_1);
        for (var_5 = 0; var_5 < (var_1 - 1) * 4; var_5++) {
            scanf("%d", &var_6);
        }
        var_8 = -1;
        for (; var_5 < var_1 * 4; var_5++) {
            scanf("%d", &var_6);
            for (var_7 = 0; var_7 < 4; var_7++) {
                if (var_6 == var_3[var_7]) {
                    if (var_8 == -1) {
                        var_8 = var_3[var_7];
                    } else {
                        var_8 = 0;
                    }
                }
            }
        }
        for (; var_5 < 16; var_5++) {
            scanf("%d", &var_6);
        }
        printf("Case #%d: ", var_4 + 1);
        if (var_8 == (-1)) {
            puts("Volunteer cheated!");
        } else if (var_8 == 0) {
            puts("Bad magician!");
        } else {
            printf("%d\n", var_8);
        }
    }
    return 0;
}
