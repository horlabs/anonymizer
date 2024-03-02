#include<stdio.h>

#define ROWS 4
#define COLS 4

typedef struct Matrix {
    int values[ROWS][COLS];
} Matrix;

void loadMatrixFromFile(Matrix* matrix, FILE* file) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            fscanf(file, "%d", &matrix->values[i][j]);
        }
    }
}

int findSelectedNumber(Matrix* matrixA, Matrix* matrixB, int r1, int r2) {
    int count = 0;
    int selectedNumber = 0;
    
    for (int i = 0; i < COLS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(matrixA->values[r1][i] == matrixB->values[r2][j]) {
                count++;
                selectedNumber = matrixA->values[r1][i];
            }	
        }
    }

    return (count == 1) ? selectedNumber : -1;
}

void writeResultToFile(FILE* file, int t, int selectedNumber) {
    if(selectedNumber == -1) {
        if(t == 0) {
            fprintf(file, "Case #%d: Volunteer cheated!", t);
        } else {
            fprintf(file, "Case #%d: Volunteer cheated!\n", t);
        }
    } else if(selectedNumber == -2) {
        if(t == 0) {
            fprintf(file, "Case #%d: Bad magician!", t);
        } else {
            fprintf(file, "Case #%d: Bad magician!\n", t);
        }	
    } else {
        if(t == 0) {
            fprintf(file, "Case #%d: %d", t, selectedNumber);
        } else {
            fprintf(file, "Case #%d: %d\n", t, selectedNumber);
        }	
    }
}

int main() {
    Matrix matrixA;
    Matrix matrixB;

    FILE *inputFile = fopen("A-small-attempt2.in", "r");
    FILE *outputFile = fopen("magic_out.txt", "w");

    int T;
    fscanf(inputFile, "%d", &T);

    for(int t = 1; t <= T; t++) {
        int r1, r2;
        fscanf(inputFile, "%d", &r1);

        loadMatrixFromFile(&matrixA, inputFile);

        fscanf(inputFile, "%d", &r2);

        loadMatrixFromFile(&matrixB, inputFile);

        int selectedNumber = findSelectedNumber(&matrixA, &matrixB, r1-1, r2-1);

        writeResultToFile(outputFile, t, selectedNumber);
    }

    fclose(inputFile);
    fclose(outputFile);
  
    return 0;
}