#include <stdio.h>

int main(int argc, char **argv) {
  freopen("replace-me.out", "w", stdout);

  int cuai_Var, nvpi_Var;
  scanf("%d\n", &nvpi_Var);
  {
    cuai_Var = 1;
    while (cuai_Var <= nvpi_Var) {
      double C, F, X;
      double total_time = 0.0;
      double rate = 2.0;
      scanf("%lf %lf %lf\n", &C, &F, &X);
      while (1) {
        double t0;
        double t1a, t1b;
        t0 = X / rate;
        t1a = C / rate;
        t1b = X / (rate + F);
        if (t0 < (t1a + t1b)) {
          total_time += t0;
          break;
        }
        rate += F;
        total_time += t1a;
      }
      printf("Case #%d: %.8lf\n", cuai_Var, total_time);
      cuai_Var++;
    }
  }
  return 0;
}
