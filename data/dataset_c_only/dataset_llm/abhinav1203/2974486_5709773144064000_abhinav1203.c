#include<stdio.h>

double calculateTime(double C, double F, double X) {
    double rate = 2.0;
    double time = 0;
    while(X/rate > C/rate + X/(rate+F)) {
        time += C/rate;
        rate += F;
    }
    time += X/rate;
    return time;
}

int main() {
    int numTests, currTest = 1;
    double initialCookies, cookiesPerFarm, desiredCookies;
    scanf("%d", &numTests);
    while(numTests--) {
        scanf("%lf %lf %lf", &initialCookies, &cookiesPerFarm, &desiredCookies);
        double time = calculateTime(initialCookies, cookiesPerFarm, desiredCookies);
        printf("Case #%d: %lf\n", currTest++, time);
    }
    return 0;
}