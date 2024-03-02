#include <stdio.h>

#define LOOP(x,N) for(x=0;x<N;x++)
#define LOOP_1(x,N) for(x=1;x<=N;x++)

typedef struct {
    float C;   // BasePrice
    float F;   // Cookie Increment
    float X;   // Target
} TestCase;

double calculateTime(TestCase tc) {
    double time = 0;
    float rate = 2;

    while(tc.X) {
        double intervalForFarmBuying = 0, intervalWithCurrRate = 0;
        double nextIntervalRate = 0;

        intervalForFarmBuying = (double)(tc.C / rate);

        intervalWithCurrRate = (double)(tc.X / rate);

        if( intervalForFarmBuying >= intervalWithCurrRate ) {
            time += intervalWithCurrRate;
            break;
        }
        nextIntervalRate = (double)( tc.X / (rate + tc.F));

        if( (intervalWithCurrRate + time) <= 
            (time + intervalForFarmBuying + nextIntervalRate) ) {
            time += intervalWithCurrRate;
            break;
        }

        time += intervalForFarmBuying;
        rate += tc.F;
    }
    
    return time;
}

int main(int argc, char *argv[])
{
    FILE *inputFile, *outputFile;
    inputFile = (argc <= 1) ? fopen("input.txt", "r+") : fopen(argv[1], "r+");
    outputFile = fopen("output.txt","w+");

    if (inputFile) {
        int T;
        int i;

        fscanf(inputFile, "%d", &T);

        LOOP(i, T) {
            TestCase testCase;
            double time;

            fscanf(inputFile,"%f %f %f", &testCase.C, &testCase.F, &testCase.X);

            time = calculateTime(testCase);

            fprintf(outputFile, "Case #%d: %.7f\n",i+1, time );
        }
    }

    return 0;
}