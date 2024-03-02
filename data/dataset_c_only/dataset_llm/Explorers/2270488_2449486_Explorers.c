#include <stdio.h>
#include <stdbool.h>

#define MAX_TEST_CASES 100
#define MAX_ROW 10
#define MAX_COL 10

typedef struct {
    int rows;
    int cols;
    int data[MAX_ROW][MAX_COL];
} TestCase;

typedef struct {
    bool isPossible;
} TestResult;

TestResult analyzeTestCase(TestCase testCase);
bool isHorizontalLine(int r, int row, int col, int data[MAX_ROW][MAX_COL]);
bool isVerticalLine(int c, int row, int col, int data[MAX_ROW][MAX_COL]);

int main()
{
    int numTestCases;
    TestCase testCases[MAX_TEST_CASES];
    TestResult results[MAX_TEST_CASES];
    
    scanf("%d", &numTestCases);
    
    for (int i = 0; i < numTestCases; i++) {
        scanf("%d %d", &testCases[i].rows, &testCases[i].cols);
        
        for (int j = 0; j < testCases[i].rows; j++) {
            for (int k = 0; k < testCases[i].cols; k++) {
                scanf("%d", &testCases[i].data[j][k]);
            }
        }
        
        results[i] = analyzeTestCase(testCases[i]);
    }
    
    for (int i = 0; i < numTestCases; i++) {
        printf("Case #%d: %s\n", i+1, results[i].isPossible ? "YES" : "NO");
    }
    
    return 0;
}

TestResult analyzeTestCase(TestCase testCase)
{
    TestResult result;
    result.isPossible = true;
    
    for (int r = 0; r < testCase.rows; r++) {
        for (int c = 0; c < testCase.cols; c++) {
            if (testCase.data[r][c] == 1) {
                if (isHorizontalLine(r, testCase.rows, testCase.cols, testCase.data) ||
                    isVerticalLine(c, testCase.rows, testCase.cols, testCase.data)) {
                    continue;
                } else {
                    result.isPossible = false;
                    return result;
                }
            }
        }
    }
    
    return result;
}

bool isHorizontalLine(int r, int row, int col, int data[MAX_ROW][MAX_COL])
{
    for (int i = 0; i < col; i++) {
        if (data[r][i] != 1) {
            return false;
        }
    }
    
    return true;
}

bool isVerticalLine(int c, int row, int col, int data[MAX_ROW][MAX_COL])
{
    for (int i = 0; i < row; i++) {
        if (data[i][c] != 1) {
            return false;
        }
    }
    
    return true;
}