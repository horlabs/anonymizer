#include <stdio.h>
#include <stdlib.h>

#define MAX_CASES 100

typedef struct {
    double C, F, X;
} TestCase;

double calculateTime(TestCase testCase);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int numCases;
    scanf("%d", &numCases);

    TestCase testCases[MAX_CASES];

    for (int i = 0; i < numCases; i++) {
        scanf("%lf %lf %lf", &testCases[i].C, &testCases[i].F, &testCases[i].X);
    }

    for (int i = 0; i < numCases; i++) {
        double result = calculateTime(testCases[i]);
        printf("Case #%d: %.7f\n", i+1, result);
    }

    return 0;
}

double calculateTime(TestCase testCase) {
    double currentRate = 2.0;
    double totalTime = 0.0;
    double currentCookieCount = 0.0;

    while (1) {
        if (currentCookieCount + testCase.C >= testCase.X) {
            totalTime += (testCase.X - currentCookieCount) / currentRate;
            break;
        }

        totalTime += testCase.C / currentRate;
        currentCookieCount += testCase.C;

        if ((testCase.X - currentCookieCount + testCase.C) / (currentRate + testCase.F) < (testCase.X - currentCookieCount) / currentRate) {
            currentCookieCount -= testCase.C;
            currentRate += testCase.F;
        } else {
            totalTime += (testCase.X - currentCookieCount) / currentRate;
            break;
        }
    }

    return totalTime;
}