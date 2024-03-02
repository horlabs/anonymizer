#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;

    scanf("%d", &var_0);

    for (var_1 = 1; var_1 <= var_0; var_1++) {
        int var_2;
        int var_3;
        int var_4;
        int var_5;

        int var_6[100][100];
        int var_7[100][100] = {0};

        scanf("%d %d", &var_2, &var_3);
        for (var_4 = 0; var_4 < var_2; var_4++) {
            for (var_5 = 0; var_5 < var_3; var_5++) {
                scanf("%d", var_6[var_4] + var_5);
            }
        }

        int var_8;
        for (var_4 = 0; var_4 < var_2; var_4++) {
            var_8 = 0;
            for (var_5 = 0; var_5 < var_3; var_5++) {
                if (var_6[var_4][var_5] > var_8) {
                    var_8 = var_6[var_4][var_5];
                }
            }
            for (var_5 = 0; var_5 < var_3; var_5++) {
                if (var_6[var_4][var_5] == var_8) {
                    var_7[var_4][var_5] = 1;
                }
            }
        }

        for (var_5 = 0; var_5 < var_3; var_5++) {
            var_8 = 0;
            for (var_4 = 0; var_4 < var_2; var_4++) {
                if (var_6[var_4][var_5] > var_8) {
                    var_8 = var_6[var_4][var_5];
                }
            }
            for (var_4 = 0; var_4 < var_2; var_4++) {
                if (var_6[var_4][var_5] == var_8) {
                    var_7[var_4][var_5] = 1;
                }
            }
        }

        printf("Case #%d: ", var_1);

        for (var_4 = 0; var_4 < var_2; var_4++) {
            for (var_5 = 0; var_5 < var_3; var_5++) {
                if (!var_7[var_4][var_5]) {
                    break;
                }
            }
            if (var_5 < var_3) {
                break;
            }
        }

        if (var_4 == var_2) {
            printf("YES");
        } else {
            printf("NO");
        }
        printf("\n");
    }
    return 0;
}
