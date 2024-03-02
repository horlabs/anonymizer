#include <stdio.h>

char var_0[5][5];

int main(int argc, char **argv) {
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;

    scanf("%d", &var_1);
    for (var_4 = 1; var_4 <= var_1; var_4++) {
        for (var_2 = 0; var_2 < 4; var_2++) {
            scanf("%s", var_0[var_2]);
        }
        var_6 = 1;
        for (var_2 = 0; var_2 < 4; var_2++) {
            var_5 = 3;
            for (var_3 = 0; var_3 < 4; var_3++) {
                if (var_0[var_2][var_3] == 'T') {
                    var_5 = var_5 & 3;
                } else {
                    if (var_0[var_2][var_3] == 'O') {
                        var_5 = var_5 & 2;
                    } else {
                        if (var_0[var_2][var_3] == 'X') {
                            var_5 = var_5 & 1;
                        } else {
                            if (var_0[var_2][var_3] == '.') {
                                var_5 = 0;
                                var_6 = 0;
                            }
                        }
                    }
                }
            }
            if (var_5) {
                goto END;
            }
        }
        for (var_3 = 0; var_3 < 4; var_3++) {
            var_5 = 3;
            for (var_2 = 0; var_2 < 4; var_2++) {
                if (var_0[var_2][var_3] == 'T') {
                    var_5 = var_5 & 3;
                } else {
                    if (var_0[var_2][var_3] == 'O') {
                        var_5 = var_5 & 2;
                    } else {
                        if (var_0[var_2][var_3] == 'X') {
                            var_5 = var_5 & 1;
                        } else {
                            if (var_0[var_2][var_3] == '.') {
                                var_5 = 0;
                                var_6 = 0;
                            }
                        }
                    }
                }
            }
            if (var_5) {
                goto END;
            }
        }
        var_5 = 3;
        for (var_2 = 0; var_2 < 4; var_2++) {
            if (var_0[var_2][var_2] == 'T') {
                var_5 = var_5 & 3;
            } else {
                if (var_0[var_2][var_2] == 'O') {
                    var_5 = var_5 & 2;
                } else {
                    if (var_0[var_2][var_2] == 'X') {
                        var_5 = var_5 & 1;
                    } else {
                        if (var_0[var_2][var_2] == '.') {
                            var_5 = 0;
                            var_6 = 0;
                        }
                    }
                }
            }
        }
        if (var_5) {
            goto END;
        }
        var_5 = 3;
        for (var_2 = 0; var_2 < 4; var_2++) {
            if (var_0[var_2][3 - var_2] == 'T') {
                var_5 = var_5 & 3;
            } else {
                if (var_0[var_2][3 - var_2] == 'O') {
                    var_5 = var_5 & 2;
                } else {
                    if (var_0[var_2][3 - var_2] == 'X') {
                        var_5 = var_5 & 1;
                    } else {
                        if (var_0[var_2][3 - var_2] == '.') {
                            var_5 = 0;
                            var_6 = 0;
                        }
                    }
                }
            }
        }
    END:
        printf("Case #%d: ", var_4);
        if (var_5 == 2) {
            puts("O won");
        } else {
            if (var_5 == 1) {
                puts("X won");
            } else {
                if (var_6 == 1) {
                    puts("Draw");
                } else {
                    puts("Game has not completed");
                }
            }
        }
    }
    return 0;
}
