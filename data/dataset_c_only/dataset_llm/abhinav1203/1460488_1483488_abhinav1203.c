#include<stdio.h>
#include<stdlib.h>

int compareNumbers(const void *a, const void *b);
int countDigits(int num);
int powerOfTen(int num);

int main()
{
    int numTests, start, end, i, j, num1, num2, numDigits1, numRepetitions, ans, tmp[100], testNum = 1;
    
    scanf("%d", &numTests);
    
    while(numTests--)
    {
        scanf("%d %d", &start, &end);
        
        ans = 0;
        
        for(i = start; i <= end; i++)
        {
            tmp[0] = i;
            numDigits1 = countDigits(i);
            
            numRepetitions = powerOfTen(numDigits1 - 1);
            
            for(j = 1; j < numDigits1; j++)
            {
                tmp[j] = tmp[j-1] / 10 + tmp[j-1] % 10 * numRepetitions;
            }
            
            qsort(tmp, numDigits1, sizeof(int), compareNumbers);
            
            for(j = 0; j < numDigits1; j++)
            {
                num1 = tmp[j];
                num2 = tmp[j-1];
                
                if(num1 >= start && num1 <= end && (j == 0 || num1 != num2) && num1 != i)
                {
                    ans++;
                }
            }
        }
        
        printf("Case #%d: %d\n", testNum, ans / 2);
        testNum++;
    }
    
    return 0;
}

int compareNumbers(const void *a, const void *b)
{
    if(*(int*)a < *(int*)b)
        return -1;
        
    return 1;
}

int countDigits(int num)
{
    int digitCount = 0;
    
    while(num > 0)
    {
        digitCount++;
        num /= 10;
    }
    
    return digitCount;
}

int powerOfTen(int num)
{
    int power = 1, i;
    
    for(i = 0; i < num; i++)
    {
        power *= 10;
    }
    
    return power;
}