#include <stdio.h>

#define SIZE 4

typedef struct {
    int matrix[SIZE][SIZE];
} Matrix;

typedef struct {
    int row;
    Matrix matrix;
} TestCase;

Matrix createMatrix() {
    Matrix matrix;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &matrix.matrix[i][j]);
        }
    }
    return matrix;
}

TestCase createTestCase() {
    TestCase testCase;
    testCase.row = -1;
    testCase.matrix = createMatrix();
    return testCase;
}

int findMatchingNumber(TestCase testCase1, TestCase testCase2) {
    int num = -1;
    for (int k = 1; k <= SIZE * SIZE; k++) {
        for (int i = 0; i < SIZE; i++) {
            if (testCase1.matrix.matrix[testCase1.row][i] == k) {
                goto next;
            }
        }
        continue;
    next:
        for (int i = 0; i < SIZE; i++) {
            if (testCase2.matrix.matrix[testCase2.row][i] == k) {
                goto next2;
            }
        }
        continue;
    next2:
        if (num > -1) {
            puts("Bad magician!");
            return -1;
        }
        num = k;
    }
    return num;
}

void solve(TestCase testCase) {
    int num = findMatchingNumber(testCase, testCase);
    if (num < 0) {
        puts("Volunteer cheated!");
    } else {
        printf("%d\n", num);
    }
}

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 1; i <= numTestCases; i++) {
        printf("Case #%d: ", i);
        solve(createTestCase(), createTestCase());
    }
    return 0;
}