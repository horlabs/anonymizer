#include <stdio.h>

float calculateTime(float C, float F, float X) {
    float f = 2.0;
    float time = X / f;
    float time_tot = C / f + X / (f + F);
    float x = C;
    int brk = 0;

    while (x < X) {
        float prev_time = time_tot;
        f += F;
        time = C / f;
        time_tot = time + X / (f + F);
        x += C;

        if (time_tot > prev_time) {
            time = prev_time;
            brk = 1;
            break;
        }
    }

    if (!brk)
        time = time_tot;

    return time;
}

int main() {
    FILE *inputFile = fopen("B-small-attempt0.in", "r");
    FILE *outputFile = fopen("cookie_out.txt", "w");

    int T;
    fscanf(inputFile, "%d", &T);

    for (int t = 1; t <= T; t++) {
        float C, F, X;
        fscanf(inputFile, "%f %f %f", &C, &F, &X);

        float time = calculateTime(C, F, X);

        if (t == T)
            fprintf(outputFile, "Case #%d: %f", t, time);
        else
            fprintf(outputFile, "Case #%d: %f\n", t, time);
    }

    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}