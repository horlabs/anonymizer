#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 200

void processMatrix(int dp[MAX_SIZE][MAX_SIZE], int map[MAX_SIZE][MAX_SIZE], int n, int m) {
    int i, j, max;
  
    for(i = 0; i < n; i++) {
        max = 0;
        for(j = 0; j < m; j++) {
            if(map[i][j] > max)
                max = map[i][j];
        }
        for(j = 0; j < m; j++) {
            if(max < dp[i][j])
                dp[i][j] = max;
        }
    }
  
    for(i = 0; i < m; i++) {
        max = 0;
        for(j = 0; j < n; j++) {
            if(map[j][i] > max)
                max = map[j][i];
        }
        for(j = 0; j < n; j++) {
            if(max < dp[j][i])
                dp[j][i] = max;
        }
    }
}

int checkMatrix(int dp[MAX_SIZE][MAX_SIZE], int map[MAX_SIZE][MAX_SIZE], int n, int m) {
    int i, j;
  
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(dp[i][j] != map[i][j])
                return 0;
        }
    }
  
    return 1;
}

int main() {
    int caseNum;
    int i, j;
    int n, m;
    int map[MAX_SIZE][MAX_SIZE];
    int dp[MAX_SIZE][MAX_SIZE];

    scanf("%d", &caseNum);

    for(i = 1; i <= caseNum; i++) {
        memset(dp, 0, sizeof(dp));
        scanf("%d%d", &n, &m);
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                scanf("%d", &map[i][j]);
                dp[i][j] = MAX_SIZE;
            }
        }

        processMatrix(dp, map, n, m);
        /*
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++)
                printf("%d ", dp[i][j]);
            printf("\n");
        }
        */
        if(checkMatrix(dp, map, n, m))
            printf("Case #%d: YES\n", i);
        else
            printf("Case #%d: NO\n", i);
    }

    return 0;
}