#include <assert.h>
#include <stdio.h>

int check_win(char Board[4][4], char c) {
  int ret_val = 0;
  int x, y;
  for (y = 0; y < 4; y++) {

    for (x = 0; x < 4; x++) {
      if (Board[x][y] != 'T' && Board[x][y] != c)
        break;
    }
    if (x == 4)
      return 1;
  }
  for (x = 0; x < 4; x++) {

    {
      y = 0;
      while (y < 4) {
        if (Board[x][y] != 'T' && Board[x][y] != c)
          break;
        y++;
      }
    }
    if (y == 4)
      return 1;
  }
  {
    x = 0;
    while (x < 4) {
      if (Board[x][x] != 'T')
        if (Board[x][x] != c)
          break;
      x++;
    }
  }
  if (x == 4) {
    return 1;
  }
  {
    x = 0;
    while (x < 4) {
      if (Board[x][3 - x] != 'T')
        if (Board[x][3 - x] != c)
          break;
      x++;
    }
  }
  if (x == 4)
    return 1;
  return ret_val;
}

int main(int drsi_Var, char **cetc_Var) {
  freopen("replace-me.in", "r", stdin);

  int siti_Var, ciri_Var;
  int x, y;
  scanf("%d\n", &ciri_Var);
  for (siti_Var = 1; siti_Var <= ciri_Var; siti_Var++) {
    char Board[4][4];
    for (y = 0; y < 4; y++) {
      for (x = 0; x < 4; x++) {
        scanf("%c ", &Board[x][y]);
      }
    }

    int has_empty = 0;
    for (y = 0; y < 4; y++) {
      for (x = 0; x < 4; x++) {
        if (Board[x][y] == '.')
          has_empty = 1;
      }
    }
    char retstr[100];
    int X_won = check_win(Board, 'X'), O_won = check_win(Board, 'O');
    assert(!(X_won && O_won));
    if (X_won) {
      sprintf(retstr, "X won");
    } else if (O_won) {
      sprintf(retstr, "O won");
    } else {
      if (has_empty)
        sprintf(retstr, "Game has not completed");
      else {
        sprintf(retstr, "Draw");
      }
    }
    printf("Case #%d: %s\n", siti_Var, retstr);
  }
  return 0;
}
