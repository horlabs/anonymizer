#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 108

char* alphabetMapping = "yhesocvxduiglbkrztnwjpfmaq";

void printModifiedString(char* string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] != ' ')
            putchar(alphabetMapping[(int)(string[i]-'a')]);
        else
            putchar(string[i]);
    }
}

int main() {
    int numberOfTestCases;
    scanf("%d", &numberOfTestCases);
    getchar();

    char** testCases = (char**)malloc(numberOfTestCases * sizeof(char*));
    for (int i = 0; i < numberOfTestCases; i++) {
        testCases[i] = (char*)malloc(MAX_SIZE * sizeof(char));
        fgets(testCases[i], MAX_SIZE, stdin);
    }

    for (int i = 0; i < numberOfTestCases; i++) {
        printf("Case #%d: ", i + 1);
        printModifiedString(testCases[i]);
    }

    for (int i = 0; i < numberOfTestCases; i++) {
        free(testCases[i]);
    }
    free(testCases);

    return 0;
}