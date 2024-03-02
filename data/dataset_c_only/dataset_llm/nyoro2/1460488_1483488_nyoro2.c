#include <stdio.h>

int getDigits(int number) {
    int count = 0;
    while (number > 0) {
        number /= 10;
        count++;
    }
    return count;
}

void numberToDigits(int number, int *digits, int num) {
    int index;
    for (index = num - 1; index >= 0; index--) {
        digits[index] = number % 10;
        number /= 10;
    }
}

int compareDigits(int *digits1, int *digits2, int num) {
    int index;
    for (index = 0; index < num; index++) {
        if (digits1[index] > digits2[index]) {
            return 1;
        } else if (digits1[index] < digits2[index]) {
            return -1;
        }
    }
    return 0;
}

void displayDigits(int *digits, int num) {
    int index;
    for (index = 0; index < num; index++) {
        fputc('0' + digits[index], stderr);
    }
}

int main() {
    int testCases;
    int index, j, n;

    fscanf(stdin, "%d\n", &testCases);
    for (index = 0; index < testCases; index++) {
        int a, b;
        int result, result1, result2;
        int numDigits;
        int refDigits[16];
        int recycDigits[16];
        int aDigits[16];
        int bDigits[16];

        fscanf(stdin, "%d %d\n", &a, &b);

        numDigits = getDigits(a);
        numberToDigits(a, aDigits, numDigits);
        numberToDigits(b, bDigits, numDigits);

        result1 = 0;
        result2 = 0;
        for (j = a; j <= b; j++) {
            numberToDigits(j, refDigits, numDigits);
            for (n = 1; n <= (numDigits / 2); n++) {
                int l, ltmp = n;
                if (refDigits[n] == 0) {
                    continue;
                }
                for (l = 0; l < numDigits; l++) {
                    recycDigits[l] = refDigits[ltmp++];
                    if (ltmp >= numDigits) {
                        ltmp = 0;
                    }
                }
                if (compareDigits(refDigits, recycDigits, numDigits) != 0) {
                    if ((compareDigits(recycDigits, aDigits, numDigits) >= 0) &&
                        (compareDigits(recycDigits, bDigits, numDigits) <= 0)) {
                        if (n * 2 == numDigits) {
                            result1++;
                        } else {
                            result2++;
                        }
                    }
                }
            }
        }
        result = result1 / 2 + result2;
        fprintf(stdout, "Case #%d: %d\n", index + 1, result);
    }

    return 0;
}
