#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int var_0;
int var_1;
int var_2;
int var_3[10][10];
int var_4[20];
int var_5;
int var_6;
int var_7;
int var_8;

int func_0() {
    var_8 = 0;
    for (var_5 = 1; var_5 <= 16; var_5++) {
        if (var_4[var_5] == 2) {
            if (var_8) {
                return 0;
            } else {
                var_8 = var_5;
            }
        }
    }
    return 1;
}

int main(int argc, char **argv) {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

    scanf("%d", &var_0);
    for (var_1 = 1; var_1 <= var_0; var_1++) {
        printf("Case #%d: ", var_1);

        memset(var_4, 0, sizeof var_4);
        for (var_5 = 0; var_5 < 2; var_5++) {
            scanf("%d", &var_2);
            for (var_7 = 1; var_7 <= 4; var_7++) {
                for (var_6 = 0; var_6 < 4; var_6++) {
                    scanf("%d", &var_3[var_7][var_6]);
                }
            }
            for (var_6 = 0; var_6 < 4; var_6++) {
                var_4[var_3[var_2][var_6]]++;
            }
        }

        if (!func_0()) {
            puts("Bad magician!");
        } else {
            if (var_8) {
                printf("%d\n", var_8);
            } else {
                puts("Volunteer cheated!");
            }
        }
    }

    return 0;
}
