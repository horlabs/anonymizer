#include<stdio.h>
int main()
{
    unsigned int a,b,temp,temp1=0,count=0,digits=0,tdigit,i=1,j,n=1,T;
    FILE *f1,*f2;
     f1=fopen("C-small-attempt2.in","r");
     f2=fopen("output.txt","w");
     fscanf(f1,"%d",&T);
    while(n<=T)
    {
     fscanf(f1,"%d %d",&a,&b);
     temp=a;
    while(temp!=0)
    {
                             digits++;
                             temp=temp/10;
    }       
    while(a<b)
    {
               tdigit=digits;
               temp1=a;
             while(tdigit!=0)
               {i=1;
                            for(j=1;j<=digits-1;j++)
                            i=i*10;
                            temp1=temp1/10+(temp1%10)*i;
                             tdigit--;
                             if(temp1<=b&&temp1>a)
                             { 
                                                  count++; 
                             }
               }
               
               a++;             
    }
   
   fprintf(f2,"Case #%d: %d\n",n,count);
    n++;
    count=0;
    digits=0;
   }
    fclose(f1);
    fclose(f2);
    return 0;
}
    
