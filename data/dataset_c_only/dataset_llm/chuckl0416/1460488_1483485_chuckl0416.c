#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX_LEN 100000

void anonymizeString(char* line) {
    int i, length;
    length = strlen(line);
    
    for (i = 0; i < length; i++) {
        if (isalpha(line[i])) {
            switch (line[i]) {
                case 'a':
                    line[i] = 'y';
                    break;
                case 'b':
                    line[i] = 'h';
                    break;
                case 'c':
                    line[i] = 'e';
                    break;
                case 'd':
                    line[i] = 's';
                    break;
                case 'e':
                    line[i] = 'o';
                    break;
                case 'f':
                    line[i] = 'c';
                    break;
                case 'g':
                    line[i] = 'v';
                    break;
                case 'h':
                    line[i] = 'x';
                    break;
                case 'i':
                    line[i] = 'd';
                    break;
                case 'j':
                    line[i] = 'u';
                    break;
                case 'k':
                    line[i] = 'i';
                    break;
                case 'l':
                    line[i] = 'g';
                    break;
                case 'm':
                    line[i] = 'l';
                    break;
                case 'n':
                    line[i] = 'b';
                    break;
                case 'o':
                    line[i] = 'k';
                    break;
                case 'p':
                    line[i] = 'r';
                    break;
                case 'q':
                    line[i] = 'z';
                    break;
                case 'r':
                    line[i] = 't';
                    break;
                case 's':
                    line[i] = 'n';
                    break;
                case 't':
                    line[i] = 'w';
                    break;
                case 'u':
                    line[i] = 'j';
                    break;
                case 'v':
                    line[i] = 'p';
                    break;
                case 'w':
                    line[i] = 'f';
                    break;
                case 'x':
                    line[i] = 'm';
                    break;
                case 'y':
                    line[i] = 'a';
                    break;
                case 'z':
                    line[i] = 'q';
                    break;
            }
        }
    }
}

int main(){
    FILE *inputFile, *outputFile;
    inputFile = fopen("input.in", "r");
    outputFile = fopen("output.out", "w");

    int Testcases, t;
    char Line[LINE_MAX_LEN];
    fscanf(inputFile, "%d", &Testcases);
    getchar();
    
    for (t = 1; t <= Testcases; t++){
        printf("Case #%d: ", t);
        fgets(Line, LINE_MAX_LEN, inputFile);
        
        anonymizeString(Line);
        
        fprintf(outputFile, "Case #%d: %s", t, Line);
    }
    
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}