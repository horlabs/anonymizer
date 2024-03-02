#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;

    char var_4[4][5];
    char var_5;
    char var_6;
    char var_7;

    scanf("%d", &var_1);
    for (var_0 = 0; var_0 < var_1; var_0++) {
        var_6 = 0;
        var_5 = 0;
        for (var_2 = 0; var_2 < 4; var_2++) {
            scanf("%s", var_4[var_2]);
            for (var_3 = 0; var_3 < 4; var_3++) {
                if (var_4[var_2][var_3] != 'X' && var_4[var_2][var_3] != 'T') {
                    break;
                }
            }
            if (var_3 == 4) {
                var_6 = 'X';
            }
            for (var_3 = 0; var_3 < 4; var_3++) {
                if (var_4[var_2][var_3] != 'O' && var_4[var_2][var_3] != 'T') {
                    break;
                }
            }
            if (var_3 == 4) {
                var_6 = 'O';
            }
            for (var_3 = 0; var_3 < 4; var_3++) {
                if (var_4[var_2][var_3] == '.') {
                    var_5 = 1;
                }
            }
        }
        for (var_3 = 0; var_3 < 4; var_3++) {
            for (var_2 = 0; var_2 < 4; var_2++) {
                if (var_4[var_2][var_3] != 'X' && var_4[var_2][var_3] != 'T') {
                    break;
                }
            }
            if (var_2 == 4) {
                var_6 = 'X';
            }
            for (var_2 = 0; var_2 < 4; var_2++) {
                if (var_4[var_2][var_3] != 'O' && var_4[var_2][var_3] != 'T') {
                    break;
                }
            }
            if (var_2 == 4) {
                var_6 = 'O';
            }
        }
        for (var_3 = 0; var_3 < 4; var_3++) {
            if (var_4[var_3][var_3] != 'X' && var_4[var_3][var_3] != 'T') {
                break;
            }
        }
        if (var_3 == 4) {
            var_6 = 'X';
        }
        for (var_3 = 0; var_3 < 4; var_3++) {
            if (var_4[var_3][var_3] != 'O' && var_4[var_3][var_3] != 'T') {
                break;
            }
        }
        if (var_3 == 4) {
            var_6 = 'O';
        }
        for (var_3 = 0; var_3 < 4; var_3++) {
            if (var_4[3 - var_3][var_3] != 'X' &&
                var_4[3 - var_3][var_3] != 'T') {
                break;
            }
        }
        if (var_3 == 4) {
            var_6 = 'X';
        }
        for (var_3 = 0; var_3 < 4; var_3++) {
            if (var_4[3 - var_3][var_3] != 'O' &&
                var_4[3 - var_3][var_3] != 'T') {
                break;
            }
        }
        if (var_3 == 4) {
            var_6 = 'O';
        }
        if (var_6 == 0) {
            if (var_5 == 1) {
                printf("Case #%d: Game has not completed\n", var_0 + 1);
            } else {
                printf("Case #%d: Draw\n", var_0 + 1);
            }
        } else {
            printf("Case #%d: %c won\n", var_0 + 1, var_6);
        }
    }
    return 0;
}
