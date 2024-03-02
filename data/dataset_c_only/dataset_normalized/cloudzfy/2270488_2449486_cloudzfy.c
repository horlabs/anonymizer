#include <stdio.h>
#include <string.h>
int var_0;
int var_1;
int var_2[100][100];
int var_3[100][100];

int main(int argc, char **argv) {
    int var_4;
    int var_5;

    freopen("B-small-attempt1.in.txt", "r", stdin);
    freopen("B-small-attempt1.out.txt", "w", stdout);
    scanf("%d", &var_4);
    for (int var_6 = 1; var_6 <= var_4; var_6++) {
        memset(var_3, 0, sizeof var_3);
        scanf("%d%d", &var_0, &var_1);
        for (int var_7 = 0; var_7 < var_0; var_7++) {
            for (int var_8 = 0; var_8 < var_1; var_8++) {
                scanf("%d", &var_2[var_7][var_8]);
            }
        }
        for (int var_9 = 0; var_9 < var_0 + var_1; var_9++) {
            int var_10 = 200;
            int var_11[2];

            for (int var_12 = 0; var_12 < var_0; var_12++) {
                for (int var_13 = 0; var_13 < var_1; var_13++) {
                    if (!var_3[var_12][var_13] &&
                        var_2[var_12][var_13] < var_10) {
                        var_11[0] = var_12;
                        var_11[1] = var_13;
                        var_10 = var_2[var_12][var_13];
                    }
                }
            }
            var_5 = 1;
            for (int var_14 = 0; var_14 < var_0; var_14++) {
                if (!var_3[var_14][var_11[1]] &&
                    var_2[var_14][var_11[1]] != var_2[var_11[0]][var_11[1]]) {
                    var_5 = 0;
                    break;
                }
            }
            if (!var_5) {
                var_5 = 2;
                for (int var_15 = 0; var_15 < var_1; var_15++) {
                    if (!var_3[var_11[0]][var_15] &&
                        var_2[var_11[0]][var_15] !=
                            var_2[var_11[0]][var_11[1]]) {
                        var_5 = 0;
                        break;
                    }
                }
            }
            if (var_5 == 1) {
                for (int var_16 = 0; var_16 < var_0; var_16++) {
                    var_3[var_16][var_11[1]] = 1;
                }
            } else {
                if (var_5 == 2) {
                    for (int var_17 = 0; var_17 < var_1; var_17++) {
                        var_3[var_11[0]][var_17] = 1;
                    }
                } else {
                    break;
                }
            }
        }
        if (var_5 == 0) {
            printf("Case #%d: NO\n", var_6);
        } else {
            printf("Case #%d: YES\n", var_6);
        }
    }
    return 0;
}
