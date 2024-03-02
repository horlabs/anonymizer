#include "superheader.h"

double C, F, X;

void handle() {
  scanf("%lf %lf %lf ", &C, &F, &X);
  double p = (F * X - F * C) / C;
  double res = 0.0;
  double curR = 2.0;
  while (curR < p) {
    res += C / curR;
    curR += F;
  }
  res += X / curR;
  printf("%.7f\n", res);
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t, i;
  scanf("%d ", &t);
  for (i = 0; i < t; i++) {
    printf("Case #%d: ", i + 1);
    handle();
  }
  return 0;
}
