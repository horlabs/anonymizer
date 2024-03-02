#include <stdio.h>

typedef struct {
    double c;
    double f;
    double x;
} TestCase;

double calculateMinTime(TestCase testCase) {
    double init = 2;
    double mintime = testCase.x / init;
    double caltime = 0;
    double timetillfarm = 0;

    while (1) {
        timetillfarm += testCase.c / init;
        init += testCase.f;
        caltime = timetillfarm + testCase.x / init;

        if (caltime < mintime)
            mintime = caltime;
        else
            break;
    }

    return mintime;
}

int main() {
    int numCases;
    scanf("%d", &numCases);

    for (int i = 0; i < numCases; i++) {
        TestCase testCase;
        scanf("%lf %lf %lf", &testCase.c, &testCase.f, &testCase.x);
        double minTime = calculateMinTime(testCase);
        printf("Case #%d: %.7lf\n", i + 1, minTime);
    }

    return 0;
}
