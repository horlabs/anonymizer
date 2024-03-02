#include <stdio.h>
#include <stdlib.h>

typedef struct TestCase {
    int N;
    int S;
    int p;
    int *t;
} TestCase;

void readInput(TestCase *testcase) {
    scanf("%d", &testcase->N);
    scanf("%d", &testcase->S);
    scanf("%d", &testcase->p);

    testcase->t = (int *)malloc(testcase->N * sizeof(int));
    for (int i = 0; i < testcase->N; i++) {
        scanf("%d", &testcase->t[i]);
    }
}

int calculateRes(TestCase *testcase) {
    int res = 0;

    for (int i = 0; i < testcase->N; i++) {
        int t = testcase->t[i];
        int t3 = t % 3;
        int best = t / 3;

        if (t3 != 0)
            best++;

        if (best >= testcase->p)
            res++;
        else if (testcase->S > 0 && best + 1 >= testcase->p &&
                 (t3 == 2 || (t3 == 0 && best - 1 >= 0))) {
            res++;
            testcase->S--;
        }
    }

    return res;
}

void printResult(int caseNum, int res) {
    printf("Case #%d: %d\n", caseNum, res);
}

void freeMemory(TestCase *testcase) {
    free(testcase->t);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tcase = 1; tcase <= T; tcase++) {
        TestCase testcase;
        readInput(&testcase);
        int res = calculateRes(&testcase);
        printResult(tcase, res);
        freeMemory(&testcase);
    }

    return 0;
}