#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    if (*(int *)a > *(int *)b) return -1;
    if (*(int *)a < *(int *)b) return 1;
    return 0;
}

void readInput(int *T, int *n, int *s, int *p, int *score) {
    scanf("%d", T);
    while (*T--) {
        scanf("%d %d %d", n, s, p);
        for (int i = 0; i < *n; i++) {
            scanf("%d", &score[i]);
        }
    }
}

int calculateScore(int n, int s, int p, int *score) {
    qsort(score, n, sizeof(int), compare);
    int threshold1 = p - 1;
    int threshold2 = p - 2;
    if (threshold1 < 0) threshold1 = 0;
    if (threshold2 < 0) threshold2 = 0;
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (score[i] >= p + threshold1 + threshold1) {
            ans++;
        } else if (s && score[i] >= p + threshold2 + threshold2) {
            ans++;
            s--;
        }
    }
    return ans;
}

void printResult(int caseno, int ans) {
    printf("Case #%d: %d\n", caseno, ans);
}

int main() {
    int T, caseno = 1;
    int n, s, p;
    int score[100];
    
    readInput(&T, &n, &s, &p, score);
    int ans = calculateScore(n, s, p, score);
    printResult(caseno++, ans);
    
    return 0;
}