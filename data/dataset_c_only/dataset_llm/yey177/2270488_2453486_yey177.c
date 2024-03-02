#include <stdio.h>

char board[4][4];

int checkRow(char symbol) {
    int fullRow;
    for (int i = 0; i < 4; i++) {
        fullRow = 1;
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != symbol && board[i][j] != 'T') {
                fullRow = 0;
                break;
            }
        }
        if (fullRow) {
            return 1;
        }
    }
    return 0;
}

int checkColumn(char symbol) {
    int fullColumn;
    for (int i = 0; i < 4; i++) {
        fullColumn = 1;
        for (int j = 0; j < 4; j++) {
            if (board[j][i] != symbol && board[j][i] != 'T') {
                fullColumn = 0;
                break;
            }
        }
        if (fullColumn) {
            return 1;
        }
    }
    return 0;
}

int checkDiagonal(char symbol) {
    int diag1 = 1;
    int diag2 = 1;
    for (int i = 0; i < 4; i++) {
        if (board[i][i] != symbol && board[i][i] != 'T') {
            diag1 = 0;
        }
        if (board[i][3 - i] != symbol && board[i][3 - i] != 'T') {
            diag2 = 0;
        }
    }
    if (diag1 || diag2) {
        return 1;
    }
    return 0;
}

int isGameCompleted() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == '.') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++) {
        for (int i = 0; i < 4; i++) {
            scanf("%s", board[i]);
        }

        int hasWinner = 0;
        char winnerSymbol;

        if (hasWinner = checkRow('X') || checkColumn('X') || checkDiagonal('X')) {
            winnerSymbol = 'X';
        } else if (hasWinner = checkRow('O') || checkColumn('O') || checkDiagonal('O')) {
            winnerSymbol = 'O';
        }

        printf("Case #%d: ", t);

        if (hasWinner) {
            printf("%c won\n", winnerSymbol);
        } else if (isGameCompleted()) {
            printf("Draw\n");
        } else {
            printf("Game has not completed\n");
        }
    }

    return 0;
}