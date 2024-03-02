#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 2000000

typedef struct {
    int start;
    int end;
} Range;

Range createRange(int start, int end) {
    Range range;
    range.start = start;
    range.end = end;
    return range;
}

int countPalindromes(Range range) {
    int count = 0;
    for (int i = range.start; i <= range.end; i++) {
        char i_str_org[100];
        sprintf(i_str_org, "%d", i);
        int i_str_len = strlen(i_str_org);
        char i_str[100];
        strcpy(i_str, i_str_org);
        while (1) {
            char c0 = i_str[i_str_len - 1];
            memmove(&i_str[1], &i_str[0], sizeof(char) * (i_str_len - 1));
            i_str[0] = c0;
            if (strcmp(i_str, i_str_org) == 0) break;
            if (i_str[0] == '0') continue;
            int i2 = atoi(i_str);
            if (range.start <= i2 && i2 <= range.end) {
                count++;
            }
        }
    }
    return count;
}

int main(void) {
    int T;
    scanf("%d\n", &T);
    for (int t = 1; t <= T; t++) {
        int A, B;
        scanf("%d %d\n", &A, &B);
        int ret = countPalindromes(createRange(A, B));
        printf("Case #%d: %d\n", t, ret / 2);
    }
    return 0;
}
