#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int var_0, char **var_1) {
    int var_2;
    int var_3;

    int var_4;
    int var_5;

    int var_6;
    int var_7;

    scanf("%d\n", &var_3);
    for (var_2 = 1; var_2 <= var_3; var_2++) {
        scanf("%d %d\n", &var_5, &var_4);
        int var_8[var_4][var_5];
        int var_9[var_4][var_5];

        for (var_7 = 0; var_7 < var_5; var_7++) {
            for (var_6 = 0; var_6 < var_4; var_6++) {
                scanf("%d ", &var_8[var_6][var_7]);
                var_9[var_6][var_7] = 100;
            }
        }

        for (var_7 = 0; var_7 < var_5; var_7++) {
            int var_10 = 0;
            for (var_6 = 0; var_6 < var_4; var_6++) {
                if (var_10 < var_8[var_6][var_7]) {
                    var_10 = var_8[var_6][var_7];
                }
            }
            for (var_6 = 0; var_6 < var_4; var_6++) {
                if (var_10 < var_9[var_6][var_7]) {
                    var_9[var_6][var_7] = var_10;
                }
            }
        }

        for (var_6 = 0; var_6 < var_4; var_6++) {
            int var_11 = 0;
            for (var_7 = 0; var_7 < var_5; var_7++) {
                if (var_11 < var_8[var_6][var_7]) {
                    var_11 = var_8[var_6][var_7];
                }
            }
            for (var_7 = 0; var_7 < var_5; var_7++) {
                if (var_11 < var_9[var_6][var_7]) {
                    var_9[var_6][var_7] = var_11;
                }
            }
        }

        int var_12 = 1;
        for (var_7 = 0; var_7 < var_5; var_7++) {
            for (var_6 = 0; var_6 < var_4; var_6++) {
                if (var_9[var_6][var_7] != var_8[var_6][var_7]) {
                    var_12 = 0;
                }
            }
        }
        printf("Case #%d: %s\n", var_2, var_12 ? "YES" : "NO");
    }
    return 0;
}
