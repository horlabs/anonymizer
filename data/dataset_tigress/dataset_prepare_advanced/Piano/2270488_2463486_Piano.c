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
  int u;
  int i;
  int cnt = 0;

  long long num[39];
  for (i = 1; i <= 2001002; ++i) {
    char s[21] = {};
    long long sq = (long long)i * i;
    long long j = (long long)i * i;

    int c = 0;
    while (j) {
      s[c++] = j % 10 + '0';
      j /= 10;
    }
    sscanf(s, "%I64d", &j);
    if (sq == j) {
      char ss[21] = {};
      j = i, c = 0;
      while (j) {
        ss[c++] = j % 10 + '0';
        j /= 10;
      }
      sscanf(ss, "%I64d", &j);
      if (i == j) {
        num[cnt++] = sq;
      }
    }
  }
  scanf("%d", &t);
  for (u = 1; u <= t; ++u) {
    long long a;
    long long b;

    int l;
    int r;
    int m;
    int x;
    int y;

    scanf("%I64d%I64d", &a, &b);
    for (l = 0, r = 39; l < r;) {
      m = (l + r) / 2;
      if (num[m] == a) {
        l = m;
        break;
      } else if (num[m] < a)
        l = m + 1;
      else
        r = m;
    }
    x = l;
    for (l = 0, r = 39; l < r;) {
      m = (l + r) / 2;
      if (num[m] <= b) {
        l = m + 1;
      } else
        r = m;
    }
    y = l;
    printf("Case #%d: %d\n", u, y - x);
  }
  return 0;
}
