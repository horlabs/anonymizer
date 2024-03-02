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

long long tab[41] = {
    0LL,       1LL,       2LL,       3LL,       11LL,      22LL,      101LL,
    111LL,     121LL,     202LL,     212LL,     1001LL,    1111LL,    2002LL,
    10001LL,   10101LL,   10201LL,   11011LL,   11111LL,   11211LL,   20002LL,
    20102LL,   100001LL,  101101LL,  110011LL,  111111LL,  200002LL,  1000001LL,
    1001001LL, 1002001LL, 1010101LL, 1011101LL, 1012101LL, 1100011LL, 1101011LL,
    1102011LL, 1110111LL, 1111111LL, 2000002LL, 2001002LL, 10000001LL};

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int i;
  int T;
  int cc;
  int nCase = 1;

  long long a;
  long long b;

  freopen("C-small-attempt0.in", "r", stdin);
  freopen("C_out.txt", "w", stdout);
  for (i = 0; i < 41; i++)
    tab[i] *= tab[i];
  scanf("%d", &T);
  while (T--) {
    scanf("%I64d%I64d", &a, &b);
    cc = 0;
    for (i = 0; i < 41; i++)
      if (tab[i] >= a && tab[i] <= b)
        cc++;
    printf("Case #%d: %d\n", nCase++, cc);
  }
  return 0;
}
