#include<stdio.h>

int countPalindromePairs(int a, int b) {
    int ten = 10;
    int count = 0;
    for (int j = a; j < b; ++j) {
        int lc = 0;
        int k = j;
        while (1) {
            k = k % ten * 10 + k / ten;
            if (k == j) {
                break;
            }
            if (k > j && k <= b) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1 ; i <= t ; ++i) {
        printf("Case #%d: ", i);
        int a, b;
        scanf("%d%d", &a, &b);
        int result = countPalindromePairs(a, b);
        printf("%d\n", result);
    }
    return 0;
}