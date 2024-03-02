#include <stdio.h>
#include <string.h>
#include <assert.h>


void checkrows(int c, int *a, int *b)
{
   int i,j;
   char answer, count;
   
   count=0;
   for(i=0;i<4;i++)
   {
       for(j=0;j<4;j++)
       {
           //printf("compare %d to %d \n",a[i],b[j]);
           if(a[i] == b[j])
           {
               count++;
               answer=a[i];
           }       
       }
   }
   if(count == 1)
       printf("Case #%d: %d\n",c,answer);
   if(count == 0)
       printf("Case #%d: Volunteer cheated!\n",c);
   if(count > 1)
       printf("Case #%d: Bad magician!\n",c);
}

int main(int argc, char **argv)
{
    int t,i;
    int a[4][4];
    int b[4][4];
    int rowa,rowb;
    
	
    assert (scanf("%d ",&t) == 1); //Number of testcases
    for(i=1;i<=t;i++)
    {
        assert (scanf("%d ",&rowa) == 1);                                    
        assert (scanf("%d%d%d%d ",&a[0][0],&a[0][1],&a[0][2],&a[0][3]) == 4);  
        assert (scanf("%d%d%d%d ",&a[1][0],&a[1][1],&a[1][2],&a[1][3]) == 4);  
        assert (scanf("%d%d%d%d ",&a[2][0],&a[2][1],&a[2][2],&a[2][3]) == 4);  
        assert (scanf("%d%d%d%d ",&a[3][0],&a[3][1],&a[3][2],&a[3][3]) == 4);  

        assert (scanf("%d ",&rowb) == 1);
        assert (scanf("%d%d%d%d ",&b[0][0],&b[0][1],&b[0][2],&b[0][3]) == 4);
        assert (scanf("%d%d%d%d ",&b[1][0],&b[1][1],&b[1][2],&b[1][3]) == 4);
        assert (scanf("%d%d%d%d ",&b[2][0],&b[2][1],&b[2][2],&b[2][3]) == 4);
        assert (scanf("%d%d%d%d ",&b[3][0],&b[3][1],&b[3][2],&b[3][3]) == 4);

        checkrows(i,a[rowa-1],b[rowb-1]);
    }
    return 0;
}
