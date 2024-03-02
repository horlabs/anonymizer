#include <stdio.h>

#define MAX_ROWS 105
#define MAX_COLS 105

int matrix_a[MAX_ROWS][MAX_COLS];
int desired[MAX_ROWS][MAX_COLS];

void readMatrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 100;
            scanf("%d", &desired[i][j]);
        }
    }
}

int findMax(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    int max_val = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
            }
        }
    }
    return max_val;
}

void updateMatrix(int rows, int cols, int max_val, int matrix[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] >= max_val) {
                matrix[i][j] = max_val;
            }
        }
    }
}

int compareMatrices(int rows, int cols, int matrix_a[MAX_ROWS][MAX_COLS], int matrix_b[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix_a[i][j] != matrix_b[i][j]) {
                return 0; // Matrices are not equal
            }
        }
    }
    return 1; // Matrices are equal
}

void printResult(int case_num, int rows, int matrix[MAX_ROWS][MAX_COLS]) {
    printf("Case #%d: ", case_num);
    int result = compareMatrices(rows, cols, matrix, desired);
    if (result) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int num_cases, rows, cols;
    scanf("%d", &num_cases);

    for (int case_num = 1; case_num <= num_cases; case_num++) {
        scanf("%d %d", &rows, &cols);
        readMatrix(rows, cols, matrix_a);
        
        int max_row_val = findMax(rows, cols, desired);
        updateMatrix(rows, cols, max_row_val, matrix_a);
        
        int max_col_val = findMax(cols, rows, desired);
        updateMatrix(rows, cols, max_col_val, matrix_a);
        
        printResult(case_num, rows, matrix_a);
    }
    
    return 0;
}
