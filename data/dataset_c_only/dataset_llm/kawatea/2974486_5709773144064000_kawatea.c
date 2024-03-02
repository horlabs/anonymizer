#include <stdio.h>

double simulate(double c, double f, double x) {
    double time = 0;
    double productionRate = 2;
    double ans = 1e9;
    
    for (int j = 0; j < 100000; j++) {
        if (time + x / productionRate < ans)
            ans = time + x / productionRate;
        
        time += c / productionRate;
        productionRate += f;
    }
    
    return ans;
}

int main() {
    int numCases;
    
    scanf("%d", &numCases);
    
    for (int i = 0; i < numCases; i++) {
        double cost, farmRate, goal;
        
        scanf("%lf %lf %lf", &cost, &farmRate, &goal);
        
        double result = simulate(cost, farmRate, goal);
        
        printf("Case #%d: %.12lf\n", i + 1, result);
    }
    
    return 0;
}