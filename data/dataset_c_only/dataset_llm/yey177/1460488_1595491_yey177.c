#include <stdio.h>

int calculateScore(int x, int p) {
    int score = 0;
    if (x >= p * 3 - 2) {
        score++;
    }
    else if (x >= p * 3 - 4 && x >= 2) {
        score--;
    }
    return score;
}

void anonymizedCode() {
    int numTests, numRounds, minSuprisingScore, totalScore;
    scanf("%d",&numTests);
    for (int test = 1; test <= numTests; test++) {
        totalScore = 0;
        scanf("%d%d%d",&numRounds,&minSuprisingScore,&totalScore);
        while (numRounds--) {
            int score;
            scanf("%d",&score);
            totalScore += calculateScore(score, minSuprisingScore);
        }
        printf("Case #%d: %d\n",test,totalScore);
    }
}

int main(){
    anonymizedCode();
    return 0;
}