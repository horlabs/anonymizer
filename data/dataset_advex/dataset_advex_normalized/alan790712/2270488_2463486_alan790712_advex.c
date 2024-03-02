#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long var_0;
long long var_1;
char var_2[10000001] = {0};
char var_3[1234];
int main(int argc, char **argv) {
    int var_4;
    int var_5;

    int var_6;
    int var_7;
    int var_8;

    long long var_9;
    int var_10 = 0;
    for (var_6 = 1; var_6 < 10000001; ++var_6) {
        sprintf(var_3, "%d", var_6);
        for (var_7 = 0, var_8 = strlen(var_3) - 1;
             var_7 < var_8 && var_3[var_7] == var_3[var_8]; ++var_7, --var_8) {
            ;
        }
        if (var_7 >= var_8) {
            var_2[var_6] = 1;
        }
    }
    scanf("%d", &var_5);

    for (var_4 = 1; var_4 <= var_5; ++var_4) {
        var_10 = 0;
        scanf("%lld %lld", &var_0, &var_1);
        for (var_9 = (long long)sqrt(var_0); var_9 * var_9 <= var_1; ++var_9) {
            if (var_9 * var_9 < var_0) {
                continue;
            } else {
                if (var_2[var_9]) {
                    sprintf(var_3, "%lld", var_9 * var_9);

                    for (var_7 = 0, var_8 = strlen(var_3) - 1;
                         var_7 < var_8 && var_3[var_7] == var_3[var_8];
                         ++var_7, --var_8) {
                        ;
                    }
                    if (var_7 >= var_8) {
                        ++var_10;
                    }
                }
            }
        }
        printf("Case #%d: ", var_4);
        printf("%d\n", var_10);
    }
    return 0;
}
