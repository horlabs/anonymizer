#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_SIZE 30

// Function to map characters
char mapChar(char c) {
    char map[MAP_SIZE] = "yhesocvxduiglbkrztnwjpfmaq";
    if(c == ' ')
        return c;
    return map[c-'a'];    
}

// Function to process input
void processInput() {
    int t;
    scanf("%d", &t);
    char line[1024];
    fgets(line, 1024, stdin);

    for(int nc = 1; nc <= t; nc++) {
        fgets(line, 1024, stdin);
        line[strlen(line)-1] = '\0';
        for(int i = 0; i < strlen(line);i++) {
            line[i] = mapChar(line[i]);
        }
        printf("Case #%d: %s\n",nc,line);
    }
}

int main() {
    processInput();
    return 0;
}