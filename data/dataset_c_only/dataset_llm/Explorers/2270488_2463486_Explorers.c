#include <stdio.h>
#include <math.h>

int isPalindrome(int num);
int isPerfectSquare(int num);

int main() {
    int numberOfTests;
    int results[100] = {0};
    int start, end, squareNum;
    int i, j;
    
    scanf("%d", &numberOfTests);
    
    for (i = 0; i < numberOfTests; i++) {
        scanf("%d %d", &start, &end);
        
        for (j = start; j <= end; j++) {
            if (isPalindrome(j) == 0)
                continue;
            if ((squareNum = isPerfectSquare(j)) == 0)
                continue;
            if (isPalindrome(squareNum) != 0)
                results[i]++;
        }
    }
    
    for (i = 0; i < numberOfTests; i++)
        printf("Case #%d: %d\n", i + 1, results[i]);
    
    return 0;
}

int isPalindrome(int num) {
    int reverse = 0;
    int remainderNum = num;
    
    while (remainderNum != 0) {
        reverse = reverse * 10 + (remainderNum % 10);
        remainderNum /= 10;
    }
    
    if (reverse == num)
        return 1;
    else
        return 0;
}

int isPerfectSquare(int num) {
    double sqrtNum, decimal;
    sqrtNum = sqrt(num);
    
    decimal = sqrtNum - (int)sqrtNum;
    
    if (decimal == 0.0)
        return sqrtNum;
    else
        return 0;
}