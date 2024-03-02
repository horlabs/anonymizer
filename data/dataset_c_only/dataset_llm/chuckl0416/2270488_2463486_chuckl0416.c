#include <stdio.h>

int casesCount, currentCase;
int rangeStart, rangeEnd;
int palindromeArray[10] = {1, 4, 9, 121, 484, 1200};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	
    scanf("%d", &casesCount);
	
    for (currentCase = 1; currentCase <= casesCount; currentCase++) {
        printf("Case #%d: ", currentCase);
        scanf("%d%d", &rangeStart, &rangeEnd);
		
        int startIndex = 0;
        while (palindromeArray[startIndex] < rangeStart) {
            startIndex++;
        }
		
        int endIndex = startIndex;
        while (palindromeArray[endIndex] <= rangeEnd) {
            endIndex++;
        }
		
        printf("%d\n", endIndex - startIndex);
    }
	
    return 0;
}