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

int a[105][105];
int des[105][105];
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int i;
  int r;
  int c;
  int j;
  int k;
  int max;

  scanf("%d", &t);
  for (i = 1; i <= t; i++) {
    scanf("%d %d", &r, &c);
    for (j = 0; j < r; j++)
      for (k = 0; k < c; k++) {
        a[j][k] = 100;
        scanf("%d", &des[j][k]);
      }
    for (j = 0; j < r; j++) {
      max = 0;
      for (k = 0; k < c; k++)
        if (des[j][k] > max)
          max = des[j][k];
      for (k = 0; k < c; k++) {
        if (a[j][k] >= max)
          a[j][k] = max;
      }
    }
    for (j = 0; j < c; j++) {
      max = 0;
      for (k = 0; k < r; k++)
        if (des[k][j] > max)
          max = des[k][j];
      for (k = 0; k < r; k++)
        if (a[k][j] >= max)
          a[k][j] = max;
    }
    printf("Case #%d: ", i);
    for (j = 0; j < r; j++) {
      for (k = 0; k < c; k++)
        if (a[j][k] != des[j][k])
          break;
      if (k < c)
        break;
    }
    if (j < r)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
