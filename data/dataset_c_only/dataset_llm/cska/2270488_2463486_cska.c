#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DIGITS 150

char numA[MAX_DIGITS], numB[MAX_DIGITS];
unsigned long long int result = 0;

int compare(char *a, char *b) {
    int i;
    for (i = 0; i < MAX_DIGITS; i++) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return 2;
    }
    return 0;
}

void assignDigits(char* s, unsigned long long int n) {
    int i;
    for (i = MAX_DIGITS - 1; i >= 0; s[i] = n ? n%10 : 0, n /= 10, i--);
}

void multiply(char* a, char* c) {
    int i, j, k, t = 0;
    assignDigits(c, 0);
    for (i = MAX_DIGITS - 1; i >= 0; i--) {
        for (t = 0, k = i, j = MAX_DIGITS - 1; k >= 0; k--, j--) {
            t += c[k] + a[i] * a[j];
            c[k] = t % 10;
            t /= 10;
        }
    }
}

int countDigits(char *s) {
    int i = -1;
    while (s[++i] == 0);
    return MAX_DIGITS - i;
}

int isPalindrome(char *s) {
    int i = -1, j;
    while (s[++i] == 0);
    for (j = MAX_DIGITS - 1; i <= j && s[i] == s[j]; i++, j--);
    return i > j;
}

void generatePalindrome(char *s, int digits, int position) {
    static char ss[MAX_DIGITS];
    int j, c1, c2;
    if (position < ceil((float)digits/2)) {
        for (j = position == 0 ? 1 : 0; j < 10; j++) {
            s[MAX_DIGITS - 1 - position] = s[MAX_DIGITS - digits + position] = j;
            generatePalindrome(s, digits, position + 1);
        }
    } else {
        multiply(s, ss);
        if (isPalindrome(ss)) {
            c1 = compare(numA, ss);
            c2 = compare(numB, ss);
            if ((c1 == 0 || c1 == 2) && (c2 == 0 || c2 == 1)) result += 1;
        }
    }
}

int main(void) {
    char s[MAX_DIGITS] = {0};
    int i, digits, testCases;
    unsigned long long int a, b;
    FILE *inputFile = fopen("input.txt", "r"), *outputFile = fopen("output.txt", "w");

    fscanf(inputFile, "%d", &testCases);

    for (i = 0; i < testCases; i++) {
        fscanf(inputFile, "%llu%llu", &a, &b);

        assignDigits(numA, a);
        assignDigits(numB, b);

        result = 0;
        for (digits = ceil(countDigits(numA) / 2.0); digits <= ceil(countDigits(numB) / 2.0); digits++) {
            assignDigits(s, 0);
            generatePalindrome(s, digits, 0);
        }

        fprintf(outputFile, "Case #%d: %llu\n", i + 1, result);
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}