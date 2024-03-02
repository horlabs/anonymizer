#include <stdio.h>

unsigned int reverseNumber(unsigned int num) {
    unsigned int reverse = 0;
    while (num > 0) {
        reverse = (reverse * 10) + (num % 10);
        num /= 10;
    }
    return reverse;
}

unsigned int countReversiblePairs(unsigned int lowerBound, unsigned int upperBound) {
    unsigned int count = 0;
    unsigned int digits = 0;
    
    unsigned int temp = lowerBound;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }
    
    for (unsigned int num = lowerBound; num < upperBound; num++) {
        unsigned int reversedNum = reverseNumber(num);
        if (reversedNum > num && reversedNum <= upperBound) {
            count++;
        }
    }
    
    return count;
}

int main() {
    unsigned int numCases;
    FILE* inputFile = fopen("C-small-attempt2.in", "r");
    FILE* outputFile = fopen("output.txt", "w");
    
    fscanf(inputFile, "%d", &numCases);
    
    for (unsigned int caseNum = 1; caseNum <= numCases; caseNum++) {
        unsigned int lowerBound, upperBound;
        fscanf(inputFile, "%d %d", &lowerBound, &upperBound);
        unsigned int count = countReversiblePairs(lowerBound, upperBound);
        fprintf(outputFile, "Case #%d: %d\n", caseNum, count);
    }
    
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}
