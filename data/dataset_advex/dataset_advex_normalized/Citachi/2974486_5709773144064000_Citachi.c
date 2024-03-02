#include <stdio.h>

int main() {
    float C, F, X;
    float time, x_bak, x;
    float f, time_tot, prev_time;
    int brk, t, T;
    FILE *fp1, *fp2;
    fp1 = fopen("B-small-attempt0.in", "r");
    fp2 = fopen("cookie_out.txt", "w");
    fscanf(fp1, "%d", &T);

    t = 1;
    while (t <= T) {

        x_bak = X;

        fscanf(fp1, "%f %f %f", &C, &F, &X);
        time = time_tot = prev_time = 0.0;
        f = 2.0;

        if (X < C) {
            time = X / f;
        }


        else {
            x = 0;
            time = C / f;
            time_tot = C / f + X / (f + F);
            x = x + C;


            brk = 0;
            while (x < X) {
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
            if (!brk)
                time = time_tot;
        }
        if (t == T)
            fprintf(fp2, "Case #%d: %f", t, time);
        else
            fprintf(fp2, "Case #%d: %f\n", t, time);
        t++;
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
