#include <stdio.h>
#include <string.h>

int func_0(char var_0) {
    if (var_0 == ('X')) {
        return 0;

    } else if (var_0 == ('O')) {
        return 1;

    } else if (var_0 == ('T')) {
        return 2;

    } else if (var_0 == ('.')) {
        return -1;
    }
    return -1;
}

int main(int argc, char **argv) {
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8;

    int var_9[10][3];
    char var_10[5][5];
    char var_11;

    scanf("%d", &var_1);
    getc(stdin);
    for (var_2 = 1; var_2 <= var_1; var_2++) {
        var_8 = 0;
        printf("Case #%d: ", var_2);
        if (var_2 > 1) {
            getc(stdin);
        }
        for (var_3 = 0; var_3 < 4; var_3++) {
            fgets(var_10[var_3], sizeof var_10[0], stdin);
            getc(stdin);
        }

        memset(var_9, 0, sizeof var_9);

        for (var_5 = 0; var_5 < 4; var_5++) {
            for (var_6 = 0; var_6 < 4; var_6++) {
                var_7 = func_0(var_10[var_5][var_6]);
                if (var_7 >= 0) {
                    var_9[var_5][var_7]++;
                }
                var_7 = func_0(var_10[var_6][var_5]);
                if (var_7 >= 0) {
                    var_9[4 + var_5][var_7]++;
                }
            }
            var_7 = func_0(var_10[var_5][var_5]);
            if (var_7 >= 0) {
                var_9[8][var_7]++;
            }
            var_7 = func_0(var_10[var_5][3 - var_5]);
            if (var_7 >= 0) {
                var_9[9][var_7]++;
            }
        }
        for (var_6 = 0; var_6 < 10; var_6++) {
            if (var_9[var_6][0] + var_9[var_6][2] == 4) {
                puts("X won");
                var_8 = 1;
                break;
            } else {
                if (var_9[var_6][1] + var_9[var_6][2] == 4) {
                    puts("O won");
                    var_8 = 1;
                    break;
                }
            }
        }
        if (var_8) {
            continue;
        } else {

            for (var_3 = 0; var_3 < 4 && var_8 == 0; var_3++) {
                for (var_4 = 0; var_4 < 4; var_4++) {
                    if (var_10[var_3][var_4] == '.') {
                        puts("Game has not completed");
                        var_8 = 1;
                        break;
                    }
                }
            }
            if (var_8) {
                continue;
            } else {
                puts("Draw");
            }
        }
    }
    return 0;
}
