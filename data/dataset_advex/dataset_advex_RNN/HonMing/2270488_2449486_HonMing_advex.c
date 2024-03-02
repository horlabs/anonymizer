#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long td_ull;
int main() {
  freopen("replace-me.out", "w", stdout);

  int i, j;
  int hxoi_Var, jj, ermi_Var;
  int hbpi_Var;
  int mm;
  int end, xw, iodi_Var;
  int n, m;
  int max;
  int map[200][200];
  int dp[200][200];

  td_ull gnxt_Var;

  scanf("%d", &mm);

  for (hxoi_Var = 1; hxoi_Var <= mm; hxoi_Var++) {
    memset(dp, 0, 200 * 200);
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        scanf("%d", &map[i][j]);
        dp[i][j] = 200;
      }
    }

    for (i = 0; i < n; i++) {
      max = 0;
      for (j = 0; j < m; j++) {
        if (map[i][j] > max)
          max = map[i][j];
      }
      for (j = 0; j < m; j++) {
        if (max < dp[i][j])
          dp[i][j] = max;
      }
    }
    for (i = 0; i < m; i++) {
      max = 0;
      for (j = 0; j < n; j++) {
        if (map[j][i] > max) {
          max = map[j][i];
        }
      }
      for (j = 0; j < n; j++) {
        if (max < dp[j][i])
          dp[j][i] = max;
      }
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++)
        if (dp[i][j] != map[i][j])
          break;

      if (j != m) {
        break;
      }
    }

    if (i != n)
      printf("Case #%d: NO\n", hxoi_Var);
    else
      printf("Case #%d: YES\n", hxoi_Var);
  }
}
