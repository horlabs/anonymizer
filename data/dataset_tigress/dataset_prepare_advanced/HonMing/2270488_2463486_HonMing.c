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
  int i;
  int j;

  int ii;
  int jj;
  int kk;

  int res;
  int mm;
  int end;
  int xw;
  int ow;

  int n;
  int m;

  int max;
  unsigned long long dp[10000];

  int result;
  unsigned long long llu;
  unsigned long long a;
  unsigned long long b;

  char line[200];

  j = 0;
  for (llu = 1; llu <= 10000000; llu++) {
    sprintf(line, "%llu", llu);
    for (i = 0; i < strlen(line) / 2; i++) {
      if (line[i] != line[strlen(line) - 1 - i])
        break;
    }

    if (i != strlen(line) / 2)
      continue;

    sprintf(line, "%llu", llu * llu);

    for (i = 0; i < strlen(line) / 2; i++) {
      if (line[i] != line[strlen(line) - 1 - i])
        break;
    }

    if (i == strlen(line) / 2)
      dp[j++] = llu * llu;
  }

  scanf("%d", &mm);

  for (ii = 1; ii <= mm; ii++) {
    result = 0;
    scanf("%llu%llu", &a, &b);

    for (i = 0; i < j; i++) {
      if (dp[i] >= a && dp[i] <= b)
        result++;

      if (dp[i] > b)
        break;
    }
    printf("Case #%d: %d\n", ii, result);
  }
}
