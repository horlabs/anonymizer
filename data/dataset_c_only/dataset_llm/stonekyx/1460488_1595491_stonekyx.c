#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int total[200];
} Numbers;

void readNumbers(Numbers *numbers, int T) {
    int i;
    for (i = 0; i < T; i++) {
        scanf("%d", &numbers->total[i]);
    }
}

int calculateCases(Numbers *numbers, int N, int S, int P) {
    int i;
    int ans = 0;
    int rest = S;
    for (i = 0; i < N; i++) {
        int cur = numbers->total[i];
        switch (cur % 3) {
            case 0:
                if (cur / 3 >= P) {
                    ans++;
                    break;
                }
                else if (rest && cur / 3 >= 1 && cur / 3 + 1 >= P) {
                    ans++;
                    rest--;
                    break;
                }
                break;
            case 1:
                if (cur / 3 + 1 >= P) {
                    ans++;
                }
                break;
            case 2:
                if (cur / 3 + 1 >= P) {
                    ans++;
                    break;
                }
                else if (rest && cur / 3 + 2 >= P) {
                    ans++;
                    rest--;
                    break;
                }
                break;
            default:
                fprintf(stderr, "This should not happen!\n");
                exit(1);
        }
    }
    return ans;
}

void printResult(int T, int cnt, int ans) {
    printf("Case #%d: %d\n", cnt + 1, ans);
}

int main() {
    int T, N, S, P;
    int cnt = 0;
    Numbers numbers;

    scanf("%d", &T);
    for (; T; T--, cnt++) {
        scanf("%d%d%d", &N, &S, &P);
        readNumbers(&numbers, N);
        int ans = calculateCases(&numbers, N, S, P);
        printResult(T, cnt, ans);
    }
    return 0;
}