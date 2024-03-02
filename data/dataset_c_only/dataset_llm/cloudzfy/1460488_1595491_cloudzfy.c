#include <stdio.h>

typedef struct {
    int N;
    int S;
    int P;
    int x;
} Testcase;

void input(Testcase *tc) {
    scanf("%d%d%d", &(tc->N), &(tc->S), &(tc->P));
}

void process(Testcase *tc) {
    int result = 0;
    
    for (int i = 0; i < tc->N; i++) {
        scanf("%d", &(tc->x));
        
        if ((tc->x) >= (tc->P * 3 - 2) && (tc->P - 1) >= 0) {
            result++;
        } else if ((tc->x) >= (tc->P * 3 - 4) && (tc->S > 0) && (tc->P - 2) >= 0 && (tc->x) <= 28) {
            result++;
            (tc->S)--;
        }
    }
    
    printf("Case #%d: %d\n", t, result);
}

int main() {
    freopen("B-small-attempt4.in", "r", stdin);
    freopen("B-small-attempt4.out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        Testcase tc;
        input(&tc);
        process(&tc);
    }
    
    return 0;
}