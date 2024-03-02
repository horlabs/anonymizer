#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 123

char gameBoard[BOARD_SIZE][BOARD_SIZE];
int counterX, counterO;
int resultX, resultO;

void checkWinner(int row, int column) {
    if (gameBoard[row][column] == 'O') {
        ++counterO;
        counterX = -1000;
    } else if (gameBoard[row][column] == 'X') {
        ++counterX;
        counterO = -1000;
    } else if (gameBoard[row][column] == 'T') {
        ++counterX;
        ++counterO;
    }
}

void calculateResult() {
    if (counterX == 4) {
        resultX = 2;
    }
    if (counterO == 4) {
        resultO = 2;
    }
    if (counterX >= 0) {
        resultX |= 1;
    }
    if (counterO >= 0) {
        resultO |= 1;
    }
}

int main() {
    int testCase, numTestCases;
    int i, j;
    scanf("%d", &numTestCases);
    for (testCase = 1; testCase <= numTestCases; ++testCase) {
        for (i = 0; i < 4; ++i) {
            scanf("%s", gameBoard[i]);
        }
        resultX = resultO = 0;
        for (i = 0; i < 4; ++i) {
            for (j = counterX = counterO = 0; j < 4; ++j) {
                checkWinner(i, j);
            }
            calculateResult();
        }
        for (i = 0; i < 4; ++i) {
            for (j = counterX = counterO = 0; j < 4; ++j) {
                checkWinner(j, i);
            }
            calculateResult();
        }
        for (i = j = counterX = counterO = 0; i < 4; ++i, ++j) {
            checkWinner(j, i);
        }
        calculateResult();
        for (i = 3, j = counterX = counterO = 0; j < 4; --i, ++j) {
            checkWinner(j, i);
        }
        calculateResult();
        printf("Case #%d: ", testCase);
        if (resultX >= 2) {
            puts("X won");
        }
        if (resultO >= 2) {
            puts("O won");
        }
        if (resultX == 1 && resultO == 1) {
            puts("Game has not completed");
        }
        if (resultX == 0 && resultO == 0) {
            puts("Draw");
        }
    }
    return 0;
}
