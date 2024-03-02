#include <stdio.h>

typedef long Number;

Number calculatePair(Number n);
int countPairs(Number a, Number b);

int main()
{
    int numOfTestCases, i;
    scanf("%d", &numOfTestCases);
    
    for (i = 0; i < numOfTestCases; i++)
    {
        Number a, b;
        scanf("%ld %ld", &a, &b);
        int numPairs = countPairs(a, b);
        printf("Case #%d: %d\n", i + 1, numPairs);
    }
    
    return 0;
}

Number calculatePair(Number n)
{
    int numDigits = 0;
    Number result = 0;
    Number temp = n;
    
    while (temp != 0)
    {
        temp /= 10;
        numDigits++;
    }
    
    int k;
    for (k = numDigits - 1; k >= 1; k--)
    {
        Number multiplier = pow(10, k);
        Number divider = pow(10, numDigits - k);
        
        Number divisor = n / divider;
        Number remainder = n % divider;
        Number pairNum = remainder * multiplier + divisor;
        
        if (numlen(pairNum) != numDigits)
            continue;
        
        if (pairNum > n && pairNum <= b)
        {
            result++;
        }
    }
    
    return result;
}

int countPairs(Number a, Number b)
{
    int i, numPairs = 0;
    for (i = a; i < b; i++)
    {
        numPairs += calculatePair(i);
    }
    
    return numPairs;
}

int numlen(Number n)
{
    if (n < 10)
        return 1;
    else
        return 1 + numlen(n / 10);
}