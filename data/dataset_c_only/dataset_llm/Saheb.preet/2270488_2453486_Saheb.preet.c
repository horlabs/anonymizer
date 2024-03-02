#include <stdio.h>

#define MAX_BOARD_SIZE 4
#define MAX_BOARD_ROW 5

struct Board {
  char grid[MAX_BOARD_SIZE][MAX_BOARD_ROW];
};

void readBoard(struct Board* board) {
  for (int i = 0; i < MAX_BOARD_SIZE; i++) {
    scanf("%s", board->grid[i]);
  }
}

int checkRow(const struct Board* board, char symbol) {
  for (int i = 0; i < MAX_BOARD_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < MAX_BOARD_SIZE; j++) {
      if (board->grid[i][j] != symbol && board->grid[i][j] != 'T') {
        break;
      }
      count++;
    }
    if (count == MAX_BOARD_SIZE) {
      return 1;
    }
  }
  return 0;
}

int checkColumn(const struct Board* board, char symbol) {
  for (int i = 0; i < MAX_BOARD_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < MAX_BOARD_SIZE; j++) {
      if (board->grid[j][i] != symbol && board->grid[j][i] != 'T') {
        break;
      }
      count++;
    }
    if (count == MAX_BOARD_SIZE) {
      return 1;
    }
  }
  return 0;
}

int checkDiagonal(const struct Board* board, char symbol) {
  int count = 0;
  for (int i = 0; i < MAX_BOARD_SIZE; i++) {
    if (board->grid[i][i] != symbol && board->grid[i][i] != 'T') {
      break;
    }
    count++;
  }
  if (count == MAX_BOARD_SIZE) {
    return 1;
  }

  count = 0;
  for (int i = 0; i < MAX_BOARD_SIZE; i++) {
    if (board->grid[MAX_BOARD_SIZE - i - 1][i] != symbol && board->grid[MAX_BOARD_SIZE - i - 1][i] != 'T') {
      break;
    }
    count++;
  }
  if (count == MAX_BOARD_SIZE) {
    return 1;
  }

  return 0;
}

int isGameCompleted(const struct Board* board) {
  for (int i = 0; i < MAX_BOARD_SIZE; i++) {
    for (int j = 0; j < MAX_BOARD_SIZE; j++) {
      if (board->grid[i][j] == '.') {
        return 0;
      }
    }
  }
  return 1;
}

void printResult(int caseNumber, char winner) {
  if (winner == 0) {
    printf("Case #%d: Game has not completed\n", caseNumber);
  }
  else if (winner == 'D') {
    printf("Case #%d: Draw\n", caseNumber);
  }
  else {
    printf("Case #%d: %c won\n", caseNumber, winner);
  }
}

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; i++) {
    struct Board board;
    readBoard(&board);

    char winner = 0;
    if (checkRow(&board, 'X') || checkColumn(&board, 'X') || checkDiagonal(&board, 'X')) {
      winner = 'X';
    }
    else if (checkRow(&board, 'O') || checkColumn(&board, 'O') || checkDiagonal(&board, 'O')) {
      winner = 'O';
    }
    else if (isGameCompleted(&board)) {
      winner = 'D';
    }

    printResult(i + 1, winner);
  }
  
  return 0;
}