#include <stdio.h>
#include <stdlib.h>

#define require(X,Y) { if(!(X)) { fprintf(stderr,"%s\n",Y); exit(-1); } }
#define N 4
#define M 4

int main()
{
	int T,tcase,i,j,jj,counter,resj,r1,r2,arr1[4][4],arr2[4][4];

	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%d",&r1);
		r1--;
		for(i=0;i<N;i++)
			for(j=0;j<M;j++)
				scanf("%d",&(arr1[i][j]));
		scanf("%d",&r2);
		r2--;
		for(i=0;i<N;i++)
			for(j=0;j<M;j++)
				scanf("%d",&(arr2[i][j]));
		counter=0;
		resj=-1;
		for(j=0;j<M;j++)
			for(jj=0;jj<M;jj++)
				if(arr1[r1][j]==arr2[r2][jj])
				{
					counter++;
					resj=j;
				}
		printf("Case #%d: ",tcase);
		if(counter==1)
			printf("%d\n",arr1[r1][resj]);
		else
			printf("%s\n",counter?"Bad magician!":"Volunteer cheated!");
	}

	return 0;
}
