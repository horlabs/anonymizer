#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int left[n1], right[n2];
    
    for (int i = 0; i < n1; i++) {
        left[i] = arr[p + i];
    }
    
    for (int j = 0; j < n2; j++) {
        right[j] = arr[q + j + 1];
    }
    
    int i = 0;
    int j = 0;
    int k = p;
    
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    
    while (i < n1) {
        arr[k++] = left[i++];
    }
    
    while (j < n2) {
        arr[k++] = right[j++];
    }
}

void partition(int arr[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        partition(arr, p, q);
        partition(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main() {
    FILE* fin = freopen("B-small-attempt0.in", "r", stdin);
    FILE* fout = freopen("B-small-attempt0.out", "w", stdout);
    
    int TestCases;
    scanf("%d", &TestCases);
    
    for (int t = 1; t <= TestCases; t++) {
        int Number, Surprise, StdScore, Answer;
        scanf("%d%d%d", &Number, &Surprise, &StdScore);
        
        int Score[100000];
        for (int i = 0; i < Number; i++) {
            scanf("%d", &Score[i]);
        }
        
        qsort(Score, Number, sizeof(int), compare);
        
        Answer = 0;
        
        for (int i = Number - 1; i >= 0; i--) {
            if (Score[i] == 0) {
                if (StdScore == 0) {
                    Answer++;
                }
                continue;
            }
            
            if ((Score[i] % 3) == 0) {
                int Highest = Score[i] / 3;
                if (Highest >= StdScore) {
                    Answer++;
                } else if (Surprise) {
                    Highest++;
                    if (Highest >= StdScore) {
                        Answer++;
                        Surprise--;
                    }
                }
                continue;
            }
            
            if ((Score[i] % 3) == 1) {
                int Highest = (Score[i] + 2) / 3;
                if (Highest >= StdScore) {
                    Answer++;
                }
                continue;
            }
            
            if ((Score[i] % 3) == 2) {
                int Highest = (Score[i] + 1) / 3;
                if (Highest >= StdScore) {
                    Answer++;
                } else if (Surprise) {
                    Highest++;
                    if (Highest >= StdScore) {
                        Answer++;
                        Surprise--;
                    }
                }
                continue;
            }
        }
        
        printf("Case #%d: %d\n", t, Answer);
    }
    
    fclose(fin);
    fclose(fout);
    
    return 0;
}