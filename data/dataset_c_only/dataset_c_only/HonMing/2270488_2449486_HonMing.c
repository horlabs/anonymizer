#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j;
    int ii,jj,kk;
    int res;
    int mm;
    int end, xw, ow;
    int n, m;
    int max;
    int map[200][200];
    int dp[200][200];

    unsigned long long result;

    scanf("%d", &mm);

    for(ii = 1; ii <= mm; ii++)
    {
        memset(dp, 0, 200 * 200);
        scanf("%d%d", &n, &m);
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                scanf("%d", &map[i][j]);
                dp[i][j] = 200;
            }
        }

        for(i = 0; i < n; i++)
        {
            max = 0;
            for(j = 0; j < m; j++)
            {
                if(map[i][j] > max)
                    max = map[i][j];
            }
            for(j = 0; j < m; j++)
            {
                if(max < dp[i][j])
                    dp[i][j] = max;
            }
        }
        for(i = 0; i < m; i++)
        {
            max = 0;
            for(j = 0; j < n; j++)
            {
                if(map[j][i] > max)
                    max = map[j][i];
            }
            for(j = 0; j < n; j++)
            {
                if(max < dp[j][i])
                    dp[j][i] = max;
            }
        }
        /*
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
                printf("%d ", dp[i][j]);
            printf("\n");
        }
        */
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
                if(dp[i][j] != map[i][j])
                    break;

            if(j != m)
                break;
        }
        
        if(i != n)
            printf("Case #%d: NO\n", ii);
        else
            printf("Case #%d: YES\n", ii);
    }
}
