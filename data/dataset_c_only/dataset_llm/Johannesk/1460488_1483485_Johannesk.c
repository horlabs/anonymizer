#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convertString(char* input) {
    char mapping[26] = "yhesocvxduiglbkrztnwjpfmaq";
    char* output = (char*) malloc(strlen(input) + 1);
    int i;

    for (i = 0; i < (int) strlen(input); i++) {
        if (input[i] == ' ') {
            output[i] = input[i];
        } else if (input[i] != '\n') {
            output[i] = mapping[input[i] - 'a'];
        }
    }

    output[i] = '\0';
    return output;
}

int main(int argc, char** argv) {
    int numOfCases, i;
    char input[105], *convertedString;

    printf("Enter the number of cases: ");
    scanf("%d", &numOfCases);

    for (i = 1; i <= numOfCases; i++) {
        printf("Enter Case #%d: ", i);
        fgets(input, sizeof input, stdin);
        convertedString = convertString(input);
        printf("Case #%d: %s\n", i, convertedString);
        free(convertedString);
    }

    return 0;
}