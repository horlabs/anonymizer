#include<stdio.h>

int main()
{
	int ntest;
	char testcase[4][5];
	char res[10];
	char nline[10];
	int i,j,k,nX,nO,nT,nDot;
	int flagDot;
	int flagWin;

	scanf("%d",&ntest);
	
	for(i=0;i<ntest;i++)
	{	
		flagWin=0;flagDot=0;
		
		for(j=0;j<4;j++){
			scanf("%s",testcase[j]);
			//printf("%s\n",testcase[j]);
		}
		//scanf("%s",nline);
	
		//Rows Checking
		for(j=0;j<4;j++)
		{
			nX=0;nO=0;nT=0;
			for(k=0;k<4;k++)
			{
				switch(testcase[j][k])
				{
					case 'X':nX++;break;
					case 'O':nO++;break;
					case 'T':nT++;break;
					case '.':flagDot=1;break;
				}
			}
			//printf("X:%d\tO:%d\tT:%d\t.:%d\n",nX,nO,nT,flagDot);
			if(nX==4 ||(nX==3 && nT==1))
			{
				res[i]='X';
				flagWin=1;
				break;
			}
			if(nO==4 ||(nO==3 && nT==1))
			{
				res[i]='O';
				flagWin=1;
				break;
			}
		}
		
		//Columns Checking
		for(j=0;j<4;j++)
		{
			if(flagWin==1)
				break;
			
			nX=0;nO=0;nT=0;	
			for(k=0;k<4;k++)
			{
				//printf("%s\n",testcase[k]);
				switch(testcase[k][j])
				{
					case 'X':nX++;break;
					case 'O':nO++;break;
					case 'T':nT++;break;
					case '.':flagDot=1;break;
				}
			}
			//printf("Test %d--X:%d\tO:%d\tT:%d\t.:%d\n",i,nX,nO,nT,flagDot);
			if(nX==4 ||(nX==3 && nT==1))
			{
				res[i]='X';
				flagWin=1;
				break;
			}
			if(nO==4 ||(nO==3 && nT==1))
			{
				res[i]='O';
				flagWin=1;
				break;
			}
		}
		
		//Principal Diagonal Checking
		nX=0;nO=0;nT=0;
		for(j=0;j<4;j++)
		{
			if(flagWin==1)
				break;
				
			switch(testcase[j][j])
			{
				case 'X':nX++;break;
				case 'O':nO++;break;
				case 'T':nT++;break;
				case '.':flagDot=1;break;
			}
			//printf("X:%d\tO:%d\tT:%d\t.:%d\n",nX,nO,nT,flagDot);
		}
		if(nX==4 ||(nX==3 && nT==1))
		{
			res[i]='X';
			flagWin=1;
		}
		if(nO==4 ||(nO==3 && nT==1))
		{
			res[i]='O';
			flagWin=1;
		}
		
		
		//Second Diagonal Checking
		nX=0;nO=0;nT=0;
		for(j=0;j<4;j++)
		{
			if(flagWin==1)
				break;
				
			switch(testcase[j][3-j])
			{
				case 'X':nX++;break;
				case 'O':nO++;break;
				case 'T':nT++;break;
				case '.':flagDot=1;break;
			}
			//printf("X:%d\tO:%d\tT:%d\t.:%d\n",nX,nO,nT,flagDot);	
		}
		//printf("no : %d\n",nO);
		if(nX==4 ||(nX==3 && nT==1))
		{
			res[i]='X';
			flagWin=1;
		}
		if(nO==4 ||(nO==3 && nT==1))
		{
			res[i]='O';
			flagWin=1;
		}
			
		
		if(flagWin==0)
			if(flagDot==1)
				res[i]='G';
			else
				res[i]='D';
	}
	
	for(i=0;i<ntest;i++)
	{
		printf("Case #%d: ",i+1);
		switch(res[i])
		{
			case 'X':printf("X won\n");break;
			case 'O':printf("O won\n");break;
			case 'D':printf("Draw\n");break;
			case 'G':printf("Game has not completed\n");break;
		}
	}
}
