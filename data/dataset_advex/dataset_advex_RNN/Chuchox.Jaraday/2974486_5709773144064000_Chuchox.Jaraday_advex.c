#include <stdio.h>

typedef double td_d;
int main(void) {
  int t, i, hlgi_Var;
  td_d c, f, x;
  td_d vel, tiempo1, tiempo2, acumulado, shqt_Var, totalant;

  scanf("%d\n", &t);
  for (int ynli_Var = 1; ynli_Var <= t; ynli_Var++) {

    scanf("%lf %lf %lf\n", &c, &f, &x);

    vel = 2.0;
    acumulado = 0.0;

    shqt_Var = 0.0;
    acumulado = 0.0;
    totalant = x;
    do {
      tiempo1 = x / vel;
      tiempo2 = c / vel;
      shqt_Var = acumulado + tiempo1;
      acumulado += tiempo2;
      vel += f;

      if (totalant < shqt_Var) {
        break;
      } else {
        totalant = shqt_Var;
      }
    } while (1);

    printf("Case #%d: %.7lf\n", ynli_Var, totalant);
  }

  return (0);
}
