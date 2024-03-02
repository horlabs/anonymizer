#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int rows;
    int columns;
    int data[MAX_SIZE][MAX_SIZE];
} Matrix;

Matrix createMatrix(int rows, int columns) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.columns = columns;
    return matrix;
}

void readMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            scanf("%d", &matrix->data[i][j]);
        }
    }
}

int checkRowConsistency(Matrix matrix, int row) {
    for (int i = 0; i < matrix.columns - 1; i++) {
        if (matrix.data[row][i] != matrix.data[row][i + 1]) {
            return 0;
        }
    }
    return 1;
}

int checkColumnConsistency(Matrix matrix, int column) {
    for (int i = 0; i < matrix.rows - 1; i++) {
        if (matrix.data[i][column] != matrix.data[i + 1][column]) {
            return 0;
        }
    }
    return 1;
}

int checkMatrixConsistency(Matrix matrix, int maxValue) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.columns; j++) {
            if (matrix.data[i][j] != maxValue && !checkRowConsistency(matrix, i) && !checkColumnConsistency(matrix, j)) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int testCases;
    scanf("%d", &testCases);
    
    for (int i = 0; i < testCases; i++) {
        int rows, columns;
        scanf("%d %d", &rows, &columns);
        
        Matrix matrix = createMatrix(rows, columns);
        readMatrix(&matrix);
        
        int maxValue = 0;
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.columns; j++) {
                if (matrix.data[i][j] > maxValue) {
                    maxValue = matrix.data[i][j];
                }
            }
        }
        
        int isConsistent = checkMatrixConsistency(matrix, maxValue);
        
        if (isConsistent) {
            printf("Case #%d: YES\n", i + 1);
        } else {
            printf("Case #%d: NO\n", i + 1);
        }
    }
    
    return 0;
}