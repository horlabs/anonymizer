#include <stdio.h>
#include <string.h>

#define SIZE 1024

int isSquare(int x) {
    /* Returns 1 if x is a perfect square */
    for (int i = 1; i * i <= x; i++) {
        if (i * i == x) {
            return 1;
        }
    }
    return 0;
}

int countPerfectSquares(int* is, int* count) {
    /* Counts the number of perfect squares from 1 to SIZE */
    int sum = 0;
    for (int i = 1; i <= SIZE; i++) {
        if (isSquare(i)) {
            is[i] = 1;
        }
        count[i] = count[i - 1] + is[i];
        sum += is[i];
    }
    return sum;
}

int main() {
    int is[SIZE] = {0};
    int count[SIZE] = {0};
    int cas_n, cas, A, B;
    
    countPerfectSquares(is, count);
    
    printf("Enter the number of test cases: ");
    scanf("%d", &cas_n);
    
    for (cas = 1; cas <= cas_n; cas++) {
        printf("Enter two numbers (A and B): ");
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d\n", cas, count[B] - count[A - 1]);
    }
    
    return 0;
}