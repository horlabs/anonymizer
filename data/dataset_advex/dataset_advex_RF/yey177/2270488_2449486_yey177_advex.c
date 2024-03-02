#include <stdio.h>

int d[102][102];

int main() {
  freopen("replace-me.in", "r", stdin);

  int t, n, m, duai_Var, j, k, x, max, min, f;
  scanf("%d", &t);
  for (x = 1; x <= t; x++) {
    scanf("%d%d", &n, &m);
    for (duai_Var = 0; duai_Var < n; duai_Var++)
      for (j = 0; j < m; j++)
        scanf("%d", &d[duai_Var][j]);
    f = 1;
    for (k = 1; k <= 100; k++) {
      for (duai_Var = 0; duai_Var < n; duai_Var++) {
        min = 101;
        max = 0;
        for (j = 0; j < m; j++) {
          if (d[duai_Var][j]) {
            min = (((min) < (d[duai_Var][j])) ? (min) : (d[duai_Var][j]));
            max = (((max) > (d[duai_Var][j])) ? (max) : (d[duai_Var][j]));
          }
        }
        if (min == k && max == k) {
          for (j = 0; j < m; j++)
            d[duai_Var][j] = 0;
        }
      }
      for (j = 0; j < m; j++) {
        min = 101;
        max = 0;
        for (duai_Var = 0; duai_Var < n; duai_Var++) {
          if (d[duai_Var][j]) {
            min = (((min) < (d[duai_Var][j])) ? (min) : (d[duai_Var][j]));
            max = (((max) > (d[duai_Var][j])) ? (max) : (d[duai_Var][j]));
          }
        }
        if (min == k && max == k) {
          for (duai_Var = 0; duai_Var < n; duai_Var++)
            d[duai_Var][j] = 0;
        }
      }
      for (duai_Var = 0; duai_Var < n; duai_Var++)
        for (j = 0; j < m; j++) {
          if (d[duai_Var][j] == k) {
            f = 0;
            goto END;
          }
        }
    }
  END:
    printf("Case #%d: %s\n", x, f ? "YES" : "NO");
  }
  return 0;
}
