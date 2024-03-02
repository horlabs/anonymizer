#include <stdio.h>
#include <string.h>

#define MAX_SIZE 2000010

int numbers[MAX_SIZE];

void findPalindromePairs(int A, int B)
{
    memset(numbers, 0, sizeof(numbers));
    int result = 0;
    int bits = 1;

    for (int i = 1; i < 10; i++)
    {
        bits *= 10;
        if (A / bits == 0)
            break;
    }
    bits /= 10;

    int flag = i;
    for (int i = A; i <= B; i++)
    {
        int num = 1;
        int tmp1 = i;
        numbers[tmp1] = 1;

        for (int j = 0; j < flag; j++)
        {
            int tmp2 = bits * (tmp1 % 10) + tmp1 / 10;
            
            if (tmp2 == tmp1)
                break;

            if (tmp2 <= B && tmp2 >= A && !numbers[tmp2])
            {
                num++;
                numbers[tmp2] = 1;
            }
            tmp1 = tmp2;
        }
        result += (num - 1) * num / 2;
    }
    printf("Case #%d: %d\n", t, result);
}

int main()
{
    int testCase;
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    scanf("%d", &testCase);

    for (int t = 1; t <= testCase; t++)
    {
        int A, B;
        scanf("%d %d", &A, &B);
        findPalindromePairs(A, B);
    }

    return 0;
}