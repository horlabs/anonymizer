#include <stdio.h>

typedef struct {
    double c;
    double f;
    double x;
} Problem;

double solve(Problem p) {
    double s = 2.0;
    double a = 0.0;
    while (1) {
        if (p.x / s <= p.c / s + p.x / (s + p.f))
            break;
        else
            a += p.c / s, s += p.f;
    }
    a += p.x / s;
    return a;
}

int main() {
    int testCaseCount;
    scanf("%d", &testCaseCount);
    for (int testCase = 1; testCase <= testCaseCount; ++testCase) {
        Problem p;
        scanf("%lf%lf%lf", &p.c, &p.f, &p.x);
        double result = solve(p);
        printf("Case #%d: %.7f\n", testCase, result);
    }
    return 0;
}