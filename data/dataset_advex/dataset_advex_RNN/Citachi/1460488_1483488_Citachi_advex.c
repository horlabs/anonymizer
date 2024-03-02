#include <stdio.h>

typedef FILE td_FILEFI;
typedef unsigned int td_ui;

typedef FILE td_FILE;

typedef FILE td_FILEF;

typedef FILE td_FIL;

int main() {
  int ret_val = 0;
  td_ui hbpu_Var, cdcu_Var, exeu_Var, temp1 = 0, vabu_Var = 0, digits = 0,
                                      tdigit, faft_Var = 1, feeu_Var,
                                      seot_Var = 1, uvit_Var;
  FILE *drbF_Var, *rhoF_Var;
  drbF_Var = fopen("C-small-attempt2.in", "r");
  rhoF_Var = fopen("output.txt", "w");
  fscanf(drbF_Var, "%d", &uvit_Var);
  while (seot_Var <= uvit_Var) {
    fscanf(drbF_Var, "%d %d", &hbpu_Var, &cdcu_Var);
    exeu_Var = hbpu_Var;
    while (exeu_Var != 0) {
      digits++;
      exeu_Var = exeu_Var / 10;
    }
    while (hbpu_Var < cdcu_Var) {
      tdigit = digits;
      temp1 = hbpu_Var;
      while (tdigit != 0) {
        faft_Var = 1;
        {
          feeu_Var = 1;
          while (feeu_Var <= digits - 1) {
            faft_Var = faft_Var * 10;
            feeu_Var++;
          }
        }
        temp1 = temp1 / 10 + (temp1 % 10) * faft_Var;
        tdigit--;
        if (temp1 <= cdcu_Var) {
          if (temp1 > hbpu_Var)
            vabu_Var++;
        }
      }

      hbpu_Var++;
    }

    fprintf(rhoF_Var, "Case #%d: %d\n", seot_Var, vabu_Var);
    seot_Var++;
    vabu_Var = 0;
    digits = 0;
  }
  fclose(drbF_Var);
  fclose(rhoF_Var);
  return ret_val;
}
