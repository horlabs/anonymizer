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
  char s[5];
  char *output[4] = {"X won", "O won", "Draw", "Game has not completed"};

  int i;
  int j;
  int k;
  int n;
  int f;
  int board[4][4];
  int T;

  FILE *fin = fopen("A-small-attempt0.in", "r");
  FILE *fout = fopen("out.txt", "w");

  fscanf(fin, "%d", &T);

  for (k = 0; k < T; k++) {
    for (i = 0; i < 4; i++) {
      fscanf(fin, "%s", s);
      for (j = 0; j < 4; j++)
        board[i][j] =
            (s[j] == 'X' ? 10 : (s[j] == 'O' ? 100 : (s[j] == 'T' ? 5 : 0)));
    }

    for (f = i = 0; i < 4 && !f; i++) {
      for (n = j = 0; j < 4; n += board[i][j++])
        ;
      if (n == 40 || n == 35 || n == 400 || n == 305) {
        for (j = 0; j < 4 && board[i][j] == 5; j++)
          ;
        f = board[i][j] == 10 ? 1 : 2;
      }
    }

    for (i = 0; i < 4 && !f; i++) {
      for (n = j = 0; j < 4; n += board[j++][i])
        ;
      if (n == 40 || n == 35 || n == 400 || n == 305) {
        for (j = 0; j < 4 && board[j][i] == 5; j++)
          ;
        f = board[j][i] == 10 ? 1 : 2;
      }
    }

    for (n = i = 0; i < 4 && !f; i++)
      n += board[i][i];
    if (!f && (n == 40 || n == 35 || n == 400 || n == 305)) {
      for (j = 0; j < 4 && board[j][j] == 5; j++)
        ;
      f = board[j][j] == 10 ? 1 : 2;
    }

    for (n = i = 0; i < 4 && !f; i++)
      n += board[i][4 - 1 - i];
    if (!f && (n == 40 || n == 35 || n == 400 || n == 305)) {
      for (j = 0; j < 4 && board[j][j] == 5; j++)
        ;
      f = board[j][4 - 1 - j] == 10 ? 1 : 2;
    }

    if (!f) {
      for (j = 4, i = 0; i < 4 && j == 4; i++)
        for (j = 0; j < 4 && board[i][j] != 0; j++)
          ;
      f = (i == 4 ? 3 : 4);
    }

    fprintf(fout, "Case #%d: %s\n", k + 1, output[f - 1]);
  }

  fclose(fin);
  fclose(fout);
  return 0;
}
