#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int ntest;
  char testcase[4][5];
  char res[10];
  char nline[10];
  int i, j, k, nX, nO, nT, nDot;
  int flagDot;
  int flagWin;

  scanf("%d", &ntest);

  for (i = 0; i < ntest; i++) {
    flagWin = 0;
    flagDot = 0;

    for (j = 0; j < 4; j++) {
      scanf("%s", testcase[j]);
    }

    for (j = 0; j < 4; j++) {
      nX = 0;
      nO = 0;
      nT = 0;
      for (k = 0; k < 4; k++) {
        switch (testcase[j][k]) {
        case 'X':
          nX++;
          break;
        case 'O':
          nO++;
          break;
        case 'T':
          nT++;
          break;
        case '.':
          flagDot = 1;
          break;
        }
      }

      if (nX == 4 || (nX == 3 && nT == 1)) {
        res[i] = 'X';
        flagWin = 1;
        break;
      }
      if (nO == 4 || (nO == 3 && nT == 1)) {
        res[i] = 'O';
        flagWin = 1;
        break;
      }
    }

    for (j = 0; j < 4; j++) {
      if (flagWin == 1)
        break;

      nX = 0;
      nO = 0;
      nT = 0;
      for (k = 0; k < 4; k++) {

        switch (testcase[k][j]) {
        case 'X':
          nX++;
          break;
        case 'O':
          nO++;
          break;
        case 'T':
          nT++;
          break;
        case '.':
          flagDot = 1;
          break;
        }
      }

      if (nX == 4 || (nX == 3 && nT == 1)) {
        res[i] = 'X';
        flagWin = 1;
        break;
      }
      if (nO == 4 || (nO == 3 && nT == 1)) {
        res[i] = 'O';
        flagWin = 1;
        break;
      }
    }

    nX = 0;
    nO = 0;
    nT = 0;
    for (j = 0; j < 4; j++) {
      if (flagWin == 1)
        break;

      switch (testcase[j][j]) {
      case 'X':
        nX++;
        break;
      case 'O':
        nO++;
        break;
      case 'T':
        nT++;
        break;
      case '.':
        flagDot = 1;
        break;
      }
    }
    if (nX == 4 || (nX == 3 && nT == 1)) {
      res[i] = 'X';
      flagWin = 1;
    }
    if (nO == 4 || (nO == 3 && nT == 1)) {
      res[i] = 'O';
      flagWin = 1;
    }

    nX = 0;
    nO = 0;
    nT = 0;
    for (j = 0; j < 4; j++) {
      if (flagWin == 1)
        break;

      switch (testcase[j][3 - j]) {
      case 'X':
        nX++;
        break;
      case 'O':
        nO++;
        break;
      case 'T':
        nT++;
        break;
      case '.':
        flagDot = 1;
        break;
      }
    }

    if (nX == 4 || (nX == 3 && nT == 1)) {
      res[i] = 'X';
      flagWin = 1;
    }
    if (nO == 4 || (nO == 3 && nT == 1)) {
      res[i] = 'O';
      flagWin = 1;
    }

    if (flagWin == 0)
      if (flagDot == 1)
        res[i] = 'G';
      else
        res[i] = 'D';
  }

  for (i = 0; i < ntest; i++) {
    printf("Case #%d: ", i + 1);
    switch (res[i]) {
    case 'X':
      printf("X won\n");
      break;
    case 'O':
      printf("O won\n");
      break;
    case 'D':
      printf("Draw\n");
      break;
    case 'G':
      printf("Game has not completed\n");
      break;
    }
  }
}
