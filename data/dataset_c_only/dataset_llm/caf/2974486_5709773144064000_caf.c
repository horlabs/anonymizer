#include <stdio.h>
#include <stdlib.h>

double buyTime(long farms, double cost, double cookies, double production) {
    if (farms > 0)
        return cost / ((farms - 1) * production + 2.0) + buyTime(farms - 1, cost, cookies, production);
    return 0;
}

void processTest(int testNumber) {
    long farms;
    double cost, production, cookies;
    double time = 0.0;

    scanf("%lf %lf %lf", &cost, &production, &cookies);

    farms = cookies / cost - 2.0/production;
    if (farms < 0)
        farms = 0;
    time = buyTime(farms, cost, cookies, production) + cookies / (farms * production + 2.0);

    printf("Case #%d: %.7f\n", testNumber + 1, time);
}

int main() {
    int numTests, i;

    scanf("%d", &numTests);

    for (i = 0; i < numTests; i++)
        processTest(i);

    return 0;
}