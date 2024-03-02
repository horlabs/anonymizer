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
  int t;
  int i;

  scanf("%d", &t);

  for (i = 0; i < t; i++) {
    int n;
    int m;
    int p = 0;
    int f = 0;
    int j;
    int k;

    int a[100][100];
    int b[100][100] = {0};

    scanf("%d %d", &n, &m);

    for (j = 0; j < n; j++) {
      for (k = 0; k < m; k++) {
        scanf("%d", &a[j][k]);

        if (a[j][k] > p)
          p = a[j][k];
      }
    }

    for (j = 0; j < n; j++) {
      for (k = 0; k < m - 1; k++) {
        if (a[j][k] != a[j][k + 1])
          break;
      }

      if (k == m - 1) {
        for (k = 0; k < m; k++)
          b[j][k] = 1;
      }
    }

    for (j = 0; j < m; j++) {
      for (k = 0; k < n - 1; k++) {
        if (a[k][j] != a[k + 1][j])
          break;
      }

      if (k == n - 1) {
        for (k = 0; k < n; k++)
          b[k][j] = 1;
      }
    }

    for (j = 0; j < n; j++) {
      for (k = 0; k < m; k++) {
        if (a[j][k] != p && b[j][k] == 0) {
          f = 1;
        }
      }
    }

    if (f == 0) {
      printf("Case #%d: YES\n", i + 1);
    } else {
      printf("Case #%d: NO\n", i + 1);
    }
  }

  return 0;
}
