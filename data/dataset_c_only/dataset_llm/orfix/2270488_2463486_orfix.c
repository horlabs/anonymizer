/* Anonymized version of the code */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_length 1024
#define EPSILON 0.000000000000000001L

char check_palindrome(unsigned long long num) {
    int result = 1;
    char str[MAX_length] = "";

    if (sprintf(str, "%llu", num) > 0) {
        unsigned int len = strlen(str);

        for (unsigned long long i = 0; i < (len / 2) + 1 && result; i++) {
            if (str[i] != str[len - i - 1])
                result = 0;
        }
    }

    return result;
}

int main(void) {
    freopen("C-small-attempt0.in", "r", stdin);

    int num_cases = 0;
    int total_cases;

    scanf("%d\n", &total_cases);

    while (num_cases < total_cases) {
        unsigned long long int res = 0;
        unsigned long long int start, end;

        scanf("%llu %llu\n", &start, &end);

        for (; start <= end; start++) {
            if (check_palindrome(start)) {
                long double square_root = sqrtl(start);

                if (square_root - (long long int)square_root < EPSILON) {
                    if (check_palindrome((unsigned long long)square_root))
                        res++;
                }
            }
        }

        printf("Case #%d: %llu\n", ++num_cases, res);
    }

    return 0;
}