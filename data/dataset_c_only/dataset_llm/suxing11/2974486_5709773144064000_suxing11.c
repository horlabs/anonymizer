// Anonymized version of the original code

#include <stdio.h>

// Function to calculate the time needed to reach the target 
double calculateTime(double productionRate, double farmCost, double targetAmount)
{
    double speed = 2, time = 0;
    double timeWithoutFarm, timeWithFarm;
    
    while (1)
    {
        timeWithoutFarm = targetAmount / speed;
        timeWithFarm = farmCost / speed + targetAmount / (speed + productionRate);

        if (timeWithFarm > timeWithoutFarm){
            time += timeWithoutFarm;
            break ;
        }

        time += farmCost / speed;
        speed += productionRate;
    }
    return time;
}

int main()
{
    int testCaseNum = 1, totalTestCases;
    double farmCost, productionRate, targetAmount;

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-out.txt", "w", stdout);

    scanf("%d", &totalTestCases);
    
    while (totalTestCases--)
    {
        scanf("%lf%lf%lf", &farmCost, &productionRate, &targetAmount);
        printf("Case #%d: %.7lf\n", testCaseNum++, calculateTime(farmCost, productionRate, targetAmount));
    }
    return 0;
}