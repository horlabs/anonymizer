#include <stdio.h>

#define FOR(i,a,b) for (i = a ; i < b ; i++)

typedef struct {
    char board[5][5];
} Game;

int checkWin(Game game, char ch) {
    int i, j;
    int col[4] = {0}, row[4] = {0};
    int diagonalOne = 0, diagonalTwo = 0;

    FOR(i, 0, 4) {
        if (game.board[i][i] == ch || game.board[i][i] == 'T')
            diagonalOne++;
        if (game.board[i][3 - i] == ch || game.board[i][3 - i] == 'T')
            diagonalTwo++;

        FOR(j, 0, 4) {
            if (game.board[i][j] == ch || game.board[i][j] == 'T')
                row[i]++;
            if (game.board[j][i] == ch || game.board[j][i] == 'T')
                col[i]++;
        }
    }

    FOR(i, 0, 4) {
        if (row[i] == 4 || col[i] == 4)
            return 1;
    }

    if (diagonalOne == 4 || diagonalTwo == 4)
        return 1;

    return 0;
}

int determineResult(Game game) {
    int i, j, flag = 0;

    FOR(i, 0, 4) {
        FOR(j, 0, 4) {
            if (game.board[i][j] == '.')
                flag++;
        }
    }

    if (checkWin(game, 'X'))
        return 0;
    if (checkWin(game, 'O'))
        return 1;
    if (flag == 0)
        return 2;

    return 3;
}

int main() {
    int T, i, testCase = 1;

    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.txt", "w", stdout);

    char result[][50] = {"X won", "O won", "Draw", "Game has not completed"};

    scanf("%d", &T);
    while (T--) {
        Game game;

        FOR(i, 0, 4) {
            scanf("%s", game.board[i]);
        }

        printf("Case #%d: %s\n", testCase++, result[determineResult(game)]);
    }

    return 0;
}