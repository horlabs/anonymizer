#include <stdio.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int grid[2][MAX_ROWS][MAX_COLS];
int visited[20];

void initializeGrids() {
    int row, col, i;
    for(i = 0; i < 2; i++) {
        for(row = 0; row < MAX_ROWS; row++) {
            for(col = 0; col < MAX_COLS; col++) {
                grid[i][row][col] = 0;
            }
        }
    }
}

void markVisited(int num) {
    visited[num] = 1;
}

void checkMagicTrick(int T) {
    int t, i, row, col, a, b, ans;
    for(t = 0; t < T; t++) {
        memset(visited, 0, sizeof(visited));
        scanf("%d", &a);
        
        for(row = 1; row <= 4; row++) {
            for(col = 1; col <= 4; col++) {
                scanf("%d", &grid[0][row][col]);
            }
        }
        
        for(col = 1; col <= 4; col++) {
            markVisited(grid[0][a][col]);
        }
        
        scanf("%d", &b);
        
        for(row = 1; row <= 4; row++) {
            for(col = 1; col <= 4; col++) {
                scanf("%d", &grid[1][row][col]);
            }
        }
        
        ans = 0;
        for(col = 1; col <= 4; col++) {
            if(visited[grid[1][b][col]]) {
                if(ans != 0) {
                    ans = -1;
                } else {
                    ans = grid[1][b][col];
                }
            }
        }
        
        printf("Case #%d: ", t + 1);
        if(ans == -1) {
            puts("Bad magician!");
        } else if(ans == 0) {
            puts("Volunteer cheated!");
        } else {
            printf("%d\n", ans);
        }
    }
}

int main() {
    int T;
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A_out.txt", "w", stdout);
    
    scanf("%d", &T);
    checkMagicTrick(T);
    
    return 0;
}