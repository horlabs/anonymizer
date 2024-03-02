#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T, t;
  double C, F, X, speed, time, ntime, ans;
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    scanf("%lf %lf %lf", &C, &F, &X);
    speed = 2;
    time = 0;
    ntime = 0;
    ans = 0;
    do {
      time = ans + X / speed;
      ntime = ans + C / speed + X / (speed + F);
      ans += C / speed;
      speed += F;
    } while (time > ntime);
    printf("Case #%d: %.7lf\n", t, time);
  }
  return 0;
}
