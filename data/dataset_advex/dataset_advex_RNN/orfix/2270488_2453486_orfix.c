#include <stdio.h>
#include <stdlib.h>


enum status_e { XPLYR,
                OPLYR,
                DRAW,
                INCOMPLETE };

int main(void) {
    freopen("A-small-attempt0.in", "r", stdin);

    int testcase = 0;
    int testcases;

    scanf("%d\n", &testcases);

    while (testcase < testcases) {
        char *result_str[] = {"X won", "O won", "Draw", "Game has not completed"};
        enum status_e status = INCOMPLETE;
        unsigned char col[2][4] = {{0}};
        unsigned char row[2][4] = {{0}};
        unsigned char diag[2][2] = {{0}};
        unsigned char c, i, j, empty = 0;


        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                switch (c = getchar()) {
                    case 'T':
                        if (++row[OPLYR][i] == 4 || ++col[OPLYR][j] == 4) {
                            status = OPLYR;
                            break;
                        }
                        if (i == j && ++diag[OPLYR][0] == 4) status = OPLYR;
                        else if (j == 3 - i && ++diag[OPLYR][1] == 4)
                            status = OPLYR;
                    case 'X':
                        if (++row[XPLYR][i] == 4 || ++col[XPLYR][j] == 4) {
                            status = XPLYR;
                            break;
                        }
                        if (i == j && ++diag[XPLYR][0] == 4) status = XPLYR;
                        else if (j == 3 - i && ++diag[XPLYR][1] == 4)
                            status = XPLYR;
                        break;
                    case 'O':
                        if (++row[OPLYR][i] == 4 || ++col[OPLYR][j] == 4) {
                            status = OPLYR;
                            break;
                        }
                        if (i == j && ++diag[OPLYR][0] == 4) status = OPLYR;
                        else if (j == 3 - i && ++diag[OPLYR][1] == 4)
                            status = OPLYR;
                        break;
                    case '.':
                        empty++;
                        break;
                }
            }
            getchar();
        }
        getchar();

        if (!empty && status == INCOMPLETE) {
            status = DRAW;
        }

        printf("Case #%d: %s\n", ++testcase, result_str[status]);
    }

    return 0;
}
