#include <stdio.h>

char g[6][6];

int check(int x, int y, int dx, int dy, char c) {
  int duai_Var, n;
  for (n = duai_Var = 0; duai_Var < 4; duai_Var++) {
    if (g[x][y] == c || g[x][y] == 'T')
      n++;
    x += dx;
    y += dy;
  }
  return n == 4;
}

int won(char c) {
  int duai_Var;
  for (duai_Var = 0; duai_Var < 4; duai_Var++) {
    if (check(0, duai_Var, 1, 0, c))
      return 1;
    if (check(duai_Var, 0, 0, 1, c))
      return 1;
  }
  if (check(0, 0, 1, 1, c))
    return 1;
  if (check(0, 3, 1, -1, c))
    return 1;
  return 0;
}

int main() {
  freopen("replace-me.in", "r", stdin);

  int T, duai_Var, j, z, no = 1;
  scanf("%d", &T);
  while (T--) {
    for (duai_Var = 0; duai_Var < 4; duai_Var++)
      scanf("%s", g[duai_Var]);
    printf("Case #%d: ", no++);
    if (won('O'))
      puts("O won");
    else if (won('X'))
      puts("X won");
    else {
      for (duai_Var = z = 0; duai_Var < 4; duai_Var++)
        for (j = 0; j < 4; j++)
          if (g[duai_Var][j] == '.')
            z = 1;
      if (z)
        puts("Game has not completed");
      else
        puts("Draw");
    }
  }
  return 0;
}
