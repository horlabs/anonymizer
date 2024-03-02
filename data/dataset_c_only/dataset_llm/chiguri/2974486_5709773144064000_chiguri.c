#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    double c;
    double f;
    double x;
} Parameters;

long double f_times[100000];

void getInput(int* num, Parameters params[]) {
    scanf("%d", num);
    for(int i = 0; i < *num; ++i) {
        scanf("%lf %lf %lf", &params[i].c, &params[i].f, &params[i].x);
    }
}

double calculateLeastTime(Parameters params) {
    double cps = 2.0;
    double least = params.x / 2;

    f_times[0] = 0.0;

    for(int i = 1; i < 100000; ++i) {
        f_times[i] = params.c / cps + f_times[i-1];
        if(f_times[i] > least) {
            break;
        }
        cps = 2.0 + params.f * i;
        double temp = f_times[i] + params.x / cps;
        if(temp < least) {
            least = temp;
        }
    }

    return least;
}

void printOutput(int num, double leastTimes[]) {
    for(int i = 0; i < num; ++i) {
        printf("Case #%d: %llf\n", i + 1, leastTimes[i]);
    }
}

int main(void) {
    int num;
    Parameters params[100];
    double leastTimes[100];

    getInput(&num, params);

    for(int i = 0; i < num; ++i) {
        leastTimes[i] = calculateLeastTime(params[i]);
    }

    printOutput(num, leastTimes);

    return 0;
}