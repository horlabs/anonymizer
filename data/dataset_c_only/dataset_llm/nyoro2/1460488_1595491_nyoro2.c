#include <stdio.h>

typedef struct {
	int not_surprising;
	int surprising;
} Result;

Result getBestResult(int score, int threshold) {
	Result result;
	result.not_surprising = (score + 2) / 3;
	if (result.not_surprising >= threshold) {
		result.surprising = 0;
	} else {
		result.surprising = result.not_surprising + 1;
	}
	return result;
}

int main() {
	int numOfCases;
	int caseIndex;
	int students;
	int surprisingCount;
	int threshold;
	int totalResult;

	scanf("%d\n", &numOfCases);
	for (caseIndex = 0; caseIndex < numOfCases; caseIndex++) {
		scanf("%d %d %d", &students, &surprisingCount, &threshold);
		totalResult = 0;
		int j;
		for (j = 0; j < students; j++) {
			int score;
			scanf("%d", &score);
			Result result = getBestResult(score, threshold);
			if (result.not_surprising >= threshold) {
				totalResult++;
			} else if (surprisingCount > 0) {
				if (((score % 3) != 1) && (result.surprising >= threshold)) {
					totalResult++;
					surprisingCount--;
				}
			}
		}
		fprintf(stdout, "Case #%d: %d\n", caseIndex + 1, totalResult);
	}

	return 0;
}