#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;

    scanf("%d", &var_0);
    for (var_7 = 1; var_7 <= var_0; var_7++) {
        var_5 = var_6 = 0;
        scanf("%d%d%d", &var_1, &var_2, &var_3);
        while (var_1--) {
            scanf("%d", &var_4);
            if (var_4 >= var_3 * 3 - 2) {
                var_5++;
            } else {
                if (var_4 >= var_3 * 3 - 4 && var_4 >= 2) {
                    var_6++;
                }
            }
        }
        printf("Case #%d: %d\n", var_7,
               var_5 + (var_2 < var_6 ? var_2 : var_6));
    }
    return 0;
}
