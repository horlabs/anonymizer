#include <stdio.h>

int countGoodNumbers(int a, int b) {
    int res = 0;
    int digits = 0;
    int temp = a;
    
    while (temp >= 10) {
        digits += 1;
        temp /= 10;
    }
    
    for (int n = a; n <= b; n++) {
        int m = n;
        int previous[digits + 1];
        
        for (int i = 0; i < digits; i++) {
            previous[i] = m;
            m = (m % 10) * 1 + (m / 10);
            
            if (m <= n || m > b || m == 0) {
                continue;
            }
            
            for (int k = 0; k < i; k++) {
                if (previous[k] == m) {
                    goto skip;
                }
            }
            
            res++;
            
skip:;
        }
    }
    
    return res;
}

int main() {
    int testCases;
    scanf("%d", &testCases);
    
    for (int caseNum = 1; caseNum <= testCases; caseNum++) {
        int first, last;
        scanf("%d %d", &first, &last);
        
        int goodNumbers = countGoodNumbers(first, last);
        printf("Case #%d: %d\n", caseNum, goodNumbers);
    }
    
    return 0;
}