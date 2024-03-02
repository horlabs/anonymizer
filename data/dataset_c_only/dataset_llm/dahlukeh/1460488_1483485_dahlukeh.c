#include <stdio.h>

#define MAX_SIZE 2000
#define CASE_PREFIX "Case #%d: "

void convertAndPrint(char* line);

char map[] = {
    'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'
};

int main() {
    int numCases;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d ", &numCases);

    for (int caseNum = 0; caseNum < numCases; caseNum++){
        printf(CASE_PREFIX, caseNum + 1);
        convertAndPrint();
    }

    return 0;
}

void convertAndPrint() {
    char line[MAX_SIZE];
    char c;
    int index = 0;
    scanf("%c", &c);

    while (c != '\n') {
        line[index] = c;
        index++;
        scanf("%c", &c);
    }

    line[index] = '\0';

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] >= 'a' && line[i] <= 'z') {
            printf("%c", map[line[i] - 'a']);
        } else {
            printf(" ");
        }
    }

    printf("\n");
}