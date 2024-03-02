#include <stdio.h>


int main(int argc, char *argv[]) {
    FILE *fp, *o;
    fp = (argc <= 1) ? fopen("input.txt", "r+") : fopen(argv[1], "r+");
    o = fopen("output.txt", "w+");

    if (fp) {
        int T;
        int i;
        int j, k;
        fscanf(fp, "%d", &T);
        for (i = 0; i < T; i++) {
            int ar;
            int grid[4], grid2[4], ignore;
            int matchCount = -1, index = -1;
            long long score = 0;

            fscanf(fp, "%d", &ar);

            for (j = 0; j < 4; j++) {
                if (j == ar - 1) {
                    fscanf(fp, "%d %d %d %d", &grid[0], &grid[1], &grid[2], &grid[3]);

                } else {
                    fscanf(fp, "%d %d %d %d", &ignore, &ignore, &ignore, &ignore);
                }
            }
            fscanf(fp, "%d", &ar);

            for (j = 0; j < 4; j++) {
                if (j == ar - 1) {
                    fscanf(fp, "%d %d %d %d", &grid2[0], &grid2[1], &grid2[2], &grid2[3]);

                } else {
                    fscanf(fp, "%d %d %d %d", &ignore, &ignore, &ignore, &ignore);
                }
            }

            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    if (grid[j] == grid2[k]) {
                        matchCount++;
                        if (index == -1)
                            index = j;
                        else
                            break;
                    }
                }
                if (matchCount > 0) break;
            }
            fprintf(o, "Case #%d: ", i + 1);
            if (matchCount == 0) {
                fprintf(o, "%d\n", grid[index]);
            } else if (matchCount < 0) {
                fprintf(o, "%s\n", "Volunteer cheated!");
            } else if (matchCount > 0) {
                fprintf(o, "%s\n", "Bad magician!");
            }
        }
    }

    return 0;
}
