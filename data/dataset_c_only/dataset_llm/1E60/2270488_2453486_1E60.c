#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char board[4][4];
} Game;

int checkWin(Game* game, char c) {
    int x, y;
    for (y = 0; y < 4; y++) {
        // Check along X
        for (x = 0; x < 4; x++) {
            if (game->board[x][y] != 'T' && game->board[x][y] != c)
                break;
        }
        if (x == 4)
            return 1;
    }
    for (x = 0; x < 4; x++) {
        // Check along Y
        for (y = 0; y < 4; y++) {
            if (game->board[x][y] != 'T' && game->board[x][y] != c)
                break;
        }
        if (y == 4)
            return 1;
    }
    // Check along Diagonal
    for (x = 0; x < 4; x++) {
        if (game->board[x][x] != 'T' && game->board[x][x] != c)
            break;
    }
    if (x == 4)
        return 1;
    for (x = 0; x < 4; x++) {
        if (game->board[x][3 - x] != 'T' && game->board[x][3 - x] != c)
            break;
    }
    if (x == 4)
        return 1;
    return 0;
}

void playGame(int numGames, Game* games) {
    for (int t = 1; t <= numGames; t++) {
        Game* currentGame = &games[t-1];

        int hasEmpty = 0;
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                if (currentGame->board[x][y] == '.') {
                    hasEmpty = 1;
                    break;
                }
            }
        }

        char result[100];
        int xWon = checkWin(currentGame, 'X');
        int oWon = checkWin(currentGame, 'O');
        if (xWon) {
            sprintf(result, "X won");
        } else if (oWon) {
            sprintf(result, "O won");
        } else {
            if (hasEmpty) {
                sprintf(result, "Game has not completed");
            } else {
                sprintf(result, "Draw");
            }
        }

        printf("Case #%d: %s\n", t, result);
    }
}

int main(int argc, char** argv) {
    int numGames;
    scanf("%d\n", &numGames);

    Game* games = malloc(sizeof(Game) * numGames);

    for (int t = 0; t < numGames; t++) {
        Game* currentGame = &games[t];

        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                scanf("%c ", &currentGame->board[x][y]);
            }
        }
    }

    playGame(numGames, games);

    free(games);
    return 0;
}