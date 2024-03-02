#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 10000001

bool isPalindrome(int number) {
    char str[20];
    sprintf(str, "%d", number);
    int i = 0, j = strlen(str) - 1;
    while (i < j && str[i] == str[j]) {
        i++;
        j--;
    }
    return (i >= j);
}

int main() {
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++) {
        int count = 0;
        long long int a, b;
        scanf("%lld %lld", &a, &b);

        for (long long int i = (long long int)sqrt(a); i * i <= b; i++) {
            if (i * i < a) continue;
            if (isPalindrome(i * i)) {
                count++;
            }
        }

        printf("Case #%d: %d\n", t, count);
    }

    return 0;
}
