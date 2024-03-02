#include <stdio.h>

int main(int argc, char **argvvoid) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;

    int var_8[4][4];
    int var_9[4][4];

    scanf("%d", &var_0);
    for (var_1 = 1; var_1 <= var_0; var_1++) {

        scanf("%d", &var_2);
        for (var_4 = 0; var_4 < 4; var_4++) {
            for (var_5 = 0; var_5 < 4; var_5++) {
                scanf("%d", &var_8[var_4][var_5]);
            }
        }
        scanf("%d", &var_3);
        for (var_4 = 0; var_4 < 4; var_4++) {
            for (var_5 = 0; var_5 < 4; var_5++) {
                scanf("%d", &var_9[var_4][var_5]);
            }
        }

        var_6 = 0;
        for (var_4 = 0; var_4 < 4; var_4++) {
            for (var_5 = 0; var_5 < 4; var_5++) {

                if (var_8[var_2 - 1][var_4] == var_9[var_3 - 1][var_5]) {
                    var_7 = var_8[var_2 - 1][var_4];
                    var_6++;
                }
            }
        }

        if (var_6 == 0) {
            printf("Case #%d: Volunteer cheated!\n", var_1);
        } else {
            if (var_6 == 1) {
                printf("Case #%d: %d\n", var_1, var_7);
            } else {
                printf("Case #%d: Bad magician!\n", var_1);
            }
        }
    }

    return 0;
}
