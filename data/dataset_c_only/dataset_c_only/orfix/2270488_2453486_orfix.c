#include  <stdio.h>
#include  <stdlib.h>

#define  WIN	4
enum status_e { XPLYR, OPLYR, DRAW, INCOMPLETE };

int main( void )
{
	freopen("A-small-attempt0.in","r",stdin);

	int testcase = 0;
	int testcases;

	scanf("%d\n", &testcases);

	while (testcase < testcases) {
		char* result_str[] = {"X won", "O won", "Draw", "Game has not completed"};
		enum status_e status = INCOMPLETE;
		unsigned char col[2][4] = {{0}};
		unsigned char row[2][4] = {{0}};
		unsigned char diag[2][2] = {{0}};
		unsigned char c, i, j, empty = 0;

		/* Parse the game board */
		for( i=0; i<4; i++) {
			for( j=0; j<4; j++) {
				switch (c=getchar()) {
					case 'T' : if(++row[OPLYR][i]==WIN || ++col[OPLYR][j]==WIN) { status = OPLYR; break; }	/* ROWS + COLUMNS */
							   if(i==j && ++diag[OPLYR][0]==WIN)		  status = OPLYR;					/* 1st DIAGONAL */
							   else if(j == 3-i && ++diag[OPLYR][1]==WIN) status = OPLYR;					/* 2nd DIAGNOAL */
					case 'X' : if(++row[XPLYR][i]==WIN || ++col[XPLYR][j]==WIN) { status = XPLYR; break; }	/* ROWS + COLUMNS */
							   if(i==j && ++diag[XPLYR][0]==WIN) 			status = XPLYR;					/* 1st DIAGONAL */
							   else if(j == 3-i && ++diag[XPLYR][1]==WIN) status = XPLYR;					/* 2nd DIAGNOAL */
							   break;
					case 'O' : if(++row[OPLYR][i]==WIN || ++col[OPLYR][j]==WIN) { status = OPLYR; break; }	/* ROWS + COLUMNS */
							   if(i==j && ++diag[OPLYR][0]==WIN) status = OPLYR;							/* 1st DIAGONAL */
							   else if(j == 3-i && ++diag[OPLYR][1]==WIN) status = OPLYR;					/* 2nd DIAGNOAL */
							   break;
					case '.' : empty++; break;
				}
			}
			getchar(); /* consume the \n */
		}
		getchar(); /* consume the \n */
		/* incomplete of draw ? */
		if(!empty && status==INCOMPLETE) {
			status = DRAW;
		}

		printf("Case #%d: %s\n",++testcase, result_str[status]);
	}

	return 0;
}
