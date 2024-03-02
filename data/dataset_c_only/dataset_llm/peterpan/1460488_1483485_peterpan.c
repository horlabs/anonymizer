#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

char* scrambleString(char* string) {
    int i = 0;
    char* result = malloc(MAX_LENGTH * sizeof(char));
    char map[] = "yhesocvxduiglbkrztnwjpfmaq";

    while (string[i] != '\0') {
        char ch = string[i];
        if (ch >= 'a' && ch <= 'z') {
            result[i] = map[ch - 'a'];
        } else {
            result[i] = ch;
        }
        i++;
    }
    result[i] = '\0';
    return result;
}

void printScrambledStrings(int T) {
    int tcase;
    char input[MAX_LENGTH];

    for (tcase = 1; tcase <= T; tcase++) {
        printf("Case #%d: ", tcase);

        fgets(input, MAX_LENGTH, stdin);
        char* output = scrambleString(input);

        printf("%s", output);
        free(output);
    }
}

int main() {
    int T;

    scanf("%d", &T);
    getchar();  // clear input buffer
    printScrambledStrings(T);

    return 0;
}