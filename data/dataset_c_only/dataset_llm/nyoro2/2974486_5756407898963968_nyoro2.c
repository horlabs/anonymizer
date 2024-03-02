// Anonymous Version of qual_a.c

#include <stdio.h>

// Anonymous function to calculate the number of matching figures
int calculateMatchingFigs(int ans[], int board_ptn[][4][4]) {
    int num_match = 0;
    int match_fig;

    for (int k = 0; k < 4; k++) {
        int tmp = board_ptn[0][ans[0] - 1][k];
        for (int l = 0; l < 4; l++) {
            if (tmp == board_ptn[1][ans[1] - 1][l]) {
                match_fig = tmp;
                num_match++;
            }
        }
    }

    return num_match;
}

// Anonymous function to print the result
void printResult(int test_case, int num_match, int match_fig) {
    printf("Case #%d: ", test_case);

    switch (num_match) {
        case 0:
            printf("Volunteer cheated!\n");
            break;
        case 1:
            printf("%d\n", match_fig);
            break;
        default:
            printf("Bad magician!\n");
            break;
    }
}

int main() {
    int t;
    int ans[2];
    int board_ptn[2][4][4];

    fscanf(stdin, "%d\n", &t);

    for (int i = 0; i < t; i++) {
        // Input data
        for (int j = 0; j < 2; j++) {
            fscanf(stdin, "%d\n", ans + j);
            for (int k = 0; k < 4; k++) {
                fscanf(stdin, "%d %d %d %d\n",
                    &board_ptn[j][k][0], &board_ptn[j][k][1],
                    &board_ptn[j][k][2], &board_ptn[j][k][3]);
            }
        }

        // Calculate number of matching figures
        int num_match = calculateMatchingFigs(ans, board_ptn);

        // Print the result
        printResult(i + 1, num_match, match_fig);
    }

    return 0;
}