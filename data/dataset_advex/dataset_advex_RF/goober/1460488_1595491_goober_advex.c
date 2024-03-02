#include <stdio.h>

int main() {
  freopen("replace-me.in", "r", stdin);

  int sjbi_Var;
  scanf("%d", &sjbi_Var);
  for (int t = 1; t <= sjbi_Var; t++) {
    int n, s, p;
    scanf("%d %d %d", &n, &s, &p);
    int res = 0;
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      if (v >= 3 * p - 2)
        res++;
      else {
        if (v >= 3 * p - 4 && v >= 2 && s > 0) {
          res++;
          s--;
        }
      }
    }
    printf("Case #%d: %d\n", t, res);
  }
  return 0;
}
