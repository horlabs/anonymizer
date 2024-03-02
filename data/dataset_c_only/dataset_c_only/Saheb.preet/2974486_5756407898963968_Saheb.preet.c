#include<stdio.h>

int main()
{
    int t,a,b,magic[4],i,j,temp,k,l;
    scanf("%d",&t);
    for (i=0;i<t;i++)
    {
	scanf("%d",&a);
	for (j=0;j<(a-1)*4;j++)
	  scanf("%d",&temp);
	for (;j<4*a;j++)
	  scanf("%d",&magic[j-(a-1)*4]);
	for (;j<16;j++)
	   scanf("%d",&temp);
	scanf("%d",&a);
	for (j=0;j<(a-1)*4;j++)
	  scanf("%d",&temp);
	l=-1;
	for (;j<a*4;j++)
	{
	    scanf("%d",&temp);
	    for(k=0;k<4;k++)
	    if(temp==magic[k])
	      if (l==-1)
		l=magic[k];
	      else
		l=0;
	}
	for (;j<16;j++)
	  scanf("%d",&temp);
	printf("Case #%d: ",i+1);
	switch(l)
	{
	  case -1:
	    puts("Volunteer cheated!");
	    break;
	  case 0:
	    puts("Bad magician!");
	    break;
	  default:
	    printf("%d\n",l);
	}
    }
    return 0;
}
