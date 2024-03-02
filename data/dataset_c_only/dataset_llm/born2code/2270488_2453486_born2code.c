#include<stdio.h>

typedef struct{
    int row;
    int col;
} Position;

int isWinner(char board[4][4], char player){
    int i, j;
    int row, col;

    // Check rows
    for(i = 0; i < 4; i++){
        row = 0;
        for(j = 0; j < 4; j++){
            if(board[i][j] == 'T' || board[i][j] == player)
                row++;
        }
        if(row == 4)
            return 1;
    }

    // Check columns
    for(j = 0; j < 4; j++){
        col = 0;
        for(i = 0; i < 4; i++){
            if(board[i][j] == 'T' || board[i][j] == player)
                col++;
        }
        if(col == 4)
            return 1;
    }

    // Check diagonal from top left to bottom right
    row = 0;
    col = 0;
    for(i = 0; i < 4; i++){
        if(board[row][col] == 'T' || board[row][col] == player)
            row++;
        col++;
    }
    if(row == 4)
        return 1;

    // Check diagonal from top right to bottom left
    row = 0;
    col = 3;
    for(i = 0; i < 4; i++){
        if(board[row][col] == 'T' || board[row][col] == player)
            row++;
        col--;
    }
    if(row == 4)
        return 1;

    return 0;
}

int main(){
    int T, T1;
    int dot, x, o, i, j;
    char board[4][4];

    T = 1;
    for(scanf("%d", &T1); T <= T1; T++){
        dot = x = o = 0;
        for(i = 0; i < 4; i++){
            for(j = 0; j < 4; j++){
                do {
                    board[i][j] = getchar();
                } while(!(board[i][j] == '.' || board[i][j] == 'T' || board[i][j] == 'O' || board[i][j] == 'X'));

                if(board[i][j] == '.')
                    dot = 1;
            }
        }

        if(isWinner(board, 'X'))
            x = 1;
        if(isWinner(board, 'O'))
            o = 1;

        printf("Case #%d: ", T);
        if(x == 1)
            printf("X won\n");
        else if(o == 1)
            printf("O won\n");
        else if(dot == 1)
            printf("Game has not completed\n");
        else
            printf("Draw\n");
    }
    return 0;
}