#include <stdio.h>

double calculateTotalTime(double cookiesPerFarm, double farmCost, double targetCookies) {
    double totalTime = 0.0;
    double currentCookiesPerSecond = 2.0;
    
    while ((targetCookies * currentCookiesPerSecond) < ((targetCookies - cookiesPerFarm) * (currentCookiesPerSecond + farmCost))) {
        totalTime += (cookiesPerFarm / currentCookiesPerSecond);
        currentCookiesPerSecond += farmCost;
    }
    
    totalTime += (targetCookies / currentCookiesPerSecond);
    
    return totalTime;
}

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    
    for (int currentTestCase = 1; currentTestCase <= numTestCases; currentTestCase++) {
        double cookieCost, extraProduction, target;
        scanf("%lf %lf %lf", &cookieCost, &extraProduction, &target);
        
        double totalTime = calculateTotalTime(cookieCost, extraProduction, target);
        
        printf("Case #%d: %.7lf\n", currentTestCase, totalTime);
    }
    
    return 0;
}
