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

    int var_8;
    int var_9;
    int var_10;

    char var_11[4][4];

    scanf("%d\n", &var_0);
    for (var_1 = 1; var_1 <= var_0; var_1++) {
        var_10 = 0;

        var_7 = var_4 = var_5 = var_6 = 0;
        for (var_2 = 0; var_2 < 4; var_2++) {
            for (var_3 = 0; var_3 < 4; var_3++) {
                var_11[var_2][var_3] = getchar();
                if (var_11[var_2][var_3] == '.') {
                    var_7++;
                } else {
                    if (var_11[var_2][var_3] == 'X') {
                        var_4++;
                    } else {
                        if (var_11[var_2][var_3] == 'O') {
                            var_5++;
                        } else {
                            var_6++;
                        }
                    }
                }
            }
            getchar();
        }
        getchar();

        if ((var_4 + var_6) < 3) {
            printf("Case #%d: Game has not completed\n", var_1);
            continue;
        } else {

            for (var_2 = 0; var_2 < 4; var_2++) {
                var_8 = var_9 = 0;
                for (var_3 = 0; var_3 < 4; var_3++) {
                    if (var_11[var_2][var_3] == 'X') {
                        var_8++;
                    } else {
                        if (var_11[var_2][var_3] == 'O') {
                            var_9++;
                        } else {
                            if (var_11[var_2][var_3] == 'T') {
                                var_8++;
                                var_9++;
                            }
                        }
                    }
                }
                if (var_8 == 4) {
                    printf("Case #%d: X won\n", var_1);
                    var_10 = 1;
                } else {
                    if (var_9 == 4) {
                        printf("Case #%d: O won\n", var_1);
                        var_10 = 1;
                    }
                }
            }
            if (var_10) {
                continue;
            } else {

                for (var_2 = 0; var_2 < 4; var_2++) {
                    var_8 = var_9 = 0;
                    for (var_3 = 0; var_3 < 4; var_3++) {
                        if (var_11[var_3][var_2] == 'X') {
                            var_8++;
                        } else {
                            if (var_11[var_3][var_2] == 'O') {
                                var_9++;
                            } else {
                                if (var_11[var_3][var_2] == 'T') {
                                    var_8++;
                                    var_9++;
                                }
                            }
                        }
                    }
                    if (var_8 == 4) {
                        printf("Case #%d: X won\n", var_1);
                        var_10 = 1;
                    } else {
                        if (var_9 == 4) {
                            printf("Case #%d: O won\n", var_1);
                            var_10 = 1;
                        }
                    }
                }
                if (var_10) {
                    continue;
                } else {

                    var_8 = var_9 = 0;
                    for (var_2 = 0; var_2 < 4; var_2++) {
                        if (var_11[var_2][var_2] == 'X') {
                            var_8++;
                        } else {
                            if (var_11[var_2][var_2] == 'O') {
                                var_9++;
                            } else {
                                if (var_11[var_2][var_2] == 'T') {
                                    var_8++;
                                    var_9++;
                                }
                            }
                        }
                    }
                    if (var_8 == 4) {
                        printf("Case #%d: X won\n", var_1);
                        var_10 = 1;
                    } else {
                        if (var_9 == 4) {
                            printf("Case #%d: O won\n", var_1);
                            var_10 = 1;
                        }
                    }
                    if (var_10) {
                        continue;
                    } else {

                        var_8 = var_9 = 0;
                        for (var_2 = 0; var_2 < 4; var_2++) {
                            if (var_11[var_2][3 - var_2] == 'X') {
                                var_8++;
                            } else {
                                if (var_11[var_2][3 - var_2] == 'O') {
                                    var_9++;
                                } else {
                                    if (var_11[var_2][3 - var_2] == 'T') {
                                        var_8++;
                                        var_9++;
                                    }
                                }
                            }
                        }
                        if (var_8 == 4) {
                            printf("Case #%d: X won\n", var_1);
                            var_10 = 1;
                        } else {
                            if (var_9 == 4) {
                                printf("Case #%d: O won\n", var_1);
                                var_10 = 1;
                            }
                        }
                        if (var_10) {
                            continue;
                        } else {

                            if (var_7 > 1) {
                                printf("Case #%d: Game has not completed\n",
                                       var_1);
                            } else {
                                printf("Case #%d: Draw\n", var_1);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
