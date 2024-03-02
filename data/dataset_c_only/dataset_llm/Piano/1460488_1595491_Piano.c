#include<stdio.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int countQualifiedPlayers(int numOfTestCases, int numOfPlayers[], int surprisingScores[], int minimumScores[]) {
    int totalQualifiedPlayers = 0;
    for (int testcase = 0; testcase < numOfTestCases; ++testcase) {
        int n = numOfPlayers[testcase];
        int s = surprisingScores[testcase];
        int p = minimumScores[testcase];
        
        int t[100];
        for (int i = 0; i < n ; ++i){
            scanf("%d", &t[i]);
        }
        qsort(t, n, sizeof(int), compare);
        
        int i = 0, j = 0;
        while (i < n && t[i] >= p * 3 - 2) {
            ++i;
        }
        
        while (j < s && i + j < n && t[i + j] >= p * 3 - 4) {
            if (p == 1 && t[i + j] == 0) {
                break;
            }
            ++j;
        }
        
        totalQualifiedPlayers += (i + j);
    }
    return totalQualifiedPlayers;
}

int main(){
    int numOfTestCases;
    scanf("%d", &numOfTestCases);
    
    int numOfPlayers[numOfTestCases];
    int surprisingScores[numOfTestCases];
    int minimumScores[numOfTestCases];
    
    for (int testcase = 0 ; testcase < numOfTestCases ; ++testcase) {
        scanf("%d%d%d", &numOfPlayers[testcase], &surprisingScores[testcase], &minimumScores[testcase]);
    }
    
    int qualifiedPlayers = countQualifiedPlayers(numOfTestCases, numOfPlayers, surprisingScores, minimumScores);
    
    for (int i = 0; i < numOfTestCases; ++i) {
        printf("Case #%d: %d\n", (i+1), qualifiedPlayers[i]);
    }
    
    return 0;
}