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

int move(int num, int steps, int size) {
  int r;
  int m = 1;
  int sm = 1;
  int p;

  p = size - steps;
  while (p--)
    m = m * 10;
  while (steps--)
    sm = sm * 10;
  r = (num % m) * sm + (num / m);
  return r;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int a;
  int b;
  int t;
  int i;
  int j;
  int temp;
  int digits;
  int k;
  int count;
  int m;

  int dup;

  (scanf("%d", &t) == 1);
  for (i = 1; i <= t; i++) {
    count = 0;
    (scanf("%d %d", &a, &b) == 2);
    for (j = a; j <= b; j++) {
      dup = 0;
      digits = floor(log10(j)) + 1;
      for (k = 1; k < digits; k++) {
        m = move(j, k, digits);
        if (m >= a && m <= b && m > j && m != dup) {

          count++;
          dup = m;
        }
      }
    }
    printf("Case #%d: %d\n", i, count);
  }
  return 0;
}