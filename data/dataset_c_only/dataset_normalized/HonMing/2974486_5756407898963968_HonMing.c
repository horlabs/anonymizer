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
    int var_7[10][10];
    int var_8;
    int var_9;
    int var_10;

    int var_11;
    int var_12;

    int var_13[10];
    int var_14[10];
    int var_15;
    int var_16;

    unsigned long long var_17;

    scanf("%d", &var_6);

    for (var_2 = 1; var_2 <= var_6; var_2++) {
        scanf("%d", &var_11);
        for (var_0 = 0; var_0 < 4; var_0++) {
            for (var_1 = 0; var_1 < 4; var_1++) {
                scanf("%d", &var_7[var_0][var_1]);
                if (var_0 == var_11 - 1) {
                    var_13[var_1] = var_7[var_0][var_1];
                }
            }
        }
        scanf("%d", &var_12);
        for (var_0 = 0; var_0 < 4; var_0++) {
            for (var_1 = 0; var_1 < 4; var_1++) {
                scanf("%d", &var_7[var_0][var_1]);
                if (var_0 == var_12 - 1) {
                    var_14[var_1] = var_7[var_0][var_1];
                }
            }
        }
        var_15 = 0;
        var_16 = -1;

        for (var_0 = 0; var_0 < 4; var_0++) {
            for (var_1 = 0; var_1 < 4; var_1++) {
                if (var_13[var_0] == var_14[var_1]) {
                    var_16 = var_13[var_0];
                    var_15++;
                    break;
                }
            }
        }

        if (var_15 == 0) {
            printf("Case #%d: Volunteer cheated!\n", var_2);
        } else {
            if (var_15 == 1) {
                printf("Case #%d: %d\n", var_2, var_16);
            } else {
                printf("Case #%d: Bad magician!\n", var_2);
            }
        }
    }
    return 0;
}
