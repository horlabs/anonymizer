#include <stdio.h>

#define MAX_TESTS 41

long long squareNumbers[MAX_TESTS] = {
    0LL, 1LL, 2LL, 3LL, 11LL, 22LL, 
    101LL, 111LL, 121LL, 202LL, 212LL, 
    1001LL, 1111LL, 2002LL, 10001LL, 10101LL, 
    10201LL, 11011LL, 11111LL, 11211LL, 20002LL, 
    20102LL, 100001LL, 101101LL, 110011LL, 111111LL, 200002LL, 
    1000001LL, 1001001LL, 1002001LL, 1010101LL, 1011101LL, 
    1012101LL, 1100011LL, 1101011LL, 1102011LL, 1110111LL, 
    1111111LL, 2000002LL, 2001002LL, 10000001LL
};

int countPalindromeSquares(long long start, long long end) {
    int count = 0;
    for (int i = 0; i < MAX_TESTS; i++) {
        if (squareNumbers[i] >= start && squareNumbers[i] <= end) {
            count++;
        }
    }
    return count;
}

int main() {
    int testCases;
    long long a, b;
    
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C_out.txt", "w", stdout);
    
    scanf("%d", &testCases);
    
    for (int i = 0; i < MAX_TESTS; i++) {
        squareNumbers[i] *= squareNumbers[i];
    }
    
    for (int testCase = 1; testCase <= testCases; testCase++) {
        scanf("%lld%lld", &a, &b);
        int count = countPalindromeSquares(a, b);
        printf("Case #%d: %d\n", testCase, count);
    }
    
    return 0;
}