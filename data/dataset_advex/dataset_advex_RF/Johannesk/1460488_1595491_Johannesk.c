#include <assert.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {
    int t, i, j, n, s, p, count, score;
    int googlers[101];
    char best[] = {0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10};
    char suprise[] = {0, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10, 10};

    assert(scanf("%d ", &t) == 1);
    for (i = 1; i <= t; i++) {
        assert(scanf("%d %d %d", &n, &s, &p) == 3);
        for (j = 0; j < n; j++)
            assert(scanf("%d", &googlers[j]) == 1);
        count = 0;
        for (j = 0; j < n; j++) {
            score = googlers[j];
            if (best[score] >= p)
                count++;
            else if ((suprise[score] >= p) && (s > 0)) {
                count++;
                s--;
            }
        }
        printf("Case #%d: %d\n", i, count);
    }
    return 0;
}
