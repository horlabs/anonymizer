#include <stdio.h>
#include <stdlib.h>

int getNextNumber(int n) {
    int x = 1;
    while (n/x >= 10)
        x *= 10;
    while (n%10 == 0)
        n = n/10;
    n = n/10 + (n%10)*x;
    return n;
}

int countSpecialNumbers(int a, int b) {
    int ans = 0;
    for (int j = a; j <= b; j++) {
        int tmp = j;
        do {
            tmp = getNextNumber(tmp);
            if (tmp > j && tmp >= a && tmp <= b)
                ans++;
        } while (tmp != j);
    }
    return ans;
}

int main() {
    int cas;
    scanf("%d", &cas);
    for (int i = 1; i <= cas; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        int ans = countSpecialNumbers(a, b);
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}