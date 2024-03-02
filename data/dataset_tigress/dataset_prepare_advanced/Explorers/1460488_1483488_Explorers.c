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
  int ntest;
  int i;
  int len;
  int k;
  int npairs[50] = {0};

  long la;
  long lb;
  long j;
  long divider;
  long multiplier;
  long remainder;
  long divisor;
  long pairnum;

  scanf("%d", &ntest);

  for (i = 0; i < ntest; i++) {
    scanf("%ld %ld", &la, &lb);
    len = numlen(la);

    for (j = la; j < lb; j++) {

      for (k = len - 1; k >= 1; k--) {
        multiplier = pow(10, k);
        divider = pow(10, len - k);

        divisor = j / divider;
        remainder = j % divider;
        pairnum = remainder * multiplier + divisor;

        if (numlen(pairnum) != len)
          continue;

        if (pairnum > j && pairnum <= lb) {

          npairs[i]++;
        }
      }
    }
  }
  for (i = 0; i < ntest; i++) {
    printf("Case #%d: %d\n", i + 1, npairs[i]);
  }
}

int numlen(long n) {
  if (n < 10)
    return 1;
  else
    return 1 + numlen(n / 10);
}
