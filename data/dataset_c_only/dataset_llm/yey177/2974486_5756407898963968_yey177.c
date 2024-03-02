#include <stdio.h>

#define MAX_NUMS 4

void readInput(int num, int arr[]) {
    int i;
    for (i = 0; i < MAX_NUMS; i++) {
        scanf("%d", &arr[i]);
    }
}

int checkMatch(int num, int arr[], int temp) {
    int i;
    for (i = 0; i < MAX_NUMS; i++) {
        if (arr[i] == temp) {
            if (num == 0) {
                return temp;
            } else {
                return -1;
            }
        }
    }
    return 0;
}

void solve(int t) {
    int c, n, i, j, k, tmp, res, arr[MAX_NUMS];

    for (c = 1; c <= t; c++) {
        res = 0;
        scanf("%d", &n);

        for (i = 1; i <= MAX_NUMS; i++) {
            for (j = 0; j < MAX_NUMS; j++) {
                if (i == n) {
                    scanf("%d", &arr[j]);
                } else {
                    scanf("%*d");
                }
            }
        }

        scanf("%d", &n);

        for (i = 1; i <= MAX_NUMS; i++) {
            for (j = 0; j < MAX_NUMS; j++) {
                if (i == n) {
                    scanf("%d", &tmp);
                    res = checkMatch(res, arr, tmp);
                    if (res != 0) {
                        break;
                    }
                } else {
                    scanf("%*d");
                }
            }
        }
        printf("Case #%d: ", c);

        if (res == 0) {
            puts("Volunteer cheated!");
        } else if (res == -1) {
            puts("Bad magician!");
        } else {
            printf("%d\n", res);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    solve(t);
    return 0;
}