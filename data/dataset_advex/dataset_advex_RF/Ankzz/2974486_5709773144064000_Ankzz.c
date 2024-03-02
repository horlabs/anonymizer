#include <stdio.h>


int main(int argc, char *argv[]) {
    FILE *fp, *o;
    fp = (argc <= 1) ? fopen("input.txt", "r+") : fopen(argv[1], "r+");
    o = fopen("output.txt", "w+");

    if (fp) {
        int T;
        int i;
        int j, k;
        fscanf(fp, "%d", &T);
        for (i = 0; i < T; i++) {
            float C, F, X;
            double time = 0;
            float rate = 2;
            fscanf(fp, "%f %f %f", &C, &F, &X);


            while (X) {
                double intervalForFarmBuying = 0, intervalWithCurrRate = 0;
                double nextIntervalRate = 0;

                intervalForFarmBuying = (double) (C / rate);

                intervalWithCurrRate = (double) (X / rate);

                if (intervalForFarmBuying >= intervalWithCurrRate) {
                    time += intervalWithCurrRate;


                    break;
                }
                nextIntervalRate = (double) (X / (rate + F));

                if ((intervalWithCurrRate + time) <=
                    (time + intervalForFarmBuying + nextIntervalRate)) {


                    time += intervalWithCurrRate;


                    break;
                }

                time += intervalForFarmBuying;

                rate += F;
            }

            fprintf(o, "Case #%d: %.7f\n", i + 1, time);
        }
    }

    return 0;
}
