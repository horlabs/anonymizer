#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int i;
  double c, f, x;
  double time_base;
  double time1, time2;
  int j;

  scanf("%d\n", &t);
  for (i = 0; i < t; i++) {

    scanf("%lf %lf %lf\n", &c, &f, &x);

    time_base = 0;
    j = 0;
    while (1) {
      time1 = time_base + x / (f * j + 2);
      time_base += c / (f * j + 2);
      j++;
      time2 = time_base + x / (f * j + 2);
      if (time1 <= time2)
        break;
    }

    printf("Case #%d: ", i + 1);
    printf("%.7f\n", time1);
  }

  return 0;
}
