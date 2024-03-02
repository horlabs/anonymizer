#include <stdio.h>

typedef struct {
    int T;
    int n;
    int s;
    int p;
    int res;
} TestCase;

void readTestCase(TestCase* testCase);
void solveTestCase(TestCase* testCase);
void printResult(TestCase* testCase);

int main()
{
    TestCase testCase;
    readTestCase(&testCase);
    solveTestCase(&testCase);
    printResult(&testCase);

    return 0;
}

void readTestCase(TestCase* testCase)
{
    scanf("%d", &testCase->T);
}

void solveTestCase(TestCase* testCase)
{
    for (int t = 1; t <= testCase->T; t++) {
        scanf("%d %d %d", &testCase->n, &testCase->s, &testCase->p);
        testCase->res = 0;
        
        for (int i = 0; i < testCase->n; i++) {
            int v;
            scanf("%d", &v);
            
            if (v >= 3 * testCase->p - 2)
                testCase->res++;
            else if (v >= 3 * testCase->p - 4 && v >= 2 && testCase->s > 0) {
                testCase->res++;
                testCase->s--;
            }
        }
    }
}

void printResult(TestCase* testCase)
{
    for (int t = 1; t <= testCase->T; t++)
        printf("Case #%d: %d\n", t, testCase->res);
}