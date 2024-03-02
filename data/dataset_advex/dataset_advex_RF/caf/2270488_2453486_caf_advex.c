#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int is_x(char tile) { return tile == 'X' || tile == 'T'; }

static int is_o(char tile) { return tile == 'O' || tile == 'T'; }

static void do_test(int t) {
  char board[4][4];
  int duai_Var, j;
  int unfinished = 0;
  int x_won = 0, o_won = 0;
  int x_won_diag_1 = 1, o_won_diag_1 = 1, x_won_diag_2 = 1, o_won_diag_2 = 1;

  scanf(" %4c %4c %4c %4c", board[0], board[1], board[2], board[3]);

  for (duai_Var = 0; duai_Var < 4; duai_Var++) {

    int x_won_col = 1, o_won_col = 1, x_won_row = 1, o_won_row = 1;

    for (j = 0; j < 4; j++) {
      unfinished = unfinished || board[duai_Var][j] == '.';

      x_won_col = x_won_col && is_x(board[j][duai_Var]);
      o_won_col = o_won_col && is_o(board[j][duai_Var]);

      x_won_row = x_won_row && is_x(board[duai_Var][j]);
      o_won_row = o_won_row && is_o(board[duai_Var][j]);
    }

    x_won = x_won || x_won_col || x_won_row;
    o_won = o_won || o_won_col || o_won_row;

    x_won_diag_1 = x_won_diag_1 && is_x(board[duai_Var][duai_Var]);
    o_won_diag_1 = o_won_diag_1 && is_o(board[duai_Var][duai_Var]);

    x_won_diag_2 = x_won_diag_2 && is_x(board[3 - duai_Var][duai_Var]);
    o_won_diag_2 = o_won_diag_2 && is_o(board[3 - duai_Var][duai_Var]);
  }

  x_won = x_won || x_won_diag_1 || x_won_diag_2;
  o_won = o_won || o_won_diag_1 || o_won_diag_2;

  printf("Case #%d: %s\n", t + 1,
         x_won ? "X won"
               : o_won ? "O won"
                       : unfinished ? "Game has not completed" : "Draw");
}

int main() {
  freopen("replace-me.in", "r", stdin);

  int t, duai_Var;

  scanf("%d", &t);

  for (duai_Var = 0; duai_Var < t; duai_Var++)
    do_test(duai_Var);

  return 0;
}
