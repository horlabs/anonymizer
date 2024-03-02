#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 150

void translateCharacters(char *str, char *translatingArr) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = translatingArr[str[i] - 'a'];
        }
    }
}

void printTranslatedStrings(char **strArr, int cas) {
    char translatingArr[] = "yhesocvxduiglbkrztnwjpfmaq";
    
    for (int i=0; i<cas; i++) {
        printf("Case #%d: ", i+1);
        translateCharacters(strArr[i], translatingArr);
        printf("%s\n", strArr[i]);
    }
}

int main() {
    int cas;
    char str[MAX_STR_LEN];
    
    fgets(str, sizeof(str), stdin);
    cas = atoi(str);
    
    char **strArr = (char **)malloc(cas * sizeof(char *));
    
    for (int i = 0; i < cas; i++) {
        strArr[i] = (char *)malloc(MAX_STR_LEN * sizeof(char));
        fgets(str, sizeof(str), stdin);
        strncpy(strArr[i], str, MAX_STR_LEN);
    }
    
    printTranslatedStrings(strArr, cas);
    
    for (int i = 0; i < cas; i++) {
        free(strArr[i]);
    }
    free(strArr);
    
    return 0;
}