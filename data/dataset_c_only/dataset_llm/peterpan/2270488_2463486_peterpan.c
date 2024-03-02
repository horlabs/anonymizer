#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define REQUIRE(condition, errorMessage) { if(!(condition)) { fprintf(stderr,"%s\n",errorMessage); exit(-1); } }

char numBuffer[20];

int isPalindrome(int num)
{
    int i, j;

    i = 0;
    while (num)
    {
        numBuffer[i++] = num % 10;
        num /= 10;
    }
    i--;
    for (j = 0; j < i; j++, i--)
    {
        if (numBuffer[j] != numBuffer[i])
        {
            return 0;
        }
    }
    return 1;
}

int isPalindromeLL(long long num)
{
    int i, j;

    i = 0;
    while (num)
    {
        numBuffer[i++] = num % 10;
        num /= 10;
    }
    i--;
    for (j = 0; j < i; j++, i--)
    {
        if (numBuffer[j] != numBuffer[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    long long start, end;
    int numTestCases, testCase, *counts;
    int startApprox, endApprox, i;

    counts = malloc(10000001 * sizeof(int));
    REQUIRE(counts != NULL, "Out of memory!");

    counts[0] = 1;
    for (i = 1; i <= 10000000; i++)
    {
        if (isPalindrome(i) && isPalindromeLL(((long long)i) * i))
        {
            counts[i] = counts[i - 1] + 1;
        }
        else
        {
            counts[i] = counts[i - 1];
        }
    }
    scanf("%d", &numTestCases);
    for (testCase = 1; testCase <= numTestCases; testCase++)
    {
        scanf("%lld %lld", &start, &end);
        startApprox = ceil(sqrt((double)start));
        endApprox = sqrt((double)end);
        printf("Case #%d: %d\n", testCase, counts[endApprox] - counts[startApprox - 1]);
    }
    return 0;
}