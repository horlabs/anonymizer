#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char grid[MAX_ROWS][MAX_COLS];
} Matrix;

int isCutRequired(Matrix matrix, int rows, int cols) {
    int i, j, k, max;
    
    for (i = 0; i < rows; i++) {
        max = 0;
        for (j = 0; j < cols; j++) {
            if (matrix.grid[i][j] > max) {
                max = matrix.grid[i][j];
            }
        }
        
        for (j = 0; j < cols; j++) {
            if (matrix.grid[i][j] < max) {
                for (k = 0; k < rows; k++) {
                    if (matrix.grid[k][j] > matrix.grid[i][j]) {
                        return 0;
                    }
                }
            }
        }
    }
    
    return 1;
}

void printMatrix(Matrix matrix, int rows, int cols) {
    int i, j;
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", matrix.grid[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    int t, i, n, m, rows, cols;
    Matrix matrix;
    
    assert(scanf("%d ", &t) == 1); //Number of testcases
    
    for (i = 1; i <= t; i++) {
        assert(scanf("%d %d ", &n, &m) == 2);
        matrix = (Matrix) {0};
        
        for (rows = 0; rows < n; rows++) {
            for (cols = 0; cols < m; cols++) {
                assert(scanf("%c ", &matrix.grid[rows][cols]) == 1);
            }
        }
        
        if (isCutRequired(matrix, n, m) == 1) {
            printf("Case #%d: YES\n", i);
        } else {
            printf("Case #%d: NO\n", i);
        }
    }
    
    return 0;
}