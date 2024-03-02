#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STRING_SIZE 102

char* anonymizeText(char* text) {
    char toEnglish[] = "yhesocvxduiglbkrztnwjpfmaq";

    for(int i = 0; i < strlen(text); i++) {
        if(isalpha(text[i])) {
            text[i] = toEnglish[text[i] - 'a'];
        }
    }

    return text;
}

int main(void) {
    FILE* file = fopen("A-small-attempt4.in", "r");
    if(file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int testcase = 0;
    int testcases;

    fscanf(file, "%d\n", &testcases);

    while(testcase < testcases) {
        char googlerese[MAX_STRING_SIZE] = "";

        fgets(googlerese, MAX_STRING_SIZE, file);
        char* anonymizedText = anonymizeText(googlerese);

        printf("Case #%d: %s", ++testcase, anonymizedText);
    }

    fclose(file);

    return 0;
}