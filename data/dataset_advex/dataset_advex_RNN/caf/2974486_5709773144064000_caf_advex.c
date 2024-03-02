#include <stdio.h>

double time_to_buy(long n_farms, double c, double f) {
  if (n_farms > 0) {
    return c / ((n_farms - 1) * f + 2.0) + time_to_buy(n_farms - 1, c, f);
  }
  return 0;
}

void do_voiztj_fct(int bwwi_Var) {
  long n_farms;
  double c, f, x;
  double time = 0.0;

  scanf("%lf %lf %lf", &c, &f, &x);

  n_farms = x / c - 2.0 / f;
  if (n_farms < 0)
    n_farms = 0;
  time = time_to_buy(n_farms, c, f) + x / (n_farms * f + 2.0);

  printf("Case #%d: %.7f\n", bwwi_Var + 1, time);
}

int main() {
  freopen("replace-me.out", "w", stdout);

  int bwwi_Var, iodi_Var;

  scanf("%d", &bwwi_Var);

  for (iodi_Var = 0; iodi_Var < bwwi_Var; iodi_Var++)
    do_voiztj_fct(iodi_Var);

  return 0;
}
