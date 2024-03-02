#include <stdio.h>

typedef struct {
    double C;
    double F;
    double X;
} TestCase;

double calculateTime(TestCase testCase) {
    double temp = testCase.X / 2.0;
    int k = 0;
    double min = 0;

    do {
        min = temp;
        temp = 0;

        for (int i = 0; i < k; i++) {
            temp = temp + testCase.C / (i * testCase.F + 2);
        }

        temp = temp + testCase.X / (k * testCase.F + 2);
        k++;
    } while (temp <= min);

    return min;
}

void printResults(int testCaseNumber, double time) {
    printf("Case #%d: %f\n", testCaseNumber, time);
}

int main() {
    int T;
    scanf("%d", &T);
    
    TestCase testCases[T];
    
    for (int t = 0; t < T; t++) {
        scanf("%lf%lf%lf", &testCases[t].C, &testCases[t].F, &testCases[t].X);
        printResults(t + 1, calculateTime(testCases[t]));
    }

    return 0;
}