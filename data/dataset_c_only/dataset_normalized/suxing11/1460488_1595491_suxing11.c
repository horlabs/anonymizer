#include <stdio.h>

int var_0[110];

int main(int argc, char **argv) {
    int var_1;
    int var_2;
    int var_3 = 1;

    int var_4;
    int var_5;

    int var_6;
    int var_7;
    int var_8;

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("bout.txt", "w", stdout);
    scanf("%d", &var_1);
    while (var_1--) {
        scanf("%d%d%d", &var_6, &var_7, &var_8);
        var_4 = 0;
        var_5 = 0;
        for (var_2 = 0; var_2 < var_6; var_2++) {
            scanf("%d", &var_0[var_2]);
            if (var_0[var_2] >= 3 * var_8 - 2) {
                var_4++;
            } else {
                if (var_8 > 1 && var_0[var_2] >= 3 * var_8 - 4) {
                    var_5++;
                }
            }
        }
        if (var_5 > var_7) {
            var_5 = var_7;
        }
        printf("Case #%d: %d\n", var_3++, var_4 + var_5);
    }
    return 0;
}
