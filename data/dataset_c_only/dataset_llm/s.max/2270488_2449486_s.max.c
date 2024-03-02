#include <stdio.h>

#define MAX_SIZE 100

int findMax(int arr[MAX_SIZE][MAX_SIZE], int n, int m) {
    int max = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    
    return max;
}

void setCondition(int arr[MAX_SIZE][MAX_SIZE], int uvjet[MAX_SIZE][MAX_SIZE], int n, int m, int max) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == max) {
                uvjet[i][j] = 1;
            }
        }
    }
}

int checkCondition(int uvjet[MAX_SIZE][MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!uvjet[i][j]) {
                return 0;
            }
        }
    }
    
    return 1;
}

int main() {
    int testCaseCount;
    
    scanf("%d", &testCaseCount);
    
    while (testCaseCount--) {
        int n, m;
        int grid[MAX_SIZE][MAX_SIZE];
        int uvjet[MAX_SIZE][MAX_SIZE] = {0};
        
        scanf("%d %d", &n, &m);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &grid[i][j]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            int max = findMax(grid, n, m);
            setCondition(grid, uvjet, n, m, max);
        }
        
        for (int j = 0; j < m; j++) {
            int max = findMax(grid, n, m);
            setCondition(grid, uvjet, n, m, max);
        }
        
        printf("Case #%d: ", testCaseCount + 1);
        
        if (checkCondition(uvjet, n, m)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}