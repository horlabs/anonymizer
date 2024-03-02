#include <stdio.h>

void readMatrix(int matrix[4][4]) {
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            scanf("%d", &matrix[row][col]);
        }
    }
}

int main() {
    int testCases;
    scanf("%d", &testCases);

    for (int testCase = 0; testCase < testCases; testCase++) {
        int firstGuessRow, secondGuessRow;
        scanf("%d", &firstGuessRow);

        int firstMatrix[4][4];
        readMatrix(firstMatrix);

        scanf("%d", &secondGuessRow);

        int secondMatrix[4][4];
        readMatrix(secondMatrix);

        int count[17] = {0};

        for (int col = 0; col < 4; col++) {
            count[firstMatrix[firstGuessRow - 1][col]]++;
            count[secondMatrix[secondGuessRow - 1][col]]++;
        }

        int answer = 0;
        for (int i = 1; i <= 16; i++) {
            if (count[i] == 2) {
                if (answer == 0) {
                    answer = i;
                } else {
                    answer = -1;
                }
            }
        }

        if (answer == 0) {
            printf("Case #%d: Volunteer cheated!\n", testCase + 1);
        } else if (answer == -1) {
            printf("Case #%d: Bad magician!\n", testCase + 1);
        } else {
            printf("Case #%d: %d\n", testCase + 1, answer);
        }
    }

    return 0;
}