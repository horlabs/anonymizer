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

int espalindromo(long long n);

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  long long cases;
  long long casos;
  long long i;
  long long j;

  long long a;
  long long b;
  long long minimo;
  long long maximo;
  long long total;

  scanf("%I64d", &cases);
  for (casos = 1; casos <= cases; casos++) {
    scanf("%I64d %I64d", &a, &b);

    minimo = sqrt(a);
    maximo = sqrt(b);
    if (minimo * minimo < a)
      minimo++;

    total = 0;
    for (i = minimo; i <= maximo; i++) {
      if (espalindromo(i)) {
        if (espalindromo(i * i)) {

          total++;
        }
      }
    }

    printf("Case #%I64d: %I64d\n", casos, total);
  }
}

int espalindromo(long long n) {
  long long cadena[110];
  long long i;
  long long total;

  i = 0;
  while (n) {
    cadena[i] = n % 10;
    n /= 10;
    i++;
  }
  total = i - 1;
  i = 0;
  while (i <= (total - i)) {
    if (cadena[i] != cadena[total - i]) {
      return (0);
    }
    i++;
  }
  return (1);
}
