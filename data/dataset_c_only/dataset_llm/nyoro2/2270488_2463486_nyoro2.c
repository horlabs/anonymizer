#include <stdio.h>

// Function to check if a number is a palindrome
int isPalindrome(int num) {
    int rev = 0;
    int temp = num;
    
    while (temp > 0) {
        rev = rev * 10 + temp % 10;
        temp = temp / 10;
    }
    
    if (rev == num)
        return 1;
    else
        return 0;
}

int main() {
    int testCases;
    
    // Read the number of test cases
    scanf("%d", &testCases);
    
    for (int i = 0; i < testCases; i++) {
        int numA, numB;
        
        // Read the range of numbers
        scanf("%d %d", &numA, &numB);
        
        printf("Case #%d: ", i+1);
        
        int kMin = (int)sqrt(numA) - 1;
        int kMax = (int)sqrt(numB) - 1;
        
        long long numX = kMin + 1;
        numX = numX * numX;
        
        // Increment kMin if numX is less than numA
        if (numX < numA) {
            kMin++;
            numX += (kMin * 2 + 1);
        }
        
        int count = 0;
        for (int k = kMin + 1; k <= kMax + 1; k++) {
            // Check if numX is a palindrome
            if (isPalindrome((int)numX)) {
                // Check if k is a palindrome
                if (isPalindrome(k)) {
                    count++;
                }
            }
            
            numX += (k * 2 + 1);
        }
        
        printf("%d\n", count);
    }
    
    return 0;
}