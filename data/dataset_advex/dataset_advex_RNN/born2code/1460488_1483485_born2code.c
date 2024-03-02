#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char hash(char x) {
    switch (x) {
        case 'a':
            return 'y';
        case 'b':
            return 'h';
        case 'c':
            return 'e';
        case 'd':
            return 's';
        case 'e':
            return 'o';
        case 'f':
            return 'c';
        case 'g':
            return 'v';
        case 'h':
            return 'x';
        case 'i':
            return 'd';
        case 'j':
            return 'u';
        case 'k':
            return 'i';
        case 'l':
            return 'g';
        case 'm':
            return 'l';
        case 'n':
            return 'b';
        case 'o':
            return 'k';
        case 'p':
            return 'r';
        case 'q':
            return 'z';
        case 'r':
            return 't';
        case 's':
            return 'n';
        case 't':
            return 'w';
        case 'u':
            return 'j';
        case 'v':
            return 'p';
        case 'w':
            return 'f';
        case 'x':
            return 'm';
        case 'y':
            return 'a';
        case 'z':
            return 'q';
    }
    return ' ';
}
int main() {
    int n, i, j, k;
    char l[200], m[200];
    scanf("%d", &n);
    scanf("%*c");
    for (i = 1; i <= n; i++) {
        gets(l);
        for (j = 0; l[j] != '\0'; j++) {
            m[j] = hash(l[j]);
        }
        m[j] = '\0';
        printf("Case #%d: %s\n", i, m);
    }
    return 0;
}
