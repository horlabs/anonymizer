#include <stdio.h>
#include <string.h>
#include <assert.h>

char b[100][100];

int checkpossible(int x, int y)
{
	int i,j,k,max;
	for (i=0;i<x;i++)
	{
		max=0;
		for(j=0;j<y;j++)
			if(b[i][j]>max)
				max=b[i][j];
		for(j=0;j<y;j++)
		{
			if(b[i][j]<max)
			{
				//Must cut other direction
				for(k=0;k<x;k++)
					if(b[k][j]>b[i][j])
						return 0;
			}
		}
		
	}
	return 1;
}

void printinput(int x, int y)
{
	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			printf("%c",b[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char **argv)
{
    int t,i,n,m,x,y;
//	char b[4][4];
	char line[10];
	
    assert (scanf("%d ",&t) == 1); //Number of testcases
    for(i=1;i<=t;i++)
    {
        assert (scanf("%d %d ",&n,&m) == 2);
		for(x=0;x<n;x++)
			for(y=0;y<m;y++)
				assert (scanf("%c ",&b[x][y]) == 1);
	    //printinput(n,m);
		if(checkpossible(n,m) == 1)
			printf("Case #%d: YES\n",i);
		else
			printf("Case #%d: NO\n",i);
			

    }
    return 0;
}
