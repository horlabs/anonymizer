#include <stdio.h>
#include <stdlib.h>
void do_voiiix_fct();
int getResult(int x, int y, int redi_Var);

int grid[4][4];

int dx[] = {0, 1, 1, -1};
int dy[] = {1, 1, 0, 1};

int main() {

  freopen("aout.txt", "w", stdout);
  int jvli_Var;
  scanf("%d ", &jvli_Var);
  int duai_Var;
  for (duai_Var = 0; duai_Var < jvli_Var; duai_Var++) {
    printf("Case #%d: ", duai_Var + 1);
    do_voiiix_fct();
  }
  return 0;
}

void do_voiiix_fct() {
  int duai_Var, j, k;
  int full = 1;
  for (duai_Var = 0; duai_Var < 4; duai_Var++) {
    for (j = 0; j < 4; j++) {
      char c;
      int type;
      scanf("%c ", &c);
      if (c == 'X') {
        type = 0;
      } else if (c == 'O') {
        type = 1;
      } else if (c == 'T') {
        type = 2;
      } else {
        full = 0;
        type = 3;
      }
      grid[duai_Var][j] = type;
    }
  }
  for (duai_Var = 0; duai_Var < 4; duai_Var++) {
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++) {
        int result = getResult(j, duai_Var, k);
        if (result == 0) {
          printf("X won\n");
          return;
        } else if (result == 1) {
          printf("O won\n");
          return;
        }
      }
    }
  }
  if (full) {
    printf("Draw\n");
  } else {
    printf("Game has not completed\n");
  }
}

int getResult(int x, int y, int redi_Var) {
  int duai_Var;
  int cur = 2;
  for (duai_Var = 0; duai_Var < 4; duai_Var++) {
    if (x >= 4 || y >= 4 || x < 0 || y < 0) {
      return 2;
    }
    if (grid[y][x] == 3) {
      return 2;
    }
    if (grid[y][x] != 2) {
      if (cur == 2 || cur == grid[y][x]) {
        cur = grid[y][x];
      } else {
        return 2;
      }
    }
    x += dx[redi_Var];
    y += dy[redi_Var];
  }
  return cur;
}
