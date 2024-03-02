#include <stdio.h>
#include <stdlib.h>

int func_0(int var_0[100][100], int var_1[100][100], int var_2, int var_3) {
    int var_4;
    int var_5;

    for (var_4 = 0; var_4 < var_2; var_4++) {
        for (var_5 = 0; var_5 < var_3; var_5++) {
            if (var_0[var_4][var_5] != var_1[var_4][var_5]) {
                return 0;
            }
        }
    }
    return 1;
}
int main(int argc, char **argv) {
    int var_6;
    int var_7;
    int var_8;
    int var_9;
    int var_10;
    int var_11;
    int var_12 = 0;
    int var_13;

    int var_14[100][100];
    int var_15[100][100];

    var_7 = 1;
    for (scanf("%d", &var_6); var_7 <= var_6; var_7++) {
        scanf("%d%d", &var_8, &var_9);
        for (var_10 = 0; var_10 < var_8; var_10++) {
            for (var_11 = 0; var_11 < var_9; var_11++) {
                scanf("%d", &var_14[var_10][var_11]);
                if (var_14[var_10][var_11] > var_12) {
                    var_12 = var_14[var_10][var_11];
                }
            }
        }
        for (var_10 = 0; var_10 < var_8; var_10++) {
            for (var_11 = 0; var_11 < var_9; var_11++) {
                var_15[var_10][var_11] = var_12;
            }
        }
        for (var_10 = 0; var_10 < var_8; var_10++) {
            var_13 = var_14[var_10][0];
            {
                var_11 = 1;
                while (var_14[var_10][var_11] == var_13 && var_11 < var_9) {
                    var_11++;
                }
                if (var_11 == var_9) {
                    for (var_11 = 0; var_11 < var_9; var_11++) {
                        var_15[var_10][var_11] = var_13;
                    }
                }
            }
        }
        for (var_11 = 0; var_11 < var_9; var_11++) {
            var_13 = var_14[0][var_11];
            {
                var_10 = 1;
                while (var_14[var_10][var_11] == var_13 && var_10 < var_8) {
                    var_10++;
                }
                if (var_10 == var_8) {
                    for (var_10 = 0; var_10 < var_8; var_10++) {
                        var_15[var_10][var_11] = var_13;
                    }
                }
            }
        }

        printf("Case #%d: ", var_7);
        if (func_0(var_14, var_15, var_8, var_9)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
