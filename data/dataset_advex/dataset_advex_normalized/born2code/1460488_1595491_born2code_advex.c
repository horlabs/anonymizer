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

    scanf("%d", &var_2);
    for (var_6 = 1; var_6 <= var_2; var_6++) {
        scanf("%d%d%d", &var_3, &var_4, &var_5);
        var_1 = 0;
        for (var_7 = 0; var_7 < var_3; var_7++) {
            scanf("%d", &var_0);
            if (var_0 >= var_5) {
                if ((var_0 + 2) / 3 >= var_5) {
                    var_1++;
                } else {
                    if (var_4 && (var_0 + 1) / 3 == var_5 - 1) {
                        var_4--;
                        var_1++;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", var_6, var_1);
    }
    return 0;
}
