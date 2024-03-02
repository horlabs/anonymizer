#include <stdio.h>

int is_palindrome(int num) {
    char s[21] = {};
    int c = 0;
    long long j = (long long)num * num;

    while (j) {
        s[c++] = j % 10 + '0';
        j /= 10;
    }

    char ss[21] = {};
    j = num, c = 0;
    while (j) {
        ss[c++] = j % 10 + '0';
        j /= 10;
    }

    long long sq = 0;
    sscanf(s, "%lld", &sq);
    long long n = 0;
    sscanf(ss, "%lld", &n);

    return sq == n;
}

int main() {
    int t;
    scanf("%d", &t);
    
    int cnt = 0;
    long long num[39];
    for (int i = 1; i <= 2001002; ++i) {
        if (is_palindrome(i)) {
            num[cnt++] = (long long)i * i;
        }
    }

    for (int u = 1; u <= t; ++u) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        
        int x = 0, y = 0, l = 0, r = 39;
        while (l < r) {
            int m = (l + r) / 2;
            if (num[m] == a) {
                l = m;
                break;
            } else if (num[m] < a) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        x = l;

        l = 0, r = 39;
        while (l < r) {
            int m = (l + r) / 2;
            if (num[m] <= b) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        y = l;

        printf("Case #%d: %d\n", u, y - x);
    }
    return 0;
}