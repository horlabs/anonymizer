#include <stdio.h>

typedef struct {
    int lowerBound;
    int upperBound;
} ScoreRange;

int calculateMaxThreshold(int score) {
    return (score + 2) / 3;
}

int calculateMinThreshold(int score) {
    return 2 + (score - 2) / 3;
}

ScoreRange setScoreRange(int score) {
    ScoreRange range;
    range.lowerBound = calculateMaxThreshold(score);
    range.upperBound = calculateMinThreshold(score);
    if (range.upperBound * 3 - 4 > score || range.upperBound > 10) {
        range.upperBound = range.lowerBound;
    }
    return range;
}

int main() {
    int t;
    int n, s, p;
    int ans;
    int currentScore;
    int testCase = 0;

    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &s, &p);
        ans = 0;
        while (n--) {
            scanf("%d", &currentScore);
            ScoreRange scoreRange = setScoreRange(currentScore);
            if (scoreRange.lowerBound >= p) {
                ++ans;
            } else if (scoreRange.upperBound >= p && s > 0) {
                ++ans;
                --s;
            }
        }
        printf("Case #%d: %d\n", ++testCase, ans);
    }
    return 0;
}