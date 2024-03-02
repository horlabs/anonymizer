#include <stdio.h>

#define SIZE 4

typedef struct {
    int data[SIZE][SIZE];
} Card;

int readNumber() {
    int number;
    scanf("%d", &number);
    return number;
}

void readCard(Card *card) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &card->data[i][j]);
        }
    }
}

int findMatch(Card *card1, Card *card2, int row1, int row2) {
    int i, j;
    int matchCount = 0;
    int matchNumber;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (card1->data[row1][i] == card2->data[row2][j]) {
                matchCount++;
                matchNumber = card1->data[row1][i];
            }
        }
    }

    if (matchCount == 0) {
        return -1;
    } else if (matchCount > 1) {
        return 0;
    } else {
        return matchNumber;
    }
}

void printResult(int cases, int caseNumber, int matchResult) {
    if (matchResult == -1) {
        printf("Case #%d: Volunteer cheated!\n", caseNumber);
    } else if (matchResult == 0) {
        printf("Case #%d: Bad magician!\n", caseNumber);
    } else {
        printf("Case #%d: %d\n", caseNumber, matchResult);
    }
}

int main(void) {
    int numberOfCases = readNumber();

    int caseNumber;
    for (caseNumber = 1; caseNumber <= numberOfCases; caseNumber++) {
        Card card1, card2;

        int row1 = readNumber() - 1;
        readCard(&card1);

        int row2 = readNumber() - 1;
        readCard(&card2);

        int matchResult = findMatch(&card1, &card2, row1, row2);

        printResult(numberOfCases, caseNumber, matchResult);
    }

    return 0;
}