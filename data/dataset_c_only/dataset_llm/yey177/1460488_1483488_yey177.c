#include <stdio.h>

int getDigits(int num) {
    int count = 0;
    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
}

int* getRotations(int num, int* size) {
    int digits = getDigits(num);
    int* rotations = malloc(digits * sizeof(int));
    rotations[0] = num;
    *size = 1;
    int exponent = 1;
    for (int i = 1; i < digits; i++) {
        exponent *= 10;
    }
    for (int i = 1; i < digits; i++) {
        num = (num % 10) * exponent + num / 10;
        if (num >= rotations[0]) {
            continue;
        }
        int found = 0;
        for (int j = 0; j < *size; j++) {
            if (rotations[j] == num) {
                found = 1;
                break;
            }
        }
        if (!found) {
            rotations[(*size)++] = num;
        }
    }
    return rotations;
}

int countRotations(int a, int b) {
    int count = 0;
    for (int i = a; i <= b; i++) {
        int size = 0;
        int* rotations = getRotations(i, &size);
        count += size;
        free(rotations);
    }
    return count;
}

int main() {
    int numCases;
    scanf("%d", &numCases);
    for (int caseNum = 1; caseNum <= numCases; caseNum++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int rotationCount = countRotations(a, b);
        printf("Case #%d: %d\n", caseNum, rotationCount);
    }
    return 0;
}