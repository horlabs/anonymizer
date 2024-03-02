#include <stdio.h>
#include <string.h>

#define NUM_ROWS 4

void readMatrix(int matrix[NUM_ROWS][NUM_ROWS]) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_ROWS; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int checkAnswer(int row, int matrix1[NUM_ROWS][NUM_ROWS], int matrix2[NUM_ROWS][NUM_ROWS]) {
    int counts[16] = {0};
    for (int i = 0; i < NUM_ROWS; i++) {
        counts[matrix1[row-1][i]-1]++;
        counts[matrix2[row-1][i]-1]++;
    }
    int answer = -1;
    for (int i = 0; i < 16; i++) {
        if (counts[i] == 2) {
            if (answer != -1) {
                answer = -2;
                break;
            }
            answer = i;
        }
    }
    return answer;
}

void printResult(int t, int caseNum, int answer) {
    printf("Case #%d: ", caseNum);
    if (answer == -1) {
        puts("Volunteer cheated!");
    } else if (answer == -2) {
        puts("Bad magician!");
    } else {
        printf("%d\n", answer+1);
    }
}

int main() {
    int numTests;
    scanf("%d", &numTests);
    
    int tCount = 0;
    for (int t = 0; t < numTests; t++) {
        int row1, row2;
        int matrix1[NUM_ROWS][NUM_ROWS];
        int matrix2[NUM_ROWS][NUM_ROWS];
        
        scanf("%d", &row1);
        readMatrix(matrix1);
        
        scanf("%d", &row2);
        readMatrix(matrix2);
        
        int answer = checkAnswer(row1, matrix1, matrix2);
        printResult(t, ++tCount, answer);
    }
    
    return 0;
}