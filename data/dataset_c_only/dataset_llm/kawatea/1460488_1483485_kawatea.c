#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 105
#define ALPHABET_SIZE 26

char transformCharacter(char c)
{
    if (c == ' ') return c;
    char mapping[ALPHABET_SIZE] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
    return mapping[c - 'a'];
}

void anonymizeInputString(char* str)
{
    int len = strlen(str);
    str[len - 1] = '\0';
}

void anonymizeString(char* str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = transformCharacter(str[i]);
    }
}

int main()
{
    int numTestCases;
    scanf("%d%*c", &numTestCases);

    for (int i = 0; i < numTestCases; i++) {
        char inputString[MAX_STR_LEN];
        fgets(inputString, MAX_STR_LEN, stdin);

        anonymizeInputString(inputString);
        anonymizeString(inputString);

        printf("Case #%d: %s\n", i + 1, inputString);
    }

    return 0;
}