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

int g[110][110];
int gg[110][110];
int row[110];
int col[110];
int h[220][3];

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  int nCase = 1;

  int ROW = 0;
  int COL = 1;

  int flag;
  int n;
  int m;
  int i;
  int j;
  int cc;
  int t;

  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B_out.txt", "w", stdout);
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
      row[i] = 0;
    for (j = 0; j < m; j++)
      col[j] = 0;
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
        scanf("%d", &g[i][j]), row[i] = max(row[i], g[i][j]),
                               col[j] = max(col[j], g[i][j]);
    cc = 0;
    for (i = 0; i < n; i++)
      h[cc][0] = row[i], h[cc][1] = i, h[cc][2] = ROW, cc++;
    for (i = 0; i < m; i++)
      h[cc][0] = col[i], h[cc][1] = i, h[cc][2] = COL, cc++;
    for (i = 0; i < cc; i++)
      for (j = 0; j < i; j++)
        if (h[i][0] < h[j][0])
          (t = h[i][0], h[i][0] = h[j][0], h[j][0] = t),
              (t = h[i][1], h[i][1] = h[j][1], h[j][1] = t),
              (t = h[i][2], h[i][2] = h[j][2], h[j][2] = t);
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
        gg[i][j] = 100;
    for (i = cc - 1; i >= 0; i--) {
      if (h[i][2] == ROW)
        for (j = 0; j < m; j++)
          gg[h[i][1]][j] = h[i][0];
      else
        for (j = 0; j < n; j++)
          gg[j][h[i][1]] = h[i][0];
    }
    flag = 0;
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
        if (g[i][j] != gg[i][j])
          flag = 1;
    printf("Case #%d: %s\n", nCase++, flag ? "NO" : "YES");
  }
  return 0;
}
