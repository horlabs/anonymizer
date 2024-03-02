#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;

    char *var_4[100];
    int var_5[10][10];
    int var_6;
    int var_7;

    int var_8 = 0;

    scanf("%d", &var_0);

    for (var_1 = 0; var_1 < var_0; var_1++) {
        var_8 = 0;
        scanf("%d %d", &var_6, &var_7);

        for (var_3 = 0; var_3 < var_6; var_3++) {
            for (var_2 = 0; var_2 < var_7; var_2++) {
                scanf("%d", &var_5[var_3][var_2]);
            }
        }

        for (var_3 = 0; var_3 < var_6; var_3++) {
            for (var_2 = 0; var_2 < var_7; var_2++) {
                if (var_5[var_3][var_2] == 1) {
                    if (func_0(var_3, var_2, var_6, var_7, var_5) == 1 ||
                        func_1(var_3, var_2, var_6, var_7, var_5) == 1) {
                        continue;
                    } else {
                        var_8 = 1;
                        break;
                    }
                }
            }
            if (var_8 == 1) {
                break;
            }
        }

        if (var_8 == 1) {
            var_4[var_1] = "NO";
        } else {
            var_4[var_1] = "YES";
        }
    }

    for (var_1 = 0; var_1 < var_0; var_1++) {
        printf("Case #%d: %s\n", var_1 + 1, var_4[var_1]);
    }
    return 0;
}

int func_0(int var_9, int var_10, int var_11, int var_12, int var_13[10][10]) {
    int var_14;

    for (var_14 = 0; var_14 < var_12; var_14++) {
        if (var_13[var_9][var_14] != 1) {
            return 0;
        }
    }
    return 1;
}

int func_1(int var_15, int var_16, int var_17, int var_18, int var_19[10][10]) {
    int var_20;

    for (var_20 = 0; var_20 < var_17; var_20++) {
        if (var_19[var_20][var_16] != 1) {
            return 0;
        }
    }
    return 1;
}
