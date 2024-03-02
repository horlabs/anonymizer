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

char g[6][6];

int check(int x, int y, int dx, int dy, char c) {
  int i;
  int n;

  for (n = i = 0; i < 4; i++) {
    if (g[x][y] == c || g[x][y] == 'T')
      n++;
    x += dx;
    y += dy;
  }
  return n == 4;
}

int won(char c) {
  int i;
  for (i = 0; i < 4; i++) {
    if (check(0, i, 1, 0, c))
      return 1;
    if (check(i, 0, 0, 1, c))
      return 1;
  }
  if (check(0, 0, 1, 1, c))
    return 1;
  if (check(0, 3, 1, -1, c))
    return 1;
  return 0;
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
  int j;
  int z;
  int no = 1;

  scanf("%d", &T);
  while (T--) {
    for (i = 0; i < 4; i++)
      scanf("%s", g[i]);
    printf("Case #%d: ", no++);
    if (won('O'))
      puts("O won");
    else if (won('X'))
      puts("X won");
    else {
      for (i = z = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
          if (g[i][j] == '.')
            z = 1;
      if (z)
        puts("Game has not completed");
      else
        puts("Draw");
    }
  }
  return 0;
}
