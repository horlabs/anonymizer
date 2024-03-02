#include<stdio.h>

int main()
{
  int t,i,a,b,count;
  scanf("%d",&t);
  for (i=0;i<t;i++)
  {
    count=0;
    scanf("%d%d",&a,&b);
    if (a<=1&&b>=1)
      count++;
    if (a<=4&&b>=4)
      count++;
    if (a<=9&&b>=9)
      count++;
    if (a<=121&&b>=121)
      count++;
    if(a<=484&&b>=484)
      count++;
    printf("Case #%d: %d\n",i+1,count);
  }
  return 0;
}