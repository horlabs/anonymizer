#include <stdio.h>

typedef FILE td_FI;
typedef FILE td_F;

typedef FILE td_FILE;

int main(void) {
  int ret_val = 0;
  int cbvi_Var, ceti_Var, emti_Var, N, S, P, ndli_Var[128];
  FILE *lhxF_Var = fopen("B-small-attempt0.in", "r"),
       *jpbF_Var = fopen("out.txt", "w");
  fscanf(lhxF_Var, "%d\n", &emti_Var);
  {
    int fqli_Var = 0;
    while (ceti_Var = 0, fqli_Var < emti_Var) {

      fscanf(lhxF_Var, "%d\n%d\n%d\n", &N, &S, &P);

      {
        cbvi_Var = 0;
        while (cbvi_Var < N) {
          fscanf(lhxF_Var, "%d\n", &ndli_Var[cbvi_Var]);
          switch (ndli_Var[cbvi_Var] % 3) {
          case 0:
            if (ndli_Var[cbvi_Var] / 3 >= P) {
              ceti_Var++;
            } else {
              if (S > 0 && ndli_Var[cbvi_Var] / 3 > 0)
                if (ndli_Var[cbvi_Var] / 3 < 10) {
                  if (ndli_Var[cbvi_Var] / 3 + 1 >= P) {
                    S--, ceti_Var++;
                  }
                }
            }
            break;
          case 1:
            if (ndli_Var[cbvi_Var] / 3 + 1 >= P) {
              ceti_Var++;
            }
            break;
          case 2:
            if (ndli_Var[cbvi_Var] / 3 + 1 >= P) {
              ceti_Var++;
            } else {
              if (S > 0 && ndli_Var[cbvi_Var] / 3 < 9 &&
                  ndli_Var[cbvi_Var] / 3 + 2 >= P) {
                S--, ceti_Var++;
              }
            }
            break;
          }
          cbvi_Var++;
        }
      }
      fprintf(jpbF_Var, "Case #%d: %d\n", fqli_Var + 1, ceti_Var);
      fqli_Var++;
    }
  }
  fclose(lhxF_Var);
  fclose(jpbF_Var);
  return ret_val;
}
