#include <stdio.h>
#include <string.h>

const char charMap[] = {
    121,
    104,
    101,
    115,
    111,
    116,
    99,
    107,
    119,
    105,
    103,
    108,
    117,
    98,
    119,
    121,
    120,
    113,
    105,
    109,
    110,
    102,
    109,
    107,
    97,
    112
};

void anonymizeString(char *str) {
    int i;
    int len = strlen(str);

    for (i = 0; i < len; ++i) {
        if (str[i] == ' ')
            continue;
        str[i] = charMap[str[i] - 'a'];
    }
}

void printAnonymizedString(int caseNum, const char *str) {
    printf("Case #%d: %s\n", caseNum, str);
}

int main() {
    int column;
    char input[102];
    int i;

    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &column);

    for (i = 1; i <= column; ++i) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  // remove newline character
        anonymizeString(input);
        printAnonymizedString(i, input);
    }

    return 0;
}