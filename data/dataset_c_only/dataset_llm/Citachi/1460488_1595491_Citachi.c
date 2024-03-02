#include <stdio.h>

typedef struct {
    int values[3];
} Element;

void processCases(FILE* inputFile, FILE* outputFile);

int main() {
    FILE *inputFile, *outputFile;
    inputFile = fopen("B-small-attempt0.in", "r");
    outputFile = fopen("output.txt", "w");
    processCases(inputFile, outputFile);
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}

void processCases(FILE* inputFile, FILE* outputFile) {
    int numCases;
    fscanf(inputFile, "%d", &numCases);
    
    for (int caseNum = 1; caseNum <= numCases; caseNum++) {
        int numValues, numPlates, targetScore;
        fscanf(inputFile, "%d %d %d", &numValues, &numPlates, &targetScore);
        
        Element array[numValues];
        int sumArray[numValues];
        sumArray[0] = numValues;
        sumArray[1] = numPlates;
        sumArray[2] = targetScore;
        
        for (int i = 0; i < numValues; i++) {
            fscanf(inputFile, "%d", &sumArray[i + 3]);
        }
        
        for (int i = 0; i < sumArray[0]; i++) {
            for (int j = 10; j > 0; j--) {
                if (sumArray[i + 3] / j == 0) {
                    if (j - 1 == 0) {
                        array[i].values[0] = 0;
                        array[i].values[1] = 0;
                        array[i].values[2] = 0;
                    }
                    continue;
                }

                if (abs((sumArray[i + 3] % j) - j) == 1 || abs((sumArray[i + 3] % j) - j) == 2) {
                    array[i].values[1] = j;
                    array[i].values[0] = sumArray[i + 3] % j;
                    array[i].values[2] = j;
                    break;
                }
            }
        }
        
        while (numPlates > 0) {
            for (int i = 0; i < numValues; i++) {
                if (array[i].values[0] <= targetScore) {
                    numPlates--;
                    array[i].values[0]++;
                    array[i].values[1]--;
                    array[i].values[2]--;
                    break;
                } else if (array[i].values[1] <= targetScore) {
                    numPlates--;
                    array[i].values[0]--;
                    array[i].values[1]++;
                    array[i].values[2]--;
                    break;
                } else {
                    numPlates--;
                    array[i].values[0]--;
                    array[i].values[1]--;
                    array[i].values[2]++;
                    break;
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < sumArray[0]; i++) {
            if (array[i].values[1] >= targetScore || array[i].values[0] >= targetScore || array[i].values[2] >= targetScore) {
                count++;
            }
        }
        
        fprintf(outputFile, "Case #%d: %d\n", caseNum, count);
    }
}