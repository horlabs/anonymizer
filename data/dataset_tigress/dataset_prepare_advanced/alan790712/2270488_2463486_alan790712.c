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

long long a;
long long b;
char isp[10000001] = {0};
char str[1234];
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int T;

  int i;
  int j;
  int k;

  long long int li;
  int ans = 0;
  for (i = 1; i < 10000001; ++i) {
    sprintf(str, "%d", i);
    for (j = 0, k = strlen(str) - 1; j < k && str[j] == str[k]; ++j, --k)
      ;
    if (j >= k)
      isp[i] = 1;
  }
  scanf("%d", &T);

  for (t = 1; t <= T; ++t) {
    ans = 0;
    scanf("%lld %lld", &a, &b);
    for (li = (long long int)(sqrt(a)); li * li <= b; ++li) {
      if (li * li < a)
        continue;
      if (isp[li]) {
        sprintf(str, "%lld", li * li);

        for (j = 0, k = strlen(str) - 1; j < k && str[j] == str[k]; ++j, --k)
          ;
        if (j >= k) {
          ++ans;
        }
      }
    }
    printf("Case #%d: ", t);
    printf("%d\n", ans);
  }
  return 0;
}
