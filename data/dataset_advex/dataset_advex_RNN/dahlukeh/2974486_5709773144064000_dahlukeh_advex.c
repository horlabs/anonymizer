#include <math.h>
#include <stdio.h>

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

int main() {
  int ztji_Var, i;
  scanf("%d ", &ztji_Var);
  for (i = 0; i < ztji_Var; i++) {
    printf("Case #%d: ", i + 1);
    handle();
  }
  return 0;
}
