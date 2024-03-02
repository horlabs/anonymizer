#include "superheader.h"

int check_win(char Board[4][4], char c) {
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

    for (y = 0; y < 4; y++) {
      if (Board[x][y] != 'T' && Board[x][y] != c)
        break;
    }
    if (y == 4)
      return 1;
  }

  for (x = 0; x < 4; x++) {
    if (Board[x][x] != 'T' && Board[x][x] != c)
      break;
  }
  if (x == 4)
    return 1;
  for (x = 0; x < 4; x++) {
    if (Board[x][3 - x] != 'T' && Board[x][3 - x] != c)
      break;
  }
  if (x == 4)
    return 1;
  return 0;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t, T;
  int x, y;
  scanf("%d\n", &T);
  for (t = 1; t <= T; t++) {
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
    (!(X_won && O_won));
    if (X_won) {
      sprintf(retstr, "X won");
    } else if (O_won) {
      sprintf(retstr, "O won");
    } else {
      if (has_empty) {
        sprintf(retstr, "Game has not completed");
      } else {
        sprintf(retstr, "Draw");
      }
    }
    printf("Case #%d: %s\n", t, retstr);
  }
  return 0;
}
