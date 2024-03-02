#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;

    scanf("%d", &var_0);
    for (var_1 = 1; var_1 <= var_0; ++var_1) {
        char var_2;
        int var_3;
        int var_4;

        int var_5[4] = {};
        int var_6[4] = {};
        int var_7[2] = {};

        int var_8[4] = {};
        int var_9[4] = {};
        int var_10[2] = {};

        int var_11[4] = {};
        int var_12[4] = {};
        int var_13[2] = {};

        int var_14 = 0;
        printf("Case #%d: ", var_1);
        getchar();
        for (var_3 = 0; var_3 < 4; ++var_3) {
            for (var_4 = 0; var_4 < 4; ++var_4) {
                var_2 = getchar();
                if (var_2 == ('.')) {
                    var_14 = 1;
                } else if (var_2 == ('X')) {
                    ++var_5[var_3];
                    ++var_6[var_4];
                    if (var_3 == var_4) {
                        ++var_7[0];
                    };
                    if (var_3 + var_4 == 3) {
                        ++var_7[1];
                    };
                } else if (var_2 == ('O')) {
                    ++var_8[var_3];
                    ++var_9[var_4];
                    if (var_3 == var_4) {
                        ++var_10[0];
                    };
                    if (var_3 + var_4 == 3) {
                        ++var_10[1];
                    };
                } else if (var_2 == ('T')) {
                    ++var_11[var_3];
                    ++var_12[var_4];
                    if (var_3 == var_4) {
                        ++var_13[0];
                    };
                    if (var_3 + var_4 == 3) {
                        ++var_13[1];
                    };
                }
            }
            getchar();
        }
        for (var_3 = 0; var_3 < 4; ++var_3) {
            if (var_5[var_3] + var_11[var_3] == 4) {
                puts("X won");
                break;
            } else {
                if (var_8[var_3] + var_11[var_3] == 4) {
                    puts("O won");
                    break;
                } else {
                    if (var_6[var_3] + var_12[var_3] == 4) {
                        puts("X won");
                        break;
                    } else {
                        if (var_9[var_3] + var_12[var_3] == 4) {
                            puts("O won");
                            break;
                        } else {
                            if (var_3 < 2) {
                                if (var_7[var_3] + var_13[var_3] == 4) {
                                    puts("X won");
                                    break;
                                } else {
                                    if (var_10[var_3] + var_13[var_3] == 4) {
                                        puts("O won");
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (var_3 == 4) {
            puts(var_14 ? "Game has not completed" : "Draw");
        }
    }
    return 0;
}
