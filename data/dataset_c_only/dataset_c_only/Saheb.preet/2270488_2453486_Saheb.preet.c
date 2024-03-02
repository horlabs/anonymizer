#include<stdio.h>

int main()
{
  int i,t,j,k;
  char board[4][5],flag,winner,curr;
  scanf("%d",&t);
  for(i=0;i<t;i++)
  {
    winner=0;
    flag=0;
    for (j=0;j<4;j++)
    {
      scanf("%s",board[j]);
      for (k=0;k<4;k++)
	if (board[j][k]!='X'&&board[j][k]!='T')
	  break;
	if (k==4)
	  winner='X';
      for (k=0;k<4;k++)
	if (board[j][k]!='O'&&board[j][k]!='T')
	  break;
	if (k==4)
	  winner='O';
      for (k=0;k<4;k++)
	if (board[j][k]=='.')
	  flag=1;
    }
    for (k=0;k<4;k++)
    {
      for (j=0;j<4;j++)
	if (board[j][k]!='X'&&board[j][k]!='T')
	  break;
      if (j==4)
	winner='X';
      for (j=0;j<4;j++)
	if (board[j][k]!='O'&&board[j][k]!='T')
	  break;
	if (j==4)
	  winner='O';
    }
    for (k=0;k<4;k++)
      if (board[k][k]!='X'&&board[k][k]!='T')
	break;
    if(k==4)
      winner='X';
    for (k=0;k<4;k++)
      if (board[k][k]!='O'&&board[k][k]!='T')
	break;
    if(k==4)
      winner='O';
    for (k=0;k<4;k++)
      if (board[3-k][k]!='X'&&board[3-k][k]!='T')
	break;
    if(k==4)
      winner='X';
    for (k=0;k<4;k++)
      if (board[3-k][k]!='O'&&board[3-k][k]!='T')
	break;
    if(k==4)
      winner='O';
    if (winner==0)
    {
      if (flag==1)
	printf("Case #%d: Game has not completed\n",i+1);
      else
	printf("Case #%d: Draw\n",i+1);
    }
    else
      printf("Case #%d: %c won\n",i+1,winner);
 }
 return 0;
}