#include <stdio.h>

#define MAX_NUMBERS 17

void readNumbers(int *possibleNumbers)
{
    int i, j;
    int row, number;
    scanf("%d", &row);
    row--;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &number);
            if (row == i)
            {
                possibleNumbers[number]++;
            }
        }
    }
}

int main()
{
    int numTestCases, testCase;
    scanf("%d", &numTestCases);

    for (testCase = 1; testCase <= numTestCases; testCase++)
    {
        int possibleNumbers[MAX_NUMBERS] = {0};

        readNumbers(possibleNumbers);
        readNumbers(possibleNumbers);

        int i, chosenNumber, count = 0;
        for (i = 1; i < MAX_NUMBERS; i++)
        {
            if (possibleNumbers[i] == 2)
            {
                chosenNumber = i;
                count++;
            }
        }

        printf("Case #%d: ", testCase);
        if (count == 0)
            printf("Volunteer cheated!");
        if (count == 1)
            printf("%d", chosenNumber);
        if (count > 1)
            printf("Bad magician!");
        printf("\n");
    }
    return 0;
}