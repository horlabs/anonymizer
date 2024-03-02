#include <stdio.h>

struct Board {
    char grid[4][5];
};

void readBoard(struct Board* board) {
    for(int i=0;i<4;i++) {
        scanf("%s",board->grid[i]);
    }
}

int checkRows(struct Board* board, char player) {
    int tmpX, tmpO, tmpT;
    for(int i=0;i<4;i++) {
        tmpX=0;
        tmpO=0;
        tmpT=0;
        for(int j=0;j<4;j++) {
            if(board->grid[i][j]=='X') {
                tmpX++;
            }
            else if(board->grid[i][j]=='O') {
                tmpO++;
            }
            else if(board->grid[i][j]=='T') {
                tmpT++;
            }
        }
        if((tmpX+tmpT)==4) {
            return (player=='X') ? 1 : 2;
        }
        if((tmpO+tmpT)==4) {
            return (player=='O') ? 2 : 1;
        }
    }
    return 0;
}

int checkColumns(struct Board* board, char player) {
    int tmpX, tmpO, tmpT;
    for(int j=0;j<4;j++) {
        tmpX=0;
        tmpO=0;
        tmpT=0;
        for(int i=0;i<4;i++) {
            if(board->grid[i][j]=='X') {
                tmpX++;
            }
            else if(board->grid[i][j]=='O') {
                tmpO++;
            }
            else if(board->grid[i][j]=='T') {
                tmpT++;
            }
        }
        if((tmpX+tmpT)==4) {
            return (player=='X') ? 1 : 2;
        }
        if((tmpO+tmpT)==4) {
            return (player=='O') ? 2 : 1;
        }
    }
    return 0;
}

int checkDiagonal1(struct Board* board, char player) {
    int tmpX=0, tmpO=0, tmpT=0;
    for(int i=0;i<4;i++) {
        if(board->grid[i][i]=='X') {
            tmpX++;
        }
        else if(board->grid[i][i]=='O') {
            tmpO++;
        }
        else if(board->grid[i][i]=='T') {
            tmpT++;
        }
    }
    if((tmpX+tmpT)==4) {
        return (player=='X') ? 1 : 2;
    }
    if((tmpO+tmpT)==4) {
        return (player=='O') ? 2 : 1;
    }
    return 0;
}

int checkDiagonal2(struct Board* board, char player) {
    int tmpX=0, tmpO=0, tmpT=0;
    for(int i=0;i<4;i++) {
        if(board->grid[i][3-i]=='X') {
            tmpX++;
        }
        else if(board->grid[i][3-i]=='O') {
            tmpO++;
        }
        else if(board->grid[i][3-i]=='T') {
            tmpT++;
        }
    }
    if((tmpX+tmpT)==4) {
        return (player=='X') ? 1 : 2;
    }
    if((tmpO+tmpT)==4) {
        return (player=='O') ? 2 : 1;
    }
    return 0;
}

int checkDraw(struct Board* board) {
    int tmpD=0;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if(board->grid[i][j]=='.') {
                tmpD++;
                break;
            }
        }
        if(tmpD!=0) {
            break;
        }
    }
    if(tmpD!=0) {
        return 4;
    }
    else {
        return 3;
    }
}

void printOutput(int t, int ans) {
    switch(ans) {
        case 1:
            printf("Case #%d: X won\n",t);
            break;
        case 2:
            printf("Case #%d: O won\n",t);
            break;
        case 3:
            printf("Case #%d: Draw\n",t);
            break;
        case 4:
            printf("Case #%d: Game has not completed\n",t);
            break;
    }
}

int main() {
    int T, ans;
    struct Board board;
    
    freopen("A-small-attempt0.in.txt","r",stdin);
	freopen("A-small-attempt0.out.txt","w",stdout);
    
    scanf("%d",&T);
    
    for(int t=1;t<=T;t++) {
        ans=0;
        readBoard(&board);
        ans = checkRows(&board, 'X');
        if(ans==0) {
            ans = checkColumns(&board, 'X');
        }
        if(ans==0) {
            ans = checkDiagonal1(&board, 'X');
        }
        if(ans==0){
            ans = checkDiagonal2(&board, 'X');
        }
        if(ans==0) {
            ans = checkRows(&board, 'O');
        }
        if(ans==0) {
            ans = checkColumns(&board, 'O');
        }
        if(ans==0) {
            ans = checkDiagonal1(&board, 'O');
        }
        if(ans==0){
            ans = checkDiagonal2(&board, 'O');
        }
        if(ans==0) {
            ans = checkDraw(&board);
        }
        printOutput(t, ans);
    }
    return 0;
}