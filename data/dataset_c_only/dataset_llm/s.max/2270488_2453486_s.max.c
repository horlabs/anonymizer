#include <stdio.h>

struct Game {
    char board[4][5];
};

int isWon(struct Game game, char first, char second) {
    for (int i = 0; i < 4; i++) {
        int j;
        for (j = 0; j < 4; j++) {
            if (game.board[i][j] != first && game.board[i][j] != second)
                break;
        }
        if (j == 4)
            return 1;
    }

    for (int i = 0; i < 4; i++) {
        int j;
        for (j = 0; j < 4; j++) {
            if (game.board[j][i] != first && game.board[j][i] != second)
                break;
        }
        if (j == 4)
            return 1;
    }

    for (int i = 0; i < 4; i++) {
        if (game.board[i][i] != first && game.board[i][i] != second)
            break;
        if (i == 3)
            return 1;
    }

    for (int i = 0; i < 4; i++) {
        if (game.board[i][3 - i] != first && game.board[i][3 - i] != second)
            break;
        if (i == 3)
            return 1;
    }

    return 0;
}

int isComplete(struct Game game) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (game.board[i][j] == '.')
                return 0;
        }
    }
    return 1;
}

int main() {
    int numberOfCases;
    scanf("%d", &numberOfCases);

    for (int currentCase = 1; currentCase <= numberOfCases; currentCase++) {
        struct Game game;
        for (int i = 0; i < 4; i++)
            scanf("%s", game.board[i]);

        printf("Case #%d: ", currentCase);
        if (isWon(game, 'X', 'T'))
            printf("X won");
        else if (isWon(game, 'O', 'T'))
            printf("O won");
        else if (isComplete(game))
            printf("Draw");
        else
            printf("Game has not completed");
        printf("\n");
    }
    return 0;
}