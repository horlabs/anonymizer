#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int var_0[16];
int var_1[16];

int main(int argc, char **argvvoid) {
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;

    int var_7;
    int var_8;

    int var_9;
    int var_10;

    scanf("%d", &var_2);
    for (var_4 = 1; var_4 <= var_2; ++var_4) {
        var_7 = -1;
        var_8 = 0;
        scanf("%d", &var_9);
        for (var_5 = 0; var_5 < 16; ++var_5) {
            scanf("%d", var_0 + var_5);
        }
        scanf("%d", &var_10);
        for (var_5 = 0; var_5 < 16; ++var_5) {
            scanf("%d", var_1 + var_5);
        }
        for (var_5 = 1; var_5 <= 4; ++var_5) {
            for (var_6 = 1; var_6 <= 4; ++var_6) {
                if (var_0[var_9 * 4 - var_5] == var_1[var_10 * 4 - var_6]) {
                    var_7 = var_0[var_9 * 4 - var_5];
                    ++var_8;
                }
            }
        }

        printf("Case #%d: ", var_4);
        if (var_8 == 1) {
            printf("%d\n", var_7);
        } else if (var_8 == 0) {
            printf("Volunteer cheated!\n");
        } else {
            printf("Bad magician!\n");
        }
    }

    return 0;
}
