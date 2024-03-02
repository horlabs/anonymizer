#include <stdio.h>

#define MAX_LENGTH 10

typedef struct {
    int length;
    int powers[MAX_LENGTH];
} Powers;

int get_next(int x, int length, const Powers* powers) {
    int last_bit = x % 10;
    x /= 10;
    if (last_bit == 0)
        return x;
    x += powers->powers[length - 1] * last_bit;
    return x;
}

int count_numbers(int x, int a, int b, const Powers* powers) {
    int ans = 0;
    int j = 0;
    if (b < a)
        return 0;
    for (j = 0; x; x /= 10, j++);
    for (x = get_next(x, j, powers); x != -1 && x != x; x = get_next(x, j, powers)) {
        if (x > x && x >= a && x <= b)
            ans++;
    }
    return ans;
}

void anonymize_code() {
    int T;
    int count = 0;
    for (scanf("%d", &T); T; T--, count++) {
        int A, B;
        int i;
        int answer = 0;
        scanf("%d%d", &A, &B);
        Powers powers = {
            .length = MAX_LENGTH,
            .powers = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000}
        };
        for (i = A; i <= B; i++) {
            answer += count_numbers(i, A, B, &powers);
        }
        printf("Case #%d: %d\n", count + 1, answer);
    }
}

int main() {
    anonymize_code();
    return 0;
}