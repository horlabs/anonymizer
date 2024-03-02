#include <stdio.h>

#define EP          0.00000001

typedef struct {
    double C;
    double F;
    double X;
} Problem;

void initialize(Problem *p) {
    scanf("%lf %lf %lf ", &p->C, &p->F, &p->X);
}

double calculateTime(Problem *p) {
    double pValue = (p->F * p->X - p->F * p->C) / p->C;
    double time = 0.0;
    double curRate = 2.0;
    while (curRate < pValue) {
        time += p->C / curRate;
        curRate += p->F;
    }
    time += p->X / curRate;
    return time;
}

void printResult(double res) {
    printf("%.7f\n", res);
}

int main() {
    int t, i;
    scanf("%d ", &t);
    for (i = 0; i < t; i++) {
        printf("Case #%d: ", i + 1);
        Problem problem;
        initialize(&problem);
        double result = calculateTime(&problem);
        printResult(result);
    }
    return 0;
}