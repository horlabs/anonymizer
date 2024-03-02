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
long most_sig_digit(long a) {
  long tens;

  for (tens = 1; a >= 10; a /= 10, tens *= 10)
    ;

  return tens;
}

long rotate(long m, long msd) { return m / 10 + msd * (m % 10); }

long pairs(long a, long b, long n) {
  const long msd = most_sig_digit(a);
  long count = 0;
  long m;

  for (m = rotate(n, msd); m != n; m = rotate(m, msd)) {
    if (m <= b && m > n) {
      count++;
      fprintf(stderr, "(%ld, %ld)\n", n, m);
    }
  }

  return count;
}
void do_test(int t) {
  long a;
  long b;
  long i;

  long count = 0;

  scanf("%ld %ld", &a, &b);

  for (i = a; i <= b; i++)
    count += pairs(a, b, i);

  printf("Case #%d: %ld\n", t + 1, count);
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

  for (i = 0; i < t; i++)
    do_test(i);

  return 0;
}
