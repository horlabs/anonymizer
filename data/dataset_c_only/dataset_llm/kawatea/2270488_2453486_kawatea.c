#include <stdio.h>

int checkWin(char board[4][5], char player) {
    int i, j, k;
    
    // Check rows and columns
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (board[i][j] != player && board[i][j] != '.') break;
        }
        if (j == 4) return 1;
        
        for (j = 0; j < 4; j++) {
            if (board[j][i] != player && board[j][i] != '.') break;
        }
        if (j == 4) return 1;
    }
    
    // Check diagonals
    for (i = 0; i < 4; i++) {
        if (board[i][i] != player && board[i][i] != '.') break;
    }
    if (i == 4) return 1;
    
    for (i = 0; i < 4; i++) {
        if (board[i][3 - i] != player && board[i][3 - i] != '.') break;
    }
    if (i == 4) return 1;
    
    return 0;
}

int main() {
    int numCases;
    
    scanf("%d", &numCases);
    
    for (int caseNum = 1; caseNum <= numCases; caseNum++) {
        char board[4][5];
        
        for (int i = 0; i < 4; i++) {
            scanf("%s", board[i]);
        }
        
        int xWin = checkWin(board, 'X');
        int oWin = checkWin(board, 'O');
        
        if (xWin) {
            printf("Case #%d: X won\n", caseNum);
        } else if (oWin) {
            printf("Case #%d: O won\n", caseNum);
        } else {
            int incomplete = 0;
            
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (board[i][j] == '.') {
                        incomplete = 1;
                        break;
                    }
                }
                
                if (incomplete) break;
            }
            
            if (incomplete) {
                printf("Case #%d: Game has not completed\n", caseNum);
            } else {
                printf("Case #%d: Draw\n", caseNum);
            }
        }
    }
    
    return 0;
}