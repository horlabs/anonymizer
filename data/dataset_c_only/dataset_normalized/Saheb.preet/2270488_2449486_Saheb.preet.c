#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4[101][101];
    int var_5;
    int var_6;
    int var_7[100];
    int var_8[100];

    scanf("%d", &var_0);
    for (var_1 = 0; var_1 < var_0; var_1++) {
        scanf("%d%d", &var_5, &var_6);
        for (var_2 = 0; var_2 < var_5; var_2++) {
            var_7[var_2] = 0;
        }
        for (var_3 = 0; var_3 < var_6; var_3++) {
            var_8[var_3] = 0;
        }
        for (var_2 = 0; var_2 < var_5; var_2++) {
            for (var_3 = 0; var_3 < var_6; var_3++) {
                scanf("%d", &var_4[var_2][var_3]);
                if (var_4[var_2][var_3] > var_7[var_2]) {
                    var_7[var_2] = var_4[var_2][var_3];
                }
                if (var_4[var_2][var_3] > var_8[var_3]) {
                    var_8[var_3] = var_4[var_2][var_3];
                }
            }
        }
        for (var_2 = 0; var_2 < var_5; var_2++) {
            for (var_3 = 0; var_3 < var_6; var_3++) {
                if (var_4[var_2][var_3] != var_7[var_2] &&
                    var_4[var_2][var_3] != var_8[var_3]) {
                    break;
                }
            }
            if (var_3 != var_6) {
                break;
            }
        }
        if (var_2 != var_5) {
            printf("Case #%d: NO\n", var_1 + 1);
        } else {
            printf("Case #%d: YES\n", var_1 + 1);
        }
    }
    return 0;
}
