#include <stdio.h>
#include <stdlib.h>

#define OUTPUT_FILE "/home/vivek/Desktop/s.out"
#define INPUT_FILE "/home/vivek/Desktop/s.in"

char map[26];

void initializeMap() {
    map[0] = 'y';
    map[1] = 'n';
    map[2] = 'f';
    map[3] = 'i';
    map[4] = 'c';
    map[5] = 'w';
    map[6] = 'l';
    map[7] = 'b';
    map[8] = 'k';
    map[9] = 'u';
    map[10] = 'o';
    map[11] = 'm';
    map[12] = 'x';
    map[13] = 's';
    map[14] = 'e';
    map[15] = 'v';
    map[16] = 'z';
    map[17] = 'p';
    map[18] = 'd';
    map[19] = 'r';
    map[20] = 'j';
    map[21] = 'g';
    map[22] = 't';
    map[23] = 'h';
    map[24] = 'a';
    map[25] = 'q';
}

char reverseMap(char c) {
    int i;
    for (i = 0; i < 26; i++) {
        if (map[i] == c)
            return (i + 'a');
    }
    return ' ';
}

void processString(FILE *input, FILE *output) {
    char c, str[500];
    int i, co = 0;
    c = fgetc(input);
    while (c != '\n') {
        str[co++] = c;
        c = fgetc(input);
    }
    for (i = 0; i < co; i++)
        str[i] = reverseMap(str[i]);
    str[co] = '\0';
    fprintf(output, "%s", str);
}

void anonymizedMain(FILE *input, FILE *output) {
    int cs, i;
    char c;
    initializeMap();
    fscanf(input, "%d", &cs);
    while (fgetc(input) != '\n');

    for (i = 1; i <= cs; i++) {
        fprintf(output, "Case #%d: ", i);
        processString(input, output);
        c = '\n';
        fputc(c, output);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    inputFile = fopen(INPUT_FILE, "r");
    outputFile = fopen(OUTPUT_FILE, "w");
    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file(s).\n");
        return 0;
    }
    anonymizedMain(inputFile, outputFile);
    fclose(inputFile);
    fclose(outputFile);
    return 1;
}
