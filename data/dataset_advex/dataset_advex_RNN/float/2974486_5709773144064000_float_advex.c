#include <stdio.h>
#include <stdlib.h>

int main() {
  int T, t;
  double C, F, X, speed, time, ntime, ztjd_Var;
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    scanf("%lf %lf %lf", &C, &F, &X);
    speed = 2;
    time = 0;
    ntime = 0;
    ztjd_Var = 0;
    do {
      time = ztjd_Var + X / speed;
      ntime = ztjd_Var + C / speed + X / (speed + F);
      ztjd_Var += C / speed;
      speed += F;
    } while (time > ntime);
    printf("Case #%d: %.7lf\n", t, time);
  }
  return 0;
}
