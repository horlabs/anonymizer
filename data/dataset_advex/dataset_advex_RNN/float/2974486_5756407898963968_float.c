#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int T, t, row, r, tmp, i;
    int num[8], count, ans;
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        count = 0;
        scanf("%d", &row);
        for (r = 1; r <= 4; r++) {
            if (r == row) {
                scanf("%d %d %d %d", &num[0], &num[1], &num[2], &num[3]);
            } else {
                scanf("%d %d %d %d", &tmp, &tmp, &tmp, &tmp);
            }
        }
        scanf("%d", &row);
        for (r = 1; r <= 4; r++) {
            if (r == row) {
                scanf("%d %d %d %d", &num[4], &num[5], &num[6], &num[7]);
            } else {
                scanf("%d %d %d %d", &tmp, &tmp, &tmp, &tmp);
            }
        }
        qsort(num, 8, sizeof(int), cmp);
        for (i = 1; i < 8; i++) {
            if (num[i] == num[i - 1]) {
                count++;
                ans = num[i];
            }
        }
        printf("Case #%d: ", t);
        switch (count) {
            case 1:
                printf("%d\n", ans);
                break;
            case 0:
                printf("Volunteer cheated!\n");
                break;
            default:
                printf("Bad magician!\n");
                break;
        }
    }
    return 0;
}
