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
char buffer[20];

int isPal(int n) {
  int i;
  int j;

  i = 0;
  while (n) {
    buffer[i++] = n % 10;
    n /= 10;
  }
  i--;
  for (j = 0; j < i; j++, i--)
    if (buffer[j] != buffer[i])
      return 0;
  return 1;
}

int isPalLL(long long n) {
  int i;
  int j;

  i = 0;
  while (n) {
    buffer[i++] = n % 10;
    n /= 10;
  }
  i--;
  for (j = 0; j < i; j++, i--)
    if (buffer[j] != buffer[i])
      return 0;
  return 1;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  long long a;
  long long b;

  int T;
  int tcase;
  int *count;

  int sa;
  int sb;
  int i;

  count = malloc(10000001 * sizeof(int));
  {
    if (!(count != NULL)) {
      fprintf(stderr, "%s\n", "Out of memory!");
      exit(-1);
    }
  };

  count[0] = 1;
  for (i = 1; i <= 10000000; i++)
    if (isPal(i) && isPalLL(((long long)i) * i))
      count[i] = count[i - 1] + 1;
    else
      count[i] = count[i - 1];
  scanf("%d", &T);
  for (tcase = 1; tcase <= T; tcase++) {
    scanf("%lld %lld", &a, &b);
    sa = ceil(sqrt((double)a));
    sb = sqrt((double)b);
    printf("Case #%d: %d\n", tcase, count[sb] - count[sa - 1]);
  }
  return 0;
}
