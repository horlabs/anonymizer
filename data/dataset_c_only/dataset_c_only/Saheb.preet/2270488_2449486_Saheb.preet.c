#include<stdio.h>

int main()
{
  int t,i,j,k,ground[101][101],n,m,rowmax[100],columnmax[100];
  scanf("%d",&t);
  for (i=0;i<t;i++)
  {
    scanf("%d%d",&n,&m);
    for (j=0;j<n;j++)
      rowmax[j]=0;
    for (k=0;k<m;k++)
      columnmax[k]=0;
    for (j=0;j<n;j++)
    {      
      for (k=0;k<m;k++)
      {
	scanf("%d",&ground[j][k]);
	if (ground[j][k]>rowmax[j])
	  rowmax[j]=ground[j][k];
	if (ground[j][k]>columnmax[k])
	  columnmax[k]=ground[j][k];
      }
    }
    for (j=0;j<n;j++)
    {
      for (k=0;k<m;k++)
      {
	if (ground[j][k]!=rowmax[j]&&ground[j][k]!=columnmax[k])
	  break;
      }
      if (k!=m)
	break;
    }
    if (j!=n)
      printf("Case #%d: NO\n",i+1);
    else
      printf("Case #%d: YES\n",i+1);
  }
  return 0;
}