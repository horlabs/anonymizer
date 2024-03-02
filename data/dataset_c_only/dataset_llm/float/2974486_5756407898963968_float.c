#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int findDuplicateNumber(int row)
{
    int num[8], count, ans;
    int tmp, r, i;
    
    for (r = 1; r <= 4; r++) {
        if (r == row) {
            scanf("%d %d %d %d", &num[0], &num[1], &num[2], &num[3]);
        } else {
            scanf("%d %d %d %d", &tmp, &tmp, &tmp, &tmp);
        }
    }
    
    qsort(num, 8, sizeof(int), compare);
    
    count = 0;
    for (i = 1; i < 8; i++) {
        if (num[i] == num[i - 1]) {
            count++;
            ans = num[i];
        }
    }
    
    return count == 1 ? ans : -1;
}

int main()
{
    int numTests, testNumber, firstRow, secondRow;
    
    scanf("%d", &numTests);
    
    for (testNumber = 1; testNumber <= numTests; testNumber++) {
        scanf("%d", &firstRow);
        int firstNumber = findDuplicateNumber(firstRow);
        
        scanf("%d", &secondRow);
        int secondNumber = findDuplicateNumber(secondRow);
        
        printf("Case #%d: ", testNumber);
        if (firstNumber == -1 || secondNumber == -1) {
            printf("Volunteer cheated!\n");
        } else if (firstNumber == secondNumber) {
            printf("%d\n", firstNumber);
        } else {
            printf("Bad magician!\n");
        }
    }
    
    return 0;
}