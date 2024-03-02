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

int digits(int);
int power(int, int);

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int i;
  int j;
  int l;
  int d;
  int k;
  int s;
  int t[8];
  int n;
  int m;
  int T;
  int A;
  int B;

  FILE *fin = fopen("C-small-attempt0.in", "r");
  FILE *fout = fopen("out.txt", "w");

  fscanf(fin, "%d", &T);

  for (i = 0; i < T; i++) {
    fscanf(fin, "%d%d\n", &A, &B);
    for (s = 0, d = digits(A), n = A; n < B; n++)
      for (k = 0, j = 1; j < d; j++) {
        m = n % power(10, j) * power(10, d - j) + n / power(10, j);
        if (m > n && m <= B) {
          for (l = 0; l < k && t[l] != m; l++)
            ;
          if (l == k)
            t[k++] = m, s += 1;
        }
      }
    fprintf(fout, "Case #%d: %d\n", i + 1, s);
  }

  fclose(fin);
  fclose(fout);
  return 0;
}

int digits(int n) { return n ? 1 + digits(n / 10) : 0; }

int power(int n, int k) {
  int i;
  for (i = n, n = 1; --k >= 0; n *= i)
    ;
  return n;
}
