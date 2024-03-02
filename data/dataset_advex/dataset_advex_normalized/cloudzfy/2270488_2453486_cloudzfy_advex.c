#include <stdio.h>
char var_0[4][5];
int main(int argc, char **argv) {
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;

    freopen("A-small-attempt0.in.txt", "r", stdin);
    freopen("A-small-attempt0.out.txt", "w", stdout);
    scanf("%d", &var_1);
    for (int var_7 = 1; var_7 <= var_1; var_7++) {
        var_6 = 0;
        for (int var_8 = 0; var_8 < 4; var_8++) {
            scanf("%s", var_0[var_8]);
        }
        for (int var_9 = 0; var_9 < 4; var_9++) {
            var_2 = 0;
            var_3 = 0;
            var_4 = 0;
            for (int var_10 = 0; var_10 < 4; var_10++) {
                if (var_0[var_9][var_10] == 'X') {
                    var_2++;
                } else {
                    if (var_0[var_9][var_10] == 'O') {
                        var_3++;
                    } else {
                        if (var_0[var_9][var_10] == 'T') {
                            var_4++;
                        }
                    }
                }
            }
            if (var_2 + var_4 == 4) {
                var_6 = 1;
            }
            if (var_3 + var_4 == 4) {
                var_6 = 2;
            }
        }
        if (var_6 == 0) {
            for (int var_11 = 0; var_11 < 4; var_11++) {
                var_2 = 0;
                var_3 = 0;
                var_4 = 0;
                for (int var_12 = 0; var_12 < 4; var_12++) {
                    if (var_0[var_12][var_11] == 'X') {
                        var_2++;
                    } else {
                        if (var_0[var_12][var_11] == 'O') {
                            var_3++;
                        } else {
                            if (var_0[var_12][var_11] == 'T') {
                                var_4++;
                            }
                        }
                    }
                }
                if (var_2 + var_4 == 4) {
                    var_6 = 1;
                }
                if (var_3 + var_4 == 4) {
                    var_6 = 2;
                }
            }
        }
        if (var_6 == 0) {
            var_2 = 0;
            var_3 = 0;
            var_4 = 0;
            for (int var_13 = 0; var_13 < 4; var_13++) {
                if (var_0[var_13][var_13] == 'X') {
                    var_2++;
                } else {
                    if (var_0[var_13][var_13] == 'O') {
                        var_3++;
                    } else {
                        if (var_0[var_13][var_13] == 'T') {
                            var_4++;
                        }
                    }
                }
            }
            if (var_2 + var_4 == 4) {
                var_6 = 1;
            }
            if (var_3 + var_4 == 4) {
                var_6 = 2;
            }
        }
        if (var_6 == 0) {
            var_2 = 0;
            var_3 = 0;
            var_4 = 0;
            for (int var_14 = 0; var_14 < 4; var_14++) {
                if (var_0[var_14][3 - var_14] == 'X') {
                    var_2++;
                } else {
                    if (var_0[var_14][3 - var_14] == 'O') {
                        var_3++;
                    } else {
                        if (var_0[var_14][3 - var_14] == 'T') {
                            var_4++;
                        }
                    }
                }
            }
            if (var_2 + var_4 == 4) {
                var_6 = 1;
            }
            if (var_3 + var_4 == 4) {
                var_6 = 2;
            }
        }
        if (var_6 == 0) {
            var_5 = 0;
            for (int var_15 = 0; var_15 < 4; var_15++) {
                for (int var_16 = 0; var_16 < 4; var_16++) {
                    if (var_0[var_15][var_16] == '.') {
                        var_5++;
                        break;
                    }
                }
                if (var_5 != 0) {
                    break;
                }
            }
            if (var_5 != 0) {
                var_6 = 4;
            } else {
                var_6 = 3;
            }
        }
        if (var_6 == 1) {
            printf("Case #%d: X won\n", var_7);
        } else {
            if (var_6 == 2) {
                printf("Case #%d: O won\n", var_7);
            } else {
                if (var_6 == 3) {
                    printf("Case #%d: Draw\n", var_7);
                } else {
                    if (var_6 == 4) {
                        printf("Case #%d: Game has not completed\n", var_7);
                    }
                }
            }
        }
    }
    return 0;
}
