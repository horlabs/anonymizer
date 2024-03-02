#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int var_0;
int var_1;
int var_2;
int var_3;
int var_4[31][2];

int main(int argc, char **argv) {
    int var_5;
    int var_6;
    int var_7;

    int var_8;
    int var_9 = 0;
    for (var_6 = 0; var_6 < 31; ++var_6) {
        var_4[var_6][0] = (var_6 + 2) / 3;
        var_4[var_6][1] = 2 + (var_6 - 2) / 3;
        if (var_4[var_6][1] * 3 - 4 > var_6 || var_4[var_6][1] > 10) {
            var_4[var_6][1] = var_4[var_6][0];
        }
    }
    scanf("%d", &var_5);
    while (var_5--) {
        scanf("%d %d %d", &var_0, &var_1, &var_2);
        var_8 = 0;
        while (var_0--) {
            scanf(" %d", &var_3);

            if (var_4[var_3][0] >= var_2) {
                ++var_8;
            } else {
                if (var_4[var_3][1] >= var_2 && var_1 > 0) {
                    ++var_8;
                    --var_1;
                }
            }
        }
        printf("Case #%d: %d\n", ++var_9, var_8);
    }
    return 0;
}
