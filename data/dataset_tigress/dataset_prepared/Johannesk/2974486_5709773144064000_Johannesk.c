#include "superheader.h"

void solve(int c, double C, double F, double X) {
  double t = 0, rate = 2;

  while ((X / rate) > (X / (rate + F) + (C / rate))) {
    t = t + C / rate;
    rate = rate + F;
  }

  t = t + X / rate;
  printf("Case #%d: %.7lf\n", c, t);
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t, i;
  double C, F, X;

  (scanf("%d ", &t) == 1);
  for (i = 1; i <= t; i++) {
    (scanf("%lf %lf %lf ", &C, &F, &X) == 3);
    solve(i, C, F, X);
  }
  return 0;
}
