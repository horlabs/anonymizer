#include <stdio.h>

int main(int nvpi_Var, char *emqc_Var[]) {

  int ret_val = 0;
  FILE *dtgF_Var, *shqF_Var;
  dtgF_Var =
      (nvpi_Var <= 1) ? fopen("input.txt", "r+") : fopen(emqc_Var[1], "r+");
  shqF_Var = fopen("output.txt", "w+");
  if (dtgF_Var) {
    int emti_Var;

    int gnri_Var, jffi_Var;
    fscanf(dtgF_Var, "%d", &emti_Var);
    int qksi_Var;
    {
      qksi_Var = 0;
      while (qksi_Var < emti_Var) {
        float C, F, X;
        double time = 0;
        float rate = 2;
        fscanf(dtgF_Var, "%f %f %f", &C, &F, &X);

        for (; X;) {
          double intervalForFarmBuying = 0, intervalWithCurrRate = 0;
          double nextIntervalRate = 0;

          intervalForFarmBuying = (double)(C / rate);

          intervalWithCurrRate = (double)(X / rate);

          if (intervalForFarmBuying >= intervalWithCurrRate) {
            time += intervalWithCurrRate;

            break;
          }
          nextIntervalRate = (double)(X / (rate + F));

          if ((intervalWithCurrRate + time) <=
              (time + intervalForFarmBuying + nextIntervalRate)) {

            time += intervalWithCurrRate;

            break;
          }

          time += intervalForFarmBuying;

          rate += F;
        }

        fprintf(shqF_Var, "Case #%d: %.7f\n", qksi_Var + 1, time);
        qksi_Var++;
      }
    }
  }
  return ret_val;
}
