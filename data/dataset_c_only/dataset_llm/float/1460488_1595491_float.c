#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int T;
    int N;
    int S;
    int p;
} TestCase;

int calculateScore(int score, int p, int* S) {
    int ans = 0;
    if (score == 30) {
        ans++;
    } else if (score == 29 && p <= 9) {
        ans++;
    } else if (score == 0) {
        if (p == 0) {
            ans++;
        }
    } else {
        switch (score % 3) {
            case 0:
                if (score/3 >= p) {
                    ans++;
                } else if (score/3 + 1 >= p && (*S) > 0) {
                    ans++;
                    (*S)--;
                }
                break;
            case 1:
                if (score/3 >= p || score/3 + 1 >= p) {
                    ans++;
                }
                break;
            case 2:
                if (score/3 >= p || score/3 + 1 >= p) {
                    ans++;
                } else if (score/3 + 2 >= p && (*S) > 0) {
                    ans++;
                    (*S)--;
                }
                break;
        }
    }
    return ans;
}

void printResult(int i, int ans) {
    printf("Case #%d: %d\n", i, ans);
}

int main() {
    int i, j;
    scanf("%d", &T);
    for (i = 1; i <= T; i++) {
        TestCase testCase;
        int score;
        int ans = 0;
        scanf("%d %d %d", &testCase.N, &testCase.S, &testCase.p);
        for (j = 0; j < testCase.N; j++) {
            scanf("%d", &score);
            ans += calculateScore(score, testCase.p, &testCase.S);
        }
        printResult(i, ans);
    }
    return 0;
}