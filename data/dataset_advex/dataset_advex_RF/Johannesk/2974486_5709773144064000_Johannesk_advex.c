#include <assert.h>
#include <stdio.h>

void solve(int fxyi_Var, double C, double F, double X) {
  double lcjd_Var = 0, rate = 2;

  while ((X / rate) > (X / (rate + F) + (C / rate))) {
    lcjd_Var = lcjd_Var + C / rate;
    rate = rate + F;
  }

  lcjd_Var = lcjd_Var + X / rate;
  printf("Case #%d: %.7lf\n", fxyi_Var, lcjd_Var);
}

int main(int nvpi_Var, char **iodc_Var) {
  int ret_val = 0;
  int lcjd_Var;
  double C, F, X;
  assert(scanf("%d ", &lcjd_Var) == 1);
  {
    int i = 1;
    while (i <= lcjd_Var) {
      assert(scanf("%lf %lf %lf ", &C, &F, &X) == 3);
      solve(i, C, F, X);
      i++;
    }
  }
  return ret_val;
}
