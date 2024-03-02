#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    scanf("%d", &var_0);
    for (int var_1 = 1; var_1 <= var_0; var_1++) {
        int var_2;
        int var_3;
        int var_4;

        scanf("%d %d %d", &var_2, &var_3, &var_4);
        int var_5 = 0;
        for (int var_6 = 0; var_6 < var_2; var_6++) {
            int var_7;
            scanf("%d", &var_7);
            if (var_7 >= 3 * var_4 - 2) {
                var_5++;
            } else {
                if (var_7 >= 3 * var_4 - 4 && var_7 >= 2 && var_3 > 0) {
                    var_5++;
                    var_3--;
                }
            }
        }
        printf("Case #%d: %d\n", var_1, var_5);
    }
    return 0;
}
