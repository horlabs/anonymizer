#include <stdio.h>
#include <stdlib.h>

int calculateDigits(int num) {
    int digits = 0;
    while (num != 0) {
        num /= 10;
        digits++;
    }
    return digits;
}

int calculatePower(int num) {
    int power = 1;
    while (num > 0) {
        power *= 10;
        num--;
    }
    return power;
}

int isNumberInRange(int num, int min, int max) {
    return (num > min && num <= max);
}

int isDistinct(int* encontrados, int nenc, int cand) {
    for (int k = 0; k < nenc; k++) {
        if (cand == encontrados[k]) {
            return 0;
        }
    }
    return 1;
}

int calculateRecycledNumbers(int min, int max) {
    int total = 0;
    for (int num = min; num < max; num++) {
        int cand = num;
        int ndigit = calculateDigits(max);
        int potencia = calculatePower(ndigit - 1);
        int nenc = 0;
        int encontrados[10];

        for (int j = 1; j < ndigit; j++) {
            int temp = cand % 10;
            cand /= 10;
            cand += (temp * potencia);
            if (isNumberInRange(num, cand, max) && isDistinct(encontrados, nenc, cand)) {
                encontrados[nenc] = cand;
                nenc++;
                total++;
            }
        }
    }
    return total;
}

int main(void) {
    int cases, min, max;
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++) {
        scanf("%d", &min);
        scanf("%d", &max);
        int total = calculateRecycledNumbers(min, max);
        printf("Case #%d: %d\n", i, total);
    }
    return 0;
}