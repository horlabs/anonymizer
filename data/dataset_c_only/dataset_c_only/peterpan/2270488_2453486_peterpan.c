#include <stdio.h>
#include <stdlib.h>

#define require(X,Y) { if(!(X)) { fprintf(stderr,"%s\n",Y); exit(-1); } }
#define N 4

void readline()
{
	while(getchar()!='\n')
		;
}

int main()
{
	int i,j,tcase,T,xs,os,ts,winner;
	char board[5][5],last;

	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		xs=os=ts=0;
		readline();
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				board[i][j]=getchar();
				if(board[i][j]=='X')
					xs++;
				else if(board[i][j]=='O')
					os++;
				else if(board[i][j]=='T')
					ts++;
				else if(board[i][j]!='.')
				{
					fprintf(stderr,"Error reading input!\n");
					exit(1);
				}
			}
			readline();
		}
		if(xs>os)
			last='X';
		else
			last='O';
		for(i=0;i<N;i++)
		{
			winner=1;
			for(j=0;j<N;j++)
			{
				if(board[i][j]!=last && board[i][j]!='T')
				{
					winner=0;
					break;
				}
			}
			if(winner)
				break;
			winner=1;
			for(j=0;j<N;j++)
			{
				if(board[j][i]!=last && board[j][i]!='T')
				{
					winner=0;
					break;
				}
			}
			if(winner)
				break;
		}
		if(winner)
		{
			printf("Case #%d: %c won\n",tcase,last);
			continue;
		}
		winner=1;
		for(j=0;j<N;j++)
		{
			if(board[j][j]!=last && board[j][j]!='T')
			{
				winner=0;
				break;
			}
		}
		if(winner)
		{
			printf("Case #%d: %c won\n",tcase,last);
			continue;
		}
		winner=1;
		for(j=0;j<N;j++)
		{
			if(board[N-1-j][j]!=last && board[N-1-j][j]!='T')
			{
				winner=0;
				break;
			}
		}
		if(winner)
		{
			printf("Case #%d: %c won\n",tcase,last);
			continue;
		}
		if(xs+os+ts==N*N)
			printf("Case #%d: Draw\n",tcase);
		else
			printf("Case #%d: Game has not completed\n",tcase);
	}

	return 0;
}
