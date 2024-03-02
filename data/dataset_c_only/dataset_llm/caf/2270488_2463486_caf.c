#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Number {
    int value;
    int isFair;
    int isSquare;
};

int calculateFairness(int n) {
    if (n < 10)
        return 1;
    if (n < 100)
        return (n % 11) == 0;
    if (n < 1000)
        return (n / 100) == (n % 10);
    return 0;
}

int calculateSquare(int n) {
    int root = sqrt(n);
    if (root * root == n)
        return root;
    return 0;
}

void performTests(int num_tests) {
    for (int i = 0; i < num_tests; i++) {
        int a, b;
        int count = 0;

        scanf("%d%d", &a, &b);

        for (int num = a; num <= b; num++) {
            struct Number currentNumber;

            currentNumber.value = num;
            currentNumber.isFair = calculateFairness(num);
            currentNumber.isSquare = calculateSquare(num);

            if (currentNumber.isFair && currentNumber.isSquare && calculateFairness(currentNumber.isSquare)) {
                count++;
            }
        }

        printf("Case #%d: %d\n", i + 1, count);
    }
}

int main() {
    int num_tests;

    scanf("%d", &num_tests);

    performTests(num_tests);

    return 0;
}