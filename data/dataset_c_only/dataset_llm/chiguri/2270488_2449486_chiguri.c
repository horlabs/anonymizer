#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int row;
    int column;
    int data[MAX_SIZE][MAX_SIZE];
} Matrix;

bool isDataSmallestInRow(Matrix *matrix, int row);
bool isDataSmallestInColumn(Matrix *matrix, int column);

bool isDataSmallestInRow(Matrix *matrix, int row) {
    int element = matrix->data[row][0];
    for (int i = 1; i < matrix->column; i++) {
        if (element > matrix->data[row][i]) {
            return false;
        }
    }
    return true;
}

bool isDataSmallestInColumn(Matrix *matrix, int column) {
    int element = matrix->data[0][column];
    for (int i = 1; i < matrix->row; i++) {
        if (element > matrix->data[i][column]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int testCases;
    scanf("%d", &testCases);

    for (int caseNumber = 1; caseNumber <= testCases; caseNumber++) {
        Matrix matrix;
        int result = 1;

        scanf("%d %d", &matrix.row, &matrix.column);

        for (int i = 0; i < matrix.row; i++) {
            for (int j = 0; j < matrix.column; j++) {
                scanf("%d", &(matrix.data[i][j]));
            }
        }

        for (int i = 0; i < matrix.row; i++) {
            for (int j = 0; j < matrix.column; j++) {
                if (!isDataSmallestInRow(&matrix, i) && !isDataSmallestInColumn(&matrix, j)) {
                    result = 0;
                    goto LAST;
                }
            }
        }

    LAST:
        printf("Case #%d: ", caseNumber);
        if (result) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}