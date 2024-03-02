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
  FILE *fin;
  FILE *fout;

  fin = freopen("C-small-attempt0.in", "r", stdin);
  fout = freopen("C-small-attempt0.out", "w", stdout);

  int TestCases;
  int t;
  int A;
  int B;
  int i;
  int m;
  int n;
  int P10;
  int P;
  int Answer;
  int Number[10];

  scanf("%d", &TestCases);
  for (t = 1; t <= TestCases; t++) {
    Answer = 0;
    scanf("%d%d", &A, &B);
    if (B < 21) {
      printf("Case #%d: 0\n", t);
      continue;
    }

    for (i = A; i < B; i++) {
      Number[0] = i;
      P10 = 0;
      P = 1;
      while (Number[0] /= 10) {
        P10++;
        P *= 10;
      }
      Number[0] = i;
      for (n = 1; n <= P10; n++)
        Number[n] = Number[n - 1] / P + 10 * (Number[n - 1] % P);

      for (m = 0; m < P10; m++)
        for (n = m + 1; n <= P10; n++)
          if (Number[n] == Number[m])
            Number[n] = 0;
      for (m = 1; m <= P10; m++) {
        if (Number[m] <= i) {
          Number[m] = 0;
          continue;
        }
        if (Number[m] > B) {
          Number[m] = 0;
          continue;
        }
        if (Number[m] < A) {
          Number[m] = 0;
          continue;
        }
        if (Number[m] > 0) {
          Answer++;
          continue;
        }
      }
    }

    printf("Case #%d: %d\n", t, Answer);
  }

  fclose(fin);
  fclose(fout);

  return 0;
}
