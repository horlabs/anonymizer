#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int var_0[100][100];
int var_1;
int var_2;

int func_0(int var_3, int var_4) {
    int var_5;
    int var_6;

    int var_7 = var_0[var_3][var_4];
    int var_8 = 1;

    for (var_5 = 0; var_5 < var_1; ++var_5) {
        if (var_7 < var_0[var_5][var_4]) {
            var_8 = 0;
            break;
        }
    }
    if (var_8) {
        return 1;
    } else {

        for (var_5 = 0; var_5 < var_2; ++var_5) {
            if (var_7 < var_0[var_3][var_5]) {
                return 0;
            }
        }

        return 1;
    }
}

int main(int argc, char **argvvoid) {
    int var_9;
    int var_10;
    int var_11;
    int var_12;

    int var_13;

    scanf("%d", &var_9);
    for (var_10 = 1; var_10 <= var_9; ++var_10) {
        scanf("%d %d", &var_1, &var_2);
        for (var_11 = 0; var_11 < var_1; ++var_11) {
            for (var_12 = 0; var_12 < var_2; ++var_12) {
                scanf("%d", &var_0[var_11][var_12]);
            }
        }

        var_13 = 1;

        for (var_11 = 0; var_11 < var_1; ++var_11) {
            for (var_12 = 0; var_12 < var_2; ++var_12) {
                if (!func_0(var_11, var_12)) {
                    var_13 = 0;
                    goto LAST;
                }
            }
        }
    LAST:
        printf("Case #%d: ", var_10);
        if (var_13) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
