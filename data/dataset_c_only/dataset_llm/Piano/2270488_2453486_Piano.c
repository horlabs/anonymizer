#include<stdio.h>

typedef struct {
    int rows[4];
    int cols[4];
    int dias[2];
} Grid;

void resetGrid(Grid* grid) {
    for (int i = 0; i < 4; ++i) {
        grid->rows[i] = 0;
        grid->cols[i] = 0;
        if (i < 2) {
            grid->dias[i] = 0;
        }
    }
}

void countMarks(Grid* grid, int row, int col, char mark) {
    switch (mark) {
        case 'X':
            ++grid->rows[row];
            ++grid->cols[col];
            if (row == col) ++grid->dias[0];
            if (row + col == 3) ++grid->dias[1];
            break;
        case 'O':
            ++grid->rows[row];
            ++grid->cols[col];
            if (row == col) ++grid->dias[0];
            if (row + col == 3) ++grid->dias[1];
            break;
        default:
            break;
    }
}

void checkWinner(Grid* grid, char* result) {
    for (int i = 0 ; i < 4 ; ++i){
        if (grid->rows[i] == 4){
            *result = 'X';
            break;
        }
        if (grid->cols[i] == 4){
            *result = 'X';
            break;
        }
        if (grid->rows[i] == 4){
            *result = 'O';
            break;
        }
        if (grid->cols[i] == 4){
            *result = 'O';
            break;
        }
        if (i < 2){
            if (grid->dias[i] == 4){
                *result = 'X';
                break;
            }
            if (grid->dias[i] == 4){
                *result = 'O';
                break;
            }
        }
    }
}

int main(){
    int testCase, u;
    scanf("%d", &testCase);
    
    for (u = 1 ; u <= testCase ; ++u){
        char c;
        int row, col;
        Grid grid;
        resetGrid(&grid);
        
        printf("Case #%d: ", u);
        getchar();
        
        for (row = 0 ; row < 4 ; ++row){
            for (col = 0 ; col < 4 ; ++col){
                c = getchar();
                countMarks(&grid, row, col, c);
            }
            getchar();
        }
        
        char result = '\0';
        checkWinner(&grid, &result);
        
        if (result != '\0'){
            printf("%c won\n", result);
        } else {
            int isGameIncomplete = 0;
            
            for (row = 0 ; row < 4 ; ++row){
                if (grid.rows[row] < 4) {
                    isGameIncomplete = 1;
                    break;
                }
            }
            
            printf(isGameIncomplete ? "Game has not completed\n" : "Draw\n");
        }
    }
    
    return 0;
}