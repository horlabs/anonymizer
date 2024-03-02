#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8;
    int var_9[4][4];
    int var_10[4][4];

    scanf("%d", &var_0);
    for (var_1 = 1; var_1 <= var_0; var_1++) {
        scanf("%d", &var_7);
        var_7--;
        for (var_2 = 0; var_2 < 4; var_2++) {
            for (var_3 = 0; var_3 < 4; var_3++) {
                scanf("%d", &var_9[var_2][var_3]);
            }
        }
        scanf("%d", &var_8);
        var_8--;
        for (var_2 = 0; var_2 < 4; var_2++) {
            for (var_3 = 0; var_3 < 4; var_3++) {
                scanf("%d", &var_10[var_2][var_3]);
            }
        }
        var_5 = 0;
        var_6 = -1;
        for (var_3 = 0; var_3 < 4; var_3++) {
            for (var_4 = 0; var_4 < 4; var_4++) {
                if (var_9[var_7][var_3] == var_10[var_8][var_4]) {
                    var_5++;
                    var_6 = var_3;
                }
            }
        }
        printf("Case #%d: ", var_1);
        if (var_5 == 1) {
            printf("%d\n", var_9[var_7][var_6]);
        } else {
            printf("%s\n", var_5 ? "Bad magician!" : "Volunteer cheated!");
        }
    }

    return 0;
}
