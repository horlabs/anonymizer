#include<stdio.h>
int main()
{
	int t,i,j,k,c;
	double C,F,X,R,T,S,P1,P2;

	scanf("%d",&t);
	for(c=1;c<=t;c++)
	{
		scanf("%lf %lf %lf",&C,&F,&X);
		P1=X/2.00;
		for(i=1;;i++)
		{
			P2=X/(2+i*F);
			for(j=0;j<i;j++)P2+=C/(2+j*F);
			if(P2>P1)break;
			P1=P2;
		}
		printf("Case #%d: %.7lf\n",c,P1);
	}
}
