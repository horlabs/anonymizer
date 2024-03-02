#include <stdio.h>
#include <stdlib.h>

enum status_e { XPLYR, OPLYR, DRAW, INCOMPLETE };

int main(int argc, char **argvvoid) {
    freopen("A-small-attempt0.in", "r", stdin);

    int var_0 = 0;
    int var_1;

    scanf("%d\n", &var_1);

    while (var_0 < var_1) {
        char *var_2[] = {"X won", "O won", "Draw", "Game has not completed"};
        unsigned int var_3 = INCOMPLETE;
        unsigned char var_4[2][4] = {{0}};
        unsigned char var_5[2][4] = {{0}};
        unsigned char var_6[2][2] = {{0}};
        unsigned char var_7;
        unsigned char var_8;
        unsigned char var_9;
        unsigned char var_10 = 0;

        for (var_8 = 0; var_8 < 4; var_8++) {
            for (var_9 = 0; var_9 < 4; var_9++) {
                var_7 = getchar();
                if (var_7 == ('T')) {
                    if (++var_5[OPLYR][var_8] == 4 ||
                        ++var_4[OPLYR][var_9] == 4) {
                        var_3 = OPLYR;
                    } else {
                        if (var_8 == var_9 && ++var_6[OPLYR][0] == 4)
                            var_3 = OPLYR;
                        else if (var_9 == 3 - var_8 && ++var_6[OPLYR][1] == 4)
                            var_3 = OPLYR;
                    }
                }
                if (var_7 == ('X') ||
                    (var_7 == ('T') &&
                     !(var_5[OPLYR][var_8] == 4 || var_4[OPLYR][var_9] == 4))) {
                    if (++var_5[XPLYR][var_8] == 4 ||
                        ++var_4[XPLYR][var_9] == 4) {
                        var_3 = XPLYR;
                    } else if (var_8 == var_9 && ++var_6[XPLYR][0] == 4)
                        var_3 = XPLYR;
                    else if (var_9 == 3 - var_8 && ++var_6[XPLYR][1] == 4)
                        var_3 = XPLYR;
                } else if (var_7 == ('O')) {
                    if (++var_5[OPLYR][var_8] == 4 ||
                        ++var_4[OPLYR][var_9] == 4) {
                        var_3 = OPLYR;
                    } else if (var_8 == var_9 && ++var_6[OPLYR][0] == 4)
                        var_3 = OPLYR;
                    else if (var_9 == 3 - var_8 && ++var_6[OPLYR][1] == 4)
                        var_3 = OPLYR;
                } else if (var_7 == ('.')) {
                    var_10++;
                }
            }
            getchar();
        }
        getchar();

        if (!var_10 && var_3 == INCOMPLETE) {
            var_3 = DRAW;
        }

        printf("Case #%d: %s\n", ++var_0, var_2[var_3]);
    }

    return 0;
}
