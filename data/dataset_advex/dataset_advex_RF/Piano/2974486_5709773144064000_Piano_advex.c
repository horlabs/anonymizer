#include <stdio.h>

int main() {
  freopen("replace-me.in", "r", stdin);

  int t, u;
  scanf("%d", &t);
  for (u = 1; u <= t; ++u) {
    double duad_Var, f, x, s = 2.0, a = 0.0;
    scanf("%lf%lf%lf", &duad_Var, &f, &x);
    while (1) {
      if (x / s <= duad_Var / s + x / (s + f))
        break;
      else
        a += duad_Var / s, s += f;
    }
    a += x / s;
    printf("Case #%d: %.7f\n", u, a);
  }
  return 0;
}
