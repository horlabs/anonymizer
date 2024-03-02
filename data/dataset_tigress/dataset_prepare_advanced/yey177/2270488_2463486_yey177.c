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

long long s[41] = {0LL,
                   1LL,
                   4LL,
                   9LL,
                   121LL,
                   484LL,
                   10201LL,
                   12321LL,
                   14641LL,
                   40804LL,
                   44944LL,
                   1002001LL,
                   1234321LL,
                   4008004LL,
                   100020001LL,
                   102030201LL,
                   104060401LL,
                   121242121LL,
                   123454321LL,
                   125686521LL,
                   400080004LL,
                   404090404LL,
                   10000200001LL,
                   10221412201LL,
                   12102420121LL,
                   12345654321LL,
                   40000800004LL,
                   1000002000001LL,
                   1002003002001LL,
                   1004006004001LL,
                   1020304030201LL,
                   1022325232201LL,
                   1024348434201LL,
                   1210024200121LL,
                   1212225222121LL,
                   1214428244121LL,
                   1232346432321LL,
                   1234567654321LL,
                   4000008000004LL,
                   4004009004004LL,
                   10000000000001LL};

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int i;
  int j;
  int k;

  long long a;
  long long b;

  scanf("%d", &t);
  for (k = 1; k <= t; k++) {
    scanf("%lld%lld", &a, &b);
    i = 0;
    j = 40;
    while (s[i + 1] < a)
      i++;
    while (s[j - 1] > b)
      j--;
    printf("Case #%d: %d\n", k, j - i - 1);
  }
  return 0;
}
