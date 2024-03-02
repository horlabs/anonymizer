#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int var_0;
int var_1;
char var_2[10][10];
int var_3;
int var_4;
int var_5;
int var_6;
int var_7;

int func_0() {
    for (var_5 = 0; var_5 < 4; var_5++) {
        var_6 = 0;
        var_7 = 0;
        for (var_4 = 0; var_4 < 4; var_4++) {
            if (var_2[var_5][var_4] == 'X') {
                var_7--;
            }
            if (var_2[var_5][var_4] == 'O') {
                var_7++;
            }
            if (var_2[var_5][var_4] == 'T') {
                var_6 = 1;
            }
        }
        if (var_6) {
            if (var_7 < 0) {
                var_7--;
            }
            if (var_7 > 0) {
                var_7++;
            }
        }
        if (var_7 == -4) {
            printf("X won\n");
            return 0;
        } else {
            if (var_7 == 4) {
                printf("O won\n");
                return 0;
            }
        }
    }

    for (var_4 = 0; var_4 < 4; var_4++) {
        var_6 = 0;
        var_7 = 0;
        for (var_5 = 0; var_5 < 4; var_5++) {
            if (var_2[var_5][var_4] == 'X') {
                var_7--;
            }
            if (var_2[var_5][var_4] == 'O') {
                var_7++;
            }
            if (var_2[var_5][var_4] == 'T') {
                var_6 = 1;
            }
        }
        if (var_6) {
            if (var_7 < 0) {
                var_7--;
            }
            if (var_7 > 0) {
                var_7++;
            }
        }
        if (var_7 == -4) {
            printf("X won\n");
            return 0;
        } else {
            if (var_7 == 4) {
                printf("O won\n");
                return 0;
            }
        }
    }

    var_6 = 0;
    var_7 = 0;
    for (var_4 = 0, var_5 = 0; var_4 < 4; var_4++, var_5++) {
        if (var_2[var_5][var_4] == 'X') {
            var_7--;
        }
        if (var_2[var_5][var_4] == 'O') {
            var_7++;
        }
        if (var_2[var_5][var_4] == 'T') {
            var_6 = 1;
        }
    }
    if (var_6) {
        if (var_7 < 0) {
            var_7--;
        }
        if (var_7 > 0) {
            var_7++;
        }
    }
    if (var_7 == -4) {
        printf("X won\n");
        return 0;
    } else {
        if (var_7 == 4) {
            printf("O won\n");
            return 0;
        } else {

            var_6 = 0;
            var_7 = 0;
            for (var_4 = 3, var_5 = 0; var_4 >= 0; var_4--, var_5++) {
                if (var_2[var_5][var_4] == 'X') {
                    var_7--;
                }
                if (var_2[var_5][var_4] == 'O') {
                    var_7++;
                }
                if (var_2[var_5][var_4] == 'T') {
                    var_6 = 1;
                }
            }
            if (var_6) {
                if (var_7 < 0) {
                    var_7--;
                }
                if (var_7 > 0) {
                    var_7++;
                }
            }
            if (var_7 == -4) {
                printf("X won\n");
                return 0;
            } else {
                if (var_7 == 4) {
                    printf("O won\n");
                    return 0;
                } else {

                    for (var_5 = 0; var_5 < 4; var_5++) {
                        for (var_4 = 0; var_4 < 4; var_4++) {
                            if (var_2[var_5][var_4] == '.') {
                                printf("Game has not completed\n");
                                return 0;
                            }
                        }
                    }
                    printf("Draw\n");
                    return 0;
                }
            }
        }
    }
}

int main(int argc, char **argv) {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

    scanf("%d", &var_0);
    for (var_1 = 1; var_1 <= var_0; var_1++) {
        printf("Case #%d: ", var_1);

        for (var_5 = 0; var_5 < 4; var_5++) {
            scanf("%s", var_2[var_5]);
        }

        func_0();
    }

    return 0;
}
