#include <stdio.h>

int calculateScore(int score, int p) {
    int quotient = score / 3;
    int remainder = score % 3;
    
    if (quotient >= p) {
        return 1;
    } else if (remainder > 0 && quotient + 1 >= p) {
        return 1;
    } else {
        return 0;
    }
}

void processInput(FILE *inputFile, FILE *outputFile) {
    int t, n, s, p, score, count;
    fscanf(inputFile, "%d", &t);
    
    for (int i = 0; i < t; i++) {
        count = 0;
        fscanf(inputFile, "%d", &n);
        fscanf(inputFile, "%d", &s);
        fscanf(inputFile, "%d", &p);
        
        for (int j = 0; j < n; j++) {
            fscanf(inputFile, "%d", &score);
            
            if (calculateScore(score, p)) {
                count++;
            } else if (s > 0 && ((score % 3 == 2 && score / 3 + 2 >= p) || (score % 3 == 0 && score / 3 + 1 == p && score > 0))) {
                count++;
                s--;
            }
        }
        
        fprintf(outputFile, "Case #%d: %d\n", i + 1, count);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    
    inputFile = fopen("B-small-attempt0.in", "r");
    if (inputFile == NULL) {
        printf("ERROR\n");
        return 1;
    }
    
    outputFile = fopen("output2.out", "a");
    processInput(inputFile, outputFile);
    
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}