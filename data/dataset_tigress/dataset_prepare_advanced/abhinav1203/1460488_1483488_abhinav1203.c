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

int compare(const void *a, const void *b) {
  if (*(int *)a < *(int *)b)
    return -1;
  return 1;
}
int numDigits(int num) {
  int ans = 0;
  while (num > 0) {
    ans++;
    num /= 10;
  }
  return ans;
}
int power(int num) {
  int ans = 1;
  int i;

  for (i = 0; i < num; i++)
    ans *= 10;
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
  int a;
  int b;
  int i;
  int j;
  int x;
  int y;
  int ans;
  int tmp[100];
  int test = 1;

  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &a, &b);
    ans = 0;
    for (i = a; i <= b; i++) {
      tmp[0] = i;
      x = numDigits(i);
      y = power(x - 1);
      for (j = 1; j < x; j++) {
        tmp[j] = tmp[j - 1] / 10 + tmp[j - 1] % 10 * y;
      }
      qsort(tmp, x, sizeof(int), &compare);
      for (j = 0; j < x; j++)
        if (tmp[j] >= a && tmp[j] <= b && (j == 0 || tmp[j] != tmp[j - 1]) &&
            tmp[j] != i)
          ans++;
    }
    printf("Case #%d: %d\n", test, ans / 2);
    test++;
  }
  return 0;
}
