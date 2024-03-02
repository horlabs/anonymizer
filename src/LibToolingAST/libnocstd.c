// compile with: gcc -Wall -O2 -Wl,--no-as-needed -fpic -shared -o libnocstd.so libnocstd.c

#define LIBRARY

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <inttypes.h>

#include "nocstd.h"

errno_t fopen_s(FILE **f, const char *name, const char *mode) {
    errno_t ret = 0;
    *f = fopen(name, mode);
    if (!*f)
        ret = errno;
    return ret;
}

void strrev(char *str) {
    int i;
    int j;
    unsigned char a;
    unsigned len = strlen((const char *) str);
    for (i = 0, j = len - 1; i < j; i++, j--) {
        a = str[i];
        str[i] = str[j];
        str[j] = a;
    }
}

char* itoa(int num, char *str, int base) {
    int sum = num;
    int i = 0;
    int digit;
    do {
        digit = sum % base;
        if (digit < 0xA)
            str[i++] = '0' + digit;
        else
            str[i++] = 'A' + digit - 0xA;
        sum /= base;
    } while (sum);
    str[i] = '\0';
    strrev(str);
    return str;
}

void _sleep(unsigned int msec) {
    usleep(msec);
}

int getch(void) {
    return getchar();
}
