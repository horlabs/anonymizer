#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int card1;
    int card2;
    int card3;
    int card4;
} Cards;

int isCardMatch(int card, Cards playerCards) {
    return card == playerCards.card1 || card == playerCards.card2 || card == playerCards.card3 || card == playerCards.card4;
}

void testGuess(int testNum) {
    int i;
    int row;
    Cards player1, player2;
    int theCard;
    int nFound = 0;

    scanf("%d", &row);

    for (i = 1; i < 5; i++) {
        scanf("%d %d %d %d", &player1.card1, &player1.card2, &player1.card3, &player1.card4);
        if (i == row) {
            player2 = player1;
        }
    }

    scanf("%d", &row);

    for (i = 1; i < 5; i++) {
        int guess1, guess2, guess3, guess4;
        scanf("%d %d %d %d", &guess1, &guess2, &guess3, &guess4);

        if (i == row) {
            if (isCardMatch(player2.card1, (Cards){guess1, guess2, guess3, guess4})) {
                theCard = player2.card1;
                nFound++;
            }
            if (isCardMatch(player2.card2, (Cards){guess1, guess2, guess3, guess4})) {
                theCard = player2.card2;
                nFound++;
            }
            if (isCardMatch(player2.card3, (Cards){guess1, guess2, guess3, guess4})) {
                theCard = player2.card3;
                nFound++;
            }
            if (isCardMatch(player2.card4, (Cards){guess1, guess2, guess3, guess4})) {
                theCard = player2.card4;
                nFound++;
            }
        }
    }

    printf("Case #%d: ", testNum + 1);
    if (nFound < 1)
        printf("Volunteer cheated!\n");
    else if (nFound > 1)
        printf("Bad magician!\n");
    else
        printf("%d\n", theCard);
}

int main() {
    int t, i;
    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        testGuess(i);
    }

    return 0;
}