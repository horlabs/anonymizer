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
int data[10000001];
void init() {
  int num[20];
  int j;
  int flag;

  long long tmp;
  freopen("C-small-attempt0.in.txt", "r", stdin);
  freopen("C-small-attempt0.out.txt", "w", stdout);
  memset(data, 0, sizeof(data));
  for (int i = 0; i < 10000001; i++) {
    tmp = i * i;
    j = 0;
    while (tmp != 0) {
      num[j] = tmp % 10;
      tmp = tmp / 10;
      j++;
    }
    flag = 1;
    for (int k = 0; k < j; k++) {
      if (num[k] != num[j - k - 1]) {
        flag = 0;
        break;
      }
    }
    tmp = i;
    j = 0;
    while (tmp != 0) {
      num[j] = tmp % 10;
      tmp = tmp / 10;
      j++;
    }
    for (int k = 0; k < j; k++) {
      if (num[k] != num[j - k - 1]) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      data[i] = 1;
    }
  }
  for (int i = 1; i < 10000001; i++) {
    data[i] = data[i - 1] + data[i];
  }
}
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  long long A;
  long long B;

  int T;

  init();
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%lld%lld", &A, &B);
    int a = (int)sqrt(A);
    int b = (int)sqrt(B);
    if (a * a == A)
      a--;
    printf("Case #%d: %d\n", t, data[b] - data[a]);
  }
  return 0;
}
