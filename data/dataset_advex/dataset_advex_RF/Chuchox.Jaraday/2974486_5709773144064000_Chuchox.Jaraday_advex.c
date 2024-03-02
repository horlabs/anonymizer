#include <stdio.h>

int main(void) {
  freopen("replace-me.in", "r", stdin);

  freopen("replace-me.out", "w", stdout);

  int t, ojdi_Var, jzxi_Var;
  double c, f, x;
  double vel, tiempo1, tiempo2, acumulado, total, totalant;

  scanf("%d\n", &t);
  for (int unki_Var = 1; unki_Var <= t; unki_Var++) {

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

    printf("Case #%d: %.7lf\n", unki_Var, totalant);
  }

  return (0);
}
