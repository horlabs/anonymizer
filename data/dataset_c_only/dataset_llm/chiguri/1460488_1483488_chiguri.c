#include <stdio.h>
#include <string.h>

typedef struct {
    int num;
    int B;
} Parameters;

void update_num(Parameters *params, int A) {
    int j;
    params->num = 1;
    for(j = A / 10; j > 0; j /= 10) {
        params->num *= 10;
    }
}

int rotate_check(int m, Parameters *params) {
    int result = 0;
    int n = m;

    while(1) {
        n = n / params->num + (n % params->num) * 10;
        if(m == n) break;
        if(n > params->B) continue;
        if(m < n) ++result;
    }

    return result;
}

int main(void) {
    int T, A;
    int i, j;
    int result;

    scanf("%d", &T);

    for(i = 1; i <= T; ++i) {
        result = 0;

        scanf("%d %d", &A, &B);

        Parameters params;
        params.B = B;

        update_num(&params, A);

        for(j = A; j < B; ++j) {
            result += rotate_check(j, &params);
        }

        printf("Case #%d: %d\n", i, result);
    }

    return 0;
}