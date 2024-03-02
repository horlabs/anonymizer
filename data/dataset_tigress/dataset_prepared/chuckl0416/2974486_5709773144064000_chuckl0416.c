#include "superheader.h"

int TC, T;
double C, F, X;
double i, x, y, Produce, Time, Ans;

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B-small-attempt0.out", "w", stdout);

  scanf("%d", &TC);
  for (T = 1; T <= TC; T++) {
    printf("Case #%d: ", T);
    scanf("%lf%lf%lf", &C, &F, &X);
    Produce = 2;
    Ans = X / Produce;
    Time = 0;

    while (1) {
      if ((Time + C / Produce + X / (Produce + F)) >= Ans)
        break;
      Ans = Time + C / Produce + X / (Produce + F);

      Time += C / Produce;
      Produce += F;
    }

    printf("%.7lf\n", Ans);
  }

  return 0;
}
