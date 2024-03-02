#include <math.h>
#include <stdio.h>


int broj[10000000 + 1];

int palindrome(long long a) {
    int polje[1000];
    int k = 0, i;

    while (a) {
        polje[k++] = a % 10;
        a /= 10;
    }

    for (i = 0; 2 * i < k - 1; i++)
        if (polje[i] != polje[k - i - 1])
            return 0;

    return 1;
}

int main() {
    long long i;
    int ukupno = 0;
    broj[0] = 0;
    for (i = 1; i <= 10000000; i++) {
        if (palindrome(i) && palindrome(i * i)) {

            ukupno++;
        }
        broj[i] = ukupno;
    }
    int t, T;
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        a = sqrt(a - 1);
        b = sqrt(b);
        printf("Case #%d: %d\n", t, broj[b] - broj[a]);
    }
    return 0;
}
