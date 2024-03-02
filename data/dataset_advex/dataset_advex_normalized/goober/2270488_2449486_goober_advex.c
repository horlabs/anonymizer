#include <stdio.h>

int var_0[100][100];
int var_1;
int var_2;

int func_0() {
    for (int var_3 = 0; var_3 < var_1; var_3++) {
        for (int var_4 = 0; var_4 < var_2; var_4++) {
            int var_5 = 1;
            for (int var_6 = 0; var_5 && var_6 < var_1; var_6++) {
                if (var_0[var_6][var_4] > var_0[var_3][var_4]) {
                    var_5 = 0;
                }
            }
            if (var_5) {
                continue;
            } else {
                var_5 = 1;
                for (int var_7 = 0; var_5 && var_7 < var_2; var_7++) {
                    if (var_0[var_3][var_7] > var_0[var_3][var_4]) {
                        var_5 = 0;
                    }
                }
                if (var_5) {
                    continue;
                } else {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main(int argc, char **argv) {
    int var_8;
    scanf("%d", &var_8);
    for (int var_9 = 1; var_9 <= var_8; var_9++) {
        scanf("%d %d", &var_1, &var_2);
        for (int var_10 = 0; var_10 < var_1; var_10++) {
            for (int var_11 = 0; var_11 < var_2; var_11++) {
                scanf("%d", &var_0[var_10][var_11]);
            }
        }
        printf("Case #%d: %s\n", var_9, func_0() ? "YES" : "NO");
    }
    return 0;
}
