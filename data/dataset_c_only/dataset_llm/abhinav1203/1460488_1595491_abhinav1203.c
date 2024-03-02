#include <stdio.h>

#define MAX_SIZE 105

int nums[MAX_SIZE];

int calculateCases(int n, int s, int p)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if ((nums[i] + 2) / 3 >= p)
            count++;
        else if ((nums[i] + 2) / 3 == (p - 1) && s > 0 && nums[i] > 1 && nums[i] % 3 != 1)
        {
            count++;
            s--;
        }
    }
    return count;
}

int main()
{
    int test_cases;
    scanf("%d", &test_cases);

    int test_no = 1;
    while (test_cases--)
    {
        int n, s, p;
        scanf("%d %d %d", &n, &s, &p);

        for (int i = 0; i < n; i++)
            scanf("%d", &nums[i]);

        int result = calculateCases(n, s, p);
        printf("Case #%d: %d\n", test_no, result);

        test_no++;
    }
    return 0;
}