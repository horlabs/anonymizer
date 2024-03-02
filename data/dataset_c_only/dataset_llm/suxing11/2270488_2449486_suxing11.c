#include <stdio.h>

#define IN "B-small-attempt0.in"

#define SWAP(a,b) (t=a,a=b,b=t)
#define FOR(i,a,b) for(i = a ; i < b ; i++)

int grid[110][110], sortedGrid[110][110];
int gridRows[110], gridCols[110];
int heightValues[220][3];

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int T, testCase = 1;
    int ROW = 0, COL = 1;
    int flag, n, m, i, j, cc, t;
    freopen(IN, "r", stdin);
    freopen("B_out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        
        for (i = 0; i < n; i++)
            gridRows[i] = 0;
        
        for (j = 0; j < m; j++)
            gridCols[j] = 0;
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                scanf("%d", &grid[i][j]);
                gridRows[i] = max(gridRows[i], grid[i][j]);
                gridCols[j] = max(gridCols[j], grid[i][j]);
            }
        }
        
        cc = 0;
        for (i = 0; i < n; i++) {
            heightValues[cc][0] = gridRows[i];
            heightValues[cc][1] = i;
            heightValues[cc][2] = ROW;
            cc++;
        }
        
        for (i = 0; i < m; i++) {
            heightValues[cc][0] = gridCols[i];
            heightValues[cc][1] = i;
            heightValues[cc][2] = COL;
            cc++;
        }
        
        for (i = 0; i < cc; i++) {
            for (j = 0; j < i; j++) {
                if (heightValues[i][0] < heightValues[j][0]) {
                    SWAP(heightValues[i][0], heightValues[j][0]);
                    SWAP(heightValues[i][1], heightValues[j][1]);
                    SWAP(heightValues[i][2], heightValues[j][2]);
                }
            }
        }
        
        for (i = 0; i < n; i++) {
        	for (j = 0; j < m; j++) {
        		sortedGrid[i][j] = 100;
        	}
        }
        
        for (i = cc - 1; i >= 0; i--) {
            if (heightValues[i][2] == ROW) {
                for (j = 0; j < m; j++) {
                	sortedGrid[heightValues[i][1]][j] = heightValues[i][0];
                }
            } else {
                for (j = 0; j < n; j++) {
                	sortedGrid[j][heightValues[i][1]] = heightValues[i][0];
                }
            }
        }
        
        flag = 0;
        for (i = 0; i < n; i++) {
        	for (j = 0; j < m; j++) {
        		if (grid[i][j] != sortedGrid[i][j]) {
        			flag = 1;
        			break;
        		}
        	}
        }
        
        printf("Case #%d: %s\n", testCase++, flag ? "NO" : "YES");
    }
    
    return 0;
}
