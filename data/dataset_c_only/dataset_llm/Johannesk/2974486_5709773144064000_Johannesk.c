#include <stdio.h>
#include <assert.h>

void calculateTime(int testCaseNumber, double costOfFarm, double farmProductionRate, double target)
{
    double currentTime = 0;
    double productionRate = 2;

    while ((target / productionRate) > ((target / (productionRate + farmProductionRate)) + (costOfFarm / productionRate))) {
        currentTime += costOfFarm / productionRate;
        productionRate += farmProductionRate;
    }

    currentTime += target / productionRate;
    printf("Case #%d: %.7lf\n", testCaseNumber, currentTime);
}

int main(int argc, char **argv)
{
    int numberOfTestCases, i;
    double farmCost, farmProductionRate, targetCost;

    assert(scanf("%d ", &numberOfTestCases) == 1);

    for (i = 1; i <= numberOfTestCases; i++) {
        assert(scanf("%lf %lf %lf ", &farmCost, &farmProductionRate, &targetCost) == 3);
        calculateTime(i, farmCost, farmProductionRate, targetCost);
    }

    return 0;
}