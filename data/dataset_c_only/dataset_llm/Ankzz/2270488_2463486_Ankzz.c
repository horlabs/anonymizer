#include <stdio.h>
#include <math.h>

#define READ( x )		fscanf( fp, "%d", &x )
#define READC( x )		fscanf( fp, "%c ", &x )
#define READ2( x, y)	fscanf( fp, "%ld %ld", &x, &y)

typedef struct {
	long start;
	long end;
} Range;

int isPalindrome(long num) {
    long temp, reversed = 0;
    temp = num;
    while( temp != 0 ) {
        reversed = reversed * 10;
        reversed = reversed + temp%10;
        temp /= 10;
    }
    return num == reversed;
}

int isSquare(int num) {
    int lastDigit = num & 0xF;
    if (lastDigit > 9) return 0;
    if (lastDigit != 2 && lastDigit != 3 && lastDigit != 5 && lastDigit != 6 && lastDigit != 7 && lastDigit != 8 ) {
        int squareRoot = (int) floor( sqrt((double) num) + 0.5 );
		return ( (squareRoot * squareRoot == num) && isPalindrome(squareRoot));
    }
    return 0;
}

Range readInput(FILE *fp) {
	Range input;
	READ2(input.start, input.end);
	return input;
}

int countPalindromeSquares(Range range) {
	int count = 0;
	for (long i = range.start; i <= range.end; i++) {
		if (isPalindrome(i) && isSquare(i)) {
			count++;
		}
	}
	return count;
}

void writeOutput(FILE *fo, int caseNumber, int count) {
	fprintf(fo, "Case #%d: %d\n", caseNumber, count);
}

int main() {
	int testCaseCount;
	FILE *fp = fopen("C-small-attempt0.in", "r");
	FILE *fo = fopen("output.txt", "w");
	READ(testCaseCount);
	for (int caseNumber = 1; caseNumber <= testCaseCount; caseNumber++) {
		Range range = readInput(fp);
		int count = countPalindromeSquares(range);
		writeOutput(fo, caseNumber, count);
	}
	fclose(fp);
	fclose(fo);
	return 0;
}