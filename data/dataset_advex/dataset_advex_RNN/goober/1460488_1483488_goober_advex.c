#include <stdio.h>

int main() {
  freopen("replace-me.in", "r", stdin);

  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int duai_Var, b;
    scanf("%d %d", &duai_Var, &b);
    int res = 0;
    int digmul = 1;
    int digs = 1;
    for (int x = duai_Var; x >= 10; x++) {
      digmul *= 10;
      digs++;
      x /= 10;
    }
    for (int n = duai_Var; n <= b; n++) {
      int m = n;
      int previous[digs];
      for (int d = 0; d < digs; d++) {
        previous[d] = m;
        m = (m % 10) * digmul + (m / 10);
        if (m <= n || m > b || m / digmul == 0)
          continue;
        for (int k = 0; k < d; k++)
          if (previous[k] == m)
            goto bad;
        res++;
      bad:;
      }
    }
    printf("Case #%d: %d\n", t, res);
  }
  return 0;
}
