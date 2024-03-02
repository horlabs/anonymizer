#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int s;
    int p;
    int score;
    int result;
    int surprise;
} Testcase;

int calculateResult(Testcase testcase) {
    testcase.result = 0;
    testcase.surprise = 0;

    for (int i = 0; i < testcase.n; i++) {
        scanf("%d", &testcase.score);

        int div = (testcase.score + 2) / 3;
        if (div >= testcase.p) {
            testcase.result++;
        } else {
            div = (testcase.score + 4) / 3;
            if (div >= testcase.p) {
                if (testcase.score != 0 && testcase.p != 0) {
                    testcase.surprise++;
                }
            }
        }
    }

    if (testcase.s >= testcase.surprise) {
        testcase.result += testcase.surprise;
    } else {
        testcase.result += testcase.s;
    }

    return testcase.result;
}

void printResult(int result, int nc) {
    printf("Case #%d: %d\n", nc, result);
}

int main() {
    int t;
    scanf("%d", &t);

    for (int nc = 1; nc <= t; nc++) {
        Testcase testcase;
        scanf("%d%d%d", &testcase.n, &testcase.s, &testcase.p);
        int result = calculateResult(testcase);
        printResult(result, nc);
    }

    return 0;
}