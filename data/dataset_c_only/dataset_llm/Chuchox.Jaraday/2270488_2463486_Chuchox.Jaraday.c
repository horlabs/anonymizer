#include <stdio.h>
#include <math.h>

typedef struct {
    long long first;
    long long second;
} Pair;

int isPalindrome(long long n);

Pair readInput() {
    Pair inputs;
  
    scanf("%lld", &inputs.first);
    scanf("%lld %lld", &inputs.second);
  
    return inputs;
}

void printOutput(int caseNumber, long long result) {
    printf("Case #%d: %lld\n", caseNumber, result);
}

int main(void) {
    int numCases;
    scanf("%d", &numCases);
  
    for (int caseNum = 1; caseNum <= numCases; caseNum++) {
        Pair inputs = readInput();

        long long min = sqrt(inputs.first);
        long long max = sqrt(inputs.second);

        if (min * min < inputs.first) {
            min++;
        }

        long long count = 0;
        for (long long i = min; i <= max; i++) {
            if (isPalindrome(i) && isPalindrome(i * i)) {
                count++;
            }
        }

        printOutput(caseNum, count);
    }
}

int isPalindrome(long long n) {
    long long digits[110];
    long long i = 0;

    while (n) {
        digits[i] = n % 10;
        n /= 10;
        i++;
    }

    long long total = i - 1;
    i = 0;
    while (i <= (total - i)) {
        if (digits[i] != digits[total - i]) {
            return 0;
        }
        i++;
    }

    return 1;
}