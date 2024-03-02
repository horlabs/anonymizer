#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define require(X,Y) { if(!(X)) { fprintf(stderr,"%s\n",Y); exit(-1); } }

char buffer[20];

int isPal(int n)
{
	int i,j;

	i=0;
	while(n)
	{
		buffer[i++]=n%10;
		n/=10;
	}
	i--;
	for(j=0;j<i;j++,i--)
		if(buffer[j]!=buffer[i])
			return 0;
	return 1;
}

int isPalLL(long long n)
{
	int i,j;

	i=0;
	while(n)
	{
		buffer[i++]=n%10;
		n/=10;
	}
	i--;
	for(j=0;j<i;j++,i--)
		if(buffer[j]!=buffer[i])
			return 0;
	return 1;
}

int main()
{
	long long a,b;
	int T,tcase,*count;
	int sa,sb,i;


	count = malloc(10000001*sizeof(int));
	require(count!=NULL,"Out of memory!");

	count[0]=1;
	for(i=1;i<=10000000;i++)
		if(isPal(i) && isPalLL(((long long) i)*i))
			count[i]=count[i-1]+1;
		else
			count[i]=count[i-1];
	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%lld %lld",&a,&b);
		sa=ceil(sqrt((double) a));
		sb=sqrt((double) b);
		printf("Case #%d: %d\n",tcase,count[sb]-count[sa-1]);
	}
	return 0;
}

