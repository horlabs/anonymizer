#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char func_0(unsigned long long var_0) {
    int var_1 = 1;
    char var_2[1024] = "";

    if (sprintf(var_2, "%llu", var_0) > 0) {
        unsigned int var_3 = strlen(var_2);

        for (var_0 = 0; var_0 < (var_3 / 2) + 1 && var_1; var_0++) {
            if (var_2[var_0] != var_2[var_3 - var_0 - 1]) {
                var_1 = 0;
            }
        }
    }

    return var_1;
}

int main(int argc, char **argvvoid) {
    freopen("C-small-attempt0.in", "r", stdin);

    int var_4 = 0;
    int var_5;

    scanf("%d\n", &var_5);

    while (var_4 < var_5) {
        unsigned long long var_6 = 0;
        unsigned long long var_7;
        unsigned long long var_8;

        scanf("%llu %llu\n", &var_7, &var_8);

        for (; var_7 <= var_8; var_7++) {
            if (func_0(var_7)) {
                long double var_9 = sqrtl(var_7);

                if ((var_9 - (long long)var_9 < 9.99999999999999999978E-19L) &&
                    func_0((unsigned long long)var_9)) {
                    var_6++;
                }
            }
        }

        printf("Case #%d: %llu\n", ++var_4, var_6);
    }

    return 0;
}
