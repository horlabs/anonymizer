#include <stdio.h>

typedef struct {
    int width;
    int height;
    int pasture[100][100];
} Pasture;

void readPasture(Pasture *pasture) {
    scanf("%d %d\n", &pasture->width, &pasture->height);
    for (int i = 0; i < pasture->width; i++) {
        for (int j = 0; j < pasture->height; j++) {
            scanf("%d", &pasture->pasture[i][j]);
        }
    }
}

int isPossible(Pasture *pasture) {
    if (pasture->width < 2 || pasture->height < 2) {
        return 1;
    }

    for (int i = 0; i < pasture->width; i++) {
        for (int j = 0; j < pasture->height; j++) {
            int isPowerful = 1;
            
            // Check from top to bottom
            for (int a = 0; a < pasture->width; a++) {
                if (pasture->pasture[i][j] < pasture->pasture[a][j]) {
                    isPowerful = 0;
                    break;
                }
            }
            
            if (isPowerful) {
                continue;
            }
            
            // Check from left to right
            isPowerful = 1;
            for (int a = 0; a < pasture->height; a++) {
                if (pasture->pasture[i][j] < pasture->pasture[i][a]) {
                    isPowerful = 0;
                    break;
                }
            }
            
            if (!isPowerful) {
                return 0;
            }
        }
    }

    return 1;
}

void printResult(int caseNumber, int isPossible) {
    if (isPossible) {
        printf("Case #%d: YES\n", caseNumber);
    }
    else {
        printf("Case #%d: NO\n", caseNumber);
    }
}

int main(void) {
    int numCases;
    scanf("%d", &numCases);

    for (int caseNumber = 1; caseNumber <= numCases; caseNumber++) {
        Pasture currentPasture;
        readPasture(&currentPasture);
        int possibility = isPossible(&currentPasture);
        printResult(caseNumber, possibility);
    }

    return 0;
}