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
    char var_7[10][10];
    int var_8;
    int var_9;
    int var_10;

    unsigned long long var_11;

    scanf("%d", &var_6);

    for (var_2 = 1; var_2 <= var_6; var_2++) {
        var_8 = 1;
        var_9 = 0;
        var_10 = 0;
        memset(var_7, 0, 100);
        var_11 = 0;
        for (var_0 = 0; var_0 < 4; var_0++) {
            scanf("%s", var_7[var_0]);
        }

        for (var_0 = 0; var_0 < 4; var_0++) {
            for (var_1 = 0; var_1 < 4; var_1++) {
                if (var_7[var_0][var_1] == '.') {
                    break;
                }
            }
            if (var_1 != 4) {
                break;
            }
        }
        if (var_0 != 4 && var_1 != 4) {
            var_8 = 0;
        }

        for (var_0 = 0; var_0 < 4; var_0++) {
            for (var_1 = 0; var_1 < 4; var_1++) {
                if (var_7[var_0][var_1] != 'O' && var_7[var_0][var_1] != 'T') {
                    break;
                }
            }
            if (var_1 == 4) {
                var_10 = 1;
            }
            for (var_1 = 0; var_1 < 4; var_1++) {
                if (var_7[var_0][var_1] != 'X' && var_7[var_0][var_1] != 'T') {
                    break;
                }
            }
            if (var_1 == 4) {
                var_9 = 1;
            }
            for (var_1 = 0; var_1 < 4; var_1++) {
                if (var_7[var_1][var_0] != 'O' && var_7[var_1][var_0] != 'T') {
                    break;
                }
            }
            if (var_1 == 4) {
                var_10 = 1;
            }
            for (var_1 = 0; var_1 < 4; var_1++) {
                if (var_7[var_1][var_0] != 'X' && var_7[var_1][var_0] != 'T') {
                    break;
                }
            }
            if (var_1 == 4) {
                var_9 = 1;
            }
        }

        for (var_0 = 0; var_0 < 4; var_0++) {
            if (var_7[var_0][var_0] != 'X' && var_7[var_0][var_0] != 'T') {
                break;
            }
        }
        if (var_0 == 4) {
            var_9 = 1;
        }

        for (var_0 = 0; var_0 < 4; var_0++) {
            if (var_7[3 - var_0][var_0] != 'X' &&
                var_7[3 - var_0][var_0] != 'T') {
                break;
            }
        }
        if (var_0 == 4) {
            var_9 = 1;
        }

        for (var_0 = 0; var_0 < 4; var_0++) {
            if (var_7[var_0][var_0] != 'O' && var_7[var_0][var_0] != 'T') {
                break;
            }
        }
        if (var_0 == 4) {
            var_10 = 1;
        }

        for (var_0 = 0; var_0 < 4; var_0++) {
            if (var_7[3 - var_0][var_0] != 'O' &&
                var_7[3 - var_0][var_0] != 'T') {
                break;
            }
        }
        if (var_0 == 4) {
            var_10 = 1;
        }

        if (var_9 == 1) {
            printf("Case #%d: X won\n", var_2);
        } else {
            if (var_10 == 1) {
                printf("Case #%d: O won\n", var_2);
            } else {
                if (var_8 == 1) {
                    printf("Case #%d: Draw\n", var_2);
                } else {
                    printf("Case #%d: Game has not completed\n", var_2);
                }
            }
        }
    }
    return 0;
}
