#include <stdio.h>

#define MAX_SIZE 100000

int isPalindrome(int num){
    int originalNum = num;
    int reverseNum = 0;
    while(num > 0){
       reverseNum = reverseNum*10 + num%10;
       num /= 10;
    }
    return reverseNum == originalNum;
}

void fillPalindromeSquares(int *palindromeSquares){
    int index = 0;
    for(int i = 1; i <= MAX_SIZE; i++){
        if(isPalindrome(i) && isPalindrome(i*i)){
            palindromeSquares[index++] = i*i;
        }
    }
}

int countPalindromicSquaresInRange(int *palindromeSquares, int a, int b){
    int count = 0;
    for(int i = 0; i < MAX_SIZE; i++){
        if(palindromeSquares[i] >= a && palindromeSquares[i] <= b){
            count++;
        }
    }
    return count;
}

int main() {
    int palindromeSquares[MAX_SIZE];
    fillPalindromeSquares(palindromeSquares);
    
    int T;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        int a, b;
        scanf("%d %d", &a, &b);
        int cnt = countPalindromicSquaresInRange(palindromeSquares, a, b);
        printf("Case #%d: %d\n", t, cnt);
    }
    return 0;
}
