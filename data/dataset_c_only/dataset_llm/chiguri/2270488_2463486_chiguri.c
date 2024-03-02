#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a number is a palindrome
int isPalindrome(int number) {
    char digits[10];
    sprintf(digits, "%d", number);
    int length = strlen(digits) - 1;
    for (int i = 0; i <= length - i; ++i) {
        if (digits[i] != digits[length - i]) {
            return 0;
        }
    }
    return 1;
}

// Function to count the number of palindromic squares within a range
int countPalindromicSquares(int start, int end) {
    int count = 0;
    int sqrt_start = (int)sqrt((double)start);
    int sqrt_end = (int)sqrt((double)end);
    for (int i = sqrt_start; i <= sqrt_end; ++i) {
        if (isPalindrome(i)) {
            int square = i * i;
            if (start <= square && square <= end && isPalindrome(square)) {
                ++count;
            }
        }
    }
    return count;
}

int main(void) {
    int testCases;
    scanf("%d", &testCases);
    for (int caseNumber = 1; caseNumber <= testCases; ++caseNumber) {
        int start, end;
        scanf("%d %d", &start, &end);
        int result = countPalindromicSquares(start, end);
        printf("Case #%d: %d\n", caseNumber, result);
    }
    return 0;
}