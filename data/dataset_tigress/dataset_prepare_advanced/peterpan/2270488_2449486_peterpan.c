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
void readline() {
  while (getchar() != '\n')
    ;
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
  int tcase;
  int T;
  int N;
  int M;
  int res;

  int a[101][101];
  int maxRow[101];
  int maxCol[101];

  scanf("%d", &T);
  for (tcase = 1; tcase <= T; tcase++) {
    scanf("%d", &N);
    scanf("%d", &M);
    res = 1;
    for (i = 0; i < N; i++) {
      maxRow[i] = 0;
      for (j = 0; j < M; j++) {
        scanf("%d", &(a[i][j]));
        if (maxRow[i] < a[i][j])
          maxRow[i] = a[i][j];
      }
    }
    for (j = 0; j < M; j++) {
      maxCol[j] = 0;
      for (i = 0; i < N; i++)
        if (maxCol[j] < a[i][j])
          maxCol[j] = a[i][j];
    }
    for (i = 0; i < N && res; i++)
      for (j = 0; j < M; j++)
        if (a[i][j] < maxRow[i] && a[i][j] < maxCol[j]) {
          res = 0;
          break;
        }

    printf("Case #%d: %s\n", tcase, res ? "YES" : "NO");
  }

  return 0;
}
