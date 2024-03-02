#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct {
    int start;
    int end;
} Interval;

int isPalindrome(int num) {
    char str[100];
    sprintf(str, "%d", num);
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int nextPalindrome(int num) {
    int next = num + 1;
    while (!isPalindrome(next)) {
        next++;
    }
    return next;
}

int countPalindromeSquares(int a, int b) {
    int lowerBound = ceil(sqrt(a));
    int upperBound = floor(sqrt(b));
    int count = 0;
    int current = lowerBound;
    while (!isPalindrome(current)) {
        current++;
    }
    for (; current <= upperBound; current = nextPalindrome(current)) {
        if (isPalindrome(current * current)) {
            count++;
        }
    }
    return count;
}

int main() {
    int testCases;
    scanf("%d", &testCases);
    for (int t = 1; t <= testCases; t++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int count = countPalindromeSquares(a, b);
        printf("Case #%d: %d\n", t, count);
    }
    return 0;
}