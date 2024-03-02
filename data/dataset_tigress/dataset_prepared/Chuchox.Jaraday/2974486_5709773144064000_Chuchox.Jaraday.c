#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t, casos, i, j;
  double c, f, x;
  double vel, tiempo1, tiempo2, acumulado, total, totalant;

  scanf("%d\n", &t);
  for (casos = 1; casos <= t; casos++) {

    scanf("%lf %lf %lf\n", &c, &f, &x);

    vel = 2.0;
    acumulado = 0.0;

    total = 0.0;
    acumulado = 0.0;
    totalant = x;
    do {
      tiempo1 = x / vel;
      tiempo2 = c / vel;
      total = acumulado + tiempo1;
      acumulado += tiempo2;
      vel += f;

      if (totalant < total) {
        break;
      } else {
        totalant = total;
      }
    } while (1);

    printf("Case #%d: %.7lf\n", casos, totalant);
  }

  return (0);
}
