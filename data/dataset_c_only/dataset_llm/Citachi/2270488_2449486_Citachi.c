#include<stdio.h>
#include<stdlib.h>

int checkMatrix(int** matrix, int rows, int cols) {
    int flag = 0;
    for(int i = 1; i < rows-1; i++) {
        for(int j = 1; j < cols-1; j++) {
            if(matrix[i][j] != 0) {
                flag = 1;
                break;
            }
        }
    }
    return flag;
}

void processMatrix(int** matrix, int rows, int cols) {
    int n;
    for(int i = 0; i < rows; i++) {
        n = matrix[i][0];

        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                matrix[i][j] = abs(n - matrix[i][j]);
            }
        }
    }

    for(int j = 0; j < cols; j++) {
        n = matrix[0][j];
        for(int i = 0; i < rows; i++) {
            if(matrix[i][j] != 0) {
                matrix[i][j] = abs(n - matrix[i][j]);
            }
        }
    }

    for(int i = 0; i < rows; i++) {
        n = matrix[i][cols-1];
        if(n == 0) {
            continue;
        }
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                matrix[i][j] = abs(n - matrix[i][j]);
            }
        }
    }

    for(int j = 0; j < cols; j++) {
        n = matrix[rows-1][j];
        if(n == 0) {
            continue;
        }
        for(int i = 0; i < rows; i++) {
            if(matrix[i][j] != 0) {
                matrix[i][j] = abs(n - matrix[i][j]);
            }
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    int** matrix;
    int numTestCases, numRows, numCols, flag;
    
    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");

    fscanf(inputFile, "%d", &numTestCases);

    for(int testCase = 1; testCase <= numTestCases; testCase++) {
        flag = 0;

        fscanf(inputFile, "%d %d", &numRows, &numCols);

        matrix = (int**)malloc(numRows * sizeof(int*));
        for(int i = 0; i < numRows; i++) {
            matrix[i] = (int*)malloc(numCols * sizeof(int));
        }

        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < numCols; j++) {
                fscanf(inputFile, "%d", &matrix[i][j]);
            }
        }

        processMatrix(matrix, numRows, numCols);

        flag = checkMatrix(matrix, numRows, numCols);

        if(flag == 0) {
            fprintf(outputFile, "Case #%d: YES\n", testCase);
        }
        else {
            fprintf(outputFile, "Case #%d: NO\n", testCase);
        }

        for(int i = 0; i < numRows; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}