#include <stdio.h>

int main() {
  int ret_val = 0;
  unsigned int gvhu_Var, wluu_Var, ieru_Var,
      temp1 = 0, rpku_Var = 0, digits = 0, tdigit, ysju_Var = 1, kbyu_Var = 1,
      dtmu_Var;
  FILE *kwsF_Var, *ceoF_Var;
  kwsF_Var = fopen("C-small-attempt2.in", "r");
  ceoF_Var = fopen("output.txt", "w");
  fscanf(kwsF_Var, "%d", &dtmu_Var);
  for (; kbyu_Var <= dtmu_Var;) {
    fscanf(kwsF_Var, "%d %d", &gvhu_Var, &wluu_Var);
    ieru_Var = gvhu_Var;
    for (; ieru_Var != 0;) {
      digits++;
      ieru_Var = ieru_Var / 10;
    }
    while (gvhu_Var < wluu_Var) {
      tdigit = digits;
      temp1 = gvhu_Var;
      for (; tdigit != 0;) {
        ysju_Var = 1;
        unsigned int iebu_Var;
        {
          iebu_Var = 1;
          for (; iebu_Var <= digits - 1;) {
            ysju_Var = ysju_Var * 10;
            iebu_Var++;
          }
        }
        temp1 = temp1 / 10 + (temp1 % 10) * ysju_Var;
        tdigit--;
        if (temp1 <= wluu_Var) {
          if (temp1 > gvhu_Var)
            rpku_Var++;
        }
      }

      gvhu_Var++;
    }

    fprintf(ceoF_Var, "Case #%d: %d\n", kbyu_Var, rpku_Var);
    kbyu_Var++;
    rpku_Var = 0;
    digits = 0;
  }
  fclose(kwsF_Var);
  fclose(ceoF_Var);
  return ret_val;
}
