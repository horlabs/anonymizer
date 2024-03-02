#include <assert.h>
#include <stdio.h>
#include <string.h>

char var_0[4][4];

int func_0(char var_1) {
    int var_2;
    int var_3;
    int var_4;

    for (var_2 = 0; var_2 < 4; var_2++) {
        var_4 = 0;
        for (var_3 = 0; var_3 < 4; var_3++) {
            if ((var_0[var_2][var_3] == var_1) ||
                (var_0[var_2][var_3] == 'T')) {
                var_4++;
            }
        }
        if (var_4 == 4) {
            return 1;
        }
    }
    for (var_3 = 0; var_3 < 4; var_3++) {
        var_4 = 0;
        for (var_2 = 0; var_2 < 4; var_2++) {
            if ((var_0[var_2][var_3] == var_1) ||
                (var_0[var_2][var_3] == 'T')) {
                var_4++;
            }
        }
        if (var_4 == 4) {
            return 1;
        }
    }

    var_4 = 0;
    for (var_2 = 0; var_2 < 4; var_2++) {
        if ((var_0[var_2][var_2] == var_1) || (var_0[var_2][var_2] == 'T')) {
            var_4++;
        }
    }
    if (var_4 == 4) {
        return 1;
    } else {

        var_4 = 0;
        for (var_2 = 0; var_2 < 4; var_2++) {
            if ((var_0[3 - var_2][var_2] == var_1) ||
                (var_0[3 - var_2][var_2] == 'T')) {
                var_4++;
            }
        }
        if (var_4 == 4) {
            return 1;
        } else {

            return 0;
        }
    }
}

int func_1() {
    int var_5;
    int var_6;

    for (var_5 = 0; var_5 < 4; var_5++) {
        for (var_6 = 0; var_6 < 4; var_6++) {
            if (var_0[var_5][var_6] == '.') {
                return 0;
            }
        }
    }
    return 1;
}

void func_2() {
    int var_7;
    int var_8;

    for (var_7 = 0; var_7 < 4; var_7++) {
        for (var_8 = 0; var_8 < 4; var_8++) {
            printf("%c", var_0[var_7][var_8]);
        }
        printf("\n");
    }
    return;
}

int main(int var_9, char **var_10) {
    int var_11;
    int var_12;

    char var_13[10];

    assert(scanf("%d ", &var_11) == 1);
    for (var_12 = 1; var_12 <= var_11; var_12++) {
        assert(scanf("%c%c%c%c ", &var_0[0][0], &var_0[0][1], &var_0[0][2],
                     &var_0[0][3]) == 4);
        assert(scanf("%c%c%c%c ", &var_0[1][0], &var_0[1][1], &var_0[1][2],
                     &var_0[1][3]) == 4);
        assert(scanf("%c%c%c%c ", &var_0[2][0], &var_0[2][1], &var_0[2][2],
                     &var_0[2][3]) == 4);
        assert(scanf("%c%c%c%c ", &var_0[3][0], &var_0[3][1], &var_0[3][2],
                     &var_0[3][3]) == 4);

        if (func_0('X')) {
            printf("Case #%d: X won\n", var_12);
        } else {
            if (func_0('O')) {
                printf("Case #%d: O won\n", var_12);
            } else {
                if (func_1()) {
                    printf("Case #%d: Draw\n", var_12);
                } else {
                    printf("Case #%d: Game has not completed\n", var_12);
                }
            }
        }
    }
    return 0;
}
