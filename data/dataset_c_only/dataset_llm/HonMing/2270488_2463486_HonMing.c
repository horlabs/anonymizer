#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 200
#define MAX_DP_SIZE 10000

typedef unsigned long long int ull;

ull dp[MAX_DP_SIZE];

int isPalindrome(ull n) {
    char line[MAX_LENGTH];
    sprintf(line, "%llu", n);
    
    int len = strlen(line);
    for(int i = 0; i < len / 2; i++) {
        if(line[i] != line[len-1-i])
            return 0;
    }
    return 1;
}

void generatePalindromes() {
    int j = 0;
    for(ull i = 1; i <= 10000000; i++) {
        if(isPalindrome(i) && isPalindrome(i*i))
            dp[j++] = i * i;
    }
}

int countPalindromesInRange(ull a, ull b) {
    int count = 0;
    for(int i = 0; dp[i] <= b && i < MAX_DP_SIZE; i++) {
        if(dp[i] >= a && dp[i] <= b)
            count++;
    }
    return count;
}

void processTestCases(int mm) {
    for(int ii = 1; ii <= mm; ii++) {
        int result = 0;
        ull a, b;
        scanf("%llu %llu", &a, &b);
        
        result = countPalindromesInRange(a, b);
        
        printf("Case #%d: %d\n", ii, result);
    }
}

int main() {
    generatePalindromes();
    
    int t;
    scanf("%d", &t);
    
    processTestCases(t);

    return 0;
}