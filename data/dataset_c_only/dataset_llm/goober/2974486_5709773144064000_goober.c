#include <stdio.h>

double calculateBest(double C, double F, double X) {
    double speed = 2;
    double best = X / speed;
    double cur = 0;
    
    while (1) {
        cur += C / speed;
        speed += F;
        
        if (best <= cur + X / speed)
            break;
        else
            best = cur + X / speed;
    }
    
    return best;
}

int main() {
    int numCases;
    scanf("%d", &numCases);
    
    for (int caseNum = 1; caseNum <= numCases; caseNum++) {
        double cost, farmRate, target;
        scanf("%lf %lf %lf", &cost, &farmRate, &target);
        
        double bestTime = calculateBest(cost, farmRate, target);
        printf("Case #%d: %.7lf\n", caseNum, bestTime);
    }
    
    return 0;
}