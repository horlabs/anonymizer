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

int n;
int m;
int map[123][123];
int gg;
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

  int p;
  int max;
  scanf("%d", &T);
  for (t = 1; t <= T; ++t) {
    scanf("%d %d", &n, &m);
    memset(map, 0, sizeof(map));
    for (i = max = 1; i <= n; ++i) {
      for (j = 1; j <= m; ++j) {
        scanf("%d", &map[i][j]);
        if (map[i][j] >= max)
          max = map[i][j];
      }
    }
    gg = 0;
    for (i = 1; i <= n && !gg; ++i) {
      for (j = 1; j <= m && !gg; ++j) {
        for (p = 1; p <= m && map[i][p] <= map[i][j]; ++p)
          ;
        if (p > m)
          continue;
        for (p = 1; p <= n && map[p][j] <= map[i][j]; ++p)
          ;
        if (p <= n)
          gg = 1;
      }
    }
    printf("Case #%d: ", t);
    if (!gg)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}