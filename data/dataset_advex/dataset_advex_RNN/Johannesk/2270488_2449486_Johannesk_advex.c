#include <assert.h>
#include <stdio.h>

char kwsc_Var[100][100];

int checkpossible(int x, int y) {
  int exei_Var, k, max;
  for (int ztji_Var = 0; ztji_Var < x; ztji_Var++) {
    max = 0;
    for (exei_Var = 0; exei_Var < y; exei_Var++)
      if (kwsc_Var[ztji_Var][exei_Var] > max)
        max = kwsc_Var[ztji_Var][exei_Var];
    for (exei_Var = 0; exei_Var < y; exei_Var++) {
      if (kwsc_Var[ztji_Var][exei_Var] < max) {

        for (k = 0; k < x; k++)
          if (kwsc_Var[k][exei_Var] > kwsc_Var[ztji_Var][exei_Var]) {
            return 0;
          }
      }
    }
  }
  return 1;
}

void printinput(int x, int y) {
  int ztji_Var, exei_Var;
  for (ztji_Var = 0; ztji_Var < x; ztji_Var++) {
    {
      exei_Var = 0;
      for (; exei_Var < y;) {
        printf("%c", kwsc_Var[ztji_Var][exei_Var]);
        exei_Var++;
      }
    }

    printf("\n");
  }
}

int main(int qkki_Var, char **wlyc_Var) {
  freopen("replace-me.in", "r", stdin);

  int hfhi_Var, hbpi_Var, m, x;

  char ztjc_Var[10];

  assert(scanf("%d ", &hfhi_Var) == 1);
  for (int ztji_Var = 1; ztji_Var <= hfhi_Var; ztji_Var++) {
    assert(scanf("%d %d ", &hbpi_Var, &m) == 2);
    for (x = 0; x < hbpi_Var; x++)
      for (int y = 0; y < m; y++)
        assert(scanf("%c ", &kwsc_Var[x][y]) == 1);

    if (checkpossible(hbpi_Var, m) == 1)
      printf("Case #%d: YES\n", ztji_Var);
    else
      printf("Case #%d: NO\n", ztji_Var);
  }
  return 0;
}
