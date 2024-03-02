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

unsigned long int rotate(unsigned long int n, int d) {
  unsigned long x;
  unsigned long p;
  unsigned long q;

  x = pow(10, d - 1);
  p = n % x;
  q = n / x;
  p = p * 10 + q;
  return p;
}

int digits(unsigned long int n) {
  int d = 0;
  while (n) {
    d++;
    n /= 10;
  }
  return d;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  unsigned long t;
  unsigned long a;
  unsigned long b;
  unsigned long m;
  unsigned long n;

  unsigned long i;
  unsigned long j;
  unsigned long k;
  unsigned long d;
  unsigned long p;

  scanf("%ld", &t);
  for (i = 1; i <= t; i++) {
    scanf("%ld%ld", &a, &b);
    d = digits(a);
    k = 0;
    for (m = a + 1; m <= b; m++) {
      for (p = a; p < m; p++) {
        n = rotate(p, d);
        j = 0;
        while (n != m && j < d - 1) {
          n = rotate(n, d);
          j++;
        }
        if (j < d - 1) {
          k++;
        }
      }
    }
    printf("Case #%ld: %ld\n", i, k);
  }

  return 0;
}
