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
  int a[200];
  int b[200][3];
  int i;
  int p;
  int q;
  int r;
  int j;
  int N;
  int S;
  int count = 0;
  int temp;
  int T;
  int m = 1;

  FILE *f1;
  FILE *f2;

  f1 = fopen("B-small-attempt0.in", "r");
  f2 = fopen("output.txt", "w");
  fscanf(f1, "%d", &T);
  while (m <= T) {
    fscanf(f1, "%d %d %d", &N, &S, &p);
    a[0] = N;
    a[1] = S;
    a[2] = p;
    for (i = 0; i < N; i++) {
      fscanf(f1, "%d", &a[i + 3]);
    }
    for (i = 0; i < a[0]; i++) {
      for (j = 10; j > 0; j--) {

        if (a[i + 3] / j == 0) {
          if (j - 1 == 0) {
            b[i][0] = 0;
            b[i][1] = 0;
            b[i][2] = 0;
          }
          continue;
        }

        if (abs((a[i + 3] % j) - j) == 1 || abs((a[i + 3] % j) - j) == 2) {
          b[i][1] = j;

          b[i][0] = a[i + 3] % j;
          b[i][2] = j;
          break;
        }
      }
    }
    while (S > 0) {
      for (i = 0; i < N; i++) {
        if (b[i][0] <= p) {
          S--;
          b[i][0]++;
          b[i][1]--;
          b[i][2]--;
          break;
        } else if (b[i][1] <= p) {
          S--;
          b[i][0]--;
          b[i][1]++;
          b[i][2]--;
          break;
        } else {
          S--;
          b[i][0]--;
          b[i][1]--;
          b[i][2]++;
          break;
        }
      }
    }
    for (i = 0; i < a[0]; i++) {
      if (b[i][1] >= p || b[i][0] >= p || b[i][2] >= p)
        count++;
    }
    fprintf(f2, "Case #%d: %d\n", m, count);
    m++;
    count = 0;
  }
  return 0;
}
