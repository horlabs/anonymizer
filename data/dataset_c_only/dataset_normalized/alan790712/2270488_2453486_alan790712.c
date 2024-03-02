#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char var_0[123][123];
int var_1;
int var_2;
int var_3;
int var_4;

void func_0(int var_5, int var_6) {
    if (var_0[var_5][var_6] == 'O') {
        ++var_4;
        var_3 = -1000;
    } else {
        if (var_0[var_5][var_6] == 'X') {
            ++var_3;
            var_4 = -1000;
        } else {
            if (var_0[var_5][var_6] == 'T') {
                ++var_3;
                ++var_4;
            }
        }
    }
    return;
}
void func_1() {
    if (var_3 == 4) {
        var_1 = 2;
    }
    if (var_4 == 4) {
        var_2 = 2;
    }
    if (var_3 >= 0) {
        var_1 = var_1 | 1;
    }
    if (var_4 >= 0) {
        var_2 = var_2 | 1;
    }
    return;
}
int main(int argc, char **argv) {
    int var_7;
    int var_8;

    int var_9;
    int var_10;

    scanf("%d", &var_8);
    for (var_7 = 1; var_7 <= var_8; ++var_7) {
        for (var_9 = 0; var_9 < 4; ++var_9) {
            scanf("%s", var_0[var_9]);
        }
        var_1 = var_2 = 0;
        for (var_9 = 0; var_9 < 4; ++var_9) {
            for (var_10 = var_3 = var_4 = 0; var_10 < 4; ++var_10) {
                func_0(var_9, var_10);
            }
            func_1();
        }
        for (var_9 = 0; var_9 < 4; ++var_9) {
            for (var_10 = var_3 = var_4 = 0; var_10 < 4; ++var_10) {
                func_0(var_10, var_9);
            }
            func_1();
        }
        for (var_9 = var_10 = var_3 = var_4 = 0; var_9 < 4; ++var_9, ++var_10) {
            func_0(var_10, var_9);
        }
        func_1();
        for (var_9 = 3, var_10 = var_3 = var_4 = 0; var_10 < 4;
             --var_9, ++var_10) {
            func_0(var_10, var_9);
        }
        func_1();
        printf("Case #%d: ", var_7);
        if (var_1 >= 2) {
            puts("X won");
        }
        if (var_2 >= 2) {
            puts("O won");
        }
        if (var_1 == 1 && var_2 == 1) {
            puts("Game has not completed");
        }
        if (var_1 == 0 && var_2 == 0) {
            puts("Draw");
        }
    }
    return 0;
}
