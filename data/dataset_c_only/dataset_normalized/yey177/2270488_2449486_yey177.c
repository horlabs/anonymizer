#include <stdio.h>

int var_0[102][102];

int main(int argc, char **argv) {
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

    scanf("%d", &var_1);
    for (var_7 = 1; var_7 <= var_1; var_7++) {
        scanf("%d%d", &var_2, &var_3);
        for (var_4 = 0; var_4 < var_2; var_4++) {
            for (var_5 = 0; var_5 < var_3; var_5++) {
                scanf("%d", &var_0[var_4][var_5]);
            }
        }
        var_10 = 1;
        for (var_6 = 1; var_6 <= 100; var_6++) {
            for (var_4 = 0; var_4 < var_2; var_4++) {
                var_9 = 101;
                var_8 = 0;
                for (var_5 = 0; var_5 < var_3; var_5++) {
                    if (var_0[var_4][var_5]) {
                        var_9 = (var_9 < var_0[var_4][var_5])
                                    ? var_9
                                    : var_0[var_4][var_5];
                        var_8 = (var_8 > var_0[var_4][var_5])
                                    ? var_8
                                    : var_0[var_4][var_5];
                    }
                }
                if (var_9 == var_6 && var_8 == var_6) {
                    for (var_5 = 0; var_5 < var_3; var_5++) {
                        var_0[var_4][var_5] = 0;
                    }
                }
            }
            for (var_5 = 0; var_5 < var_3; var_5++) {
                var_9 = 101;
                var_8 = 0;
                for (var_4 = 0; var_4 < var_2; var_4++) {
                    if (var_0[var_4][var_5]) {
                        var_9 = (var_9 < var_0[var_4][var_5])
                                    ? var_9
                                    : var_0[var_4][var_5];
                        var_8 = (var_8 > var_0[var_4][var_5])
                                    ? var_8
                                    : var_0[var_4][var_5];
                    }
                }
                if (var_9 == var_6 && var_8 == var_6) {
                    for (var_4 = 0; var_4 < var_2; var_4++) {
                        var_0[var_4][var_5] = 0;
                    }
                }
            }
            for (var_4 = 0; var_4 < var_2; var_4++) {
                for (var_5 = 0; var_5 < var_3; var_5++) {
                    if (var_0[var_4][var_5] == var_6) {
                        var_10 = 0;
                        goto END;
                    }
                }
            }
        }
    END:
        printf("Case #%d: %s\n", var_7, var_10 ? "YES" : "NO");
    }
    return 0;
}
