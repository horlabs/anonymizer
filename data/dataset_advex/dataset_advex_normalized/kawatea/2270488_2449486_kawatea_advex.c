#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;

    scanf("%d", &var_0);

    for (var_1 = 0; var_1 < var_0; var_1++) {
        int var_2;
        int var_3;
        int var_4 = 0;
        int var_5 = 0;
        int var_6;
        int var_7;

        int var_8[100][100];
        int var_9[100][100] = {0};

        scanf("%d %d", &var_2, &var_3);

        for (var_6 = 0; var_6 < var_2; var_6++) {
            for (var_7 = 0; var_7 < var_3; var_7++) {
                scanf("%d", &var_8[var_6][var_7]);

                if (var_8[var_6][var_7] > var_4) {
                    var_4 = var_8[var_6][var_7];
                }
            }
        }

        for (var_6 = 0; var_6 < var_2; var_6++) {
            for (var_7 = 0; var_7 < var_3 - 1; var_7++) {
                if (var_8[var_6][var_7] != var_8[var_6][var_7 + 1]) {
                    break;
                }
            }

            if (var_7 == var_3 - 1) {
                for (var_7 = 0; var_7 < var_3; var_7++) {
                    var_9[var_6][var_7] = 1;
                }
            }
        }

        for (var_6 = 0; var_6 < var_3; var_6++) {
            for (var_7 = 0; var_7 < var_2 - 1; var_7++) {
                if (var_8[var_7][var_6] != var_8[var_7 + 1][var_6]) {
                    break;
                }
            }

            if (var_7 == var_2 - 1) {
                for (var_7 = 0; var_7 < var_2; var_7++) {
                    var_9[var_7][var_6] = 1;
                }
            }
        }

        for (var_6 = 0; var_6 < var_2; var_6++) {
            for (var_7 = 0; var_7 < var_3; var_7++) {
                if (var_8[var_6][var_7] != var_4 && var_9[var_6][var_7] == 0) {
                    var_5 = 1;
                }
            }
        }

        if (var_5 == 0) {
            printf("Case #%d: YES\n", var_1 + 1);
        } else {
            printf("Case #%d: NO\n", var_1 + 1);
        }
    }

    return 0;
}
