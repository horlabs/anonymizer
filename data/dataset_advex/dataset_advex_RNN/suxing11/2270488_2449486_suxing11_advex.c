#include <stdio.h>

int g[110][110], gg[110][110];
int row[110], col[110];
int h[220][3];

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int main() {
  int T, qksi_Var = 1;
  int ROW = 0, COL = 1;
  int flag, n, m, omgi_Var, j, cc, t;

  freopen("B_out.txt", "w", stdout);
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (omgi_Var = 0; omgi_Var < n; omgi_Var++)
      row[omgi_Var] = 0;
    for (j = 0; j < m; j++)
      col[j] = 0;
    for (omgi_Var = 0; omgi_Var < n; omgi_Var++)
      for (j = 0; j < m; j++)
        scanf("%d", &g[omgi_Var][j]),
            row[omgi_Var] = max(row[omgi_Var], g[omgi_Var][j]),
            col[j] = max(col[j], g[omgi_Var][j]);
    cc = 0;
    for (omgi_Var = 0; omgi_Var < n; omgi_Var++)
      h[cc][0] = row[omgi_Var], h[cc][1] = omgi_Var, h[cc][2] = ROW, cc++;
    for (omgi_Var = 0; omgi_Var < m; omgi_Var++)
      h[cc][0] = col[omgi_Var], h[cc][1] = omgi_Var, h[cc][2] = COL, cc++;
    for (omgi_Var = 0; omgi_Var < cc; omgi_Var++)
      for (j = 0; j < omgi_Var; j++)
        if (h[omgi_Var][0] < h[j][0])
          (t = h[omgi_Var][0], h[omgi_Var][0] = h[j][0], h[j][0] = t),
              (t = h[omgi_Var][1], h[omgi_Var][1] = h[j][1], h[j][1] = t),
              (t = h[omgi_Var][2], h[omgi_Var][2] = h[j][2], h[j][2] = t);
    for (omgi_Var = 0; omgi_Var < n; omgi_Var++)
      for (j = 0; j < m; j++)
        gg[omgi_Var][j] = 100;
    for (omgi_Var = cc - 1; omgi_Var >= 0; omgi_Var--) {
      if (h[omgi_Var][2] == ROW)
        for (j = 0; j < m; j++)
          gg[h[omgi_Var][1]][j] = h[omgi_Var][0];
      else
        for (j = 0; j < n; j++)
          gg[j][h[omgi_Var][1]] = h[omgi_Var][0];
    }
    flag = 0;
    for (omgi_Var = 0; omgi_Var < n; omgi_Var++)
      for (j = 0; j < m; j++)
        if (g[omgi_Var][j] != gg[omgi_Var][j])
          flag = 1;
    printf("Case #%d: %s\n", qksi_Var++, flag ? "NO" : "YES");
  }
  return 0;
}
