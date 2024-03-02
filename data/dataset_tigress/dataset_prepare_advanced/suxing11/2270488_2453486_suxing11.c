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

char g[5][5];
int flag;

int check(char ch) {
  int i;
  int j;
  int col[4] = {0};
  int row[4] = {0};

  int cc = 0;
  int dd = 0;

  for (i = 0; i < 4; i++) {
    if (g[i][i] == ch || g[i][i] == 'T')
      cc++;
    if (g[i][3 - i] == ch || g[i][3 - i] == 'T')
      dd++;
    for (j = 0; j < 4; j++) {
      if (g[i][j] == ch || g[i][j] == 'T')
        row[i]++;
      if (g[j][i] == ch || g[j][i] == 'T')
        col[i]++;
    }
  }
  for (i = 0; i < 4; i++)
    if (row[i] == 4 || col[i] == 4)
      return 1;
  if (cc == 4 || dd == 4)
    return 1;
  return 0;
}

int gao() {
  int i;
  int j;
  int flag = 0;

  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      flag += (g[i][j] == '.');
  if (check('X'))
    return 0;
  if (check('O'))
    return 1;
  if (flag == 0)
    return 2;
  return 3;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  int i;
  int nCase = 1;

  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.txt", "w", stdout);

  char result[][50] = {"X won", "O won", "Draw", "Game has not completed"};
  scanf("%d", &T);
  while (T--) {
    for (i = 0; i < 4; i++)
      scanf("%s", g[i]);
    printf("Case #%d: %s\n", nCase++, result[gao()]);
  }
  return 0;
}
