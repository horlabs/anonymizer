#include <stdio.h>
#include <stdlib.h>

// Function to compare two matrices and check if they are equal
int areMatricesEqual(int matrix1[100][100], int matrix2[100][100], int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to update a matrix with the maximum value
void updateMatrixWithMaxValue(int matrix[100][100], int numRows, int numCols, int maxValue) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = maxValue;
        }
    }
}

int main() {
    int numTestCases, testCase, numRows, numCols, i, j, maxValue, x;
    int originalMatrix[100][100], updatedMatrix[100][100];
    numTestCases = 1;
    for (scanf("%d", &testCase); testCase <= numTestCases; testCase++) {
        scanf("%d%d", &numRows, &numCols);
        maxValue = 0;
        for (i = 0; i < numRows; i++) {
            for (j = 0; j < numCols; j++) {
                scanf("%d", &originalMatrix[i][j]);
                if (originalMatrix[i][j] > maxValue) {
                    maxValue = originalMatrix[i][j];
                }
            }
        }
        updateMatrixWithMaxValue(updatedMatrix, numRows, numCols, maxValue);
        for (i = 0; i < numRows; i++) {
            x = originalMatrix[i][0];
            for (j = 1; j < numCols; j++) {
                if (originalMatrix[i][j] != x) {
                    break;
                }
            }
            if (j == numCols) {
                for (j = 0; j < numCols; j++) {
                    updatedMatrix[i][j] = x;
                }
            }
        }
        for (j = 0; j < numCols; j++) {
            x = originalMatrix[0][j];
            for (i = 1; i < numRows; i++) {
                if (originalMatrix[i][j] != x) {
                    break;
                }
            }
            if (i == numRows) {
                for (i = 0; i < numRows; i++) {
                    updatedMatrix[i][j] = x;
                }
            }
        }
        printf("Case #%d: ", testCase);
        if (areMatricesEqual(originalMatrix, updatedMatrix, numRows, numCols)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}