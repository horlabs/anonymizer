#include "superheader.h"

char g[5][5];
int flag;

int check(char ch) {
  int i, j, col[4] = {0}, row[4] = {0};
  int cc = 0, dd = 0;
  for (i = 0; i < 4; i++) {
    if (g[i][i] == ch || g[i][i] == 'T')
      cc++;
    if (g[i][3 - i] == ch || g[i][3 - i] == 'T')
      dd++;
    for (j = 0; j < 4; j++) {
      if (g[i][j] == ch || g[i][j] == 'T')
        row[i]++;
      if (g[j][i] == ch || g[j][i] == 'T')
        col[i]++;
    }
  }
  for (i = 0; i < 4; i++)
    if (row[i] == 4 || col[i] == 4)
      return 1;
  if (cc == 4 || dd == 4)
    return 1;
  return 0;
}

int gao() {
  int i, j, flag = 0;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      flag += (g[i][j] == '.');
  if (check('X'))
    return 0;
  if (check('O'))
    return 1;
  if (flag == 0)
    return 2;
  return 3;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T, i, nCase = 1;

  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.txt", "w", stdout);

  char result[][50] = {"X won", "O won", "Draw", "Game has not completed"};
  scanf("%d", &T);
  while (T--) {
    for (i = 0; i < 4; i++)
      scanf("%s", g[i]);
    printf("Case #%d: %s\n", nCase++, result[gao()]);
  }
  return 0;
}
