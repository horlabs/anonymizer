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

char board[123][123];
int X;
int O;
int x;
int o;

void check(int i, int j) {
  if (board[i][j] == 'O') {
    ++o, x = -1000;
  } else if (board[i][j] == 'X') {
    ++x, o = -1000;
  } else if (board[i][j] == 'T') {
    ++x, ++o;
  }
}
void cnt() {
  if (x == 4)
    X = 2;
  if (o == 4)
    O = 2;
  if (x >= 0)
    X |= 1;
  if (o >= 0)
    O |= 1;
}
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int T;

  int i;
  int j;

  scanf("%d", &T);
  for (t = 1; t <= T; ++t) {
    for (i = 0; i < 4; ++i) {
      scanf("%s", board[i]);
    }
    X = O = 0;
    for (i = 0; i < 4; ++i) {
      for (j = x = o = 0; j < 4; ++j) {
        check(i, j);
      }
      cnt();
    }
    for (i = 0; i < 4; ++i) {
      for (j = x = o = 0; j < 4; ++j) {
        check(j, i);
      }
      cnt();
    }
    for (i = j = x = o = 0; i < 4; ++i, ++j) {
      check(j, i);
    }
    cnt();
    for (i = 3, j = x = o = 0; j < 4; --i, ++j) {
      check(j, i);
    }
    cnt();
    printf("Case #%d: ", t);
    if (X >= 2)
      puts("X won");
    if (O >= 2)
      puts("O won");
    if (X == 1 && O == 1)
      puts("Game has not completed");
    if (X == 0 && O == 0)
      puts("Draw");
  }
  return 0;
}
