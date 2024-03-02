#include <stdio.h>

typedef struct {
    int x;
    int o;
    int t;
    int blank;
} Stats;

typedef struct {
    char board[4][4];
} Game;

void readBoard(Game* game) {
    game->board = {};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            game->board[i][j] = getchar();
        }
        getchar();
    }

    getchar();
}

Stats analyzeBoard(Game* game) {
    Stats stats = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (game->board[i][j] == '.') {
                stats.blank++;
            } else if (game->board[i][j] == 'X') {
                stats.x++;
            } else if (game->board[i][j] == 'O') {
                stats.o++;
            } else {
                stats.t++;
            }
        }
    }

    return stats;
}

int checkColumns(Game* game) {
    for (int i = 0; i < 4; i++) {
        int xCount = 0;
        int oCount = 0;

        for (int j = 0; j < 4; j++) {
            if (game->board[i][j] == 'X') {
                xCount++;
            } else if (game->board[i][j] == 'O') {
                oCount++;
            } else if (game->board[i][j] == 'T') {
                xCount++;
                oCount++;
            }
        }

        if (xCount == 4) {
            return 1;
        } else if (oCount == 4) {
            return -1;
        }
    }

    return 0;
}

int checkRows(Game* game) {
    for (int i = 0; i < 4; i++) {
        int xCount = 0;
        int oCount = 0;

        for (int j = 0; j < 4; j++) {
            if (game->board[j][i] == 'X') {
                xCount++;
            } else if (game->board[j][i] == 'O') {
                oCount++;
            } else if (game->board[j][i] == 'T') {
                xCount++;
                oCount++;
            }
        }

        if (xCount == 4) {
            return 1;
        } else if (oCount == 4) {
            return -1;
        }
    }

    return 0;
}

int checkDiagonals(Game* game) {
    int xCount = 0;
    int oCount = 0;

    for (int i = 0; i < 4; i++) {
        if (game->board[i][i] == 'X') {
            xCount++;
        } else if (game->board[i][i] == 'O') {
            oCount++;
        } else if (game->board[i][i] == 'T') {
            xCount++;
            oCount++;
        }
    }

    if (xCount == 4) {
        return 1;
    } else if (oCount == 4) {
        return -1;
    }

    xCount = 0;
    oCount = 0;

    for (int i = 0; i < 4; i++) {
        if (game->board[i][3 - i] == 'X') {
            xCount++;
        } else if (game->board[i][3 - i] == 'O') {
            oCount++;
        } else if (game->board[i][3 - i] == 'T') {
            xCount++;
            oCount++;
        }
    }

    if (xCount == 4) {
        return 1;
    } else if (oCount == 4) {
        return -1;
    }

    return 0;
}

void printResult(int result, int cases) {
    if (result == 1) {
        printf("Case #%d: X won\n", cases);
    } else if (result == -1) {
        printf("Case #%d: O won\n", cases);
    } else {
        printf("Case #%d: Draw\n", cases);
    }
}

int main(void) {
    int cases;
    scanf("%d\n", &cases);

    for (int i = 1; i <= cases; i++) {
        Game game;
        readBoard(&game);
        Stats stats = analyzeBoard(&game);

        if ((stats.x + stats.t) < 3) {
            printf("Case #%d: Game has not completed\n", i);
            continue;
        }

        int result = checkColumns(&game);
        if (result) {
            printResult(result, i);
            continue;
        }

        result = checkRows(&game);
        if (result) {
            printResult(result, i);
            continue;
        }

        result = checkDiagonals(&game);
        if (result) {
            printResult(result, i);
            continue;
        }

        if (stats.blank > 1) {
            printf("Case #%d: Game has not completed\n", i);
        } else {
            printf("Case #%d: Draw\n", i);
        }
    }

    return 0;
}