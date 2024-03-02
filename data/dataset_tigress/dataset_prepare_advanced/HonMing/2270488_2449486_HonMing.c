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
  int j;

  int ii;
  int jj;
  int kk;

  int res;
  int mm;
  int end;
  int xw;
  int ow;

  int n;
  int m;

  int max;
  int map[200][200];
  int dp[200][200];

  unsigned long long result;

  scanf("%d", &mm);

  for (ii = 1; ii <= mm; ii++) {
    memset(dp, 0, 200 * 200);
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        scanf("%d", &map[i][j]);
        dp[i][j] = 200;
      }
    }

    for (i = 0; i < n; i++) {
      max = 0;
      for (j = 0; j < m; j++) {
        if (map[i][j] > max)
          max = map[i][j];
      }
      for (j = 0; j < m; j++) {
        if (max < dp[i][j])
          dp[i][j] = max;
      }
    }
    for (i = 0; i < m; i++) {
      max = 0;
      for (j = 0; j < n; j++) {
        if (map[j][i] > max)
          max = map[j][i];
      }
      for (j = 0; j < n; j++) {
        if (max < dp[j][i])
          dp[j][i] = max;
      }
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++)
        if (dp[i][j] != map[i][j])
          break;

      if (j != m)
        break;
    }

    if (i != n)
      printf("Case #%d: NO\n", ii);
    else
      printf("Case #%d: YES\n", ii);
  }
}
