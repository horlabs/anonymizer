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
    int var_7;

    char var_8[5][5];
    char var_9;

    scanf("%d", &var_3);
    for (var_2 = 1; var_2 <= var_3; var_2++) {
        var_4 = var_5 = var_6 = 0;
        func_0();
        for (var_0 = 0; var_0 < 4; var_0++) {
            for (var_1 = 0; var_1 < 4; var_1++) {
                var_8[var_0][var_1] = getchar();
                if (var_8[var_0][var_1] == 'X') {
                    var_4++;
                } else {
                    if (var_8[var_0][var_1] == 'O') {
                        var_5++;
                    } else {
                        if (var_8[var_0][var_1] == 'T') {
                            var_6++;
                        } else {
                            if (var_8[var_0][var_1] != '.') {
                                fprintf(stderr, "Error reading input!\n");
                                exit(1);
                            }
                        }
                    }
                }
            }
            func_0();
        }
        if (var_4 > var_5) {
            var_9 = 'X';
        } else {
            var_9 = 'O';
        }
        for (var_0 = 0; var_0 < 4; var_0++) {
            var_7 = 1;
            for (var_1 = 0; var_1 < 4; var_1++) {
                if (var_8[var_0][var_1] != var_9 &&
                    var_8[var_0][var_1] != 'T') {
                    var_7 = 0;
                    break;
                }
            }
            if (var_7) {
                break;
            } else {
                var_7 = 1;
                for (var_1 = 0; var_1 < 4; var_1++) {
                    if (var_8[var_1][var_0] != var_9 &&
                        var_8[var_1][var_0] != 'T') {
                        var_7 = 0;
                        break;
                    }
                }
                if (var_7) {
                    break;
                }
            }
        }
        if (var_7) {
            printf("Case #%d: %c won\n", var_2, var_9);
            continue;
        } else {
            var_7 = 1;
            for (var_1 = 0; var_1 < 4; var_1++) {
                if (var_8[var_1][var_1] != var_9 &&
                    var_8[var_1][var_1] != 'T') {
                    var_7 = 0;
                    break;
                }
            }
            if (var_7) {
                printf("Case #%d: %c won\n", var_2, var_9);
                continue;
            } else {
                var_7 = 1;
                for (var_1 = 0; var_1 < 4; var_1++) {
                    if (var_8[4 - 1 - var_1][var_1] != var_9 &&
                        var_8[4 - 1 - var_1][var_1] != 'T') {
                        var_7 = 0;
                        break;
                    }
                }
                if (var_7) {
                    printf("Case #%d: %c won\n", var_2, var_9);
                    continue;
                } else {
                    if (var_4 + var_5 + var_6 == 4 * 4) {
                        printf("Case #%d: Draw\n", var_2);
                    } else {
                        printf("Case #%d: Game has not completed\n", var_2);
                    }
                }
            }
        }
    }

    return 0;
}
