#include <stdio.h>
#include <string.h>

int var_0[111][111];
int var_1[111][111];
int var_2;
int var_3;

int func_0() {
    int var_4;
    int var_5;
    int var_6;
    int var_7;

    for (var_4 = 0; var_4 < var_2; var_4++) {
        for (var_5 = 0; var_5 < var_3; var_5++) {
            var_1[var_4][var_5] = 100;
        }
    }
    do {
        var_7 = 0;
        for (var_4 = 0; var_4 < var_2; var_4++) {
            var_6 = 0;
            for (var_5 = 0; var_5 < var_3; var_5++) {
                if (var_6 < var_0[var_4][var_5]) {
                    var_6 = var_0[var_4][var_5];
                }
            }
            for (var_5 = 0; var_5 < var_3; var_5++) {
                if (var_1[var_4][var_5] > var_6) {
                    var_1[var_4][var_5] = var_6;
                    var_7 = 1;
                }
            }
        }
        for (var_5 = 0; var_5 < var_3; var_5++) {
            var_6 = 0;
            for (var_4 = 0; var_4 < var_2; var_4++) {
                if (var_6 < var_0[var_4][var_5]) {
                    var_6 = var_0[var_4][var_5];
                }
            }
            for (var_4 = 0; var_4 < var_2; var_4++) {
                if (var_1[var_4][var_5] > var_6) {
                    var_1[var_4][var_5] = var_6;
                    var_7 = 1;
                }
            }
        }
    } while (var_7);
    for (var_4 = 0; var_4 < var_2; var_4++) {
        for (var_5 = 0; var_5 < var_3; var_5++) {
            if (var_1[var_4][var_5] != var_0[var_4][var_5]) {
                return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char **argv) {
    int var_8;
    int var_9 = 1;
    int var_10;
    int var_11;

    scanf("%d", &var_8);
    while (var_8--) {
        scanf("%d %d", &var_2, &var_3);
        for (var_10 = 0; var_10 < var_2; var_10++) {
            for (var_11 = 0; var_11 < var_3; var_11++) {
                scanf("%d", &var_0[var_10][var_11]);
            }
        }
        printf("Case #%d: %s\n", var_9++, func_0() ? "YES" : "NO");
    }
    return 0;
}
