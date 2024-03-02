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

char str[5][5];
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int i;
  int j;
  int k;
  int result;
  int numRowX[5];
  int numRowO[5];
  int numColX[5];
  int numColO[5];
  int numDiag1X;
  int numDiag1O;
  int numDiag2X;
  int numDiag2O;

  scanf("%d", &t);
  for (i = 1; i <= t; i++) {
    for (j = 0; j < 4; j++)
      scanf("%s", str[j]);
    result = -1;
    for (j = 0; j < 4; j++) {
      numRowX[j] = numRowO[j] = numColX[j] = numColO[j] = 0;
      for (k = 0; k < 4; k++) {
        if (str[j][k] == 'X')
          numRowX[j]++;
        else if (str[j][k] == 'O')
          numRowO[j]++;
        if (str[k][j] == 'X')
          numColX[j]++;
        else if (str[k][j] == 'O')
          numColO[j]++;
        if (str[j][k] == 'T') {
          numRowX[j]++;
          numRowO[j]++;
        }
        if (str[k][j] == 'T') {
          numColX[j]++;
          numColO[j]++;
        }
        if (str[k][j] == '.')
          result = 2;
      }
    }
    numDiag1X = numDiag1O = numDiag2X = numDiag2O = 0;
    for (j = 0; j < 4; j++) {
      if (str[j][j] == 'X')
        numDiag1X++;
      else if (str[j][j] == 'O')
        numDiag1O++;
      else if (str[j][j] == 'T') {
        numDiag1X++;
        numDiag1O++;
      }
      if (str[j][3 - j] == 'X')
        numDiag2X++;
      else if (str[j][3 - j] == 'O')
        numDiag2O++;
      else if (str[j][3 - j] == 'T') {
        numDiag2X++;
        numDiag2O++;
      }
    }
    for (j = 0; j < 4; j++)
      if (numRowX[j] == 4 || numColX[j] == 4)
        result = 0;
      else if (numRowO[j] == 4 || numColO[j] == 4)
        result = 1;
    if (numDiag1X == 4 || numDiag2X == 4)
      result = 0;
    else if (numDiag1O == 4 || numDiag2O == 4)
      result = 1;
    printf("Case #%d: ", i);
    if (result == -1)
      printf("Draw\n");
    else if (result == 0)
      printf("X won\n");
    else if (result == 1)
      printf("O won\n");
    else if (result == 2)
      printf("Game has not completed\n");
  }
  return 0;
}
