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
  int i;
  int t;
  int j;
  int k;

  char board[4][5];
  char flag;
  char winner;
  char curr;

  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    winner = 0;
    flag = 0;
    for (j = 0; j < 4; j++) {
      scanf("%s", board[j]);
      for (k = 0; k < 4; k++)
        if (board[j][k] != 'X' && board[j][k] != 'T')
          break;
      if (k == 4)
        winner = 'X';
      for (k = 0; k < 4; k++)
        if (board[j][k] != 'O' && board[j][k] != 'T')
          break;
      if (k == 4)
        winner = 'O';
      for (k = 0; k < 4; k++)
        if (board[j][k] == '.')
          flag = 1;
    }
    for (k = 0; k < 4; k++) {
      for (j = 0; j < 4; j++)
        if (board[j][k] != 'X' && board[j][k] != 'T')
          break;
      if (j == 4)
        winner = 'X';
      for (j = 0; j < 4; j++)
        if (board[j][k] != 'O' && board[j][k] != 'T')
          break;
      if (j == 4)
        winner = 'O';
    }
    for (k = 0; k < 4; k++)
      if (board[k][k] != 'X' && board[k][k] != 'T')
        break;
    if (k == 4)
      winner = 'X';
    for (k = 0; k < 4; k++)
      if (board[k][k] != 'O' && board[k][k] != 'T')
        break;
    if (k == 4)
      winner = 'O';
    for (k = 0; k < 4; k++)
      if (board[3 - k][k] != 'X' && board[3 - k][k] != 'T')
        break;
    if (k == 4)
      winner = 'X';
    for (k = 0; k < 4; k++)
      if (board[3 - k][k] != 'O' && board[3 - k][k] != 'T')
        break;
    if (k == 4)
      winner = 'O';
    if (winner == 0) {
      if (flag == 1)
        printf("Case #%d: Game has not completed\n", i + 1);
      else
        printf("Case #%d: Draw\n", i + 1);
    } else
      printf("Case #%d: %c won\n", i + 1, winner);
  }
  return 0;
}
