#include <stdio.h>

int var_0[105][105];
int var_1[105][105];
int main(int argc, char **argv) {
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8;

    scanf("%d", &var_2);
    for (var_3 = 1; var_3 <= var_2; var_3++) {
        scanf("%d %d", &var_4, &var_5);
        for (var_6 = 0; var_6 < var_4; var_6++) {
            for (var_7 = 0; var_7 < var_5; var_7++) {
                var_0[var_6][var_7] = 100;
                scanf("%d", &var_1[var_6][var_7]);
            }
        }
        for (var_6 = 0; var_6 < var_4; var_6++) {
            var_8 = 0;
            for (var_7 = 0; var_7 < var_5; var_7++) {
                if (var_1[var_6][var_7] > var_8) {
                    var_8 = var_1[var_6][var_7];
                }
            }
            for (var_7 = 0; var_7 < var_5; var_7++) {
                if (var_0[var_6][var_7] >= var_8) {
                    var_0[var_6][var_7] = var_8;
                }
            }
        }
        for (var_6 = 0; var_6 < var_5; var_6++) {
            var_8 = 0;
            for (var_7 = 0; var_7 < var_4; var_7++) {
                if (var_1[var_7][var_6] > var_8) {
                    var_8 = var_1[var_7][var_6];
                }
            }
            for (var_7 = 0; var_7 < var_4; var_7++) {
                if (var_0[var_7][var_6] >= var_8) {
                    var_0[var_7][var_6] = var_8;
                }
            }
        }
        printf("Case #%d: ", var_3);
        for (var_6 = 0; var_6 < var_4; var_6++) {
            for (var_7 = 0; var_7 < var_5; var_7++) {
                if (var_0[var_6][var_7] != var_1[var_6][var_7]) {
                    break;
                }
            }
            if (var_7 < var_5) {
                break;
            }
        }
        if (var_6 < var_4) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}
