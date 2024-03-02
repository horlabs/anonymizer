#include <stdio.h>
#include <stdlib.h>

#define MAX_CARDS 4

// Function to read the input
void readInput(int* answer, int cards[MAX_CARDS][MAX_CARDS], int* testcases) {
	freopen("A-small-attempt0.in", "r", stdin);

	scanf("%d\n", testcases);

	int testcase = 0;

	while (testcase < *testcases) {
		scanf("%d\n", &(*answer));
		for (int row = 0; row < MAX_CARDS; row++) {
			for (int col = 0; col < MAX_CARDS; col++) {
				scanf("%d", &cards[row][col]);
			}
		}

		testcase++;
	}
}

// Function to calculate the result
void calculateResult(int answer, int cards[MAX_CARDS][MAX_CARDS], int* found, int* theCard) {
	int userAnswer;
	int userCards[MAX_CARDS];

	scanf("%d\n", &userAnswer);

	for (int row = 0; row < MAX_CARDS; row++) {
		for (int col = 0; col < MAX_CARDS; col++) {
			scanf("%d", &userCards[col]);
		}
		if (row == answer - 1) { // Convert to 0-based indexing
			for (int i = 0; i < MAX_CARDS; i++) {
				if (cards[row][i] == userCards[i]) {
					(*found)++;
					(*theCard) = userCards[i];
				}
			}
		}
	}
}

// Function to display the result
void displayResult(int testcase, int found, int theCard) {
	printf("Case #%d: ", testcase);
	if (found == 0) {
		printf("Volunteer cheated!\n");
	} else if (found == 1) {
		printf("%d\n", theCard);
	} else {
		printf("Bad magician!\n");
	}
}

int main(void) {
	int testcases;
	int answer;
	int cards[MAX_CARDS][MAX_CARDS];

	// Read the input
	readInput(&answer, cards, &testcases);

	int testcase = 1;

	while (testcase <= testcases) {
		int found = 0;
		int theCard = 0;

		// Calculate the result
		calculateResult(answer, cards, &found, &theCard);

		// Display the result
		displayResult(testcase, found, theCard);

		testcase++;
	}

	return 0;
}