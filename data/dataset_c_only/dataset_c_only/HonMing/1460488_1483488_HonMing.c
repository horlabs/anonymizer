#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t;
    int m, n, p,s;
    int i,j,k;
    int ii;
    int x,y,z;
    int nc;
    int result;
    int a, b;
    char str[100];
    int dup[10];


    scanf("%d", &t);

    for(nc = 1; nc <= t; nc++)
    {
        scanf("%d%d", &a, &b);
        
        int temp;

        if(a < 10)
            k = 0;
        else if (a < 100)
            k = 1;
        else if (a < 1000)
            k = 2;
        else if (a < 10000)
            k = 3;
        else if (a < 100000)
            k = 4;
        else if (a < 1000000)
            k = 5;
        else if (a < 10000000)
            k = 6;


        result = 0;
        if( k > 0)
        {
            for(i = a; i <= b; i++)
            {
                z = 10;
                memset(dup, 0, 10*sizeof(int));
                for (j = 0; j < k; j++)
                {
                    x = i % z;
                    y = i / z;
                    sprintf(str, "%d%d", x,y);
                    temp = atoi(str);
                    if((temp > i) && (temp <= b) && (temp >= a))
                    {
                        int bdup = 0;
                        for(ii = 0;  ii < j; ii++)
                        {
                            if(dup[ii] == temp)
                                bdup = 1;
                        }
                        if(!bdup)
                        {
                            //printf("%d %d\n", temp,i);
                            result++;
                            dup[j] = temp;
                        }
                    }

                    z *= 10;
                }
            }
        }

        printf("Case #%d: %d\n",nc,result);
    }
}
