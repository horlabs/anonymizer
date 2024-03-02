#include <stdio.h>

#define LOOP(n) for(int i = 0; i < n; i++)
#define LOOP1(n) for(int i = 1; i <= n; i++)

int main(int argc, char *argv[]) {
    FILE *inputFile, *outputFile;
    inputFile = (argc <= 1) ? fopen("input.txt", "r+") : fopen(argv[1], "r+");
    outputFile = fopen("output.txt", "w+");

    if (inputFile) {
        int testCases;
        fscanf(inputFile, "%d", &testCases);
        LOOP(testCases) {
            int N, S, p;
            int count = 0, s = 0;
            fscanf(inputFile, "%d %d %d", &N, &S, &p);
            LOOP(N) {
                int x, y, z;
                short flag = 0;
                fscanf(inputFile, "%d", &x);
                for (y = 3, z = p; y > 1 && z <= x; y = k) {
                    y = (x - z) / 2;
                    k = (y > z) ? y - z + 1 : z - y;
                    if (k > 2) {
                        if (y < z) break;
                        z++;
                    } else if (k == 2) {
                        if (s < S) {
                            s++; count++; flag = 1;
                        } else if (y < z) break;
                        z++;
                    } else {
                        if (!flag) {
                            count++;
                            flag = 0;
                        } else s--;
                        break;
                    }
                }
            }
            fprintf(outputFile, "Case #%d: %d\n", i + 1, count);
        }
    }

    return 0;
}