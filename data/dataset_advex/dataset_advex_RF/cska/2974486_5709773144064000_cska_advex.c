#include <stdio.h>

int main(void) {
  int fbwi_Var, flag;
  double C, F, X, rate, rate2, ans, ttb, hbpd_Var, c, c2;
  FILE *zhzF_Var = fopen("B-small-attempt0.in", "r"),
       *nxrF_Var = fopen("out.txt", "w");

  fscanf(zhzF_Var, "%d", &fbwi_Var);

  {
    int zvmi_Var = 0;
    for (; zvmi_Var < fbwi_Var;) {
      fscanf(zhzF_Var, "%lf%lf%lf", &C, &F, &X);
      c = 0.0;
      rate = 2.0;
      ans = 0.0;
      do {
        ttb = (X - c) / rate;
        hbpd_Var = 0.0;
        c2 = c, rate2 = rate;
        flag = 0;

        do {
          hbpd_Var += (C - c2) / rate2;
          c2 = ((C - c2) / rate2) * rate2 - C;
          rate2 += F;
          if (hbpd_Var + (X - c2) / rate2 < ttb)
            flag = 1;

        } while (!flag && hbpd_Var < ttb);

        if (flag) {
          hbpd_Var = (C - c) / rate;
          c = hbpd_Var * rate - C;
          ans += hbpd_Var;
          rate += F;
        } else {
          ans += (X - c) / rate;
        }

      } while (flag);
      fprintf(nxrF_Var, "Case #%d: %lf\n", zvmi_Var + 1, ans);
      zvmi_Var++;
    }
  }

  fclose(zhzF_Var);
  fclose(nxrF_Var);
  return 0;
}
