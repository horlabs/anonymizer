#include <stdio.h>

int main(int argc, char **argvvoid) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;

    int var_6;
    int var_7;

    int var_8[100][100];

    scanf("%d", &var_0);
    for (var_1 = 1; var_1 <= var_0; var_1++) {

        scanf("%d %d\n", &var_4, &var_5);
        for (var_2 = 0; var_2 < var_4; var_2++) {
            for (var_3 = 0; var_3 < var_5; var_3++) {
                scanf("%d", &var_8[var_2][var_3]);
            }
        }
        if ((var_4 < 2) || (var_5 < 2)) {
            printf("Case #%d: YES\n", var_1);
            continue;
        } else {

            for (var_2 = 0; var_2 < var_4; var_2++) {
                for (var_3 = 0; var_3 < var_5; var_3++) {

                    var_7 = 1;
                    for (var_6 = 0; var_6 < var_4; var_6++) {
                        if (var_8[var_2][var_3] < var_8[var_6][var_3]) {
                            var_7 = 0;
                            break;
                        }
                    }
                    if (var_7) {
                        continue;
                    } else {

                        var_7 = 1;
                        for (var_6 = 0; var_6 < var_5; var_6++) {
                            if (var_8[var_2][var_3] < var_8[var_2][var_6]) {
                                var_7 = 0;
                                break;
                            }
                        }
                        if (var_7) {
                            continue;
                        } else {

                            break;
                        }
                    }
                }
                if (!var_7) {
                    break;
                }
            }
            if (var_7) {
                printf("Case #%d: YES\n", var_1);
            } else {

                printf("Case #%d: NO\n", var_1);
            }
        }
    }
    return 0;
}
