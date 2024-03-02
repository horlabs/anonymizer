#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


int main(void) {
    char s[4 + 1], *output[] = {"X won", "O won", "Draw", "Game has not completed"};
    int i, j, k, n, f, board[4][4], T;
    FILE *fin = fopen("A-small-attempt0.in", "r"), *fout = fopen("out.txt", "w");

    fscanf(fin, "%d", &T);

    for (k = 0; k < T; k++) {
        for (i = 0; i < 4; i++) {
            fscanf(fin, "%s", s);
            for (j = 0; j < 4; j++)
                board[i][j] = (s[j] == 'X' ? 10 : (s[j] == 'O' ? 100 : (s[j] == 'T' ? 5 : 0)));
        }

        for (f = i = 0; i < 4 && !f; i++) {
            for (n = j = 0; j < 4; n += board[i][j++])
                ;
            if (n == 40 || n == 35 || n == 400 || n == 305) {
                for (j = 0; j < 4 && board[i][j] == 5; j++)
                    ;
                f = board[i][j] == 10 ? 1 : 2;
            }
        }

        for (i = 0; i < 4 && !f; i++) {
            for (n = j = 0; j < 4; n += board[j++][i])
                ;
            if (n == 40 || n == 35 || n == 400 || n == 305) {
                for (j = 0; j < 4 && board[j][i] == 5; j++)
                    ;
                f = board[j][i] == 10 ? 1 : 2;
            }
        }

        for (n = i = 0; i < 4 && !f; i++)
            n += board[i][i];
        if (!f && (n == 40 || n == 35 || n == 400 || n == 305)) {
            for (j = 0; j < 4 && board[j][j] == 5; j++)
                ;
            f = board[j][j] == 10 ? 1 : 2;
        }

        for (n = i = 0; i < 4 && !f; i++)
            n += board[i][4 - 1 - i];
        if (!f && (n == 40 || n == 35 || n == 400 || n == 305)) {
            for (j = 0; j < 4 && board[j][j] == 5; j++)
                ;
            f = board[j][4 - 1 - j] == 10 ? 1 : 2;
        }

        if (!f) {
            for (j = 4, i = 0; i < 4 && j == 4; i++)
                for (j = 0; j < 4 && board[i][j] != 0; j++)
                    ;
            f = (i == 4 ? 3 : 4);
        }

        fprintf(fout, "Case #%d: %s\n", k + 1, output[f - 1]);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
