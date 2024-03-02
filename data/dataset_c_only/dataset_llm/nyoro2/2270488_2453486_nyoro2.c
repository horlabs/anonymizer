// Anonymous.c

#include <stdio.h>

typedef struct {
	int board[4][4];
} Game;

void initializeBoard(Game* game) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			game->board[i][j] = 0;
		}
	}
}

void getInputGame(Game* game) {
	char c;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf(" %c", &c);
			switch (c) {
			case 'O':
				game->board[i][j] = 1;
				break;
			case 'X':
				game->board[i][j] = 2;
				break;
			case 'T':
				game->board[i][j] = 3;
				break;
			default:
				game->board[i][j] = 0;
				break;
			}
			// Skip newline character after each row
			if (j == 3) {
				scanf("\n");
			}
		}
	}
}

void evaluateGame(Game* game, int* result, int* hasEmptyCell) {
	int lineResults[10];
	*result = 0;
	*hasEmptyCell = 0;

	// Initialize line results to 3 (no winner yet)
	for (int i = 0; i < 10; i++) {
		lineResults[i] = 3;
	}

	// Evaluate rows and columns
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			lineResults[i] &= game->board[i][j];
			lineResults[i + 4] &= game->board[j][i];
		}
	}

	// Evaluate diagonals
	lineResults[8] = game->board[0][0] & game->board[1][1] & game->board[2][2] & game->board[3][3];
	lineResults[9] = game->board[0][3] & game->board[1][2] & game->board[2][1] & game->board[3][0];

	// Check for empty cells
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (game->board[i][j] == 0) {
				*hasEmptyCell = 1;
			}
		}
	}

	// Determine result
	for (int i = 0; i < 10; i++) {
		*result |= lineResults[i];
	}
}

void printResult(int caseNum, int result, int hasEmptyCell) {
	printf("Case #%d: ", caseNum);
	if (result & 1) {
		printf("O won");
	} else if (result & 2) {
		printf("X won");
	} else if (hasEmptyCell) {
		printf("Game has not completed");
	} else {
		printf("Draw");
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d\n", &t);

	for (int i = 0; i < t; i++) {
		Game game;
		int result;
		int hasEmptyCell;

		initializeBoard(&game);
		getInputGame(&game);
		evaluateGame(&game, &result, &hasEmptyCell);
		printResult(i + 1, result, hasEmptyCell);
	}

	return 0;
}