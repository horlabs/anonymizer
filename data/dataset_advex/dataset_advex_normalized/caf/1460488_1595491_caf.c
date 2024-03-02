#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void do_test(int t) {
    int i;
    int n, s, p;
    int thresh_norm, thresh_surprise;
    int y = 0;

    scanf("%d %d %d", &n, &s, &p);

    thresh_norm = p > 0 ? 3 * p - 2 : 0;
    thresh_surprise = p > 1 ? 3 * p - 4 : p;

    for (i = 0; i < n; i++) {
        int total;
        scanf("%d", &total);


        if (p > 10)
            continue;

        if (total >= thresh_norm) {

            y++;
        } else if (s > 0 && total >= thresh_surprise) {

            y++;
            s--;
        }
    }

    printf("Case #%d: %d\n", t + 1, y);
}

int main() {
    int t, i;

    scanf("%d", &t);

    for (i = 0; i < t; i++)
        do_test(i);

    return 0;
}
