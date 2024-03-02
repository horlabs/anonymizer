#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 200

void sanitizeInput(char* input) {
    int length = strlen(input);
    while (length && !isprint(input[length - 1])) {
        input[--length] = 0;
    }
}

void replaceCharacters(char* string, const char* mapping) {
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        if (string[i] == ' ') {
            continue;
        }
        string[i] = mapping[string[i] - 'a'];
    }
}

int main() {
    int testCaseCount;
    scanf("%d\n", &testCaseCount);

    int currentTestCase = 1;
    while (testCaseCount--) {
        char input[MAX_LENGTH];
        fgets(input, MAX_LENGTH, stdin);

        sanitizeInput(input);

        replaceCharacters(input, mapping);

        printf("Case #%d: %s\n", currentTestCase++, input);
    }

    return 0;
}