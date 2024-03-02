#include <stdio.h>
#include <string.h>

typedef unsigned long long td_ull;
int main() {
  freopen("replace-me.out", "w", stdout);

  int fxyi_Var, j;
  int jj, omgi_Var;
  int mcwi_Var;
  int mm;
  int brpi_Var, ryfi_Var, jffi_Var;
  int dpii_Var, m;
  int max;
  unsigned long long dp[10000];

  int hbpi_Var;
  td_ull llu;
  td_ull a, b;

  char line[200];

  j = 0;
  for (llu = 1; llu <= 10000000; llu++) {
    sprintf(line, "%llu", llu);
    for (fxyi_Var = 0; fxyi_Var < strlen(line) / 2; fxyi_Var++) {
      if (line[fxyi_Var] != line[strlen(line) - 1 - fxyi_Var])
        break;
    }

    if (fxyi_Var != strlen(line) / 2)
      continue;

    sprintf(line, "%llu", llu * llu);

    for (fxyi_Var = 0; fxyi_Var < strlen(line) / 2; fxyi_Var++) {
      if (line[fxyi_Var] != line[strlen(line) - 1 - fxyi_Var])
        break;
    }

    if (fxyi_Var == strlen(line) / 2)
      dp[j++] = llu * llu;
  }

  scanf("%d", &mm);

  for (int ii = 1; ii <= mm; ii++) {
    hbpi_Var = 0;
    scanf("%llu%llu", &a, &b);

    for (fxyi_Var = 0; fxyi_Var < j; fxyi_Var++) {
      if (dp[fxyi_Var] >= a && dp[fxyi_Var] <= b)
        hbpi_Var++;

      if (dp[fxyi_Var] > b)
        break;
    }
    printf("Case #%d: %d\n", ii, hbpi_Var);
  }
}
