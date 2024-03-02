#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    double C, F, X;
    scanf("%lf %lf %lf", &C, &F, &X);

    double speed = 2;
    double best = X / speed;
    double cur = 0;
    for (;;) {
      cur += C / speed;
      speed += F;
      if (best <= cur + X / speed)
        break;
      else
        best = cur + X / speed;
    }
    printf("Case #%d: %.7lf\n", t, best);
  }
  return 0;
}
