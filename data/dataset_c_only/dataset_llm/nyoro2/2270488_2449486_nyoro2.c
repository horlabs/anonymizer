//
// anonymized_code.c
//

#include <stdio.h>

typedef struct {
    int rows;
    int columns;
    int ptn[128][128];
} Lawn;

int checkLawn(Lawn lawn) {
    int i, j, l, k;
    int lawnRef;
    
    for (i = 0; i < lawn.rows; i++) {
        for (j = 0; j < lawn.columns; j++) {
            lawnRef = lawn.ptn[i][j];
            for (l = 0; l < lawn.rows; l++) {
                if (lawn.ptn[l][j] > lawnRef) {
                    break;
                }
            }
            if (l < lawn.rows) {
                for (k = 0; k < lawn.columns; k++) {
                    if (lawn.ptn[i][k] > lawnRef) {
                        break;
                    }
                }
                if (k < lawn.columns) {
                    return 0;
                }
            }
        }
    }
    
    return 1;
}

int main() {
    int t;
    int i;
    Lawn lawn;
    int result;

    fscanf(stdin, "%d\n", &t);
    for (i = 0; i < t; i++) {
        fscanf(stdin, "%d %d\n", &lawn.rows, &lawn.columns);
        fprintf(stdout, "Case #%d: ", i + 1);
        
        // Data input
        for (int l = 0; l < lawn.rows; l++) {
            for (int k = 0; k < lawn.columns; k++) {
                fscanf(stdin, "%d", &(lawn.ptn[l][k]));
            }
        }
        
        // Check lawn
        result = checkLawn(lawn);

        fprintf(stdout, "%s", result ? "YES" : "NO");
        fprintf(stdout, "\n");
    }

    return 0;
}

// End of anonymized_code.c