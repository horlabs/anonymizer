#include <stdio.h>

typedef struct {
    double cookiesPerSecond;
    double farmCost;
    double targetCookies;
} Problem;

void solveProblem(Problem *problem);

int main()
{
    int numCases;
    scanf("%d", &numCases);

    Problem problems[numCases];

    for (int i = 0; i < numCases; i++) 
    {
        scanf("%lf %lf %lf", &problems[i].cookiesPerSecond, &problems[i].farmCost, &problems[i].targetCookies);
    }

    for (int i = 0; i < numCases; i++) 
    {
        solveProblem(&problems[i]);
    }

    return 0;
}

void solveProblem(Problem *problem)
{
    double currentCookiesPerSecond = 2.0;
    double totalTime = 0.0;
    double nextTime = 0.0;
    double elapsedTime;

    do 
    {
        elapsedTime = problem->targetCookies / currentCookiesPerSecond;
        nextTime = problem->farmCost / currentCookiesPerSecond + problem->targetCookies / (currentCookiesPerSecond + problem->farmCost);
        totalTime += problem->farmCost / currentCookiesPerSecond;
        currentCookiesPerSecond += problem->farmCost;
    } while (elapsedTime > nextTime);

    printf("Time needed: %.7lf\n", elapsedTime);
}