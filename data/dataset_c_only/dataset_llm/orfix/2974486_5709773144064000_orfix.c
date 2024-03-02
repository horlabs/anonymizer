#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double farm;
    double extraRate;
    double cookiesToWin;
} Problem;

double calculateTimeSpent(Problem problem);

int main(void) {
    freopen("B-small-attempt0.in", "r", stdin);
    int testcases;
    scanf("%d\n", &testcases);

    Problem problems[testcases];

    for (int i = 0; i < testcases; i++) {
        scanf("%lf %lf %lf\n", &problems[i].farm, &problems[i].extraRate, &problems[i].cookiesToWin);
    }

    for (int i = 0; i < testcases; i++) {
        double timeSpent = calculateTimeSpent(problems[i]);
        printf("Case #%d: %lf\n", i + 1, timeSpent);
    }

    return 0;
}

double calculateTimeSpent(Problem problem) {
    double timeSpent = 0.0;
    double cookieRate = 2.0;

    while (1) {
        double timeWithCurrentRate = timeSpent + (problem.cookiesToWin / cookieRate);
        double timeWithNewRate = timeSpent + (problem.farm / cookieRate) + (problem.cookiesToWin / (cookieRate + problem.extraRate));

        if (timeWithCurrentRate > timeWithNewRate) {
            timeSpent += problem.farm / cookieRate;
            cookieRate += problem.extraRate;
        } else {
            timeSpent += problem.cookiesToWin / cookieRate;
            break;
        }
    }

    return timeSpent;
}