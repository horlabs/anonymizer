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
    int var_8;

    int var_9[4];
    scanf("%d", &var_0);
    for (var_8 = 1; var_8 <= var_0; var_8++) {
        scanf("%d", &var_4);
        for (var_2 = 0; var_2 < 4; var_2++) {
            for (var_3 = 0; var_3 < 4; var_3++) {
                scanf("%d", &var_5);
                if (var_2 == (var_4 - 1)) {
                    var_9[var_3] = var_5;
                }
            }
        }
        var_7 = 0;
        scanf("%d", &var_4);
        for (var_2 = 0; var_2 < 4; var_2++) {
            for (var_3 = 0; var_3 < 4; var_3++) {
                scanf("%d", &var_5);
                if ((var_2 == (var_4 - 1)) &&
                    ((var_5 == var_9[0]) || (var_5 == var_9[1]) ||
                     (var_5 == var_9[2]) || (var_5 == var_9[3]))) {
                    if (var_7 == 0) {
                        var_6 = var_5;
                        var_7 = 1;
                    } else {
                        var_7 = 2;
                    }
                }
            }
        }
        if (var_7 == 1) {
            printf("Case #%d: %d\n", var_8, var_6);
        } else {
            if (var_7 == 0) {
                printf("Case #%d: Volunteer cheated!\n", var_8);
            } else {
                printf("Case #%d: Bad magician!\n", var_8);
            }
        }
    }
    return 0;
}
