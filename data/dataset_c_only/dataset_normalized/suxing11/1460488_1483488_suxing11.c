#include <stdio.h>
#include <string.h>

int var_0[1010][1010];

int func_0(int var_1, int var_2) {
    char var_3[30];
    char var_4[30];

    sprintf(var_3, "%d", var_1);
    sprintf(var_4, "%d", var_2);
    int var_5;
    int var_6;
    int var_7 = strlen(var_3);

    if (var_7 != strlen(var_4)) {
        return 0;
    } else {
        for (var_5 = 0; var_5 < var_7; var_5++) {
            for (var_6 = 0; var_6 < var_7; var_6++) {
                if (var_3[var_6] != var_4[(var_5 + var_6) % var_7]) {
                    break;
                }
            }
            if (var_6 == var_7) {
                return 1;
            }
        }
        return 0;
    }
}

int main(int argc, char **argv) {
    int var_8;
    int var_9;
    int var_10;

    int var_11;
    int var_12;
    int var_13;
    int var_14 = 1;

    freopen("C-small-attempt0.in", "r", stdin);
    freopen("c-out.txt", "w", stdout);
    for (var_8 = 1; var_8 <= 1000; var_8++) {
        for (var_9 = 1; var_9 < var_8; var_9++) {
            if (func_0(var_9, var_8)) {
                var_0[var_9][var_8] = 1;
            } else {
                var_0[var_9][var_8] = 0;
            }
        }
    }
    scanf("%d", &var_10);
    while (var_10--) {
        scanf("%d%d", &var_11, &var_12);
        var_13 = 0;
        for (var_8 = var_11; var_8 <= var_12; var_8++) {
            for (var_9 = var_11; var_9 < var_8; var_9++) {
                if (var_0[var_9][var_8] == 1) {

                    var_13++;
                }
            }
        }
        printf("Case #%d: %d\n", var_14++, var_13);
    }
    return 0;
}
