#include <math.h>
#include <stdio.h>

int var_0[10000005];
int var_1[100];
int func_0(long long var_2) {
    int var_3 = 0;
    int var_4;

    while (var_2 > 0) {
        var_1[var_3++] = var_2 % 10;
        var_2 = var_2 / 10;
    }
    var_3--;
    var_4 = 0;
    while (var_3 > var_4 && var_1[var_3] == var_1[var_4]) {
        var_3--;
        var_4++;
    }
    if (var_3 <= var_4) {
        return 1;
    } else {
        return 0;
    }
}
int main(int argc, char **argv) {
    int var_5;
    int var_6;

    long long var_7;
    long long var_8;
    long long var_9;

    scanf("%d", &var_5);
    var_6 = 0;
    var_0[0] = 0;
    for (var_7 = 1; var_7 <= 1e7; var_7++) {
        if (func_0(var_7) && func_0(var_7 * var_7)) {
            var_6++;
        }
        var_0[var_7] = var_6;
    }
    for (var_7 = 1; var_7 <= var_5; var_7++) {
        scanf("%lld %lld", &var_8, &var_9);
        printf("Case #%lld: %d\n", var_7,
               var_0[(int)floor(sqrt(var_9))] -
                   var_0[(int)floor(sqrt(var_8 - 1))]);
    }
    return 0;
}
