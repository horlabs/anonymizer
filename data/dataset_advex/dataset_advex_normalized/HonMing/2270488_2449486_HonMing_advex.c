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

    int var_12;
    int var_13[200][200];
    int var_14[200][200];

    unsigned long long var_15;

    scanf("%d", &var_6);

    for (var_2 = 1; var_2 <= var_6; var_2++) {
        memset(var_14, 0, 200 * 200);
        scanf("%d%d", &var_10, &var_11);
        for (var_0 = 0; var_0 < var_10; var_0++) {
            for (var_1 = 0; var_1 < var_11; var_1++) {
                scanf("%d", &var_13[var_0][var_1]);
                var_14[var_0][var_1] = 200;
            }
        }

        for (var_0 = 0; var_0 < var_10; var_0++) {
            var_12 = 0;
            for (var_1 = 0; var_1 < var_11; var_1++) {
                if (var_13[var_0][var_1] > var_12) {
                    var_12 = var_13[var_0][var_1];
                }
            }
            for (var_1 = 0; var_1 < var_11; var_1++) {
                if (var_12 < var_14[var_0][var_1]) {
                    var_14[var_0][var_1] = var_12;
                }
            }
        }
        for (var_0 = 0; var_0 < var_11; var_0++) {
            var_12 = 0;
            for (var_1 = 0; var_1 < var_10; var_1++) {
                if (var_13[var_1][var_0] > var_12) {
                    var_12 = var_13[var_1][var_0];
                }
            }
            for (var_1 = 0; var_1 < var_10; var_1++) {
                if (var_12 < var_14[var_1][var_0]) {
                    var_14[var_1][var_0] = var_12;
                }
            }
        }
        for (var_0 = 0; var_0 < var_10; var_0++) {
            for (var_1 = 0; var_1 < var_11; var_1++) {
                if (var_14[var_0][var_1] != var_13[var_0][var_1]) {
                    break;
                }
            }

            if (var_1 != var_11) {
                break;
            }
        }

        if (var_0 != var_10) {
            printf("Case #%d: NO\n", var_2);
        } else {
            printf("Case #%d: YES\n", var_2);
        }
    }
    return 0;
}
