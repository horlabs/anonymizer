#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int emti_Var, k, flag;
  double C, F, X, rate, rate2, ans, ttb, t, c, c2;
  FILE *hihF_Var = fopen("B-small-attempt0.in", "r"),
       *ztjF_Var = fopen("out.txt", "w");

  fscanf(hihF_Var, "%d", &emti_Var);

  {
    k = 0;
    while (k < emti_Var) {
      fscanf(hihF_Var, "%lf%lf%lf", &C, &F, &X);
      c = 0.0;
      rate = 2.0;
      ans = 0.0;
      do {
        ttb = (X - c) / rate;
        t = 0.0;
        c2 = c, rate2 = rate;
        flag = 0;

        do {
          t += (C - c2) / rate2;
          c2 = ((C - c2) / rate2) * rate2 - C;
          rate2 += F;
          if (t + (X - c2) / rate2 < ttb)
            flag = 1;
        } while (!flag && t < ttb);

        if (flag) {
          t = (C - c) / rate;
          c = t * rate - C;
          ans += t;
          rate += F;
        } else
          ans += (X - c) / rate;
      } while (flag);
      fprintf(ztjF_Var, "Case #%d: %lf\n", k + 1, ans);
      k++;
    }
  }

  fclose(hihF_Var);
  fclose(ztjF_Var);
  return 0;
}
