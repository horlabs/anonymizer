#include <stdio.h>

#define MAX_SIZE 128

typedef struct {
    int rows;
    int cols;
    int values[MAX_SIZE][MAX_SIZE];
} Lawn;

int is_valid_lawn(Lawn *lawn) {
    int i, j, k, flag;
    for (i = 0; i < lawn->rows; i++) {
        for (j = 0; j < lawn->cols; j++) {
            flag = 0;
            for (k = 0; k < lawn->rows; k++) {
                if (lawn->values[k][j] > lawn->values[i][j]) {
                    flag++;
                    break;
                }
            }
            for (k = 0; k < lawn->cols; k++) {
                if (lawn->values[i][k] > lawn->values[i][j]) {
                    flag++;
                    break;
                }
            }
            if (flag >= 2) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int num_cases, case_num;
    int i, j;
    
    scanf("%d", &num_cases);
    for (case_num = 1; case_num <= num_cases; case_num++) {
        int num_rows, num_cols;
        Lawn lawn;
        
        scanf("%d %d", &num_rows, &num_cols);
        lawn.rows = num_rows;
        lawn.cols = num_cols;
        
        for (i = 0; i < num_rows; i++) {
            for (j = 0; j < num_cols; j++) {
                scanf("%d", &lawn.values[i][j]);
            }
        }
        
        if (is_valid_lawn(&lawn)) {
            printf("Case #%d: YES\n", case_num);
        } else {
            printf("Case #%d: NO\n", case_num);
        }
    }
    
    return 0;
}