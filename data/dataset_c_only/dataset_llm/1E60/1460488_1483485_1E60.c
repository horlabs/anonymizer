#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char str[100*5];
    int conversionTable[26];
} Input;

typedef struct {
    char str[100*5];
} Output;

void convertString(Input* input, Output* output) {
    int i=0;
    while (input->str[i] != '\0') {
        if (input->str[i] != ' ') {
            output->str[i] = 'a' + input->conversionTable[input->str[i]-'a'];
        } else {
            output->str[i] = ' ';
        }
        i++;
    }
    output->str[i] = '\0';
}

int main(void) {
    int N;
    scanf("%d\n", &N);

    for (int n = 1; n <= N; n++) {
        Input input;
        memset(input.str, 0, sizeof(input.str));
        scanf("%[a-z ]\n", input.str);
        
        for (int i = 0; i < 26; i++) {
            input.conversionTable[i] = 0; // Initialize all conversion table entries to 0
        }

        int convTable[] = {24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};
        for (int i = 0; i < 26; i++) {
            input.conversionTable[i] = convTable[i]; // Assign values from the conversion table
        }
        
        Output output;
        convertString(&input, &output);
        printf("Case #%d: %s\n", n, output.str);
    }

    return 0;
}