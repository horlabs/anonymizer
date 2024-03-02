#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define BOARD_SIZE 4

typedef struct {
    char s[BOARD_SIZE+1];
} Row;

typedef struct {
    int x;
    int o;
} Score;

char* output[] = {"X won", "O won", "Draw", "Game has not completed"};

void readBoard(FILE *fin, Row board[BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        fscanf(fin, "%s", board[i].s);
    }
}

void updateScore(char ch, Score *score) {
    if (ch == 'X') {
        score->x++;
    } else if (ch == 'O') {
        score->o++;
    }
}

Score calculateRowScore(const Row boardRow) {
    Score rowScore = {0, 0};
    for (int i = 0; i < BOARD_SIZE; i++) {
        updateScore(boardRow.s[i], &rowScore);
    }
    return rowScore;
}

int checkWin(Score score) {
    if (score.x == BOARD_SIZE) {
        return 1;
    } else if (score.o == BOARD_SIZE) {
        return 2;
    } else {
        return 0;
    }
}

int checkRows(const Row board[BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        Score rowScore = calculateRowScore(board[i]);
        int result = checkWin(rowScore);
        if (result != 0) {
            return result;
        }
    }
    return 0;
}

int checkColumns(const Row board[BOARD_SIZE]) {
    for (int j = 0; j < BOARD_SIZE; j++) {
        Score columnScore = {0, 0};
        for (int i = 0; i < BOARD_SIZE; i++) {
            updateScore(board[i].s[j], &columnScore);
        }
        int result = checkWin(columnScore);
        if (result != 0) {
            return result;
        }
    }
    return 0;
}

int checkDiagonal(const Row board[BOARD_SIZE]) {
    Score diagonalScore = {0, 0};
    for (int i = 0; i < BOARD_SIZE; i++) {
        updateScore(board[i].s[i], &diagonalScore);
    }
    int result = checkWin(diagonalScore);
    if (result != 0) {
        return result;
    }
    
    diagonalScore.x = 0;
    diagonalScore.o = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        updateScore(board[i].s[BOARD_SIZE-1-i], &diagonalScore);
    }
    result = checkWin(diagonalScore);
    if (result != 0) {
        return result;
    }
    
    return 0;
}

int checkGameStatus(const Row board[BOARD_SIZE]) {
    int rowWin = checkRows(board);
    if (rowWin != 0) {
        return rowWin;
    }
    
    int columnWin = checkColumns(board);
    if (columnWin != 0) {
        return columnWin;
    }
    
    int diagonalWin = checkDiagonal(board);
    if (diagonalWin != 0) {
        return diagonalWin;
    }
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i].s[j] == '.') {
                return 4;
            }
        }
    }
    
    return 3;
}

int main(void) {
    Row board[BOARD_SIZE];
    int T;
    FILE *fin = fopen("A-small-attempt0.in", "r");
    FILE *fout = fopen("out.txt", "w");

    fscanf(fin, "%d", &T);

    for (int k = 0; k < T; k++) {
        readBoard(fin, board);
        int gameStatus = checkGameStatus(board);
        fprintf(fout, "Case #%d: %s\n", k+1, output[gameStatus-1]);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}