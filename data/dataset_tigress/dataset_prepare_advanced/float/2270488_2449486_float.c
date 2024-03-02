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

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int cas;
  int cas_n;
  int N;
  int M;
  int i;
  int j;
  int k;
  int flag;

  int lawn[128][128];
  scanf("%d", &cas_n);
  for (cas = 1; cas <= cas_n; cas++) {
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
      for (j = 0; j < M; j++)
        scanf("%d", &lawn[i][j]);

    flag = 0;
    for (i = 0; i < N; i++) {
      for (j = 0; j < M; j++) {
        flag = 0;
        for (k = 0; k < N; k++)
          if (lawn[k][j] > lawn[i][j]) {
            flag++;
            break;
          }
        for (k = 0; k < M; k++)
          if (lawn[i][k] > lawn[i][j]) {
            flag++;
            break;
          }
        if (flag >= 2)
          goto CHECK_END;
      }
    }
  CHECK_END:
    if (i == N && j == M)
      printf("Case #%d: YES\n", cas);
    else
      printf("Case #%d: NO\n", cas);
  }
}
