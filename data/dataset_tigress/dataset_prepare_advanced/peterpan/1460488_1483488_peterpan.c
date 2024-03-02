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
  int T;
  int tcase;
  int A;
  int B;
  int res;
  int n;
  int m;
  int d;
  int i;
  int ms[10];
  int cands;
  int j;

  char nstr[20];

  scanf("%d", &T);
  for (tcase = 1; tcase <= T; tcase++) {
    scanf("%d", &A);
    scanf("%d", &B);
    sprintf(nstr, "%d%d", A, A);
    d = strlen(nstr) / 2;
    res = 0;
    for (n = A; n < B; n++) {
      cands = 0;
      for (i = 1; i < d; i++) {
        nstr[i + d] = 0;
        sscanf(nstr + i, "%d", &m);
        nstr[i + d] = nstr[i];
        if (n < m && m <= B) {
          for (j = 0; j < cands; j++)
            if (ms[cands] == m)
              break;
          if (j == cands) {
            ms[cands++] = m;
            res++;
          }
        }
      }
      for (i = d - 1; i >= 0; i--) {
        if (nstr[i] == '9')
          nstr[i] = nstr[i + d] = '0';
        else {
          nstr[i]++;
          nstr[i + d]++;
          break;
        }
      }
    }
    printf("Case #%d: %d\r\n", tcase, res);
  }
  return 0;
}
