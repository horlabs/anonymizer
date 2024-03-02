#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct {
    char grid[4][4];
} Board;

int isWin(Board board, char player) {
    int row, col;

    // Check rows
    for (row = 0; row < 4; row++) {
        int count = 0;
        for (col = 0; col < 4; col++) {
            if (board.grid[row][col] == player || board.grid[row][col] == 'T') {
                count++;
            }
        }
        if (count == 4) {
            return 1;
        }
    }

    // Check columns
    for (col = 0; col < 4; col++) {
        int count = 0;
        for (row = 0; row < 4; row++) {
            if (board.grid[row][col] == player || board.grid[row][col] == 'T') {
                count++;
            }
        }
        if (count == 4) {
            return 1;
        }
    }

    // Check diagonals
    int count = 0;
    for (row = 0; row < 4; row++) {
        if (board.grid[row][row] == player || board.grid[row][row] == 'T') {
            count++;
        }
    }
    if (count == 4) {
        return 1;
    }

    count = 0;
    for (row = 0; row < 4; row++) {
        if (board.grid[3 - row][row] == player || board.grid[3 - row][row] == 'T') {
            count++;
        }
    }
    if (count == 4) {
        return 1;
    }

    return 0;
}

int isDraw(Board board) {
    int row, col;

    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            if (board.grid[row][col] == '.') {
                return 0;
            }
        }
    }
    return 1;
}

void printBoard(Board board) {
    int row, col;

    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            printf("%c", board.grid[row][col]);
        }
        printf("\n");
    }
}

int main(void) {
    int numTestcases, i;
    Board board;
    char line[10];

    assert(scanf("%d", &numTestcases) == 1); // Number of testcases

    for (i = 1; i <= numTestcases; i++) {
        assert(scanf("%c%c%c%c ", &board.grid[0][0], &board.grid[0][1], &board.grid[0][2], &board.grid[0][3]) == 4);
        assert(scanf("%c%c%c%c ", &board.grid[1][0], &board.grid[1][1], &board.grid[1][2], &board.grid[1][3]) == 4);
        assert(scanf("%c%c%c%c ", &board.grid[2][0], &board.grid[2][1], &board.grid[2][2], &board.grid[2][3]) == 4);
        assert(scanf("%c%c%c%c ", &board.grid[3][0], &board.grid[3][1], &board.grid[3][2], &board.grid[3][3]) == 4);

        if (isWin(board, 'X'))
            printf("Case #%d: X won\n", i);
        else if (isWin(board, 'O'))
            printf("Case #%d: O won\n", i);
        else if (isDraw(board))
            printf("Case #%d: Draw\n", i);
        else
            printf("Case #%d: Game has not completed\n", i);
    }

    return 0;
}