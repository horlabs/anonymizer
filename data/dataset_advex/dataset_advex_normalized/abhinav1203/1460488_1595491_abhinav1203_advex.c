#include <stdio.h>

int var_0[105];
int main(int argc, char **argv) {
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7 = 1;

    scanf("%d", &var_6);
    while (var_6--) {
        scanf("%d %d %d", &var_1, &var_2, &var_3);
        for (var_4 = 0; var_4 < var_1; var_4++) {
            scanf("%d", &var_0[var_4]);
        }
        var_5 = 0;
        for (var_4 = 0; var_4 < var_1; var_4++) {
            if ((var_0[var_4] + 2) / 3 >= var_3) {
                var_5++;
            } else {
                if ((var_0[var_4] + 2) / 3 == (var_3 - 1) && var_2 > 0 &&
                    var_0[var_4] > 1 && var_0[var_4] % 3 != 1) {
                    var_5++;
                    var_2--;
                }
            }
        }
        printf("Case #%d: %d\n", var_7, var_5);
        var_7++;
    }
    return 0;
}
