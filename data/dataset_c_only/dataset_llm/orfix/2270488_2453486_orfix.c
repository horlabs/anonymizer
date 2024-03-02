#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 4
#define WIN_CONDITION 4

typedef enum {
  PLAYER_X,
  PLAYER_O,
  DRAW,
  INCOMPLETE
} Status;

typedef struct {
  Status status;
  unsigned char cols[BOARD_SIZE][WIN_CONDITION];
  unsigned char rows[BOARD_SIZE][WIN_CONDITION];
  unsigned char diags[2][WIN_CONDITION];
  unsigned char empty;
} GameBoard;

void parseBoard(GameBoard* board) {
  for (unsigned char i = 0; i < BOARD_SIZE; i++) {
    for (unsigned char j = 0; j < BOARD_SIZE; j++) {
      char c = getchar();
      switch (c) {
        case 'T':
          if (++board->rows[PLAYER_O][i] == WIN_CONDITION || ++board->cols[PLAYER_O][j] == WIN_CONDITION) {
            board->status = PLAYER_O;
            break;
          }
          if (i == j && ++board->diags[PLAYER_O][0] == WIN_CONDITION) {
            board->status = PLAYER_O;
          } else if (j == BOARD_SIZE - i - 1 && ++board->diags[PLAYER_O][1] == WIN_CONDITION) {
            board->status = PLAYER_O;
          }
          break;
        case 'X':
          if (++board->rows[PLAYER_X][i] == WIN_CONDITION || ++board->cols[PLAYER_X][j] == WIN_CONDITION) {
            board->status = PLAYER_X;
            break;
          }
          if (i == j && ++board->diags[PLAYER_X][0] == WIN_CONDITION) {
            board->status = PLAYER_X;
          } else if (j == BOARD_SIZE - i - 1 && ++board->diags[PLAYER_X][1] == WIN_CONDITION) {
            board->status = PLAYER_X;
          }
          break;
        case 'O':
          if (++board->rows[PLAYER_O][i] == WIN_CONDITION || ++board->cols[PLAYER_O][j] == WIN_CONDITION) {
            board->status = PLAYER_O;
            break;
          }
          if (i == j && ++board->diags[PLAYER_O][0] == WIN_CONDITION) {
            board->status = PLAYER_O;
          } else if (j == BOARD_SIZE - i - 1 && ++board->diags[PLAYER_O][1] == WIN_CONDITION) {
            board->status = PLAYER_O;
          }
          break;
        case '.':
          board->empty++;
          break;
      }
    }
    getchar();
  }
  getchar();
}

void printResult(int test, Status status) {
  const char* resultStr[] = {"X won", "O won", "Draw", "Game has not completed"};
  printf("Case #%d: %s\n", test, resultStr[status]);
}

int main(void) {
  freopen("A-small-attempt0.in", "r", stdin);

  int testCase = 0;
  int testCases;
  scanf("%d\n", &testCases);

  while (testCase < testCases) {
    GameBoard board = {INCOMPLETE, {{0}}, {{0}}, {{0}}, 0};
    parseBoard(&board);

    if (!board.empty && board.status == INCOMPLETE) {
      board.status = DRAW;
    }

    printResult(++testCase, board.status);
  }

  return 0;
}