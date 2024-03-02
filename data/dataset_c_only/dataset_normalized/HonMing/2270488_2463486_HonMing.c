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
    unsigned long long var_13[10000];

    int var_14;
    unsigned long long var_15;
    unsigned long long var_16;
    unsigned long long var_17;

    char var_18[200];

    var_1 = 0;
    for (var_15 = 1; var_15 <= 10000000; var_15++) {
        sprintf(var_18, "%llu", var_15);
        for (var_0 = 0; var_0 < strlen(var_18) / 2; var_0++) {
            if (var_18[var_0] != var_18[strlen(var_18) - 1 - var_0]) {
                break;
            }
        }

        if (var_0 != strlen(var_18) / 2) {
            continue;
        } else {

            sprintf(var_18, "%llu", var_15 * var_15);

            for (var_0 = 0; var_0 < strlen(var_18) / 2; var_0++) {
                if (var_18[var_0] != var_18[strlen(var_18) - 1 - var_0]) {
                    break;
                }
            }

            if (var_0 == strlen(var_18) / 2) {
                var_13[var_1++] = var_15 * var_15;
            }
        }
    }

    scanf("%d", &var_6);

    for (var_2 = 1; var_2 <= var_6; var_2++) {
        var_14 = 0;
        scanf("%llu%llu", &var_16, &var_17);

        for (var_0 = 0; var_0 < var_1; var_0++) {
            if (var_13[var_0] >= var_16 && var_13[var_0] <= var_17) {
                var_14++;
            }

            if (var_13[var_0] > var_17) {
                break;
            }
        }
        printf("Case #%d: %d\n", var_2, var_14);
    }
    return 0;
}
