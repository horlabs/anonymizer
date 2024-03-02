#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SCORES 100

typedef struct {
    int total;
    int surprising;
} Result;

Result calculateBestScore(int total, int surprising) {
    Result result;
    if (total == 0) {
        result.total = 0;
        result.surprising = 0;
        return result;
    }

    if (surprising == 0) {
        result.total = (total % 3 == 0) ? total / 3 : total / 3 + 1;
        result.surprising = 0;
    } else {
        if (total % 3 == 2) {
            result.total = total / 3 + 2;
            result.surprising = 0;
        } else {
            result.total = total / 3 + 1;
            result.surprising = 0;
        }
    }

    return result;
}

void searchScores(int *scores, int remaining, int maxSurprising, int threshold, int currentCount, int *maxCount) {
    if (remaining == 0) {
        if (*maxCount < currentCount) {
            *maxCount = currentCount;
        }
        return;
    }

    if (remaining > maxSurprising) {
        Result result = calculateBestScore(*scores, 0);
        int increase = (result.total >= threshold) ? 1 : 0;
        searchScores(scores + 1, remaining - 1, maxSurprising, threshold, currentCount + increase, maxCount);
    }

    if (maxSurprising > 0 && *scores >= 2) {
        Result result = calculateBestScore(*scores, 1);
        int increase = (result.total >= threshold) ? 1 : 0;
        searchScores(scores + 1, remaining - 1, maxSurprising - 1, threshold, currentCount + increase, maxCount);
    }
}

int main(void) {
    int T;
    scanf("%d\n", &T);

    for (int t = 1; t <= T; t++) {
        int N, S, p;
        int scores[MAX_SCORES];
        memset(scores, 0, sizeof(scores));
        scanf("%d %d %d ", &N, &S, &p);
        
        for (int n = 0; n < N; n++) {
            scanf("%d ", &scores[n]);
        }

        int maxCount = 0;
        searchScores(scores, N, S, p, 0, &maxCount);
        printf("Case #%d: %d\n", t, maxCount);
    }

    return 0;
}