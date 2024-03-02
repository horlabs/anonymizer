#include <stdio.h>

int main(int argc, char **argv) {
    freopen("C:\\Users\\vivek\\Desktop\\in.txt", "r", stdin);
    freopen("C:\\Users\\vivek\\Desktop\\out.txt", "w", stdout);
    char var_0[4][5];
    char var_1;

    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;

    scanf("%d", &var_5);
    for (var_6 = 1; var_6 <= var_5; var_6++) {
        for (var_2 = 0; var_2 < 4; var_2++) {
            scanf("%s", var_0[var_2]);
        }
        for (var_2 = 0, var_4 = 0; var_2 < 4; var_2++) {
            for (var_3 = 0; (var_3 < 4) && ((var_0[var_2][var_3] == 'X') ||
                                            (var_0[var_2][var_3] == 'T'));
                 var_3++) {
                ;
            }
            if (var_3 == 4) {
                var_4 = 1;
                break;
            } else {
                for (var_3 = 0; (var_3 < 4) && ((var_0[var_2][var_3] == 'O') ||
                                                (var_0[var_2][var_3] == 'T'));
                     var_3++) {
                    ;
                }
                if (var_3 == 4) {
                    var_4 = 2;
                    break;
                } else {
                    for (var_3 = 0;
                         (var_3 < 4) && ((var_0[var_3][var_2] == 'X') ||
                                         (var_0[var_3][var_2] == 'T'));
                         var_3++) {
                        ;
                    }
                    if (var_3 == 4) {
                        var_4 = 1;
                        break;
                    } else {
                        for (var_3 = 0;
                             (var_3 < 4) && ((var_0[var_3][var_2] == 'O') ||
                                             (var_0[var_3][var_2] == 'T'));
                             var_3++) {
                            ;
                        }
                        if (var_3 == 4) {
                            var_4 = 2;
                            break;
                        }
                    }
                }
            }
        }
        if (var_4 == 1) {
            printf("Case #%d: X won\n", var_6, var_2);
        } else {
            if (var_4 == 2) {
                printf("Case #%d: O won\n", var_6, var_2);
            } else {
                for (var_3 = 0; (var_3 < 4) && ((var_0[var_3][var_3] == 'X') ||
                                                (var_0[var_3][var_3] == 'T'));
                     var_3++) {
                    ;
                }
                if (var_3 == 4) {
                    printf("Case #%d: X won\n", var_6);
                } else {
                    for (var_3 = 3, var_4 = 0;
                         (var_3 >= 0) && ((var_0[var_3][var_4] == 'X') ||
                                          (var_0[var_3][var_4] == 'T'));
                         var_3--, var_4++) {
                        ;
                    }
                    if (var_4 == 4) {
                        printf("Case #%d: X won\n", var_6);
                    } else {
                        for (var_3 = 0;
                             (var_3 < 4) && ((var_0[var_3][var_3] == 'O') ||
                                             (var_0[var_3][var_3] == 'T'));
                             var_3++) {
                            ;
                        }
                        if (var_3 == 4) {
                            printf("Case #%d: O won\n", var_6);
                        } else {
                            for (var_3 = 3, var_4 = 0;
                                 (var_3 >= 0) &&
                                 ((var_0[var_3][var_4] == 'O') ||
                                  (var_0[var_3][var_4] == 'T'));
                                 var_3--, var_4++) {
                                ;
                            }
                            if (var_4 == 4) {
                                printf("Case #%d: O won\n", var_6);
                            } else {
                                for (var_2 = 0; var_2 < 4; var_2++) {
                                    for (var_3 = 0;
                                         (var_3 < 4) &&
                                         (var_0[var_2][var_3] != '.');
                                         var_3++) {
                                        ;
                                    }
                                    if (var_3 < 4) {
                                        break;
                                    }
                                }
                                if (var_2 < 4) {
                                    printf("Case #%d: Game has not completed\n",
                                           var_6);
                                } else {
                                    printf("Case #%d: Draw\n", var_6);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
