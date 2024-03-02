#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROWS 120
#define MAX_COLUMNS 120

typedef struct {
    int map[MAX_ROWS][MAX_COLUMNS];
    int minY[MAX_ROWS];
    int minX[MAX_COLUMNS];
    int rows;
    int columns;
} Grid;

void initialize(Grid* grid, int rows, int columns) {
    grid->rows = rows;
    grid->columns = columns;
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < columns; x++) {
            scanf("%d", &grid->map[y][x]);
        }
    }
}

int findMinimum(Grid* grid, int* tryY, int* tryX) {
    int tryMin = 1000;
    int min = 1000;
    *tryY = 1000;
    *tryX = 1000;

    for (int y = 0; y < grid->rows; y++) {
        if (grid->minY[y] < min) {
            tryMin = grid->minY[y];
            for (int x = 0; x < grid->columns; x++) {
                if (grid->map[y][x] == grid->minY[y]) continue;
                else break;
            }
            if (x == grid->columns) {
                min = grid->minY[y];
                *tryY = y;
                *tryX = 1000;
            }
        }
    }
    for (int x = 0; x < grid->columns; x++) {
        if (grid->minX[x] < min) {
            tryMin = grid->minX[x];
            for (int y = 0; y < grid->rows; y++) {
                if (grid->map[y][x] == grid->minX[x]) continue;
                else break;
            }
            if (y == grid->rows) {
                min = grid->minX[x];
                *tryY = 1000;
                *tryX = x;
            }
        }
    }
    return tryMin;
}

int updateGrid(Grid* grid, int tryMin, int tryY, int tryX) {
    int x, y;
    if (tryX == 1000) {
        if (tryY == 1000) return 0;
        if (tryMin != grid->minY[tryY]) return 0;
        grid->rows--;
        for (x = 0; x < grid->columns; x++) {
            grid->map[tryY][x] = grid->map[grid->rows][x];
        }
        grid->minY[tryY] = grid->minY[grid->rows];
        for (x = 0; x < grid->columns; x++) {
            grid->minX[x] = 1000;
            for (y = 0; y < grid->rows; y++) {
                if (grid->map[y][x] < grid->minX[x]) {
                    grid->minX[x] = grid->map[y][x];
                }
            }
        }
        return 1;
    }
    if (tryY == 1000) {
        if (tryMin != grid->minX[tryX]) return 0;
        grid->columns--;
        for (y = 0; y < grid->rows; y++) {
            grid->map[y][tryX] = grid->map[y][grid->columns];
        }
        grid->minX[tryX] = grid->minX[grid->columns];
        for (y = 0; y < grid->rows; y++) {
            grid->minY[y] = 1000;
            for (x = 0; x < grid->columns; x++) {
                if (grid->map[y][x] < grid->minY[y]) {
                    grid->minY[y] = grid->map[y][x];
                }
            }
        }
        return 1;
    }
    return 0;
}

void anonymizeCode(Grid* grid) {
    while (grid->rows && grid->columns) {
        if (updateGrid(grid, findMinimum(grid))) {
            continue;
        } else {
            break;
        }
    }
}

int main() {
    int testCases;
    scanf("%d", &testCases);

    for (int tcCount = 1; tcCount <= testCases; tcCount++) {
        printf("Case #%d: ", tcCount);

        int rows, columns;
        scanf("%d %d", &rows, &columns);

        Grid grid;
        initialize(&grid, rows, columns);

        while (getchar() != '\n'); // clear input buffer

        anonymizeCode(&grid);

        if (grid.rows && grid.columns) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}