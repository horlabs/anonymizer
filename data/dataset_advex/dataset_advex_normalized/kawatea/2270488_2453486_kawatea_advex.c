#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;

    scanf("%d", &var_0);

    for (var_1 = 0; var_1 < var_0; var_1++) {
        int var_2 = 0;
        int var_3;
        int var_4;

        char var_5[4][5];

        for (var_3 = 0; var_3 < 4; var_3++) {
            scanf("%s", var_5[var_3]);
        }

        for (var_3 = 0; var_3 < 4; var_3++) {
            for (var_4 = 0; var_4 < 4; var_4++) {
                if (var_5[var_3][var_4] == 'O' || var_5[var_3][var_4] == '.') {
                    break;
                }
            }

            if (var_4 == 4) {
                var_2 = 1;
            }

            for (var_4 = 0; var_4 < 4; var_4++) {
                if (var_5[var_4][var_3] == 'O' || var_5[var_4][var_3] == '.') {
                    break;
                }
            }

            if (var_4 == 4) {
                var_2 = 1;
            }

            for (var_4 = 0; var_4 < 4; var_4++) {
                if (var_5[var_3][var_4] == 'X' || var_5[var_3][var_4] == '.') {
                    break;
                }
            }

            if (var_4 == 4) {
                var_2 = 2;
            }

            for (var_4 = 0; var_4 < 4; var_4++) {
                if (var_5[var_4][var_3] == 'X' || var_5[var_4][var_3] == '.') {
                    break;
                }
            }

            if (var_4 == 4) {
                var_2 = 2;
            }
        }

        for (var_3 = 0; var_3 < 4; var_3++) {
            if (var_5[var_3][var_3] == 'O' || var_5[var_3][var_3] == '.') {
                break;
            }
        }

        if (var_3 == 4) {
            var_2 = 1;
        }

        for (var_3 = 0; var_3 < 4; var_3++) {
            if (var_5[var_3][3 - var_3] == 'O' ||
                var_5[var_3][3 - var_3] == '.') {
                break;
            }
        }

        if (var_3 == 4) {
            var_2 = 1;
        }

        for (var_3 = 0; var_3 < 4; var_3++) {
            if (var_5[var_3][var_3] == 'X' || var_5[var_3][var_3] == '.') {
                break;
            }
        }

        if (var_3 == 4) {
            var_2 = 2;
        }

        for (var_3 = 0; var_3 < 4; var_3++) {
            if (var_5[var_3][3 - var_3] == 'X' ||
                var_5[var_3][3 - var_3] == '.') {
                break;
            }
        }

        if (var_3 == 4) {
            var_2 = 2;
        }

        if (var_2 == 1) {
            printf("Case #%d: X won\n", var_1 + 1);
        } else {
            if (var_2 == 2) {
                printf("Case #%d: O won\n", var_1 + 1);
            } else {
                for (var_3 = 0; var_3 < 4; var_3++) {
                    for (var_4 = 0; var_4 < 4; var_4++) {
                        if (var_5[var_3][var_4] == '.') {
                            var_2 = 1;
                        }
                    }
                }

                if (var_2 == 1) {
                    printf("Case #%d: Game has not completed\n", var_1 + 1);
                } else {
                    printf("Case #%d: Draw\n", var_1 + 1);
                }
            }
        }
    }

    return 0;
}
