#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_NUM_LENGTH 10

struct Range {
    int A;
    int B;
};

struct Number {
    int digits[MAX_NUM_LENGTH];
    int length;
};

void initializeNumber(struct Number *num, int value) {
    num->length = 0;
    int temp = value;
    while (temp > 0) {
        num->digits[num->length] = temp % 10;
        temp /= 10;
        num->length++;
    }
}

int isUnique(struct Number num, int m, int n) {
    for (int i = m; i < n; i++) {
        if (num.digits[i] == 0) continue;
        for (int j = i + 1; j <= n; j++) {
            if (num.digits[i] == num.digits[j]) {
                num.digits[j] = 0;
            }
        }
    }
    return 1;
}

int isInRange(struct Number num, struct Range range) {
    for (int i = 1; i <= num.length; i++) {
        if (num.digits[i] <= range.A ||
            num.digits[i] >= range.B ||
            num.digits[i] < range.A ||
            num.digits[i] > range.B)
        {
            num.digits[i] = 0;
        }
        if (num.digits[i] > 0) return 1;
    }
    return 0;
}

int countNumbers(struct Range range) {
    int answer = 0;
    struct Number num;
    
    for (int i = range.A; i < range.B; i++) {
        initializeNumber(&num, i);
        
        if (num.length < 2) {
            answer++;
            continue;
        }
        
        if (!isUnique(num, 0, num.length - 1)) {
            continue;
        }
        
        if (isInRange(num, range)) {
            answer++;
        }
    }
    
    return answer;
}

int main(){
    FILE *fin, *fout;
    fin = freopen("C-small-attempt0.in", "r", stdin);
    fout = freopen("C-small-attempt0.out", "w", stdout);
    
    int TestCases;
    scanf("%d", &TestCases);
    
    for (int t=1; t <= TestCases; t++){
        struct Range range;
        scanf("%d%d", &range.A, &range.B);
        
        if (range.B < 21) {
            printf("Case #%d: 0\n", t);
            continue;
        }
        
        int answer = countNumbers(range);
        printf("Case #%d: %d\n", t, answer);
    }
    
    fclose(fin);
    fclose(fout);
    
    return 0;
}