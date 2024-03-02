#include <stdio.h>

void checkRange(int min, int max, int* count) {
    if(min <= 1 && max >= 1)
        (*count)++;
    if(min <= 4 && max >= 4)
        (*count)++;
    if(min <= 9 && max >= 9)
        (*count)++;
    if(min <= 121 && max >= 121)
        (*count)++;
    if(min <= 484 && max >= 484)
        (*count)++;
}

void processCases() {
    int t, i, a, b, count;
    scanf("%d", &t);
    
    for(i = 0; i < t; i++) {
        count = 0;
        scanf("%d %d", &a, &b);
        checkRange(a, b, &count);
        printf("Case #%d: %d\n", i + 1, count);
    }
}

int main() {
    processCases();
    return 0;
}