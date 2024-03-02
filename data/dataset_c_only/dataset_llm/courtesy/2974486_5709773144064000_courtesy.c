#include <stdio.h>

typedef struct {
    double value;
    int index;
} DoubleWithIndex;

double calculateTime(double initialCookies, double farmPrice, double targetCookies) {
    double time = 0.0;
    double productionRate = 2.0;
    double currentCookies = 0.0;
    
    while (currentCookies < targetCookies) {
        double timeToTarget = targetCookies / productionRate;
        double timeToFarm = farmPrice / productionRate;
        double timeToTargetWithFarm = timeToFarm + (targetCookies / (productionRate + farmPrice));
        
        if (timeToTarget <= timeToTargetWithFarm) {
            return time += timeToTarget;
        }
        
        time += timeToFarm;
        productionRate += farmPrice;
        currentCookies += farmPrice;
    }
    
    return time;
}

int main() {
    int numberOfCases;
    scanf("%d", &numberOfCases);
    
    for (int i = 1; i <= numberOfCases; i++) {
        double initialCookies, farmPrice, targetCookies;
        scanf("%lf %lf %lf", &initialCookies, &farmPrice, &targetCookies);
        
        double time = calculateTime(initialCookies, farmPrice, targetCookies);
        printf("Case #%d: %.7lf\n", i, time);
    }
    
    return 0;
}