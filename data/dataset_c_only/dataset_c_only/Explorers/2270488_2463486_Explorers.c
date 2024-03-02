#include<stdio.h>
#include<math.h>

int main()
{
	int ntest;
	int res[100]={0};
	int start,end,sqnm,i,j;
	
	scanf("%d",&ntest);
	
	for(i=0;i<ntest;i++)
	{
		scanf("%d %d",&start,&end);
		
		for(j=start;j<=end;j++)
		{
			if(pald(j)==0)
				continue;
			if((sqnm=sqrtInt(j))==0)
				continue;
			if(pald(sqnm)!=0)
				res[i]++;
		}
	}
	
	for(i=0;i<ntest;i++)
		printf("Case #%d: %d\n",i+1,res[i]);
	
}

int pald(int nm)
{
	int rev=0;
	int remnm=nm;
	
	while(remnm!=0)
	{
		rev=rev*10+(remnm%10);
		remnm/=10;
	}
	
	if(rev==nm)
		return 1;
	else
		return 0;
}

int sqrtInt(int nm)
{
	double sqroot,denom;
	sqroot=sqrt(nm);
	
	denom=sqroot-(int)sqroot;
	
	if(denom==0.0)
		return sqroot;
	else
		return 0;
}
