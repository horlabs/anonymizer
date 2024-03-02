#include <stdio.h>

int main()
{
    int T,t;

    scanf("%d",&T);

    for(t=1;t<=T;t++)
    {
        int n,m,i,j;
        int a[100][100];
        int uvjet[100][100]={0};

        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",a[i]+j);

        int max;
        for(i=0;i<n;i++)
        {
            max=0;
            for(j=0;j<m;j++)
                if (a[i][j]>max)
                    max=a[i][j];
            for(j=0;j<m;j++)
                if (a[i][j]==max)
                    uvjet[i][j]=1;
        }

        for(j=0;j<m;j++)
        {
            max=0;
            for(i=0;i<n;i++)
                if(a[i][j]>max)
                    max=a[i][j];
            for(i=0;i<n;i++)
                if (a[i][j]==max)
                    uvjet[i][j]=1;
        }

        printf("Case #%d: ",t);

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                if (!uvjet[i][j])
                    break;
            if (j<m)
                break;
        }

        if (i==n)
            printf("YES");
        else
            printf("NO");
        printf("\n");
    }
}
