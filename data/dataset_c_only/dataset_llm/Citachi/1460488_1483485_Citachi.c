#include <stdio.h>

char mapping[26] = {'y', 'n', 'f', 'i', 'c', 'w', 'l', 'b', 'k', 'u', 'o', 'm', 'x', 's', 'e', 'v', 'z', 'p', 'd', 'r', 'j', 'g', 't', 'h', 'a', 'q'};

void anonymizedFunction(char* inputFileName, char* outputFileName) {
    FILE* inputFile = fopen(inputFileName, "r");
    FILE* outputFile = fopen(outputFileName, "w");

    int T;
    fscanf(inputFile, "%d", &T);
    
    int currentCase = 0;
    char character;
    
    while((character = getc(inputFile)) != EOF) {
        if(character == '\n') {
            currentCase++;
            if(currentCase != 1)
                putc(character, outputFile);
            if(currentCase != T + 1)
                fprintf(outputFile, "Case #%d: ", currentCase);
        }

        if(character == ' ')
            putc(character, outputFile);
        else {
            for(int i = 0; i < 26; i++) {
                if(character == mapping[i])
                    putc((i + 'a'), outputFile);
            }
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    anonymizedFunction("A-small-attempt1.in", "output.txt");
    return 0;
}