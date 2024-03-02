#include <stdio.h>
#include <string.h>

typedef unsigned long long td_ull;
int main() {
  freopen("replace-me.in", "r", stdin);

  int i, j;
  int jj, ztji_Var;
  int rffi_Var;
  int wnci_Var;
  char map[10][10];
  int ekpi_Var, xw, ow;

  td_ull ahlt_Var;

  scanf("%d", &wnci_Var);

  for (int drbi_Var = 1; drbi_Var <= wnci_Var; drbi_Var++) {
    ekpi_Var = 1;
    xw = 0;
    ow = 0;
    memset(map, 0, 100);
    ahlt_Var = 0;
    for (i = 0; i < 4; i++) {
      scanf("%s", map[i]);
    }

    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        if (map[i][j] == '.')
          break;
      }
      if (j != 4)
        break;
    }
    if (i != 4 && j != 4)
      ekpi_Var = 0;

    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        if (map[i][j] != 'O' && map[i][j] != 'T') {
          break;
        }
      }
      if (j == 4)
        ow = 1;
      for (j = 0; j < 4; j++) {
        if (map[i][j] != 'X' && map[i][j] != 'T')
          break;
      }
      if (j == 4)
        xw = 1;
      for (j = 0; j < 4; j++) {
        if (map[j][i] != 'O' && map[j][i] != 'T')
          break;
      }
      if (j == 4)
        ow = 1;
      for (j = 0; j < 4; j++) {
        if (map[j][i] != 'X' && map[j][i] != 'T')
          break;
      }
      if (j == 4)
        xw = 1;
    }

    for (i = 0; i < 4; i++) {
      if (map[i][i] != 'X' && map[i][i] != 'T')
        break;
    }
    if (i == 4)
      xw = 1;

    for (i = 0; i < 4; i++) {
      if (map[3 - i][i] != 'X' && map[3 - i][i] != 'T')
        break;
    }
    if (i == 4)
      xw = 1;

    for (i = 0; i < 4; i++) {
      if (map[i][i] != 'O' && map[i][i] != 'T')
        break;
    }
    if (i == 4)
      ow = 1;

    for (i = 0; i < 4; i++) {
      if (map[3 - i][i] != 'O' && map[3 - i][i] != 'T')
        break;
    }
    if (i == 4)
      ow = 1;

    if (xw == 1)
      printf("Case #%d: X won\n", drbi_Var);
    else if (ow == 1)
      printf("Case #%d: O won\n", drbi_Var);
    else {
      if (ekpi_Var == 1)
        printf("Case #%d: Draw\n", drbi_Var);
      else
        printf("Case #%d: Game has not completed\n", drbi_Var);
    }
  }
}
