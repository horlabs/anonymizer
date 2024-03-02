#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int var_0, char **var_1) {
    int var_2;
    int var_3;

    scanf("%d\n", &var_3);
    for (var_2 = 1; var_2 <= var_3; var_2++) {
        int var_4;
        int var_5;

        int var_6;
        int var_7;

        int var_8[4][4];
        int var_9[4][4];

        int var_10;
        int var_11;

        int var_12 = 0;
        scanf("%d\n", &var_4);
        for (var_6 = 0; var_6 < 4; var_6++) {
            for (var_7 = 0; var_7 < 4; var_7++) {
                scanf("%d ", &var_8[var_6][var_7]);
            }
        }
        scanf("%d\n", &var_5);
        for (var_6 = 0; var_6 < 4; var_6++) {
            for (var_7 = 0; var_7 < 4; var_7++) {
                scanf("%d ", &var_9[var_6][var_7]);
            }
        }
        for (var_10 = 0; var_10 < 4; var_10++) {
            for (var_11 = 0; var_11 < 4; var_11++) {
                if (var_8[var_4 - 1][var_10] == var_9[var_5 - 1][var_11]) {
                    if (var_12 > 0) {
                        var_12 = -1;
                    } else {
                        if (var_12 == 0) {
                            var_12 = var_9[var_5 - 1][var_11];
                        }
                    }
                }
            }
        }
        if (var_12 > 0) {
            printf("Case #%d: %d\n", var_2, var_12);
        } else {
            if (var_12 == 0) {
                printf("Case #%d: Volunteer cheated!\n", var_2);
            } else {
                printf("Case #%d: Bad magician!\n", var_2);
            }
        }
    }
    return 0;
}
