#include<stdio.h>
#include<stdlib.h>

int calculateRequiredCount(int n, int s, int p, int* array) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int a = array[i];
        if (a >= p) {
            if ((a + 2) / 3 >= p) {
                count++;
            } else if (s && (a + 1) / 3 == p - 1) {
                s--;
                count++;
            }
        }
    }
    return count;
}

void printResults(int t, int* results) {
    for (int i = 0; i < t; i++) {
        printf("Case #%d: %d\n", i+1, results[i]);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    
    int* nArray = malloc(t * sizeof(int));
    int* sArray = malloc(t * sizeof(int));
    int* pArray = malloc(t * sizeof(int));
    int** aArrays = malloc(t * sizeof(int*));
    
    for (int i = 0; i < t; i++) {
        scanf("%d%d%d", &nArray[i], &sArray[i], &pArray[i]);
        aArrays[i] = malloc(nArray[i] * sizeof(int));
        for (int j = 0; j < nArray[i]; j++) {
            scanf("%d", &aArrays[i][j]);
        }
    }
    
    int* resultArray = malloc(t * sizeof(int));
    
    for (int i = 0; i < t; i++) {
        resultArray[i] = calculateRequiredCount(nArray[i], sArray[i], pArray[i], aArrays[i]);
    }
    
    printResults(t, resultArray);
    
    for (int i = 0; i < t; i++) {
        free(aArrays[i]);
    }
    free(nArray);
    free(sArray);
    free(pArray);
    free(aArrays);
    free(resultArray);
    
    return 0;
}