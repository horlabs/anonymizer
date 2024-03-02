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

int TestCases;
int TCCount;
char Map[10][10];
int i;
int x;
int y;
int T;
int Ans;

int Solve() {
  for (y = 0; y < 4; y++) {
    T = 0;
    Ans = 0;
    for (x = 0; x < 4; x++) {
      if (Map[y][x] == 'X')
        Ans--;
      if (Map[y][x] == 'O')
        Ans++;
      if (Map[y][x] == 'T')
        T = 1;
    }
    if (T) {
      if (Ans < 0)
        Ans--;
      if (Ans > 0)
        Ans++;
    }
    if (Ans == -4) {
      printf("X won\n");
      return 0;
    }
    if (Ans == 4) {
      printf("O won\n");
      return 0;
    }
  }

  for (x = 0; x < 4; x++) {
    T = 0;
    Ans = 0;
    for (y = 0; y < 4; y++) {
      if (Map[y][x] == 'X')
        Ans--;
      if (Map[y][x] == 'O')
        Ans++;
      if (Map[y][x] == 'T')
        T = 1;
    }
    if (T) {
      if (Ans < 0)
        Ans--;
      if (Ans > 0)
        Ans++;
    }
    if (Ans == -4) {
      printf("X won\n");
      return 0;
    }
    if (Ans == 4) {
      printf("O won\n");
      return 0;
    }
  }

  T = 0;
  Ans = 0;
  for (x = 0, y = 0; x < 4; x++, y++) {
    if (Map[y][x] == 'X')
      Ans--;
    if (Map[y][x] == 'O')
      Ans++;
    if (Map[y][x] == 'T')
      T = 1;
  }
  if (T) {
    if (Ans < 0)
      Ans--;
    if (Ans > 0)
      Ans++;
  }
  if (Ans == -4) {
    printf("X won\n");
    return 0;
  }
  if (Ans == 4) {
    printf("O won\n");
    return 0;
  }

  T = 0;
  Ans = 0;
  for (x = 3, y = 0; x >= 0; x--, y++) {
    if (Map[y][x] == 'X')
      Ans--;
    if (Map[y][x] == 'O')
      Ans++;
    if (Map[y][x] == 'T')
      T = 1;
  }
  if (T) {
    if (Ans < 0)
      Ans--;
    if (Ans > 0)
      Ans++;
  }
  if (Ans == -4) {
    printf("X won\n");
    return 0;
  }
  if (Ans == 4) {
    printf("O won\n");
    return 0;
  }

  for (y = 0; y < 4; y++)
    for (x = 0; x < 4; x++)
      if (Map[y][x] == '.') {
        printf("Game has not completed\n");
        return 0;
      }
  printf("Draw\n");
  return 0;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);

  scanf("%d", &TestCases);
  for (TCCount = 1; TCCount <= TestCases; TCCount++) {
    printf("Case #%d: ", TCCount);

    for (y = 0; y < 4; y++)
      scanf("%s", Map[y]);

    Solve();
  }

  return 0;
}
