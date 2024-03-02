#include <stdio.h>

void findIntersection(int firstSet[4], int secondSet[4])
{
    int i, j, count = 0, result = 0, num;
    
    for (i = 0; i < 4; i++)
    {
        num = firstSet[i];
        
        for (j = 0; j < 4; j++)
        {
            if (num == secondSet[j])
            {
                result = num;
                count++;
            }
        }
    }
    
    if (count == 1)
        printf("%d", result);
    else if (count > 1)
        printf("Bad magician!");
    else
        printf("Volunteer cheated!");
}

int main()
{
    int T, n1, n2, firstSet[4], secondSet[4], t, i, j, k, l;
    
    scanf("%d", &T);
    
    for (t = 1; t <= T; t++)
    {
        scanf("%d", &n1);
        
        k = 0;
        
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                scanf("%d", &l);
                
                if (i == n1 - 1)
                {
                    firstSet[k++] = l;
                }
            }
        }
        
        scanf("%d", &n1);
        
        k = 0;
        
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                scanf("%d", &l);
                
                if (i == n1 - 1)
                {
                    secondSet[k++] = l;
                }
            }
        }
        
        printf("Case #%d: ", t);
        
        findIntersection(firstSet, secondSet);
        
        printf("\n");
    }
    
    return 0;
}