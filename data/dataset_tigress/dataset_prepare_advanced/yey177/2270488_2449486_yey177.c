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

int d[102][102];

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int n;
  int m;
  int i;
  int j;
  int k;
  int x;
  int max;
  int min;
  int f;

  scanf("%d", &t);
  for (x = 1; x <= t; x++) {
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
        scanf("%d", &d[i][j]);
    f = 1;
    for (k = 1; k <= 100; k++) {
      for (i = 0; i < n; i++) {
        min = 101;
        max = 0;
        for (j = 0; j < m; j++) {
          if (d[i][j]) {
            min = (((min) < (d[i][j])) ? (min) : (d[i][j]));
            max = (((max) > (d[i][j])) ? (max) : (d[i][j]));
          }
        }
        if (min == k && max == k) {
          for (j = 0; j < m; j++)
            d[i][j] = 0;
        }
      }
      for (j = 0; j < m; j++) {
        min = 101;
        max = 0;
        for (i = 0; i < n; i++) {
          if (d[i][j]) {
            min = (((min) < (d[i][j])) ? (min) : (d[i][j]));
            max = (((max) > (d[i][j])) ? (max) : (d[i][j]));
          }
        }
        if (min == k && max == k) {
          for (i = 0; i < n; i++)
            d[i][j] = 0;
        }
      }
      for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
          if (d[i][j] == k) {
            f = 0;
            goto END;
          }
        }
    }
  END:
    printf("Case #%d: %s\n", x, f ? "YES" : "NO");
  }
  return 0;
}
