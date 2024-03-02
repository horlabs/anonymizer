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

const int numbers[] = {
    1,       2,       3,       11,      22,      101,     111,     121,
    202,     212,     1001,    1111,    2002,    10001,   10101,   10201,
    11011,   11111,   11211,   20002,   20102,   100001,  101101,  110011,
    111111,  200002,  1000001, 1001001, 1002001, 1010101, 1011101, 1012101,
    1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002};

long long squ[100];

int bis(long long a) {
  int i;
  for (i = 0; i <= sizeof(numbers) / sizeof(int); i++) {
    if (squ[i] > a)
      return i - 1;
  }
  return sizeof(numbers) / sizeof(int);
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  int Tcnt = 0;

  int i;
  for (i = 0; i < sizeof(numbers) / sizeof(int); i++) {
    squ[i] = (long long)numbers[i] * numbers[i];
  }
  squ[i] = LLONG_MAX;
  for (scanf("%d", &T); T; T--) {
    long long a;
    long long b;

    scanf("%lld%lld", &a, &b);
    printf("Case #%d: %d\n", ++Tcnt, bis(b) - bis(a - 1));
  }
  return 0;
}
