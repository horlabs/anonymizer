#include "superheader.h"

double get_ans(int k, double C, double F, double X) {
  int i;
  double ans = 0;
  for (i = 0; i < k; i++) {
    ans += C / (2.0 + F * i);
  }
  return ans + X / (2.0 + k * F);
}

int get_k(double C, double F, double X) {
  int k = (F * X - 2 * C) / (F * C);
  if (k < 0)
    k = 0;
  return k;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T, Tcnt = 0;
  for (scanf("%d", &T); T; T--) {
    double C, F, X;
    scanf("%lf%lf%lf", &C, &F, &X);
    printf("Case #%d: %.7lf\n", ++Tcnt, get_ans(get_k(C, F, X), C, F, X));
  }
  return 0;
}
