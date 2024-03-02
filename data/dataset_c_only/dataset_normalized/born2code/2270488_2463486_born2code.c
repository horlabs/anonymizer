#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func_0(int var_0, char var_1[]) {
    int var_2;
    int var_3;
    int var_4;

    char var_5;
    char var_6[100];

    var_2 = var_0;
    var_3 = 0;
    while (var_0) {
        var_1[var_3++] = var_0 % 10 + '0';
        var_0 = var_0 / 10;
    }
    var_1[var_3] = '\0';
    var_4 = strlen(var_1);
    for (var_2 = 0, var_3 = var_4 - 1; var_2 <= var_4 - 1; var_3--, var_2++) {
        var_6[var_3] = var_1[var_2];
    }
    for (var_2 = 0; var_2 <= var_4 - 1; var_2++) {
        var_1[var_2] = var_6[var_2];
    }
    return;
}
int func_1(int var_7) {
    char var_8[100];
    func_0(var_7, var_8);
    int var_9 = strlen(var_8);
    int var_10;

    for (var_10 = 0; var_10 < var_9 - 1; var_10++) {
        if (var_8[var_10] != var_8[var_9 - var_10 - 1]) {
            return 0;
        }
    }

    return 1;
}

int func_2(int var_11) {
    int var_12 = var_11 + 1;
    while (!func_1(var_12)) {
        var_12++;
    }
    return var_12;
}

int main(int argc, char **argv) {
    int var_13;
    int var_14;
    int var_15;
    int var_16;
    int var_17;
    int var_18;
    int var_19;
    int var_20;

    var_13 = 1;
    for (scanf("%d", &var_14); var_13 <= var_14; var_13++) {
        scanf("%d%d", &var_15, &var_16);
        var_17 = ceil(sqrt(var_15));
        var_18 = floor(sqrt(var_16));
        var_19 = 0;
        var_20 = var_17;
        while (!func_1(var_20)) {
            var_20++;
        }
        for (; var_20 <= var_18; var_20 = func_2(var_20)) {
            if (func_1(var_20 * var_20)) {
                var_19++;
            }
        }
        printf("Case #%d: %d\n", var_13, var_19);
    }
    return 0;
}
