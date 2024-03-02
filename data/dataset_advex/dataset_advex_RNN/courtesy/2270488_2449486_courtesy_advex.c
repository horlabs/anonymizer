#include <stdio.h>

int miqi_Var[100][100], r[100], c[100], n, m;
int main() {
  freopen("replace-me.out", "w", stdout);

  int t, mloi_Var, j, k;
  scanf("%d", &t);
  for (int ryji_Var = 1; ryji_Var <= t; ryji_Var++) {
    scanf("%d %d", &n, &m);
    for (mloi_Var = 0; mloi_Var < 100; mloi_Var++)
      r[mloi_Var] = c[mloi_Var] = 0;
    for (mloi_Var = 0; mloi_Var < n; mloi_Var++) {
      for (j = 0; j < m; j++) {
        scanf("%d", &miqi_Var[mloi_Var][j]);
        if (miqi_Var[mloi_Var][j] > r[mloi_Var])
          r[mloi_Var] = miqi_Var[mloi_Var][j];
        if (miqi_Var[mloi_Var][j] > c[j])
          c[j] = miqi_Var[mloi_Var][j];
      }
    }
    for (mloi_Var = 0; mloi_Var < n; mloi_Var++) {
      for (j = 0; (j < m) && ((miqi_Var[mloi_Var][j] >= r[mloi_Var]) ||
                              (miqi_Var[mloi_Var][j] >= c[j]));
           j++)
        ;
      if (j < m)
        break;
    }
    if (mloi_Var < n)
      printf("Case #%d: NO\n", ryji_Var);
    else
      printf("Case #%d: YES\n", ryji_Var);
  }
  return 0;
}
