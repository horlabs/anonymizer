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
  int j;
  int k;
  int ground[101][101];
  int n;
  int m;
  int rowmax[100];
  int columnmax[100];

  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d%d", &n, &m);
    for (j = 0; j < n; j++)
      rowmax[j] = 0;
    for (k = 0; k < m; k++)
      columnmax[k] = 0;
    for (j = 0; j < n; j++) {
      for (k = 0; k < m; k++) {
        scanf("%d", &ground[j][k]);
        if (ground[j][k] > rowmax[j])
          rowmax[j] = ground[j][k];
        if (ground[j][k] > columnmax[k])
          columnmax[k] = ground[j][k];
      }
    }
    for (j = 0; j < n; j++) {
      for (k = 0; k < m; k++) {
        if (ground[j][k] != rowmax[j] && ground[j][k] != columnmax[k])
          break;
      }
      if (k != m)
        break;
    }
    if (j != n)
      printf("Case #%d: NO\n", i + 1);
    else
      printf("Case #%d: YES\n", i + 1);
  }
  return 0;
}
