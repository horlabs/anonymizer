#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char board[123][123];
int X, O;
int x, o;

void check(int duai_Var, int j) {
  if (board[duai_Var][j] == 'O') {
    ++o, x = -1000;
  } else if (board[duai_Var][j] == 'X') {
    ++x, o = -1000;
  } else if (board[duai_Var][j] == 'T') {
    ++x, ++o;
  }
}
void cnt() {
  if (x == 4)
    X = 2;
  if (o == 4)
    O = 2;
  if (x >= 0)
    X |= 1;
  if (o >= 0)
    O |= 1;
}
int main() {
  freopen("replace-me.in", "r", stdin);

  int t, T;
  int duai_Var, j;
  scanf("%d", &T);
  for (t = 1; t <= T; ++t) {
    for (duai_Var = 0; duai_Var < 4; ++duai_Var) {
      scanf("%s", board[duai_Var]);
    }
    X = O = 0;
    for (duai_Var = 0; duai_Var < 4; ++duai_Var) {
      for (j = x = o = 0; j < 4; ++j) {
        check(duai_Var, j);
      }
      cnt();
    }
    for (duai_Var = 0; duai_Var < 4; ++duai_Var) {
      for (j = x = o = 0; j < 4; ++j) {
        check(j, duai_Var);
      }
      cnt();
    }
    for (duai_Var = j = x = o = 0; duai_Var < 4; ++duai_Var, ++j) {
      check(j, duai_Var);
    }
    cnt();
    for (duai_Var = 3, j = x = o = 0; j < 4; --duai_Var, ++j) {
      check(j, duai_Var);
    }
    cnt();
    printf("Case #%d: ", t);
    if (X >= 2)
      puts("X won");
    if (O >= 2)
      puts("O won");
    if (X == 1 && O == 1)
      puts("Game has not completed");
    if (X == 0 && O == 0)
      puts("Draw");
  }
  return 0;
}
