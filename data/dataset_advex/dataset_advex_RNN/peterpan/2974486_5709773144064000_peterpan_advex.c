#include <stdio.h>
#include <stdlib.h>
typedef double td_d;
int main() {
  int duai_Var, iixi_Var, i, counter;
  td_d C, F, X, t, v, tf, tmin;

  scanf("%d", &duai_Var);
  for (iixi_Var = 1; iixi_Var <= duai_Var; iixi_Var++) {
    scanf("%lf %lf %lf", &C, &F, &X);

    i = 0;
    tf = 0;
    v = 2.0;
    tmin = tf + X / v;
    counter = 0;
    while (counter < 100) {
      tf += C / v;
      i++;
      v += F;
      t = tf + X / v;
      if (t < tmin) {
        tmin = t;
        if (counter)
          fprintf(stderr, "Reseting counter.\n");
        counter = 0;
      } else
        counter++;
    }
    printf("Case #%d: %.7lf\n", iixi_Var, tmin);
  }

  return 0;
}
