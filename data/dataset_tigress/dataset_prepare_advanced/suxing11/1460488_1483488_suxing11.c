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

int graph[1010][1010];

int test(int a, int b) {
  char s1[30];
  char s2[30];

  sprintf(s1, "%d", a);
  sprintf(s2, "%d", b);
  int i;
  int j;
  int len = strlen(s1);

  if (len != strlen(s2))
    return 0;
  for (i = 0; i < len; i++) {
    for (j = 0; j < len; j++)
      if (s1[j] != s2[(i + j) % len])
        break;
    if (j == len)
      return 1;
  }
  return 0;
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
  int T;

  int a;
  int b;
  int sum;
  int nCase = 1;

  freopen("C-small-attempt0.in", "r", stdin);
  freopen("c-out.txt", "w", stdout);
  for (i = 1; i <= 1000; i++)
    for (j = 1; j < i; j++)
      if (test(j, i))
        graph[j][i] = 1;
      else
        graph[j][i] = 0;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &a, &b);
    sum = 0;
    for (i = a; i <= b; i++)
      for (j = a; j < i; j++)
        if (graph[j][i] == 1) {

          sum++;
        }
    printf("Case #%d: %d\n", nCase++, sum);
  }
  return 0;
}
