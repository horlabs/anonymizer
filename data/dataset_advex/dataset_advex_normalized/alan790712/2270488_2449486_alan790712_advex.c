#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int var_0;
int var_1;
int var_2[123][123];
int var_3;
int main(int argc, char **argv) {
    int var_4;
    int var_5;

    int var_6;
    int var_7;

    int var_8;
    int var_9;
    scanf("%d", &var_5);
    for (var_4 = 1; var_4 <= var_5; ++var_4) {
        scanf("%d %d", &var_0, &var_1);
        memset(var_2, 0, sizeof var_2);
        for (var_6 = var_9 = 1; var_6 <= var_0; ++var_6) {
            for (var_7 = 1; var_7 <= var_1; ++var_7) {
                scanf("%d", &var_2[var_6][var_7]);
                if (var_2[var_6][var_7] >= var_9) {
                    var_9 = var_2[var_6][var_7];
                }
            }
        }
        var_3 = 0;
        for (var_6 = 1; var_6 <= var_0 && !var_3; ++var_6) {
            for (var_7 = 1; var_7 <= var_1 && !var_3; ++var_7) {
                for (var_8 = 1; var_8 <= var_1 &&
                                var_2[var_6][var_8] <= var_2[var_6][var_7];
                     ++var_8) {
                    ;
                }
                if (var_8 > var_1) {
                    continue;
                } else {
                    for (var_8 = 1; var_8 <= var_0 &&
                                    var_2[var_8][var_7] <= var_2[var_6][var_7];
                         ++var_8) {
                        ;
                    }
                    if (var_8 <= var_0) {
                        var_3 = 1;
                    }
                }
            }
        }
        printf("Case #%d: ", var_4);
        if (!var_3) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
