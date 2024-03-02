#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define BOARD_SIZE 4

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} Game;

static bool is_x(char tile) {
    return tile == 'X' || tile == 'T';
}

static bool is_o(char tile) {
    return tile == 'O' || tile == 'T';
}

static void get_board(Game* game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        scanf(" %4c", game->board[i]);
    }
}

static bool check_winning_sequence(const char* sequence) {
    bool x_won = true, o_won = true;

    for (int i = 0; i < BOARD_SIZE; i++) {
        x_won = x_won && is_x(sequence[i]);
        o_won = o_won && is_o(sequence[i]);
    }

    return x_won || o_won;
}

static void check_game_status(const Game* game, bool* unfinished, bool* x_won, bool* o_won) {
    bool x_won_diag_1 = true, o_won_diag_1 = true, x_won_diag_2 = true, o_won_diag_2 = true;

    for (int i = 0; i < BOARD_SIZE; i++) {
        bool x_won_col = true, o_won_col = true, x_won_row = true, o_won_row = true;

        for (int j = 0; j < BOARD_SIZE; j++) {
            *unfinished = *unfinished || game->board[i][j] == '.';

            x_won_col = x_won_col && is_x(game->board[j][i]);
            o_won_col = o_won_col && is_o(game->board[j][i]);

            x_won_row = x_won_row && is_x(game->board[i][j]);
            o_won_row = o_won_row && is_o(game->board[i][j]);
        }

        *x_won = *x_won || x_won_col || x_won_row;
        *o_won = *o_won || o_won_col || o_won_row;

        x_won_diag_1 = x_won_diag_1 && is_x(game->board[i][i]);
        o_won_diag_1 = o_won_diag_1 && is_o(game->board[i][i]);

        x_won_diag_2 = x_won_diag_2 && is_x(game->board[BOARD_SIZE - 1 - i][i]);
        o_won_diag_2 = o_won_diag_2 && is_o(game->board[BOARD_SIZE - 1 - i][i]);
    }

    *x_won = *x_won || x_won_diag_1 || x_won_diag_2;
    *o_won = *o_won || o_won_diag_1 || o_won_diag_2;
}

static void print_game_status(int t, bool x_won, bool o_won, bool unfinished) {
    printf("Case #%d: ", t + 1);

    if (x_won) {
        printf("X won\n");
    } else if (o_won) {
        printf("O won\n");
    } else if (unfinished) {
        printf("Game has not completed\n");
    } else {
        printf("Draw\n");
    }
}

static void do_test(int t) {
    Game game;
    bool unfinished = false;
    bool x_won = false;
    bool o_won = false;

    get_board(&game);
    check_game_status(&game, &unfinished, &x_won, &o_won);
    print_game_status(t, x_won, o_won, unfinished);
}

int main() {
    int t;

    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        do_test(i);
    }

    return 0;
}