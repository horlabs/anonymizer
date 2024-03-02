#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

char* conversion(char c){
    static const char * const eng = "abcdefghijklmnopqrstuvwxyz";
    static const char * const goog = "ynficwlbkuomxsevzpdrjgthaq";
    const char * const p = strchr(goog, c);

    if (p)
        return eng[p - goog];
    else
        return c;
}

void test_case(int t){
    char str[MAX_LENGTH];
    int i, c;

    printf("Case #%d: ", t + 1);
    fgets(str, MAX_LENGTH, stdin);

    for (i = 0; i < strlen(str); i++) {
        c = str[i];

        if (c == '\n')
            break;

        if (isupper(c))
            putchar(toupper(conversion(tolower(c))));
        else
            putchar(conversion(c));
    }
}

int main(){
    int t, i, c;
    char str[MAX_LENGTH];

    fgets(str, MAX_LENGTH, stdin);
    t = atoi(str);

    for (i = 0; i < t; i++)
        test_case(i);

    return 0;
}