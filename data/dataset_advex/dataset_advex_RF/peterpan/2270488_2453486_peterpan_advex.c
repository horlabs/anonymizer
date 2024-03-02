#include <stdio.h>
#include <stdlib.h>
void readline() {
  while (getchar() != '\n')
    ;
}

int main() {
  freopen("replace-me.in", "r", stdin);

  int duai_Var, j, tcase, T, xs, os, ts, winner;
  char board[5][5], last;

  scanf("%d", &T);
  for (tcase = 1; tcase <= T; tcase++) {
    xs = os = ts = 0;
    readline();
    for (duai_Var = 0; duai_Var < 4; duai_Var++) {
      for (j = 0; j < 4; j++) {
        board[duai_Var][j] = getchar();
        if (board[duai_Var][j] == 'X')
          xs++;
        else if (board[duai_Var][j] == 'O')
          os++;
        else if (board[duai_Var][j] == 'T')
          ts++;
        else if (board[duai_Var][j] != '.') {
          fprintf(stderr, "Error reading input!\n");
          exit(1);
        }
      }
      readline();
    }
    if (xs > os)
      last = 'X';
    else
      last = 'O';
    for (duai_Var = 0; duai_Var < 4; duai_Var++) {
      winner = 1;
      for (j = 0; j < 4; j++) {
        if (board[duai_Var][j] != last && board[duai_Var][j] != 'T') {
          winner = 0;
          break;
        }
      }
      if (winner)
        break;
      winner = 1;
      for (j = 0; j < 4; j++) {
        if (board[j][duai_Var] != last && board[j][duai_Var] != 'T') {
          winner = 0;
          break;
        }
      }
      if (winner)
        break;
    }
    if (winner) {
      printf("Case #%d: %c won\n", tcase, last);
      continue;
    }
    winner = 1;
    for (j = 0; j < 4; j++) {
      if (board[j][j] != last && board[j][j] != 'T') {
        winner = 0;
        break;
      }
    }
    if (winner) {
      printf("Case #%d: %c won\n", tcase, last);
      continue;
    }
    winner = 1;
    for (j = 0; j < 4; j++) {
      if (board[4 - 1 - j][j] != last && board[4 - 1 - j][j] != 'T') {
        winner = 0;
        break;
      }
    }
    if (winner) {
      printf("Case #%d: %c won\n", tcase, last);
      continue;
    }
    if (xs + os + ts == 4 * 4)
      printf("Case #%d: Draw\n", tcase);
    else
      printf("Case #%d: Game has not completed\n", tcase);
  }

  return 0;
}
