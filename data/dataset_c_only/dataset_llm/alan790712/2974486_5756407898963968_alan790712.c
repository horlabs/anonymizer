#include <stdio.h>
#include <stdlib.h>

int main() {
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; ++t) {
        int row[2];
        int card[2][4][4];

        for (int i = 0; i < 2; ++i) {
            scanf("%d", &row[i]);

            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    if (j + 1 == row[i])
                        scanf("%d", &card[i][j][k]);
                    else
                        scanf("%*d");
                }
            }
        }

        int ans = -1;
        int count = 0;

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (card[0][i][j] == card[1][row[1] - 1][j]) {
                    ans = card[0][i][j];
                    ++count;
                }
            }
        }

        printf("Case #%d: ", t);

        if (count == 1)
            printf("%d\n", ans);
        else if (count > 1)
            printf("Bad magician!\n");
        else
            printf("Volunteer cheated!\n");
    }

    return 0;
}