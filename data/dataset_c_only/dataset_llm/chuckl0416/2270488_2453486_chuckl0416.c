#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 4

typedef struct {
    int x;
    int y;
} Position;

typedef enum {
    EMPTY,
    X,
    O,
    T
} Cell;

typedef enum {
    DRAW,
    X_WON,
    O_WON,
    INCOMPLETE
} Result;

Result checkRow(Cell matrix[SIZE][SIZE], int row) {
    int x, tCount = 0, xCount = 0, oCount = 0;
    for (x = 0; x < SIZE; x++) {
        if (matrix[row][x] == X) xCount++;
        else if (matrix[row][x] == O) oCount++;
        else if (matrix[row][x] == T) tCount++;
    }
    if ((xCount + tCount) == SIZE) return X_WON;
    else if ((oCount + tCount) == SIZE) return O_WON;
    return INCOMPLETE;
}

Result checkColumn(Cell matrix[SIZE][SIZE], int column) {
    int y, tCount = 0, xCount = 0, oCount = 0;
    for (y = 0; y < SIZE; y++) {
        if (matrix[y][column] == X) xCount++;
        else if (matrix[y][column] == O) oCount++;
        else if (matrix[y][column] == T) tCount++;
    }
    if ((xCount + tCount) == SIZE) return X_WON;
    else if ((oCount + tCount) == SIZE) return O_WON;
    return INCOMPLETE;
}

Result checkDiagonal(Cell matrix[SIZE][SIZE], Position start, Position increment) {
    int countT = 0, countX = 0, countO = 0;
    Position pos = start;
    do {
        if (matrix[pos.y][pos.x] == X) countX++;
        else if (matrix[pos.y][pos.x] == O) countO++;
        else if (matrix[pos.y][pos.x] == T) countT++;
        pos.x += increment.x;
        pos.y += increment.y;
    } while (pos.x >= 0 && pos.x < SIZE && pos.y >= 0 && pos.y < SIZE);
    if ((countX + countT) == SIZE) return X_WON;
    else if ((countO + countT) == SIZE) return O_WON;
    return INCOMPLETE;
}

Result checkGrid(Cell matrix[SIZE][SIZE]) {
    int i;
    Result result;
    for (i = 0; i < SIZE; i++) {
        result = checkRow(matrix, i);
        if (result == X_WON || result == O_WON) return result;
        result = checkColumn(matrix, i);
        if (result == X_WON || result == O_WON) return result;
    }
    result = checkDiagonal(matrix, (Position) {0, 0}, (Position) {1, 1});
    if (result == X_WON || result == O_WON) return result;
    result = checkDiagonal(matrix, (Position) {SIZE - 1, 0}, (Position) {-1, 1});
    if (result == X_WON || result == O_WON) return result;
    return DRAW;
}

Cell parseCell(char c) {
    switch (c) {
        case 'X':
            return X;
        case 'O':
            return O;
        case 'T':
            return T;
        default:
            return EMPTY;
    }
}

void solveGame(Cell matrix[SIZE][SIZE]) {
    Result result = checkGrid(matrix);
    switch (result) {
        case X_WON:
            printf("X won\n");
            break;
        case O_WON:
            printf("O won\n");
            break;
        case INCOMPLETE:
            printf("Game has not completed\n");
            break;
        default:
            printf("Draw\n");
            break;
    }
}

int main() {
    Cell matrix[SIZE][SIZE];
    int t, i, j;
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    scanf("%d", &t);
    for (i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        for (j = 0; j < SIZE; j++) {
            char row[SIZE + 1];
            scanf("%s", row);
            for (int k = 0; k < SIZE; k++) {
                matrix[j][k] = parseCell(row[k]);
            }
        }
        solveGame(matrix);
    }
    return 0;
}