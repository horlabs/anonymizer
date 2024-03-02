#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;

    scanf("%d", &var_0);

    for (var_1 = 0; var_1 < var_0; var_1++) {
        int var_2;
        int var_3;
        int var_4 = 0;
        int var_5;
        int var_6;

        int var_7[4][4];
        int var_8[4][4];
        int var_9[17] = {0};

        scanf("%d", &var_2);

        for (var_5 = 0; var_5 < 4; var_5++) {
            for (var_6 = 0; var_6 < 4; var_6++) {
                scanf("%d", &var_7[var_5][var_6]);
            }
        }

        scanf("%d", &var_3);

        for (var_5 = 0; var_5 < 4; var_5++) {
            for (var_6 = 0; var_6 < 4; var_6++) {
                scanf("%d", &var_8[var_5][var_6]);
            }
        }

        for (var_5 = 0; var_5 < 4; var_5++) {
            var_9[var_7[var_2 - 1][var_5]]++;
        }
        for (var_5 = 0; var_5 < 4; var_5++) {
            var_9[var_8[var_3 - 1][var_5]]++;
        }

        for (var_5 = 1; var_5 <= 16; var_5++) {
            if (var_9[var_5] == 2) {
                if (var_4 == 0) {
                    var_4 = var_5;
                } else {
                    var_4 = -1;
                }
            }
        }

        if (var_4 == 0) {
            printf("Case #%d: Volunteer cheated!\n", var_1 + 1);
        } else {
            if (var_4 == -1) {
                printf("Case #%d: Bad magician!\n", var_1 + 1);
            } else {
                printf("Case #%d: %d\n", var_1 + 1, var_4);
            }
        }
    }

    return 0;
}
