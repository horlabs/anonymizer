#include <stdio.h>

#define SIZE 4

typedef struct {
    char board[SIZE][SIZE];
} Game;

typedef struct {
    int numX[SIZE];
    int numO[SIZE];
} RowColCount;

typedef struct {
    int x;
    int o;
} DiagonalCount;

int checkResult(Game game);
void initializeRowColCounts(RowColCount* rowColCount);
void initializeDiagonalCounts(DiagonalCount* diagonalCount);
RowColCount countRowCol(Game game);
DiagonalCount countDiagonals(Game game);
void printResult(int result, int caseNumber);
void printGameResult(int result);

int main() {
    int t, i, j;
    scanf("%d", &t);

    for (i = 1; i <= t; i++) {
        Game game;
        for (j = 0; j < SIZE; j++) {
            scanf("%s", game.board[j]);
        }

        int result = checkResult(game);
        printResult(result, i);
    }

    return 0;
}

int checkResult(Game game) {
    int result = -1;

    RowColCount rowColCount = countRowCol(game);
    DiagonalCount diagonalCount = countDiagonals(game);

    for (int i = 0; i < SIZE; i++) {
        if (rowColCount.numX[i] == SIZE || diagonalCount.x == SIZE) {
            result = 0;
        } else if (rowColCount.numO[i] == SIZE || diagonalCount.o == SIZE) {
            result = 1;
        } else if (game.board[i][j] == '.') {
            result = 2;
        }
    }

    return result;
}

void initializeRowColCounts(RowColCount* rowColCount) {
    for (int i = 0; i < SIZE; i++) {
        rowColCount->numX[i] = 0;
        rowColCount->numO[i] = 0;
    }
}

void initializeDiagonalCounts(DiagonalCount* diagonalCount) {
    diagonalCount->x = 0;
    diagonalCount->o = 0;
}

RowColCount countRowCol(Game game) {
    RowColCount rowColCount;
    initializeRowColCounts(&rowColCount);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (game.board[i][j] == 'X') {
                rowColCount.numX[i]++;
            } else if (game.board[i][j] == 'O') {
                rowColCount.numO[i]++;
            }
        }
    }

    return rowColCount;
}

DiagonalCount countDiagonals(Game game) {
    DiagonalCount diagonalCount;
    initializeDiagonalCounts(&diagonalCount);

    for (int i = 0; i < SIZE; i++) {
        if (game.board[i][i] == 'X') {
            diagonalCount.x++;
        } else if (game.board[i][i] == 'O') {
            diagonalCount.o++;
        }

        if (game.board[i][SIZE - 1 - i] == 'X') {
            diagonalCount.x++;
        } else if (game.board[i][SIZE - 1 - i] == 'O') {
            diagonalCount.o++;
        }
    }

    return diagonalCount;
}

void printResult(int result, int caseNumber) {
    printf("Case #%d: ", caseNumber);
    if (result == -1) {
        printf("Draw\n");
    } else if (result == 0) {
        printf("X won\n");
    } else if (result == 1) {
        printf("O won\n");
    } else if (result == 2) {
        printf("Game has not completed\n");
    }
}