#include <stdio.h>
#include <math.h>

int isPalindrome(long long num) {
    char str[100];
    sprintf(str, "%lld", num);
    int i, len;
    len = strlen(str);
    int isPalin = 1;
    for (i = 0; i < len; i++) {
        if (str[i] != str[len - 1 - i]) {
            isPalin = 0;
        }
    }
    return isPalin;
}

int countPalindromeSquares(int A, int B) {
    int ret = 0;
    long long As = sqrt((double)A) - 1;
    long long Bs = sqrt((double)B) + 1;
    if (As < 1) {
        As = 1;
    }
    for (long long n = As; n <= Bs; n++) {
        long long n2 = n * n;
        if (A <= n2 && n2 <= B) {
            if (isPalindrome(n) && isPalindrome(n2)) {
                ret++;
            }
        }
    }
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int A, B;
        scanf("%d %d", &A, &B);
        int count = countPalindromeSquares(A, B);
        printf("Case #%d: %d\n", t, count);
    }
    return 0;
}