#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j;
    int ii,jj,kk;
    int res;
    int m;
    char map[10][10];
    int end, xw, ow;

    unsigned long long result;

    scanf("%d", &m);

    for(ii = 1; ii <= m; ii++)
    {
        end = 1;
        xw = 0;
        ow = 0;
        memset(map, 0, 100);
        result = 0;
        for(i = 0; i < 4; i++)
        {
            scanf("%s", map[i]);
        }

        for(i = 0; i < 4; i++)
        {
            for(j = 0; j < 4; j++)
            {
                if(map[i][j] == '.')
                    break;
            }
            if( j != 4)
                break;
        }
        if( i != 4 && j != 4)
            end = 0;
        // check horizontal & vertial
        for(i = 0; i < 4; i++)
        {
            for(j = 0; j < 4; j++)
            {
                if(map[i][j] != 'O' && map[i][j] != 'T')
                    break;
            }
            if(j == 4)
                ow = 1;
            for(j = 0; j < 4; j++)
            {
                if(map[i][j] != 'X' && map[i][j] != 'T')
                    break;
            }
            if(j == 4)
                xw = 1;
            for(j = 0; j < 4; j++)
            {
                if(map[j][i] != 'O' && map[j][i] != 'T')
                    break;
            }
            if(j == 4)
                ow = 1;
            for(j = 0; j < 4; j++)
            {
                if(map[j][i] != 'X' && map[j][i] != 'T')
                    break;
            }
            if(j == 4)
                xw = 1;
        }

        // check diagonal 
        for(i = 0; i < 4; i++)
        {
            if(map[i][i] != 'X' && map[i][i] != 'T')
                break;
        }
        if(i == 4)
            xw = 1;
        
        for(i = 0; i < 4; i++)
        {
            if(map[3-i][i] != 'X' && map[3-i][i] != 'T')
                break;
        }
        if(i == 4)
            xw = 1;

        for(i = 0; i < 4; i++)
        {
            if(map[i][i] != 'O' && map[i][i] != 'T')
                break;
        }
        if(i == 4)
            ow = 1;
        
        for(i = 0; i < 4; i++)
        {
            if(map[3-i][i] != 'O' && map[3-i][i] != 'T')
                break;
        }
        if(i == 4)
            ow = 1;
        
        if(xw == 1)
            printf("Case #%d: X won\n", ii);
        else if(ow == 1)
            printf("Case #%d: O won\n", ii);
        else if(end == 1)
            printf("Case #%d: Draw\n", ii);
        else 
            printf("Case #%d: Game has not completed\n", ii);
    }
}
