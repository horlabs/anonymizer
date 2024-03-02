#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1 = 0;

    for (scanf("%d", &var_0); var_0; var_0--) {
        int var_2;
        int var_3;

        int var_4[4][4];
        int var_5[4][4];

        static int var_6[16];
        int var_7;
        int var_8;
        scanf("%d", &var_2);
        for (var_8 = 0; var_8 < 4; var_8++) {
            int var_9;
            for (var_9 = 0; var_9 < 4; var_9++) {
                scanf("%d", var_4[var_8] + var_9);
            }
        }
        scanf("%d", &var_3);
        for (var_8 = 0; var_8 < 4; var_8++) {
            int var_10;
            for (var_10 = 0; var_10 < 4; var_10++) {
                scanf("%d", var_5[var_8] + var_10);
            }
        }
        memset(var_6, 0, sizeof var_6);
        for (var_8 = 0; var_8 < 4; var_8++) {
            var_6[var_4[var_2 - 1][var_8] - 1]++;
            var_6[var_5[var_3 - 1][var_8] - 1]++;
        }
        var_7 = -1;
        for (var_8 = 0; var_8 < 16; var_8++) {
            if (var_6[var_8] == 2) {
                if (var_7 != -1) {
                    var_7 = -2;
                    break;
                } else {
                    var_7 = var_8;
                }
            }
        }
        printf("Case #%d: ", ++var_1);
        if (var_7 == -1) {
            puts("Volunteer cheated!");
        } else {
            if (var_7 == -2) {
                puts("Bad magician!");
            } else {
                printf("%d\n", var_7 + 1);
            }
        }
    }
    return 0;
}
