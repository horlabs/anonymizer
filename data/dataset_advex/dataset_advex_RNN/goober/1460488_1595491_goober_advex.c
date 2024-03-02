#include <stdio.h>

int main() {
  freopen("replace-me.out", "w", stdout);

  int ynli_Var;
  scanf("%d", &ynli_Var);
  for (int t = 1; t <= ynli_Var; t++) {
    int hxoi_Var, s, p;
    scanf("%d %d %d", &hxoi_Var, &s, &p);
    int res = 0;
    for (int i = 0; i < hxoi_Var; i++) {
      int v;
      scanf("%d", &v);
      if (v >= 3 * p - 2)
        res++;
      else if (v >= 3 * p - 4 && v >= 2 && s > 0) {
        res++;
        s--;
      }
    }
    printf("Case #%d: %d\n", t, res);
  }
  return 0;
}
