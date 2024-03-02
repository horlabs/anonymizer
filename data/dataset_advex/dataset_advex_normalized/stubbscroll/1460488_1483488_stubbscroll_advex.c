#include <stdio.h>
#include <string.h>

int func_0(int var_0, int var_1) {
    char var_2[10];
    char var_3[10];

    int var_4;
    int var_5;
    int var_6;

    sprintf(var_2, "%d", var_0);
    sprintf(var_3, "%d", var_1);
    if (strlen(var_2) != strlen(var_3)) {
        return 0;
    } else {
        var_5 = strlen(var_2);
        for (var_4 = 1; var_2[var_4]; var_4++) {
            for (var_6 = 0; var_2[var_6]; var_6++) {
                if (var_2[var_6] != var_3[(var_4 + var_6) % var_5]) {
                    goto next;
                }
            }
            return 1;
        next:;
        }
        return 0;
    }
}

int main(int argc, char **argv) {
    int var_7;
    int var_8 = 1;
    int var_9;
    int var_10;
    int var_11;
    int var_12;
    int var_13;

    scanf("%d", &var_7);
    while (var_7--) {
        scanf("%d %d", &var_9, &var_10);
        for (var_13 = 0, var_11 = var_9; var_11 <= var_10; var_11++) {
            for (var_12 = var_11 + 1; var_12 <= var_10; var_12++) {
                if (func_0(var_11, var_12)) {
                    var_13++;
                }
            }
        }
        printf("Case #%d: %d\n", var_8++, var_13);
    }
    return 0;
}
