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

int compi(const void *a, const void *b) {
  if (*(int *)a > *(int *)b)
    return -1;
  if (*(int *)a < *(int *)b)
    return 1;
  return 0;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  int caseno = 1;

  int n;
  int s;
  int p;
  int lo1;
  int lo2;

  int i;
  int score[100];
  int ans;

  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d", &n, &s, &p);
    for (i = 0; i < n; i++)
      scanf("%d", &score[i]);
    qsort(score, n, sizeof(int), compi);
    lo1 = p - 1;
    lo2 = p - 2;
    if (lo1 < 0)
      lo1 = 0;
    if (lo2 < 0)
      lo2 = 0;
    for (ans = i = 0; i < n; i++) {
      if (score[i] >= p + lo1 + lo1)
        ans++;
      else if (s && score[i] >= p + lo2 + lo2)
        ans++, s--;
    }
    printf("Case #%d: %d\n", caseno++, ans);
  }
  return 0;
}
