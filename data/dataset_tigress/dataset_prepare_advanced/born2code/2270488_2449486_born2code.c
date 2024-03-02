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

int equal(int a[100][100], int b[100][100], int n, int m) {
  int i;
  int j;

  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      if (a[i][j] != b[i][j])
        return 0;
    }
  return 1;
}
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T1;
  int T;
  int n;
  int m;
  int i;
  int j;
  int max = 0;
  int x;

  int a[100][100];
  int b[100][100];

  T = 1;
  for (scanf("%d", &T1); T <= T1; T++) {
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) {
        scanf("%d", &a[i][j]);
        if (a[i][j] > max)
          max = a[i][j];
      }
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
        b[i][j] = max;
    for (i = 0; i < n; i++) {
      x = a[i][0];
      {
        j = 1;
        while (a[i][j] == x && j < m) {
          j++;
        }
        if (j == m)
          for (j = 0; j < m; j++)
            b[i][j] = x;
      }
    }
    for (j = 0; j < m; j++) {
      x = a[0][j];
      {
        i = 1;
        while (a[i][j] == x && i < n)
          i++;
        if (i == n)
          for (i = 0; i < n; i++)
            b[i][j] = x;
      }
    }

    printf("Case #%d: ", T);
    if (equal(a, b, n, m)) {
      printf("YES\n");
    } else
      printf("NO\n");
  }
  return 0;
}
