#include <stdio.h>
#include <stdlib.h>

unsigned long int rotate(unsigned long int number, int digits);
int countDigits(unsigned long int number);

unsigned long int rotate(unsigned long int number, int digits) {
    unsigned long int temp = number % 10;
    unsigned long int divisor = 1;
  
    for (int i = 0; i < digits - 1; i++) {
        divisor *= 10;
    }
  
    number = number / 10 + temp * divisor;
    return number;
}

int countDigits(unsigned long int number) {
    int count = 0;
  
    while (number) {
        count++;
        number /= 10;
    }
  
    return count;
}

int main() {
    unsigned long int testCases, start, end;
    unsigned long int i, j, k, digits, rotatedNum, p;
  
    scanf("%ld", &testCases);
  
    for (i = 1; i <= testCases; i++) {
        scanf("%ld%ld", &start, &end);
        digits = countDigits(start);
        k = 0;
      
        for (j = start + 1; j <= end; j++) {
            for (p = start; p < j; p++) {
                rotatedNum = rotate(p, digits);
              
                for (int l = 1; l < digits; l++) {
                    rotatedNum = rotate(rotatedNum, digits);
                  
                    if (rotatedNum == j) {
                        k++;
                        break;
                    }
                }
            }
        }
        printf("Case #%ld: %ld\n", i, k);
    }
  
    return 0;
}