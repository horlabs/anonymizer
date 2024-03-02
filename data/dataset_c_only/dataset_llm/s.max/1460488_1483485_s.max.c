#include <stdio.h>

void obfuscate(char *sentence, char *translation) {
    int i;
    for (i = 0; sentence[i]; i++) {
        if (sentence[i] != ' ' && sentence[i] != '\n') {
            sentence[i] = translation[sentence[i] - 'a'];
        }
    }
}

int main() {
    char translation[26] = "yhesocvxduiglbkrztnwjpfmaq";
    char input[1000];
    int numCases, caseNum;

    fgets(input, 1000, stdin);
    sscanf(input, "%d", &numCases);
    
    for (caseNum = 1; caseNum <= numCases; caseNum++) {
        fgets(input, 1000, stdin);
        
        obfuscate(input, translation);

        printf("Case #%d: %s", caseNum, input);
    }

    return 0;
}
