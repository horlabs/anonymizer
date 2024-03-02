#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

#define X_WON 0
#define O_WON 1
#define NO_WIN 2
#define BLANK 3

void handleCase();
int getWinResult(int x, int y, int t);

int grid[4][4];
int dx[] = {0, 1, 1, -1};
int dy[] = {1, 1, 0, 1};

int main() {
    freopen("ain.txt", "r", stdin);
    freopen("aout.txt", "w", stdout);
    
    int n;
    scanf("%d ", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Case #%d: ", i + 1);
        handleCase();
    }
    
    return 0;
}

void handleCase() {
    bool full = true;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            char c;
            int type;
            scanf("%c ", &c);
            
            if (c == 'X') {
                type = X_WON;
            }
            else if (c == 'O') {
                type = O_WON;
            }
            else if (c == 'T') {
                type = NO_WIN;
            }
            else {
                full = false;
                type = BLANK;
            }
            
            grid[i][j] = type;
        }
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                int result = getWinResult(j, i, k);
                
                if (result == X_WON) {
                    printf("X won\n");
                    return;
                }
                else if (result == O_WON) {
                    printf("O won\n");
                    return;
                }
            }
        }
    }
    
    if (full) {
        printf("Draw\n");
    }
    else {
        printf("Game has not completed\n");
    }
}

int getWinResult(int x, int y, int t) {
    int cur = NO_WIN;
    
    for (int i = 0; i < 4; i++) {
        if (x >= 4 || y >= 4 || x < 0 || y < 0) {
            return NO_WIN;
        }
        
        if (grid[y][x] == BLANK) {
            return NO_WIN;
        }
        
        if (grid[y][x] != NO_WIN) {
            if (cur == NO_WIN || cur == grid[y][x]) {
                cur = grid[y][x];
            }
            else {
                return NO_WIN;
            }
        }
        
        x += dx[t];
        y += dy[t];
    }
    
    return cur;
}