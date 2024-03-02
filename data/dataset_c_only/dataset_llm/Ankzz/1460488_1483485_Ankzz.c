#include <stdio.h>

#define ARRAY_SIZE 26
#define CASE_PREFIX "Case #"
#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

void readInputFile(char* filename, int* T, char* input)
{
    FILE* fp = fopen(filename, "r+");
    if (fp)
    {
        fscanf(fp, "%d", T);
        fgetc(fp); // consume newline character
        fgets(input, *T + 1, fp); // read all test cases at once
        fclose(fp);
    }
}

void writeOutputFile(char* filename, int* T, char* output)
{
    FILE* fp = fopen(filename, "w+");
    if (fp)
    {
        int i;
        for (i = 0; i < *T; i++)
        {
            fprintf(fp, "%s%d: %s\n", CASE_PREFIX, i + 1, &output[i]);
        }
        fclose(fp);
    }
}

void mapCharacters(char* input, char* output)
{
    int i;
    char characterMap[ARRAY_SIZE] = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q' };
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != ' ' && input[i] != '\n')
        {
            output[i] = characterMap[input[i] - 'a'];
        }
        else
        {
            output[i] = input[i];
        }
    }
}

int main(int argc, char* argv[])
{
    int T;
    char input[1000];
    char output[1000];

    readInputFile((argc <= 1) ? INPUT_FILENAME : argv[1], &T, input);

    int i;
    int nextLineIndex = 0;
    for (i = 0; i < T; i++)
    {
        char tempOutput[100];
        int j, index = 0;
        while (input[nextLineIndex] != '\n' && input[nextLineIndex] != '\0')
        {
            tempOutput[index++] = input[nextLineIndex++];
        }
        tempOutput[index] = '\0';

        mapCharacters(tempOutput, &output[i]);
        nextLineIndex++;
    }

    writeOutputFile(OUTPUT_FILENAME, &T, output);

    return 0;
}