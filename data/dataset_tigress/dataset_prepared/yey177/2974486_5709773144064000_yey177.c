#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t, k;
  double c, f, x, v, r;
  scanf("%d", &t);
  for (k = 1; k <= t; k++) {
    scanf("%lf%lf%lf", &c, &f, &x);
    v = 2.0;
    r = 0.0;
    while (x * v < (x - c) * (v + f)) {
      r = r + c / v;
      v = v + f;
    }
    r = r + x / v;
    printf("Case #%d: %.7lf\n", k, r);
  }
  return 0;
}
