#include <stdio.h>

#define ITERATE(x,N) for(x=0;x<N;x++)

int main(int argc, char *argv[])
{
    FILE *inputFile, *outputFile;
    inputFile = (argc <= 1) ? fopen("input.txt", "r+") : fopen(argv[1], "r+");
    outputFile = fopen("output.txt", "w+");

    if (inputFile) {
        int numCases;
        int caseIndex;

        fscanf(inputFile, "%d", &numCases);
        for (caseIndex = 0; caseIndex < numCases; caseIndex++) {
            int firstAnswer;
            int grid1[4], grid2[4], ignore;
            int matchCount = -1, matchIndex = -1;
            long long score = 0;

            fscanf(inputFile, "%d", &firstAnswer);
            ITERATE(i, 4) {
                if (i == firstAnswer - 1) {
                    fscanf(inputFile, "%d %d %d %d", &grid1[0], &grid1[1], &grid1[2], &grid1[3]);
                } else {
                    fscanf(inputFile, "%d %d %d %d", &ignore, &ignore, &ignore, &ignore);
                }
            }
            fscanf(inputFile, "%d", &firstAnswer);
            ITERATE(i, 4) {
                if (i == firstAnswer - 1) {
                    fscanf(inputFile, "%d %d %d %d", &grid2[0], &grid2[1], &grid2[2], &grid2[3]);
                } else {
                    fscanf(inputFile, "%d %d %d %d", &ignore, &ignore, &ignore, &ignore);
                }
            }
            ITERATE(i, 4) {
                ITERATE(j, 4) {
                    if (grid1[i] == grid2[j]) {
                        matchCount++;
                        if (matchIndex == -1)
                            matchIndex = i;

                        break;
                    }
                }
                if (matchCount > 0) break;
            }
            fprintf(outputFile, "Case #%d: ", caseIndex + 1);
            if (matchCount == 0) {
                fprintf(outputFile, "%d\n", grid1[matchIndex]);
            } else if (matchCount < 0) {
                fprintf(outputFile, "%s\n", "Volunteer cheated!");
            } else if (matchCount > 0) {
                fprintf(outputFile, "%s\n", "Bad magician!");
            }
        }
    }

    return 0;
}