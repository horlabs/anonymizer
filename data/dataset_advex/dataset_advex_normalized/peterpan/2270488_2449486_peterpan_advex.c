#include <stdio.h>
#include <stdlib.h>
void func_0() {
    while (getchar() != '\n') {
        ;
    }
    return;
}

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;

    int var_7[101][101];
    int var_8[101];
    int var_9[101];

    scanf("%d", &var_3);
    for (var_2 = 1; var_2 <= var_3; var_2++) {
        scanf("%d", &var_4);
        scanf("%d", &var_5);
        var_6 = 1;
        for (var_0 = 0; var_0 < var_4; var_0++) {
            var_8[var_0] = 0;
            for (var_1 = 0; var_1 < var_5; var_1++) {
                scanf("%d", &var_7[var_0][var_1]);
                if (var_8[var_0] < var_7[var_0][var_1]) {
                    var_8[var_0] = var_7[var_0][var_1];
                }
            }
        }
        for (var_1 = 0; var_1 < var_5; var_1++) {
            var_9[var_1] = 0;
            for (var_0 = 0; var_0 < var_4; var_0++) {
                if (var_9[var_1] < var_7[var_0][var_1]) {
                    var_9[var_1] = var_7[var_0][var_1];
                }
            }
        }
        for (var_0 = 0; var_0 < var_4 && var_6; var_0++) {
            for (var_1 = 0; var_1 < var_5; var_1++) {
                if (var_7[var_0][var_1] < var_8[var_0] &&
                    var_7[var_0][var_1] < var_9[var_1]) {
                    var_6 = 0;
                    break;
                }
            }
        }
        printf("Case #%d: %s\n", var_2, var_6 ? "YES" : "NO");
    }

    return 0;
}
