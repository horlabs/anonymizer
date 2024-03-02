#include <stdio.h>

char var_0[4][5];

int func_0(char var_1) {
    int var_2;

    var_2 = 0;
    for (int var_3 = 0; var_3 < 4; var_3++) {
        var_2 = var_2 +
                (var_0[var_3][var_3] == var_1 || var_0[var_3][var_3] == 'T');
    }
    if (var_2 == 4) {
        return 1;
    } else {

        var_2 = 0;
        for (int var_4 = 0; var_4 < 4; var_4++) {
            var_2 = var_2 + (var_0[var_4][3 - var_4] == var_1 ||
                             var_0[var_4][3 - var_4] == 'T');
        }
        if (var_2 == 4) {
            return 1;
        } else {

            for (int var_5 = 0; var_5 < 4; var_5++) {
                var_2 = 0;
                for (int var_6 = 0; var_6 < 4; var_6++) {
                    var_2 = var_2 + (var_0[var_5][var_6] == var_1 ||
                                     var_0[var_5][var_6] == 'T');
                }
                if (var_2 == 4) {
                    return 1;
                } else {

                    var_2 = 0;
                    for (int var_7 = 0; var_7 < 4; var_7++) {
                        var_2 = var_2 + (var_0[var_7][var_5] == var_1 ||
                                         var_0[var_7][var_5] == 'T');
                    }
                    if (var_2 == 4) {
                        return 1;
                    }
                }
            }
            return 0;
        }
    }
}

int main(int argc, char **argv) {
    int var_8;
    scanf("%d", &var_8);
    for (int var_9 = 1; var_9 <= var_8; var_9++) {
        for (int var_10 = 0; var_10 < 4; var_10++) {
            scanf("%s", &var_0[var_10]);
        }
        const char *var_11 = "Draw";
        if (func_0('X')) {
            var_11 = "X won";
        } else {
            if (func_0('O')) {
                var_11 = "O won";
            } else {
                int var_12 = 0;
                for (int var_13 = 0; var_13 < 4; var_13++) {
                    for (int var_14 = 0; var_14 < 4; var_14++) {
                        if (var_0[var_13][var_14] == '.') {
                            var_12++;
                        }
                    }
                }
                if (var_12 > 0) {
                    var_11 = "Game has not completed";
                }
            }
        }
        printf("Case #%d: %s\n", var_9, var_11);
    }
    return 0;
}
