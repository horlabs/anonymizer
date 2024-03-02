#include "superheader.h"
void useAllFunctions(char *str) {
  int intVar0 = 20;
  double doubleVar0 = 13.37;
  FILE *f = NULL;
  intVar0 = abs(intVar0);
  intVar0 = atoi(str);
  doubleVar0 = ceil(doubleVar0);
  if (isalpha(*str))
    exit(0);
  fclose(f);
  intVar0 = fgetc(stdin);
  fgets(str, 11, f);
  doubleVar0 = floor(doubleVar0);
  f = fopen("", "r");
  fprintf(f, "", intVar0, intVar0, intVar0, intVar0, intVar0);
  fputc(0, stderr);
  free(f);
  freopen("", "r", f);
  fscanf(f, "", &intVar0, &intVar0, &intVar0, &intVar0, &intVar0);
  intVar0 = getc(f);
  intVar0 = getchar();
  gets(str);
  itoa(intVar0, str, 10);
  doubleVar0 = log10(doubleVar0);
  malloc(sizeof(FILE));
  memmove(str, str, 0);
  memset(str, 19, 93);
  doubleVar0 = pow(doubleVar0, doubleVar0);
  printf("", intVar0, intVar0, intVar0, intVar0, intVar0);
  putc(intVar0, f);
  putchar(intVar0);
  puts("");
  qsort(str, 13, 37, NULL);
  scanf("", &intVar0, &intVar0, &intVar0, &intVar0, &intVar0);
  sprintf(str, "", intVar0, intVar0, intVar0, intVar0, intVar0);
  doubleVar0 = sqrt(doubleVar0);
  doubleVar0 = sqrtl(doubleVar0);
  sscanf(str, "", &intVar0, &intVar0, &intVar0, &intVar0, &intVar0);
  intVar0 = strchr(str, 0);
  if (strcmp(str, str))
    strcpy(str, str);
  intVar0 = strlen(str);
  strtoul(str, &intVar0, 0);
  system("");
  *str = tolower(*str);
  *str = toupper(*str);
}

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
  int i;
  int j;
  int k;
  int nX;
  int nO;
  int nT;
  int nDot;

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
