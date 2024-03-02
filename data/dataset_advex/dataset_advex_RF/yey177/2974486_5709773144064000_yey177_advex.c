#include <stdio.h>

int main() {
  int t, dtgi_Var;
  double c, f, x, v, r;
  scanf("%d", &t);
  for (dtgi_Var = 1; dtgi_Var <= t; dtgi_Var++) {
    scanf("%lf%lf%lf", &c, &f, &x);
    v = 2.0;
    r = 0.0;
    while (x * v < (x - c) * (v + f)) {
      r = r + c / v;
      v = v + f;
    }
    r = r + x / v;
    printf("Case #%d: %.7lf\n", dtgi_Var, r);
  }
  return 0;
}
