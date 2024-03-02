#include <stdio.h>
#include <string.h>

char convertChar(char);

int main()
{
    char inputString[105];
    int i, numCases, j;
    FILE *inputFile, *outputFile;
    inputFile = fopen("A-small-attempt2.in", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }
    outputFile = fopen("output1.out", "a");
    fscanf(inputFile, "%d", &numCases);
    fgets(inputString, 2, inputFile);
    for (j = 0; j < numCases; j++) {
        fprintf(outputFile, "Case #%d: ", j + 1);
        fgets(inputString, 105, inputFile);
        for (i = 0; i < strlen(inputString) - 1; i++) {
            fprintf(outputFile, "%c", convertChar(inputString[i]));
        }
        fprintf(outputFile, "\n");
    }
    fclose(outputFile);
    fclose(inputFile);
    return 0;
}

char convertChar(char c)
{
    int i;
    char originalAlphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char replacementAlphabet[] = "yhesocvxduiglbkrztnwjpfmaq";
    if (c == 'q') {
        return 'z';
    }
    if (c == 'z') {
        return 'q';
    }
    for (i = 0; i < strlen(originalAlphabet); i++) {
        if (c == replacementAlphabet[i]) {
            break;
        }
    }
    return originalAlphabet[i];
}