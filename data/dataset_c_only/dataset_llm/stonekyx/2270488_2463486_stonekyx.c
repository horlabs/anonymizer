#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define SQUARE_ARR_SIZE 38

typedef struct {
    int* arr;
    int length;
} IntArray;

typedef struct {
    long long* arr;
    int length;
} LongArray;

LongArray get_squares()
{
    IntArray numbers = {
        .arr = (int[]){ 1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002 },
        .length = SQUARE_ARR_SIZE
    };

    LongArray squares = {
        .arr = (long long*)malloc(sizeof(long long) * (numbers.length + 1)),
        .length = numbers.length + 1
    };

    for (int i = 0; i < numbers.length; i++) {
        squares.arr[i] = (long long)numbers.arr[i] * numbers.arr[i];
    }

    squares.arr[numbers.length] = LLONG_MAX;

    return squares;
}

int binary_search(long long* arr, int arr_length, long long target)
{
    int low = 0;
    int high = arr_length - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return high;
}

int main()
{
    int num_testcases;
    scanf("%d", &num_testcases);

    LongArray squares = get_squares();

    for (int testcase = 0; testcase < num_testcases; testcase++) {
        long long a, b;
        scanf("%lld %lld", &a, &b);

        int index_a = binary_search(squares.arr, squares.length, a - 1);
        int index_b = binary_search(squares.arr, squares.length, b);

        int result = index_b - index_a;
        printf("Case #%d: %d\n", testcase + 1, result);
    }

    free(squares.arr);
    return 0;
}