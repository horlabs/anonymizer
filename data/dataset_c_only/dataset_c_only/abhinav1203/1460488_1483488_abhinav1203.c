#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
  if(*(int*)a<*(int*)b)
    return -1;
  return 1;
}
int numDigits(int num)
{
  int ans=0;
  while(num>0)
    {
      ans++;
      num/=10;
    }
  return ans;
}
int power(int num)
{
  int ans=1,i;
  for(i=0;i<num;i++)
    ans*=10;
  return ans;
}
int main()
{
  int t,a,b,i,j,x,y,ans,tmp[100],test=1;
  scanf("%d",&t);
  while(t--)
    {
      scanf("%d %d",&a,&b);
      ans=0;
      for(i=a;i<=b;i++)
	{
	  tmp[0]=i;
	  x=numDigits(i);
	  y=power(x-1);
	  for(j=1;j<x;j++)
	    {
	      tmp[j]=tmp[j-1]/10+tmp[j-1]%10*y;
	      //if(tmp!=i && tmp>=a && tmp<=b)
	      //ans++;
	    }
	  qsort(tmp,x,sizeof(int),&compare);
	  for(j=0;j<x;j++)
	    if(tmp[j]>=a && tmp[j]<=b && (j==0 || tmp[j]!=tmp[j-1]) && tmp[j]!=i)
	      ans++;
	}
      printf("Case #%d: %d\n",test,ans/2);
      test++;
    }
  return 0;
}
