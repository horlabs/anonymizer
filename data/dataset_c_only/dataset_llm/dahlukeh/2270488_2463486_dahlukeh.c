#include <stdio.h>
#include <stdlib.h>

#define TRUE         1
#define FALSE        0

typedef struct {
    char numSmall[200];
    long long a, b;
} Data;

void handleCase(Data *data);

int isPalindrome(long long num);
long long findPalindromeCount(long long start);
long long getPalindrome(long long base, int digits);
int numDigits(long long num);
void writeNumber(long long num, char *buf);
long long readNumber(char *buf);

int main() {
    freopen("cin.txt", "r", stdin);
    freopen("cout.txt", "w", stdout);

    int caseCount;
    scanf("%d ", &caseCount);

    for (int i = 0; i < caseCount; i++) {
        Data data;
        printf("Case #%d: ", i + 1);
        handleCase(&data);
    }

    return 0;
}

void handleCase(Data *data) {
    scanf("%I64d %I64d ", &(data->a), &(data->b));

    long long result = findPalindromeCount(data->b) - findPalindromeCount(data->a - 1);
    printf("%I64d\n", result);
}

long long findPalindromeCount(long long start) {
    long long total = 0ll;

    for (int digits = 1; ; digits++) {
        long long base = 1ll;

        for (int i = 0; i < ((digits - 1) / 2); i++) {
            base *= 10ll;
        }

        long long end = base * 10ll;

        for (; base < end; base++) {
            long long pal = getPalindrome(base, digits);

            if (pal * pal > start) {
                return total;
            }

            if (isPalindrome(pal * pal)) {
                total++;
            }
        }
    }

    return total;
}

long long getPalindrome(long long base, int digits) {
    writeNumber(base, data->numSmall);

    for (int i = digits - 1; i >= 0; i--) {
        data->numSmall[i] = data->numSmall[digits - i - 1];
    }

    data->numSmall[digits] = '\0';
    return readNumber(data->numSmall);
}

int isPalindrome(long long num) {
    writeNumber(num, data->numSmall);
    int numDig = numDigits(num);

    for (int i = 0; i < numDig; i++) {
        if (data->numSmall[i] != data->numSmall[numDig - i - 1]) {
            return FALSE;
        }
    }

    return TRUE;
}

int numDigits(long long num) {
    int digits = 1;
    long long current = 10ll;

    for (; current <= num; digits++) {
        current *= 10ll;
    }

    return digits;
}

void writeNumber(long long num, char *buf) {
    int numDig = numDigits(num);

    buf[numDig] = '\0';

    for (int i = 0; i < numDig; i++) {
        char dig = (num % 10ll) + '0';
        buf[numDig - i - 1] = dig;
        num /= 10ll;
    }
}

long long readNumber(char *buf) {
    long long num = 0ll;

    for (int i = 0; buf[i] != '\0'; i++) {
        num *= 10ll;
        num += (buf[i] - '0');
    }

    return num;
}