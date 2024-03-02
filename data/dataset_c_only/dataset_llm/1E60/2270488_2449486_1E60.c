#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int columns;
    int** data;
} Matrix;

Matrix createMatrix(int rows, int columns) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.columns = columns;
    matrix.data = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        matrix.data[i] = (int*)malloc(columns * sizeof(int));
    }
    return matrix;
}

void freeMatrix(Matrix matrix) {
    for(int i = 0; i < matrix.rows; i++) {
        free(matrix.data[i]);
    }
    free(matrix.data);
}

Matrix readMatrix() {
    int rows, columns;
    scanf("%d %d\n", &rows, &columns);
    Matrix matrix = createMatrix(columns, rows);
    for(int y = 0; y < rows; y++) {
        for(int x = 0; x < columns; x++) {
            scanf("%d ", &(matrix.data[x][y]));
        }
    }
    return matrix;
}

int getMaxValue(Matrix matrix) {
    int max = 0;
    for(int y = 0; y < matrix.rows; y++) {
        for(int x = 0; x < matrix.columns; x++) {
            if (matrix.data[x][y] > max) {
                max = matrix.data[x][y];
            }
        }
    }
    return max;
}

Matrix cutAlongXAxis(Matrix matrix) {
    int max = getMaxValue(matrix);
    Matrix result = createMatrix(matrix.columns, matrix.rows);
    for(int y = 0; y < matrix.rows; y++) {
        for(int x = 0; x < matrix.columns; x++) {
            if (max < result.data[x][y]) {
                result.data[x][y] = max;
            }
        }
    }
    return result;
}

Matrix cutAlongYAxis(Matrix matrix) {
    int max = getMaxValue(matrix);
    Matrix result = createMatrix(matrix.columns, matrix.rows);
    for(int x = 0; x < matrix.columns; x++) {
        for(int y = 0; y < matrix.rows; y++) {
            if (max < result.data[x][y]) {
                result.data[x][y] = max;
            }
        }
    }
    return result;
}

int matricesAreEqual(Matrix matrix1, Matrix matrix2) {
    for(int y = 0; y < matrix1.rows; y++) {
        for(int x = 0; x < matrix2.columns; x++) {
            if (matrix1.data[x][y] != matrix2.data[x][y]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int testCases;
    scanf("%d\n", &testCases);
    for (int testCase = 1; testCase <= testCases; testCase++) {
        Matrix goal = readMatrix();
        Matrix board = createMatrix(goal.columns, goal.rows);
        for(int y = 0; y < goal.rows; y++) {
            for(int x = 0; x < goal.columns; x++) {
                board.data[x][y] = 100;
            }
        }
        Matrix cut_X = cutAlongXAxis(goal);
        Matrix cut_Y = cutAlongYAxis(goal);
        if (matricesAreEqual(board, cut_X) && matricesAreEqual(board, cut_Y)) {
            printf("Case #%d: %s\n", testCase, "YES");
        } else {
            printf("Case #%d: %s\n", testCase, "NO");
        }
        freeMatrix(goal);
        freeMatrix(board);
        freeMatrix(cut_X);
        freeMatrix(cut_Y);
    }
    return 0;
}