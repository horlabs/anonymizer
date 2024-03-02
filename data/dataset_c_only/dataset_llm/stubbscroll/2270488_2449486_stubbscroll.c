#include <stdio.h>
#include <string.h>

#define MAX_SIZE 111

int grid[MAX_SIZE][MAX_SIZE];
int attempt[MAX_SIZE][MAX_SIZE];
int rows, columns;

int check_grid() {
    int i, j, max, changed;
    
    for(i = 0; i < rows; i++) {
        for(j = 0; j < columns; j++) {
            attempt[i][j] = 100;
        }
    }
    
    do {
        changed = 0;
        
        for(i = 0; i < rows; i++) {
            max = 0;
            
            for(j = 0; j < columns; j++) {
                if(max < grid[i][j]) {
                    max = grid[i][j];
                }
            }
            
            for(j = 0; j < columns; j++) {
                if(attempt[i][j] > max) {
                    attempt[i][j] = max;
                    changed = 1;
                }
            }
        }
        
        for(j = 0; j < columns; j++) {
            max = 0;
            
            for(i = 0; i < rows; i++) {
                if(max < grid[i][j]) {
                    max = grid[i][j];
                }
            }
            
            for(i = 0; i < rows; i++) {
                if(attempt[i][j] > max) {
                    attempt[i][j] = max;
                    changed = 1;
                }
            }
        }
    } while(changed);
    
    for(i = 0; i < rows; i++) {
        for(j = 0; j < columns; j++) {
            if(attempt[i][j] != grid[i][j]) {
                return 0;
            }
        }
    }
    
    return 1;
}

int main() {
    int test_cases, num = 1, i, j;
    
    scanf("%d", &test_cases);
    
    while(test_cases--) {
        scanf("%d %d", &rows, &columns);
        
        for(i = 0; i < rows; i++) {
            for(j = 0; j < columns; j++) {
                scanf("%d", &grid[i][j]);
            }
        }
        
        printf("Case #%d: %s\n", num++, check_grid() ? "YES" : "NO");
    }
    
    return 0;
}