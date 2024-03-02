#include <stdio.h>
#include <math.h>

#define MAX 10000000

typedef struct {
    int numbers[MAX+1];
} Numbers;

int isPalindrome(long long number) {
    int digits[1000];
    int k = 0, i;

    while(number) {
        digits[k++] = number % 10;
        number /= 10;
    }

    for(i = 0; 2 * i < k - 1; i++) {
        if(digits[i] != digits[k - i - 1])
            return 0;
    }

    return 1;
}

void calculatePalindromicNumbers(Numbers* numbers) {
    long long i;
    int count = 0;
    numbers->numbers[0] = 0;

    for(i = 1; i <= MAX; i++) {
        if(isPalindrome(i) && isPalindrome(i * i)) {
            //printf("%lld %lld\n", i, i * i);
            count++;
        }

        numbers->numbers[i] = count;
    }
}

int main() {
    int t, T;
    scanf("%d", &T);

    Numbers numbers;
    calculatePalindromicNumbers(&numbers);

    for(t = 1; t <= T; t++) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        a = sqrt(a - 1);
        b = sqrt(b);
        printf("Case #%d: %d\n", t, numbers.numbers[b] - numbers.numbers[a]);
    }

    return 0;
}