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

void itos(int a, char s[]) {
  int i;
  int j;
  int k;

  char x;
  char y[100];

  i = a;
  j = 0;
  while (a) {
    s[j++] = a % 10 + '0';
    a /= 10;
  }
  s[j] = '\0';
  k = strlen(s);
  for (i = 0, j = k - 1; i <= k - 1; j--, i++) {
    y[j] = s[i];
  }
  for (i = 0; i <= k - 1; i++)
    s[i] = y[i];
}
int palind(int a) {
  char x[100];
  itos(a, x);
  int n = strlen(x);
  int i;

  for (i = 0; i < n - 1; i++) {
    if (x[i] != x[n - i - 1])
      return 0;
  }

  return 1;
}

int next(int i) {
  int j = i + 1;
  while (!(palind(j)))
    j++;
  return j;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  int T1;
  int a;
  int b;
  int lb;
  int ub;
  int count;
  int i;

  T = 1;
  for (scanf("%d", &T1); T <= T1; T++) {
    scanf("%d%d", &a, &b);
    lb = ceil(sqrt(a));
    ub = floor(sqrt(b));
    count = 0;
    i = lb;
    while (!(palind(i)))
      i++;
    for (; i <= ub; i = next(i)) {
      if (palind(i * i)) {
        count++;
      }
    }
    printf("Case #%d: %d\n", T, count);
  }
  return 0;
}
