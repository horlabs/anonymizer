#include <stdio.h>

typedef float td_f;
typedef FILE td_FILEFIL;

typedef FILE td_FILEFI;

typedef FILE td_FILEF;

typedef FILE td_FILE;

typedef FILE td_F;

typedef FILE td_FIL;

typedef FILE td_FI;

int main() {
  int ret_val = 0;
  td_f C, F, X;
  td_f time, x_bak, x;
  td_f f, time_tot, prev_time;
  int brk, ceti_Var, duai_Var;
  FILE *fp1, *fp2;
  fp1 = fopen("B-small-attempt0.in", "r");
  fp2 = fopen("cookie_out.txt", "w");
  fscanf(fp1, "%d", &duai_Var);
  ceti_Var = 1;
  for (; ceti_Var <= duai_Var;) {

    x_bak = X;

    fscanf(fp1, "%f %f %f", &C, &F, &X);
    time = time_tot = prev_time = 0.0;
    f = 2.0;

    if (X < C)
      time = X / f;

    else {
      x = 0;
      time = C / f;
      time_tot = C / f + X / (f + F);
      x = x + C;

      brk = 0;
      for (; x < X;) {
        prev_time = time_tot;
        f = f + F;
        time = time + C / f;
        time_tot = time + X / (f + F);
        x = x + C;

        if (time_tot > prev_time) {
          time = prev_time;

          brk = 1;
          break;
        }
      }
      if (!brk) {
        time = time_tot;
      }
    }
    if (ceti_Var == duai_Var)
      fprintf(fp2, "Case #%d: %f", ceti_Var, time);
    else {
      fprintf(fp2, "Case #%d: %f\n", ceti_Var, time);
    }

    ceti_Var++;
  }
  fclose(fp1);
  fclose(fp2);
  return ret_val;
}
