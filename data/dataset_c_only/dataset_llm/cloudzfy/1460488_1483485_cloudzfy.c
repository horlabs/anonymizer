#include <stdio.h>

#define NO_OF_LETTERS 26

int letterMap[NO_OF_LETTERS] = {24, 7, 4, 18, 14, 2, 21, 23, 3, 20, 8, 6, 11, 1, 10, 17, 25, 19, 13, 22, 9, 15, 5, 12, 0, 16};

void anonymizeString(char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            continue;
        }
        str[i] = letterMap[str[i] - 'a'] + 'a';
    }
}

void printAnonymizedString(int caseNumber, char* str) {
    printf("Case #%d: %s\n", caseNumber, str);
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    
    int T, t;
    scanf("%d", &T);
    getchar();
    
    for (t = 1; t <= T; t++) {
        char str[200];
        fgets(str, 200, stdin);
        anonymizeString(str);
        printAnonymizedString(t, str);
    }
    
    return 0;
}