#include <stdio.h>
#include <string.h>

int var_0[5][10][10];
int var_1[20];

int main(int argc, char **argv) {
    int var_2;
    int var_3 = 1;

    int var_4;
    int var_5;
    int var_6;
    int var_7;

    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A_out.txt", "w", stdout);
    scanf("%d", &var_2);
    while (var_2--) {
        memset(var_1, 0, sizeof var_1);
        scanf("%d", &var_6);
        for (var_4 = 1; var_4 <= 4; var_4++) {
            for (var_5 = 1; var_5 <= 4; var_5++) {
                scanf("%d", &var_0[0][var_4][var_5]);
            }
        }
        for (var_4 = 1; var_4 <= 4; var_4++) {
            var_1[var_0[0][var_6][var_4]] = 1;
        }

        scanf("%d", &var_7);
        for (var_4 = 1; var_4 <= 4; var_4++) {
            for (var_5 = 1; var_5 <= 4; var_5++) {
                scanf("%d", &var_0[1][var_4][var_5]);
            }
        }

        int var_8 = 0;
        for (var_4 = 1; var_4 <= 4; var_4++) {
            if (var_1[var_0[1][var_7][var_4]]) {
                if (var_8 != 0) {
                    var_8 = -1;
                } else {
                    var_8 = var_0[1][var_7][var_4];
                }
            }
        }

        printf("Case #%d: ", var_3++);
        if (var_8 == -1) {
            puts("Bad magician!");
        } else {
            if (var_8 == 0) {
                puts("Volunteer cheated!");
            } else {
                printf("%d\n", var_8);
            }
        }
    }
    return 0;
}
