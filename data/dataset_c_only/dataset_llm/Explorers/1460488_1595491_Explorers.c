#include <stdio.h>

// Function to calculate number of Google Qualifications
int calculateGoogleQualifications(int nparticipant, int nsurprising, int bscore, int *pscores) {
    int ngoogle = 0;
    
    for (int j = 0; j < nparticipant; j++) {
        int pscore = pscores[j];
        int sjscore = pscore / 3;
        int remaining = pscore % 3;
        
        if (sjscore == 0 && remaining == 0 && bscore != 0) {
            continue;
        }
        
        if (sjscore >= bscore) {
            ngoogle++;
        } else if (remaining == 0 && nsurprising > 0 && sjscore + 1 >= bscore && sjscore + 1 <= 10) {
            ngoogle++;
            nsurprising--;
        } else if (remaining == 1 && sjscore + 1 >= bscore && sjscore + 1 <= 10) {
            ngoogle++;
        } else if (remaining == 2) {
            if (sjscore + 1 >= bscore) {
                ngoogle++;
            } else if (nsurprising > 0 && sjscore + 2 >= bscore && sjscore + 2 <= 10) {
                nsurprising--;
                ngoogle++;
            }
        }
    }
    
    return ngoogle;
}

int main() {
    int ntest;
    scanf("%d", &ntest);
    
    // Array to store number of Google Qualifications for each test case
    int ngoogle[100] = {0};
    
    for (int i = 0; i < ntest; i++) {
        int nparticipant, nsurprising, bscore;
        scanf("%d", &nparticipant);
        scanf("%d", &nsurprising);
        scanf("%d", &bscore);
        
        int pscores[nparticipant];
        for (int j = 0; j < nparticipant; j++) {
            scanf("%d", &pscores[j]);
        }
        
        ngoogle[i] = calculateGoogleQualifications(nparticipant, nsurprising, bscore, pscores);
    }
    
    for (int i = 0; i < ntest; i++) {
        printf("Case #%d: %d\n", i + 1, ngoogle[i]);
    }
    
    return 0;
}
