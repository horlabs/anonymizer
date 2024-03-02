#include <stdio.h>

typedef struct {
    char data[4][5];
} Game;

void readInt(FILE *file, int *value) {
    fscanf(file, "%d", value);
}

void readChar(FILE *file, char *value) {
    fscanf(file, "%c ", value);
}

void readInts(FILE *file, int *value1, int *value2) {
    fscanf(file, "%d %d", value1, value2);
}

int isBitSet(int value, int bit) {
    return (value & (0x1 << bit));
}

void readGame(FILE *file, Game *game) {
    int i;
    for (i = 0; i < 4; i++) {
        fscanf(file, "%s", game->data[i]);
    }
}

void skipLines(FILE *file, int numLines) {
    int i;
    char dummy[100];
    for (i = 0; i < numLines; i++) {
        fscanf(file, "%s", dummy);
    }
}

void checkRows(Game *game, char *result) {
    int i, j;
    for (i = 0; i < 4; i++) {
        char prev = (game->data[i][0] == 'T') ? 0 : game->data[i][0];
        for (j = 1; j < 4; j++) {
            if (prev > 0) {
                if (prev != game->data[i][j] && game->data[i][j] != 'T') {
                    prev = -1;
                }
            } else if (game->data[i][j] != 'T' && prev == 0) {
                prev = game->data[i][j];
            }
        }
        if (prev > 0 && prev != '.') {
            *result = prev;
            return;
        }
    }
}

void checkColumns(Game *game, char *result) {
    int i, j;
    for (i = 0; i < 4; i++) {
        char prev = (game->data[0][i] == 'T') ? 0 : game->data[0][i];
        for (j = 1; j < 4; j++) {
            if (prev > 0) {
                if (prev != game->data[j][i] && game->data[j][i] != 'T') {
                    prev = -1;
                }
            } else if (game->data[j][i] != 'T' && prev == 0) {
                prev = game->data[j][i];
            }
        }
        if (prev > 0 && prev != '.') {
            *result = prev;
            return;
        }
    }
}

void checkDiagonals(Game *game, char *result) {
    int i;
    char prev = (game->data[0][0] == 'T') ? 0 : game->data[0][0];
    for (i = 1; i < 4; i++) {
        if (prev > 0) {
            if (prev != game->data[i][i] && game->data[i][i] != 'T') {
                prev = -1;
            }
        } else if (game->data[i][i] != 'T' && prev == 0) {
            prev = game->data[i][i];
        }
    }
    if (prev > 0 && prev != '.') {
        *result = prev;
        return;
    }

    prev = (game->data[0][3] == 'T') ? 0 : game->data[0][3];
    for (i = 1; i < 4; i++) {
        if (prev > 0) {
            if (prev != game->data[i][3 - i] && game->data[i][3 - i] != 'T') {
                prev = -1;
            }
        } else if (game->data[i][3 - i] != 'T' && prev == 0) {
            prev = game->data[i][3 - i];
        }
    }
    if (prev > 0 && prev != '.') {
        *result = prev;
        return;
    }
}

void analyzeGame(Game *game, char *result) {
    checkRows(game, result);
    if (*result != '.') {
        return;
    }
    
    checkColumns(game, result);
    if (*result != '.') {
        return;
    }

    checkDiagonals(game, result);
}

void writeResult(FILE *file, int caseNumber, char result) {
    if (result > 0) {
        fprintf(file, "Case #%d: %c won\n", caseNumber, result);
    } else {
        fprintf(file, "Case #%d: Draw\n", caseNumber);
    }
}

int main() {
    FILE *inputFile = fopen("A-small-attempt0.in", "r");
    FILE *outputFile = fopen("output.txt", "w");

    int numTestCases = -1;
    char result;
    Game game;

    readInt(inputFile, &numTestCases);

    int caseNumber;
    for (caseNumber = 1; caseNumber <= numTestCases; caseNumber++) {
        readGame(inputFile, &game);
        analyzeGame(&game, &result);
        writeResult(outputFile, caseNumber, result);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}