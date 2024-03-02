#include <stdio.h>
#define MAX_ROWS 4
#define MAX_COLS 4

int readInteger() {
    int num;
    scanf("%d\n", &num);
    return num;
}

void readMatrix(int matrix[MAX_ROWS][MAX_COLS]) {
    int row, col;
    for (row = 0; row < MAX_ROWS; row++) {
        for (col = 0; col < MAX_COLS; col++) {
            scanf("%d ", &matrix[row][col]);
        }
    }
}

int findCommonElement(int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int row1, int row2) {
    int col1, col2;
    int commonElement = 0;
    for (col1 = 0; col1 < MAX_COLS; col1++) {
        for (col2 = 0; col2 < MAX_COLS; col2++) {
            if (matrix1[row1][col1] == matrix2[row2][col2]) {
                if (commonElement > 0) {
                    commonElement = -1; // multiple answers, bad magician!
                } else if (commonElement == 0) {
                    commonElement = matrix2[row2][col2];
                }
            }
        }
    }
    return commonElement;
}

void printResult(int testCase, int result) {
    if (result > 0) {
        printf("Case #%d: %d\n", testCase, result);
    } else if (result == 0) {
        printf("Case #%d: Volunteer cheated!\n", testCase);
    } else {
        printf("Case #%d: Bad magician!\n", testCase);
    }
}

int main() {
    int numTestCases = readInteger();
    int testCase;
    for (testCase = 1; testCase <= numTestCases; testCase++) {
        int query1 = readInteger();
        int board1[MAX_ROWS][MAX_COLS];
        readMatrix(board1);

        int query2 = readInteger();
        int board2[MAX_ROWS][MAX_COLS];
        readMatrix(board2);

        int commonElement = findCommonElement(board1, board2, query1 - 1, query2 - 1);
        printResult(testCase, commonElement);
    }
    
    return 0;
}