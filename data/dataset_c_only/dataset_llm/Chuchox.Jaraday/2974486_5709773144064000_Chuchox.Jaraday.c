#include <stdio.h>

typedef struct {
    double first;
    double second;
    double third;
} Triple;

Triple inputTriple() {
    Triple t;
    scanf("%lf %lf %lf\n", &t.first, &t.second, &t.third);
    return t;
}

double calculateTotalTime(double c, double f, double x, double initialVelocity) {
    double accumulated = 0.0;
    double velocity = initialVelocity;
    double totalTime = 0.0;
    double previousTotal = x;

    do {
        double time1 = x / velocity;
        double time2 = c / velocity;
        totalTime = accumulated + time1;
        accumulated += time2;
        velocity += f;

        if (previousTotal < totalTime) {
            break;
        } else {
            previousTotal = totalTime;
        }
    } while (1);

    return totalTime;
}

void printOutput(int caseNum, double totalTime) {
    printf("Case #%d: %.7lf\n", caseNum, totalTime);
}

int main(void) {
    int numTestCases;
    scanf("%d\n", &numTestCases);

    for (int caseNum = 1; caseNum <= numTestCases; caseNum++) {
        Triple input = inputTriple();
        double result = calculateTotalTime(input.first, input.second, input.third, 2.0);
        printOutput(caseNum, result);
    }

    return 0;
}