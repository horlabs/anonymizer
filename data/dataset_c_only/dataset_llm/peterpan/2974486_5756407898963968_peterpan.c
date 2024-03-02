#include <stdio.h>

#define MAX_ROWS 4
#define MAX_COLUMNS 4

void readMatrix(int matrix[MAX_ROWS][MAX_COLUMNS], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf("%d", &(matrix[i][j]));
        }
    }
}

int countOccurrences(int matrix1[MAX_ROWS][MAX_COLUMNS], int matrix2[MAX_ROWS][MAX_COLUMNS], int r1, int r2) {
    int count = 0;
    int resj = -1;
    
    for (int j = 0; j < MAX_COLUMNS; j++) {
        for (int jj = 0; jj < MAX_COLUMNS; jj++) {
            if (matrix1[r1][j] == matrix2[r2][jj]) {
                count++;
                resj = j;
            }
        }
    }
    
    return resj;
}

void printResult(int tcase, int count, int res) {
    printf("Case #%d: ", tcase);
    
    if (count == 1) {
        printf("%d\n", res);
    } else {
        printf("%s\n", count ? "Bad magician!" : "Volunteer cheated!");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int tcase = 1; tcase <= T; tcase++) {
        int r1, r2;
        scanf("%d", &r1);
        r1--;
        
        int matrix1[MAX_ROWS][MAX_COLUMNS];
        readMatrix(matrix1, MAX_ROWS, MAX_COLUMNS);
        
        scanf("%d", &r2);
        r2--;
        
        int matrix2[MAX_ROWS][MAX_COLUMNS];
        readMatrix(matrix2, MAX_ROWS, MAX_COLUMNS);
        
        int count = 0;
        int resj = countOccurrences(matrix1, matrix2, r1, r2);
        
        printResult(tcase, count, matrix1[r1][resj]);
    }
    
    return 0;
}