#include <stdio.h>

int var_0[100][100];
int var_1[100];
int var_2[100];
int var_3;
int var_4;
int main(int argc, char **argv) {
    freopen("C:\\Users\\vivek\\Desktop\\in.txt", "r", stdin);
    freopen("C:\\Users\\vivek\\Desktop\\out.txt", "w", stdout);

    int var_5;
    int var_6;
    int var_7;
    int var_8;
    int var_9;

    scanf("%d", &var_5);
    for (var_9 = 1; var_9 <= var_5; var_9++) {
        scanf("%d %d", &var_3, &var_4);
        for (var_6 = 0; var_6 < 100; var_6++) {
            var_1[var_6] = var_2[var_6] = 0;
        }
        for (var_6 = 0; var_6 < var_3; var_6++) {
            for (var_7 = 0; var_7 < var_4; var_7++) {
                scanf("%d", &var_0[var_6][var_7]);
                if (var_0[var_6][var_7] > var_1[var_6]) {
                    var_1[var_6] = var_0[var_6][var_7];
                }
                if (var_0[var_6][var_7] > var_2[var_7]) {
                    var_2[var_7] = var_0[var_6][var_7];
                }
            }
        }
        for (var_6 = 0; var_6 < var_3; var_6++) {
            for (var_7 = 0;
                 (var_7 < var_4) && ((var_0[var_6][var_7] >= var_1[var_6]) ||
                                     (var_0[var_6][var_7] >= var_2[var_7]));
                 var_7++) {
                ;
            }
            if (var_7 < var_4) {
                break;
            }
        }
        if (var_6 < var_3) {
            printf("Case #%d: NO\n", var_9);
        } else {
            printf("Case #%d: YES\n", var_9);
        }
    }
    return 0;
}
