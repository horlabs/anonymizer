#include<stdio.h>

void checkRows(char testcase[4][5], int* flagWin, int* flagDot, char* res, int i) {
    int nX=0, nO=0, nT=0;
    for(int j=0; j<4; j++) {
        switch(testcase[i][j]) {
            case 'X':
                nX++;
                break;
            case 'O':
                nO++;
                break;
            case 'T':
                nT++;
                break;
            case '.':
                *flagDot = 1;
                break;
        }
    }
    if(nX==4 ||(nX==3 && nT==1)) {
        *res='X';
        *flagWin=1;
    }
    else if(nO == 4 || (nO == 3 && nT == 1)) {
        *res='O';
        *flagWin=1;
    }
}

void checkColumns(char testcase[4][5], int* flagWin, int* flagDot, char* res, int i) {
    int nX=0, nO=0, nT=0;
    for(int j=0; j<4; j++) {
        switch(testcase[j][i]) {
            case 'X':
                nX++;
                break;
            case 'O':
                nO++;
                break;
            case 'T':
                nT++;
                break;
            case '.':
                *flagDot = 1;
                break;
        }
    }
    if(nX==4 ||(nX==3 && nT==1)) {
        *res='X';
        *flagWin=1;
    }
    else if(nO == 4 || (nO == 3 && nT == 1)) {
        *res='O';
        *flagWin=1;
    }
}

void checkDiagonals(char testcase[4][5], int* flagWin, int* flagDot, char* res) {
    int nX=0, nO=0, nT=0;
    for(int j=0; j<4; j++) {
        switch(testcase[j][j]) {
            case 'X':
                nX++;
                break;
            case 'O':
                nO++;
                break;
            case 'T':
                nT++;
                break;
            case '.':
                *flagDot = 1;
                break;
        }
    }
    if(nX==4 ||(nX==3 && nT==1)) {
        *res='X';
        *flagWin=1;
    }
    else if(nO == 4 || (nO == 3 && nT == 1)) {
        *res='O';
        *flagWin=1;
    }
}

void checkSecondDiagonal(char testcase[4][5], int* flagWin, int* flagDot, char* res) {
    int nX=0, nO=0, nT=0;
    for(int j=0; j<4; j++) {
        switch(testcase[j][3-j]) {
            case 'X':
                nX++;
                break;
            case 'O':
                nO++;
                break;
            case 'T':
                nT++;
                break;
            case '.':
                *flagDot = 1;
                break;
        }
    }
    if(nX==4 ||(nX==3 && nT==1)) {
        *res='X';
        *flagWin=1;
    }
    else if(nO == 4 || (nO == 3 && nT == 1)) {
        *res='O';
        *flagWin=1;
    }
}

int main() {
    int numTests;
    char testcases[4][5];
    char result[10];
    char newLine[10];
    int flagDot;
    int flagWin;

    scanf("%d",&numTests);
	
    for(int i=0; i<numTests; i++) {	
        flagWin=0;
        flagDot=0;

        for(int j=0; j<4; j++) {
            scanf("%s",testcases[j]);
        }
		

        for(int j=0; j<4; j++) {
            checkRows(testcases, &flagWin, &flagDot, &result[i], j);
            if(flagWin==1) {
                break;
            }
        }

        for(int j=0; j<4; j++) {
            if(flagWin==1) {
                break;
            }

            checkColumns(testcases, &flagWin, &flagDot, &result[i], j);
        }

        checkDiagonals(testcases, &flagWin, &flagDot, &result[i]);
        checkSecondDiagonal(testcases, &flagWin, &flagDot, &result[i]);

        if(flagWin==0) {
            if(flagDot==1) {
                result[i]='G';
            }
            else {
                result[i]='D';
            }
        }
    }

    for(int i=0; i<numTests; i++) {
        printf("Case #%d: ",i+1);
        switch(result[i]) {
            case 'X':
                printf("X won\n");
                break;
            case 'O':
                printf("O won\n");
                break;
            case 'D':
                printf("Draw\n");
                break;
            case 'G':
                printf("Game has not completed\n");
                break;
        }
    }
}