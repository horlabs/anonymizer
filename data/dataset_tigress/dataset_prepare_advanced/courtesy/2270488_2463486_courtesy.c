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

typedef long long ll;
int palin(ll n) {
  int a[20];
  int i;
  int j;
  int k;

  for (i = 0; n > 0; i++, n /= 10)
    a[i] = n % 10;
  for (i--, j = 0; i > j; i--, j++) {
    if (a[i] != a[j])
      return 0;
  }
  return 1;
}
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  freopen("C:\\Users\\vivek\\Desktop\\in.txt", "r", stdin);
  freopen("C:\\Users\\vivek\\Desktop\\out.txt", "w", stdout);

  int i;
  int j;
  int k;
  int t;
  int cs;
  int a;
  int b;
  int l;

  scanf("%d", &cs);
  for (t = 1; t <= cs; t++) {
    scanf("%d %d", &a, &b);
    l = sqrt(b);
    for (i = sqrt(a), k = 0; i <= l; i++) {
      if (palin(i)) {
        j = i * i;
        if ((j >= a) && (j <= b) && palin(j))
          k++;
      }
    }
    printf("Case #%d: %d\n", t, k);
  }
  return 0;
}
