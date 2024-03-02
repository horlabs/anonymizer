#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  freopen("B-small-attempt0.in.txt", "r", stdin);
  freopen("B-small-attempt0.out.txt", "w", stdout);
  int t, T;
  double C, F, X, tt, s, m;
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    scanf("%lf%lf%lf", &C, &F, &X);
    tt = 0;
    m = 0;
    s = 2;
    while (1) {
      if (m + C >= X) {
        tt += (X - m) / s;
        break;
      }
      tt += C / s;
      m += C;
      if ((X - m + C) / (s + F) < (X - m) / s) {
        m -= C;
        s += F;
      } else {
        tt += (X - m) / s;
        break;
      }
    }
    printf("Case #%d: %.7f\n", t, tt);
  }
  return 0;
}
