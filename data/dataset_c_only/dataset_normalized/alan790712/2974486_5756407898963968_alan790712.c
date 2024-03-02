#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int var_0;
int var_1;
int var_2[2][5];
int var_3[2];
int main(int argc, char **argv) {
    int var_4;
    int var_5;
    int var_6;

    int var_7;
    scanf("%d", &var_1);
    for (var_0 = 1; var_0 <= var_1; ++var_0) {
        for (var_4 = 0; var_4 < 2; ++var_4) {
            scanf("%d", &var_3[var_4]);
            for (var_5 = 1; var_5 <= 4; ++var_5) {
                for (var_6 = 1; var_6 <= 4; ++var_6) {
                    if (var_5 == var_3[var_4]) {
                        scanf("%d", &var_2[var_4][var_6]);
                    } else {
                        scanf("%*d");
                    }
                }
            }
        }
        for (var_4 = 1, var_7 = -1; var_4 <= 4; ++var_4) {
            for (var_5 = 1; var_5 <= 4; ++var_5) {
                if (var_2[0][var_4] == var_2[1][var_5]) {
                    if (var_7 == -1) {
                        var_7 = var_2[0][var_4];
                    } else {
                        break;
                    }
                }
            }
            if (var_5 <= 4) {
                break;
            }
        }
        printf("Case #%d: ", var_0);
        if (var_7 != -1 && var_4 > 4) {
            printf("%d\n", var_7);
        } else {
            if (var_7 != -1 && var_4 <= 4) {
                printf("Bad magician!\n");
            } else {
                printf("Volunteer cheated!\n");
            }
        }
    }

    return 0;
}
