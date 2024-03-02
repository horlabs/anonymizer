#include <math.h>
#include <stdio.h>
#include <string.h>

int rearrangeNumber(int number, int steps, int size) {
    int reverseMask = 1;
    int shiftMask = 1;
    int p = size - steps;
    
    while (p--) {
        shiftMask *= 10;
    }
    
    while (steps--) {
        reverseMask *= 10;
    }
    
    int reversedNumber = (number % shiftMask) * reverseMask + (number / shiftMask);
    return reversedNumber;
}

int main(int argc, char **argv) {
    int numCases;
    assert(scanf("%d", &numCases) == 1);
    
    for (int i = 1; i <= numCases; i++) {
        int count = 0;
        int start, end;
        assert(scanf("%d %d", &start, &end) == 2);
        
        for (int j = start; j <= end; j++) {  
            int duplicate = 0;
            int digits = floor(log10(j)) + 1;
            
            for (int k = 1; k < digits; k++) { 
                int rearrangedNumber = rearrangeNumber(j, k, digits);
                
                if (rearrangedNumber >= start && rearrangedNumber <= end && rearrangedNumber > j && rearrangedNumber != duplicate) {                    
                    //printf("%d %d\n",j,rearrangedNumber);
                    count++;
                    duplicate = rearrangedNumber;
                }
            }
        }
        
        printf("Case #%d: %d\n", i, count);
    }
    
    return 0;
}
