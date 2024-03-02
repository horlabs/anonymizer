#include <stdio.h>

int main() {
  freopen("replace-me.out", "w", stdout);

  int t;

  scanf("%d", &t);

  for (int i = 0; i < t; i++) {
    int n, m, p = 0, f = 0, j, rhoi_Var;
    int a[100][100];
    int b[100][100] = {0};

    scanf("%d %d", &n, &m);

    for (j = 0; j < n; j++) {
      for (rhoi_Var = 0; rhoi_Var < m; rhoi_Var++) {
        scanf("%d", &a[j][rhoi_Var]);

        if (a[j][rhoi_Var] > p)
          p = a[j][rhoi_Var];
      }
    }

    for (j = 0; j < n; j++) {
      for (rhoi_Var = 0; rhoi_Var < m - 1; rhoi_Var++) {
        if (a[j][rhoi_Var] != a[j][rhoi_Var + 1])
          break;
      }

      if (rhoi_Var == m - 1) {
        for (rhoi_Var = 0; rhoi_Var < m; rhoi_Var++)
          b[j][rhoi_Var] = 1;
      }
    }

    for (j = 0; j < m; j++) {
      for (rhoi_Var = 0; rhoi_Var < n - 1; rhoi_Var++) {
        if (a[rhoi_Var][j] != a[rhoi_Var + 1][j])
          break;
      }

      if (rhoi_Var == n - 1) {
        for (rhoi_Var = 0; rhoi_Var < n; rhoi_Var++)
          b[rhoi_Var][j] = 1;
      }
    }

    for (j = 0; j < n; j++) {
      for (rhoi_Var = 0; rhoi_Var < m; rhoi_Var++) {
        if (a[j][rhoi_Var] != p && b[j][rhoi_Var] == 0) {
          f = 1;
        }
      }
    }

    if (f == 0) {
      printf("Case #%d: YES\n", i + 1);
    } else
      printf("Case #%d: NO\n", i + 1);
  }

  return 0;
}
