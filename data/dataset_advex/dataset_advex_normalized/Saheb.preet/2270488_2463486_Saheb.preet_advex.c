#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4;

    scanf("%d", &var_0);
    for (var_1 = 0; var_1 < var_0; var_1++) {
        var_4 = 0;
        scanf("%d%d", &var_2, &var_3);
        if (var_2 <= 1 && var_3 >= 1) {
            var_4++;
        }
        if (var_2 <= 4 && var_3 >= 4) {
            var_4++;
        }
        if (var_2 <= 9 && var_3 >= 9) {
            var_4++;
        }
        if (var_2 <= 121 && var_3 >= 121) {
            var_4++;
        }
        if (var_2 <= 484 && var_3 >= 484) {
            var_4++;
        }
        printf("Case #%d: %d\n", var_1 + 1, var_4);
    }
    return 0;
}
