#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10

char* getNextPermutation(char* str, int length);

int main()
{
    char inputStr[MAX_LENGTH], *permutedStr;
    int numTestCases, i, j, k, check, count;
    long int start, end;
    FILE *inputFile, *outputFile;

    inputFile = fopen("C-small-attempt0.in", "r");
    if (inputFile == NULL) {
        printf("ERROR");
    } else {
        fscanf(inputFile, "%d", &numTestCases);
        for (i = 0; i < numTestCases; i++) {
            count = 0;
            fscanf(inputFile, "%ld%ld", &start, &end);
            for (j = start; j < end; j++) {
                sprintf(inputStr, "%ld", j);
                for (k = 0; k < strlen(inputStr) - 1; k++) {
                    permutedStr = getNextPermutation(&inputStr[0], strlen(inputStr));
                    check = atoi(permutedStr);
                    if (check > j && check <= end) {
                        count++;
                    }
                }
            }
            outputFile = fopen("out3.txt", "a");
            fprintf(outputFile, "Case #%d: %d\n", i + 1, count);
            fclose(outputFile);
        }
        fclose(inputFile);
    }
    return 0;
}

char* getNextPermutation(char* str, int length)
{
    char temp;
    int i;
    temp = *(str + length - 1);
    for (i = length - 1; i > 0; i--) {
        *(str + i) = *(str + i - 1);
    }
    *str = temp;
    return str;
}