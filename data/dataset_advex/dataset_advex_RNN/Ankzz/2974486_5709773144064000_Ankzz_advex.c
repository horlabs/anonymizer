#include <stdio.h>

int main(int argc, char *argv[]) {
  int ret_val = 0;
  FILE *duaF_Var, *zhzF_Var;
  duaF_Var = (argc <= 1) ? fopen("input.txt", "r+") : fopen(argv[1], "r+");
  zhzF_Var = fopen("output.txt", "w+");
  if (duaF_Var) {
    int fsqi_Var;
    int i;
    int rffi_Var, k;
    fscanf(duaF_Var, "%d", &fsqi_Var);
    for (i = 0; i < fsqi_Var; i++) {
      float C, F, X;
      double time = 0;
      float rate = 2;
      fscanf(duaF_Var, "%f %f %f", &C, &F, &X);

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

      fprintf(zhzF_Var, "Case #%d: %.7f\n", i + 1, time);
    }
  }
  return ret_val;
}
