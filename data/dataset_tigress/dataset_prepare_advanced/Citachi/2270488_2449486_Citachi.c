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
  FILE *fp_in;
  FILE *fp_out;

  int a[10][10];
  int T;
  int N;
  int M;
  int i;
  int j;
  int n;
  int c;
  int flag = 0;

  fp_in = fopen("B-small-attempt1.in", "r");
  fp_out = fopen("output.txt", "w");
  fscanf(fp_in, "%d", &T);
  for (c = 1; c <= T; c++) {
    flag = 0;
    fscanf(fp_in, "%d %d", &N, &M);
    for (i = 0; i < N; i++) {
      for (j = 0; j < M; j++)
        fscanf(fp_in, "%d", &a[i][j]);
    }
    for (i = 0; i < N; i++) {
      n = a[i][0];

      for (j = 0; j < M; j++) {
        if (a[i][j] != 0) {
          a[i][j] = (int)abs(n - a[i][j]);
        }
      }
    }

    for (j = 0; j < M; j++) {
      n = a[0][j];
      for (i = 0; i < N; i++) {
        if (a[i][j] != 0) {
          a[i][j] = (int)abs(n - a[i][j]);
        }
      }
    }

    for (i = 0; i < N; i++) {
      n = a[i][M - 1];
      if (n == 0)
        continue;
      for (j = 0; j < M; j++) {
        if (a[i][j] != 0) {
          a[i][j] = (int)abs(n - a[i][j]);
        }
      }
    }

    for (j = 0; j < M; j++) {
      n = a[N - 1][j];
      if (n == 0)
        continue;
      for (i = 0; i < N; i++) {
        if (a[i][j] != 0) {
          a[i][j] = (int)abs(n - a[i][j]);
        }
      }
    }

    for (i = 1; i < N - 1; i++) {
      for (j = 1; j < M - 1; j++)
        if (a[i][j] != 0) {
          flag = 1;
          break;
        }
    }
    if (flag == 0)
      fprintf(fp_out, "Case #%d: YES\n", c);
    else
      fprintf(fp_out, "Case #%d: NO\n", c);
  }
  fclose(fp_in);
  fclose(fp_out);
  system("pause");
}
