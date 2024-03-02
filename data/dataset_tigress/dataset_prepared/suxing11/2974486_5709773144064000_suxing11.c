#include "superheader.h"

double gao(double c, double f, double x) {
  double p = 2, ans = 0;
  double t, tt;
  while (1) {
    t = x / p;
    tt = c / p + x / (p + f);
    if (tt > t) {
      ans += t;
      break;
    }
    ans += c / p;
    p += f;
  }
  return ans;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int nCase = 1, T;
  double c, f, x;
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B-small-out.txt", "w", stdout);
  scanf("%d", &T);
  while (T--) {
    scanf("%lf%lf%lf", &c, &f, &x);
    printf("Case #%d: %.7lf\n", nCase++, gao(c, f, x));
  }
  return 0;
}
