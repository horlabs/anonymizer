#include <stdio.h>
#include <string.h>

typedef long long ll;

ll palindrome[1000000];
int palindromeCount;

void generatePalindromes() {
    char str[20], reversedStr[20];
    int num, i, length;
    palindromeCount = 0;
    
    for (num = 1; num < 10000001; num++) {
        sprintf(str, "%d", num);
        length = strlen(str);
        for (i = 0; i + i < length; i++) {
            if (str[i] != str[length - i - 1]) {
                goto notPalindrome;
            }
        }
        
        sprintf(reversedStr, "%I64d", (ll)num * num);
        length = strlen(reversedStr);
        for (i = 0; i + i < length; i++) {
            if (reversedStr[i] != reversedStr[length - i - 1]) {
                goto notPalindrome;
            }
        }
        
        palindrome[palindromeCount++] = (ll)num * num;
        
    notPalindrome:;
    }
}

int countPalindromesInRange(int a, int b) {
    int i, count = 0;
    
    for (i = 0; i < palindromeCount; i++) {
        if (a <= palindrome[i] && palindrome[i] <= b) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int testCases, a, b, testCaseNo = 1, count;
    
    generatePalindromes();
    
    scanf("%d", &testCases);
    
    while (testCases--) {
        scanf("%d %d", &a, &b);
        count = countPalindromesInRange(a, b);
        printf("Case #%d: %d\n", testCaseNo++, count);
    }
    
    return 0;
}