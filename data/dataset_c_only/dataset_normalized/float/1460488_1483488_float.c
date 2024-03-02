#include <stdio.h>
#include <stdlib.h>

int func_0(int var_0) {
    int var_1 = 1;
    while (var_0 / var_1 >= 10) {
        var_1 = var_1 * 10;
    }
    while (var_0 % 10 == 0) {
        var_0 = var_0 / 10;
    }
    var_0 = var_0 / 10 + (var_0 % 10) * var_1;
    return var_0;
}

int main(int argc, char **argv) {
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8;

    scanf("%d", &var_2);
    for (var_5 = 1; var_5 <= var_2; var_5++) {
        scanf("%d %d", &var_3, &var_4);
        var_8 = 0;
        for (var_6 = var_3; var_6 <= var_4; var_6++) {
            var_7 = var_6;
            do {
                var_7 = func_0(var_7);
                if (var_7 > var_6 && var_7 >= var_3 && var_7 <= var_4) {
                    var_8++;
                }
            } while (var_7 != var_6);
        }
        printf("Case #%d: %d\n", var_5, var_8);
    }
    return 0;
}
