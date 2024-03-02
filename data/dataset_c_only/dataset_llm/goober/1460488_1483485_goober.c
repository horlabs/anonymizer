#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

char charMap[] = "yhesocvxduiglbkrztnwjpfmaq";

void anonymizeString(char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = charMap[str[i] - 'a'];
        }
    }
}

void processString(int caseNum, char* str) {
    anonymizeString(str);
    printf("Case #%d: %s\n", caseNum, str);
}

int main() {
    int numberOfCases;
    scanf("%d ", &numberOfCases);

    char* buffer = (char*)malloc(MAX_SIZE * sizeof(char));

    for (int caseNum = 1; caseNum <= numberOfCases; caseNum++) {
        fgets(buffer, MAX_SIZE, stdin);
        processString(caseNum, buffer);
    }

    free(buffer);

    return 0;
}