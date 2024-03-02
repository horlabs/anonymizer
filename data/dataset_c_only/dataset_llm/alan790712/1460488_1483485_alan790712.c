#include <stdio.h>
#include <stdlib.h>

#define SIZE 1234567

char input[SIZE];
char translated[256];

void initializeTranslation() {
    for (int i = 0; i < 256; ++i) {
        translated[i] = i;
    }
    
    translated['a'] = 'y';
    translated['b'] = 'h';
    translated['c'] = 'e';
    translated['d'] = 's';
    translated['e'] = 'o';
    translated['f'] = 'c';
    translated['g'] = 'v';
    translated['h'] = 'x';
    translated['i'] = 'd';
    translated['j'] = 'u';
    translated['k'] = 'i';
    translated['l'] = 'g';
    translated['m'] = 'l';
    translated['n'] = 'b';
    translated['o'] = 'k';
    translated['p'] = 'r';
    translated['q'] = 'z';
    translated['r'] = 't';
    translated['s'] = 'n';
    translated['t'] = 'w';
    translated['u'] = 'j';
    translated['v'] = 'p';
    translated['w'] = 'f';
    translated['x'] = 'm';
    translated['y'] = 'a';
    translated['z'] = 'q';
}

void anonymizedCode() {
    int numCases;
    scanf("%d", &numCases);
    getchar();

    for (int i = 1; i <= numCases; ++i) {
        fgets(input, SIZE, stdin);
        
        printf("Case #%d: ", i);
        for (int j = 0; input[j] != '\0'; ++j) {
            putchar(translated[input[j]]);
        }
        puts("");
    }
}

int main() {
    initializeTranslation();
    anonymizedCode();
    return 0;
}
