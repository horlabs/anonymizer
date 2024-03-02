#include <stdio.h>

typedef int boolean;
#define TRUE 1
#define FALSE 0

boolean isWinner(int board[4][4], int player) {
    // Check rows
    for (int i = 0; i < 4; i++) {
        boolean won = TRUE;
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != player && board[i][j] != 'T') {
                won = FALSE;
                break;
            }
        }
        if (won) {
            return TRUE;
        }
    }

    // Check columns
    for (int j = 0; j < 4; j++) {
        boolean won = TRUE;
        for (int i = 0; i < 4; i++) {
            if (board[i][j] != player && board[i][j] != 'T') {
                won = FALSE;
                break;
            }
        }
        if (won) {
            return TRUE;
        }
    }

    // Check diagonal 1
    boolean won = TRUE;
    for (int i = 0; i < 4; i++) {
        if (board[i][i] != player && board[i][i] != 'T') {
            won = FALSE;
            break;
        }
    }
    if (won) {
        return TRUE;
    }

    // Check diagonal 2
    won = TRUE;
    for (int i = 0; i < 4; i++) {
        if (board[i][3 - i] != player && board[i][3 - i] != 'T') {
            won = FALSE;
            break;
        }
    }
    if (won) {
        return TRUE;
    }

    return FALSE;
}

int main(void) {
    int num;
    scanf("%d", &num);

    for (int i = 1; i <= num; ++i) {
        char buf[6];
        int board[4][4];
        int empty = FALSE;

        // Input
        for (int j = 0; j < 4; ++j) {
            scanf("%s", buf);
            for (int k = 0; k < 4; ++k) {
                if (buf[k] == 'X') {
                    board[j][k] = 'X';
                } else if (buf[k] == 'O') {
                    board[j][k] = 'O';
                } else if (buf[k] == 'T') {
                    board[j][k] = 'T';
                } else {
                    board[j][k] = '.';
                    empty = TRUE;
                }
            }
        }

        // Check for winners
        printf("Case #%d: ", i);
        if (isWinner(board, 'X')) {
            printf("X won\n");
        } else if (isWinner(board, 'O')) {
            printf("O won\n");
        } else if (empty) {
            printf("Game has not completed\n");
        } else {
            printf("Draw\n");
        }
    }

    return 0;
}