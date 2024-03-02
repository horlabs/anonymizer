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

int check(long long x) {
  int i;
  int j;

  int a[20];

  for (i = 0; x > 0; i++) {
    a[i] = x % 10;
    x /= 10;
  }

  for (j = 0; j < i / 2; j++) {
    if (a[j] != a[i - j - 1])
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
  int c = 0;
  int t;
  int i;

  long long a[100] = {0};

  for (i = 1; i <= 10000000; i++) {
    if (check(i) && check((long long)i * i))
      a[c++] = (long long)i * i;
  }

  scanf("%d", &t);

  for (i = 0; i < t; i++) {
    int sum = 0;
    int j;

    long long x;
    long long y;

    scanf("%lld %lld", &x, &y);

    for (j = 0; j < c; j++) {
      if (a[j] >= x && a[j] <= y)
        sum++;
    }

    printf("Case #%d: %d\n", i + 1, sum);
  }

  return 0;
}