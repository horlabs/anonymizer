#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t, u;
  scanf("%d", &t);
  for (u = 1; u <= t; ++u) {
    double c, f, x, s = 2.0, a = 0.0;
    scanf("%lf%lf%lf", &c, &f, &x);
    while (1) {
      if (x / s <= c / s + x / (s + f))
        break;
      else
        a += c / s, s += f;
    }
    a += x / s;
    printf("Case #%d: %.7f\n", u, a);
  }
  return 0;
}
