#include <stdio.h>

typedef struct {
    int digits[20];
} Number;

int isPalindrome(Number n) {
    int i;
    
    for (i = 0; i < 10; i++) {
        if (n.digits[i] != n.digits[19 - i]) return 0;
    }
    
    return 1;
}

Number separateDigits(long long x) {
    Number n;
    int i;
    
    for (i = 0; i < 20; i++) {
        n.digits[i] = x % 10;
        x /= 10;
    }
    
    return n;
}

int main() {
    int count = 0, t, i;
    long long palindromeSquares[100];
    
    for (i = 1; i <= 10000000; i++) {
        Number num = separateDigits(i);
        
        if (isPalindrome(num)) {
            long long square = (long long)i * i;
            
            if (isPalindrome(separateDigits(square))) {
                palindromeSquares[count++] = square;
            }
        }
    }
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int sum = 0, j;
        long long x, y;
        
        scanf("%lld %lld", &x, &y);
        
        for (j = 0; j < count; j++) {
            if (palindromeSquares[j] >= x && palindromeSquares[j] <= y) sum++;
        }
        
        printf("Case #%d: %d\n", i + 1, sum);
    }
    
    return 0;
}