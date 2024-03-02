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
int data[100][100];
int N;
int M;

int check(int x, int y) {
  int i;
  int j;

  int t = data[x][y];
  int result = 1;

  for (i = 0; i < N; ++i) {
    if (t < data[i][y]) {
      result = 0;
      break;
    }
  }
  if (result)
    return 1;

  for (i = 0; i < M; ++i) {
    if (t < data[x][i]) {
      return 0;
    }
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
  int num;
  int i;
  int j;
  int k;

  int result;

  scanf("%d", &num);
  for (i = 1; i <= num; ++i) {
    scanf("%d %d", &N, &M);
    for (j = 0; j < N; ++j) {
      for (k = 0; k < M; ++k) {
        scanf("%d", &(data[j][k]));
      }
    }

    result = 1;

    for (j = 0; j < N; ++j) {
      for (k = 0; k < M; ++k) {
        if (!check(j, k)) {
          result = 0;
          goto LAST;
        }
      }
    }
  LAST:
    printf("Case #%d: ", i);
    if (result) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}
