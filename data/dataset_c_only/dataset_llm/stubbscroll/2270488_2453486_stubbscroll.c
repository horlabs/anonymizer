#include <stdio.h>

char gameBoard[6][6];

int checkWin(int x, int y, int dx, int dy, char player) {
	int count = 0;
	for (int i = 0; i < 4; i++) {
		if (gameBoard[x][y] == player || gameBoard[x][y] == 'T') count++;
		x += dx;
		y += dy;
	}
	return count == 4;
}

int hasWon(char player) {
	for (int i = 0; i < 4; i++) {
		if (checkWin(0, i, 1, 0, player)) return 1;
		if (checkWin(i, 0, 0, 1, player)) return 1;
	}
	if (checkWin(0, 0, 1, 1, player)) return 1;
	if (checkWin(0, 3, 1, -1, player)) return 1;
	return 0;
}

int main() {
	int numGames, row, col, no = 1;
	char player;
	scanf("%d", &numGames);
	while (numGames--) {
		for (int i = 0; i < 4; i++) scanf("%s", gameBoard[i]);
		printf("Case #%d: ", no++);
		if (hasWon('O')) puts("O won");
		else if (hasWon('X')) puts("X won");
		else {
			int isDraw = 0;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (gameBoard[i][j] == '.') {
						isDraw = 1;
						break;
					}
				}
				if (isDraw) break;
			}
			if (isDraw) puts("Game has not completed");
			else puts("Draw");
		}
	}
	return 0;
}
