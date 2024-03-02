#include <stdio.h>

#define MAX_NUM 10000000

int mark[MAX_NUM];

int getDigits(int n)
{
    int digits[10] = {0};
    int result, i;

    while (n)
    {
        digits[n % 10]++;
        n /= 10;
    }

    result = 0;
    for (i = 9; i >= 0; i--)
    {
        while (digits[i]--)
        {
            result = 10 * result + i;
        }
    }
    return result;
}

int main()
{
    int numTestCases, currentTestCase;

    scanf("%d", &numTestCases);

    for (currentTestCase = 1; currentTestCase <= numTestCases; currentTestCase++)
    {
        int x, a, b, totalCount = 0;
        int numDigits = 0;
        int maxDivisor = 1;
        scanf("%d %d", &a, &b);
        int tempA = a;

        while (tempA)
        {
            numDigits++;
            maxDivisor *= 10;
            tempA /= 10;
        }
        maxDivisor /= 10;

        for (x = a; x <= b; x++)
        {
            int queue[10];
            int countQueue = 0;
            int i;

            tempA = x;
            for (i = 0; i < numDigits; i++)
            {
                tempA = maxDivisor * (tempA % 10) + tempA / 10;
                if (tempA < x && !mark[tempA] && tempA >= a && tempA <= b)
                {
                    mark[tempA] = 1;
                    queue[countQueue++] = tempA;
                    totalCount++;
                }
            }
            for (i = 0; i < countQueue; i++)
            {
                mark[queue[i]] = 0;
            }
        }
        printf("Case #%d: %d\n", currentTestCase, totalCount);
    }

    return 0;
}
