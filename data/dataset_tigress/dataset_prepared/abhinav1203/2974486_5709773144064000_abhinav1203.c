#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T, test = 1;
  double C, F, X, rate, time;
  scanf("%d", &T);
  while (T--) {
    scanf("%lf %lf %lf", &C, &F, &X);
    rate = 2.0;
    time = 0;
    while (X / rate > C / rate + X / (rate + F)) {
      time += C / rate;
      rate += F;
    }
    time += X / rate;
    printf("Case #%d: %lf\n", test++, time);
  }
  return 0;
}
