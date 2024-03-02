#include <stdio.h>
#include <string.h>

int var_0[16];
int main(int argc, char **argv) {
    freopen("A-small-attempt0.in.txt", "r", stdin);
    freopen("A-small-attempt0.out.txt", "w", stdout);
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;

    scanf("%d", &var_2);
    for (var_1 = 1; var_1 <= var_2; var_1++) {
        memset(var_0, 0, sizeof var_0);
        scanf("%d", &var_3);
        for (int var_7 = 0; var_7 < 4; var_7++) {
            for (int var_8 = 0; var_8 < 4; var_8++) {
                scanf("%d", &var_5);
                if (var_7 == var_3 - 1) {
                    var_0[var_5 - 1]++;
                }
            }
        }
        scanf("%d", &var_4);
        for (int var_9 = 0; var_9 < 4; var_9++) {
            for (int var_10 = 0; var_10 < 4; var_10++) {
                scanf("%d", &var_5);
                if (var_9 == var_4 - 1) {
                    var_0[var_5 - 1]++;
                }
            }
        }
        var_6 = 0;
        for (int var_11 = 0; var_11 < 16; var_11++) {
            if (var_0[var_11] == 2 && var_6 == 0) {
                var_6 = var_11 + 1;
            } else {
                if (var_0[var_11] == 2 && var_6 != 0) {
                    var_6 = -1;
                }
            }
        }
        printf("Case #%d: ", var_1);
        if (var_6 == 0) {
            printf("Volunteer cheated!\n");
        } else {
            if (var_6 == -1) {
                printf("Bad magician!\n");
            } else {
                printf("%d\n", var_6);
            }
        }
    }
    return 0;
}
