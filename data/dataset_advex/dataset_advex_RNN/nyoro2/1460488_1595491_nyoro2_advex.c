#include <stdio.h>

int main() {

  int ret_val = 0;
  int T;
  int ekpi_Var, plli_Var;
  int zffi_Var, s, p;
  int ojdi_Var;
  int best_not_surprising;
  int best_surprising;
  int zsci_Var;
  fscanf(stdin, "%d\n", &T);
  {
    ekpi_Var = 0;
    for (; ekpi_Var < T;) {
      fscanf(stdin, "%d %d %d", &zffi_Var, &s, &p);

      zsci_Var = 0;
      {
        plli_Var = 0;
        for (; plli_Var < zffi_Var;) {
          fscanf(stdin, "%d", &ojdi_Var);

          best_not_surprising = (ojdi_Var + 2) / 3;

          if (best_not_surprising >= p) {
            zsci_Var++;
          } else {
            if (s > 0) {
              if (((ojdi_Var % 3) != 1)) {
                if ((best_not_surprising != 0)) {
                  best_surprising = best_not_surprising + 1;

                  if (best_surprising >= p) {
                    zsci_Var++;
                    s--;
                  }
                }
              }
            }
          }
          plli_Var++;
        }
      }
      fprintf(stdout, "Case #%d: %d\n", ekpi_Var + 1, zsci_Var);
      ekpi_Var++;
    }
  }
  return ret_val;
}
