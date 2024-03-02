#include <stdio.h>

int main() {
  freopen("replace-me.in", "r", stdin);

  int ntest;
  char testcase[4][5];
  char res[10];
  char nline[10];
  int i, duai_Var, k, nX, nO, nT, nDot;
  int flagDot;
  int flagWin;

  scanf("%d", &ntest);

  for (i = 0; i < ntest; i++) {
    flagWin = 0;
    flagDot = 0;

    for (duai_Var = 0; duai_Var < 4; duai_Var++) {
      scanf("%s", testcase[duai_Var]);
    }

    for (duai_Var = 0; duai_Var < 4; duai_Var++) {
      nX = 0;
      nO = 0;
      nT = 0;
      for (k = 0; k < 4; k++) {
        switch (testcase[duai_Var][k]) {
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

    for (duai_Var = 0; duai_Var < 4; duai_Var++) {
      if (flagWin == 1)
        break;

      nX = 0;
      nO = 0;
      nT = 0;
      for (k = 0; k < 4; k++) {

        switch (testcase[k][duai_Var]) {
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
    for (duai_Var = 0; duai_Var < 4; duai_Var++) {
      if (flagWin == 1)
        break;

      switch (testcase[duai_Var][duai_Var]) {
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
    for (duai_Var = 0; duai_Var < 4; duai_Var++) {
      if (flagWin == 1)
        break;

      switch (testcase[duai_Var][3 - duai_Var]) {
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
