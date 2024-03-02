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

int a;
int b;
int digit;
int ten[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
int n[1234];
int nNum;

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int check(int num) {
  int i;
  int ans = 0;
  nNum = 0;
  for (i = 1; i < digit; ++i) {
    n[nNum] = num % ten[i] * ten[digit - i] + num / ten[i];
    if (n[nNum] >= a && n[nNum] <= b && n[nNum] < num) {
      ++nNum;
    }
  }
  qsort(n, nNum, sizeof(int), cmp);
  ans = (nNum > 0);
  for (i = 1; i < nNum; ++i) {
    if (n[i] != n[i - 1])
      ++ans;
  }

  return ans;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int i;
  int ans;
  int Case = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &a, &b);
    for (i = a, digit = 0; i > 0; i /= 10, ++digit)
      ;
    for (i = a, ans = 0; i <= b; ++i) {
      ans += check(i);
    }
    printf("Case #%d: %d\n", ++Case, ans);
  }

  return 0;
}
