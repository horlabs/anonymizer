#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

typedef struct {
    int x;
    int y;
} Pair;

int getInputCount(FILE *file) {
    int count = 0;
    fscanf(file, "%d", &count);
    return count;
}

Pair* getPairs(FILE *file, int count) {
    Pair *pairs = (Pair*)malloc(count * sizeof(Pair));
    int i;

    for(i = 0; i < count; i++) {
        fscanf(file, "%d %d", &(pairs[i].x), &(pairs[i].y));
    }

    return pairs;
}

int calculateCount(Pair pair) {
    int i;
    int count = 0;
    int me = 10;
    int x = pair.x;
    int y = pair.y;
    int s = 1;
    int c = x;

    while( c = c/10 ) { 
        s++; 
        me *= 10; 
    }

    for(i = x; i <= y; i++) {
        int m = me;
        while((m=m/10)>=10) {
            int t = (i%m)*(me/m) + (i/m);
            if(i < t && t <= y && t >= x) {
                count++;
            }
        }
    }

    return count;
}

void writeOutput(FILE *file, int count, Pair *pairs) {
    int i;

    for(i = 0; i < count; i++) {
        fprintf(file, "Case #%d: %d\n", i+1, calculateCount(pairs[i]));
    }
}

void anonymizedFunction() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w+");

	if(inputFile) {
		int inputCount = getInputCount(inputFile);
        Pair *pairs = getPairs(inputFile, inputCount);
        writeOutput(outputFile, inputCount, pairs);
        free(pairs);
		fclose(inputFile);
	}
	fclose(outputFile);
}

int main(int argc, char *argv[]) {
    anonymizedFunction();
	return 0;
}