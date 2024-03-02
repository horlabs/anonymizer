#include <stdio.h>
#include <stdlib.h>

void anonymizedFunction(char *inputStr, char *translatedStr) {
    char googlerese[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
    int i = 0;
    
    while (inputStr[i] != '\0') {
        if (inputStr[i] >= 'a' && inputStr[i] <= 'z') {
            translatedStr[i] = googlerese[inputStr[i] - 'a'];
        } else {
            translatedStr[i] = ' ';
        }
        
        i++;
    }
    
    translatedStr[i] = '\0';
}

int main(void) {
    char *inputStr;
    char *translatedStr;
    int t, test = 1;
    
    scanf("%d", &t);
    getchar();
    
    inputStr = (char*)malloc(sizeof(char) * 120);
    translatedStr = (char*)malloc(sizeof(char) * 120);
    
    while (t--) {
        printf("Case #%d: ", test);
        fgets(inputStr, 120, stdin);
        anonymizedFunction(inputStr, translatedStr);
        printf("%s", translatedStr);
        test++;
    }
    
    free(inputStr);
    free(translatedStr);
    
    return 0;
}