#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 10

int pairCount(int n);
void handleCase();

int main() {
    int n;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        printf("Case #%d: ", i + 1);
        handleCase();
    }
    return 0;
}

void handleCase() {
    int a, b;
    scanf("%d %d ", &a, &b);
    int total = 0;
    int digits = 0;
    int temp = a;
    while (temp > 0) {
        temp /= 10;
        digits++;
    }
    for (int i = a; i <= b; i++) {
        total += pairCount(i, b, digits);
    }
    printf("%d\n", total);
}

int pairCount(int n, int limit, int digits) {
    int others[MAX_DIGITS];
    int count = 0;
    int curN = n;
    int multiplier = 1;
    for (int i = 0; i < digits - 1; i++) {
        multiplier *= 10;
    }
    for (int i = 0; i < digits; i++) {
        int front = curN % 10;
        int back = curN / 10;
        curN = front * multiplier + back;
        if (curN > n && curN <= limit) {
            int valid = TRUE;
            for (int j = 0; j < count && valid; j++) {
                if (curN == others[j]) {
                    valid = FALSE;
                }
            }
            if (valid) {
                others[count] = curN;
                count++;
            }
        }
    }
    return count;
}