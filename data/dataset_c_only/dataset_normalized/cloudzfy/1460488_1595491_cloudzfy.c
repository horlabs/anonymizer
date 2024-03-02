#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;

    freopen("B-small-attempt4.in", "r", stdin);
    freopen("B-small-attempt4.out", "w", stdout);
    scanf("%d", &var_1);
    for (var_0 = 1; var_0 <= var_1; var_0++) {
        var_6 = 0;
        scanf("%d%d%d", &var_2, &var_3, &var_4);
        for (var_5 = 0; var_5 < var_2; var_5++) {
            scanf("%d", &var_7);
            if (var_7 >= var_4 * 3 - 2 && var_4 - 1 >= 0) {
                var_6++;
            } else {
                if (var_7 >= var_4 * 3 - 4 && var_3 > 0 && var_4 - 2 >= 0 &&
                    var_7 <= 28) {
                    var_6++;
                    var_3--;
                }
            }
        }
        printf("Case #%d: %d\n", var_0, var_6);
    }
    return 0;
}
