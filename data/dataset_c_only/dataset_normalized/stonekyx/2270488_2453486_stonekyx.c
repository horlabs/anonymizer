#include <stdio.h>

char var_0[10][10];

int func_0(int var_1) {
    int var_2;
    for (var_2 = 0; var_2 < 4; var_2++) {
        int var_3;
        for (var_3 = 0; var_3 < 4; var_3++) {
            if (var_0[var_2][var_3] != var_1 && var_0[var_2][var_3] != 'T') {
                break;
            }
        }
        if (var_3 >= 4) {
            return 1;
        } else {
            for (var_3 = 0; var_3 < 4; var_3++) {
                if (var_0[var_3][var_2] != var_1 &&
                    var_0[var_3][var_2] != 'T') {
                    break;
                }
            }
            if (var_3 >= 4) {
                return 1;
            }
        }
    }
    for (var_2 = 0; var_2 < 4; var_2++) {
        if (var_0[var_2][var_2] != var_1 && var_0[var_2][var_2] != 'T') {
            break;
        }
    }
    if (var_2 >= 4) {
        return 1;
    } else {
        for (var_2 = 0; var_2 < 4; var_2++) {
            if (var_0[var_2][3 - var_2] != var_1 &&
                var_0[var_2][3 - var_2] != 'T') {
                break;
            }
        }
        if (var_2 >= 4) {
            return 1;
        } else {
            return 0;
        }
    }
}

int func_1(void) {
    int var_4;
    for (var_4 = 0; var_4 < 4; var_4++) {
        int var_5;
        for (var_5 = 0; var_5 < 4; var_5++) {
            if (var_0[var_4][var_5] == '.') {
                return 0;
            }
        }
    }
    return 1;
}

int func_2(void) {
    if (func_0('X')) {
        return 0;
    } else {
        if (func_0('O')) {
            return 1;
        } else {
            if (func_1()) {
                return 2;
            } else {
                return 3;
            }
        }
    }
}

int main(int argc, char **argv) {
    int var_6;
    int var_7 = 0;

    for (scanf("%d\n", &var_6); var_6; var_6--) {
        int var_8;
        int var_9;
        for (var_8 = 0; var_8 < 5; var_8++) {
            fgets(var_0[var_8], 10, stdin);
        }
        var_9 = func_2();
        printf("Case #%d: ", ++var_7);
        if (var_9 == 0) {
            puts("X won");
        } else if (var_9 == 1) {
            puts("O won");
        } else if (var_9 == 2) {
            puts("Draw");
        } else if (var_9 == 3) {
            puts("Game has not completed");
        } else {
        }
    }
    return 0;
}
