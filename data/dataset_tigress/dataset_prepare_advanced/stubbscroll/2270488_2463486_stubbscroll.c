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

ll tall[1000000];
int n;

void gen() {
  char s[20];
  char t[20];

  int a;
  int i;
  int l;

  n = 0;
  for (a = 1; a < 10000001; a++) {
    sprintf(s, "%d", a);
    l = strlen(s);
    for (i = 0; i + i < l; i++)
      if (s[i] != s[l - i - 1])
        goto fail;
    sprintf(t, "%I64d", (ll)a * a);
    l = strlen(t);
    for (i = 0; i + i < l; i++)
      if (t[i] != t[l - i - 1])
        goto fail;
    tall[n++] = (ll)a * a;
  fail:;
  }
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  int a;
  int b;
  int no = 1;
  int i;
  int ans;

  gen();
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &a, &b);
    for (ans = i = 0; i < n; i++)
      if (a <= tall[i] && tall[i] <= b)
        ans++;
    printf("Case #%d: %d\n", no++, ans);
  }
  return 0;
}
