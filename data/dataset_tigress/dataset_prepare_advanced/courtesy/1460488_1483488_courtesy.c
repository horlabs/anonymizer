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
FILE *f1;
FILE *f2;
int str1[8];
int str2[8];
int len;
long long te[7];
long long co;
int ln(long long int i) {
  int r = 0;
  while (i > 0) {
    r++;
    i /= 10;
  }
  return (r - 1);
}
void conv(long long int i) {
  int j;
  int k;

  for (j = len; j >= 0; j--) {
    str1[j] = i % 10;
    i /= 10;
  }
}
long long int get() {
  long long int j = 0;
  int i;
  for (i = 0; i <= len; i++) {
    j += str2[i];
    j = j * 10;
  }
  j /= 10;
  return (j);
}
int eq(long long int j) {
  int i;
  for (i = 0; i <= len; i++) {
    if (str1[i] != str2[i])
      return (0);
  }
  return (1);
}
void sh() {
  int i;
  int j;
  int k;

  i = str2[len];
  for (j = (len - 1); j >= 0; j--)
    str2[j + 1] = str2[j];
  str2[0] = i;
}
int chk(long long int i, long long int m, long long int n) {
  if (str1[0] == 0)
    return (0);
  int j;
  int k = 0;

  for (j = 0; j <= len; j++)
    str2[j] = str1[j];
  int ch;
  long long int f;
  co = -1;
  for (j = 1; j <= len; j++) {
    sh();
    f = get();
    for (ch = 0; ch <= co; ch++) {
      if (te[ch] == f)
        goto lst;
    }
    if ((f > i) && (f >= m) && (f <= n)) {
      k++;
      co++;
      te[co] = f;
    }
  lst:
    k += 0;
  }
  return (k);
}
void Main() {
  long long m;
  long long n;
  long long i;

  long r = 0;
  long k;

  fscanf(f1, "%lld", &m);
  fscanf(f1, "%lld", &n);
  len = ln(m);
  if (len == 0)
    goto end;
  for (i = m; i <= n; i++) {
    conv(i);
    k = chk(i, m, n);
    r += k;
    if (k > 0)
      printf("%lld:%ld\t", i, k);
  }
end:
  fprintf(f2, "%ld", r);
}
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  f1 = fopen("/home/vivek/Desktop/s.in", "r");
  f2 = fopen("/home/vivek/Desktop/s.out", "w");
  int cs;
  int i;

  char c;
  fscanf(f1, "%d", &cs);
  for (i = 1; i <= cs; i++) {
    fprintf(f2, "Case #%d: ", i);
    Main();
    c = '\n';
    fputc(c, f2);
  }
  return (1);
}
