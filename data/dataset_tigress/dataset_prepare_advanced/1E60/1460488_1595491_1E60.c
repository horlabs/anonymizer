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

int calc_best(int total, int s) {
  if (total == 0) {
    (!s);
    return 0;
  }
  if (!s) {
    if (total % 3 == 0)
      return total / 3;
    else
      return total / 3 + 1;
  } else {
    if (total % 3 == 2)
      return total / 3 + 2;
    else
      return total / 3 + 1;
  }
  (0);
}

int above_num;

void search(int *sc, int rest, int S, int p, int curr_count) {
  int total = *sc;
  if (rest == 0) {
    (S == 0);

    if (above_num < curr_count) {
      above_num = curr_count;
    }
    return;
  }

  if (rest > S) {

    int inc;
    inc = (calc_best(total, 0) >= p) ? 1 : 0;
    search(sc + 1, rest - 1, S, p, curr_count + inc);
  }
  if (S > 0 && total >= 2) {

    int inc;
    inc = (calc_best(total, 1) >= p) ? 1 : 0;
    search(sc + 1, rest - 1, S - 1, p, curr_count + inc);
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
  int t;

  scanf("%d\n", &T);
  for (t = 1; t <= T; t++) {
    int N;
    int S;
    int p;

    int n;
    int sc[100];
    memset(sc, 0, sizeof(sc));
    scanf("%d %d %d ", &N, &S, &p);
    for (n = 0; n < N; n++) {
      scanf("%d ", &sc[n]);
    }
    above_num = 0;
    search(sc, N, S, p, 0);
    printf("Case #%d: %d\n", t, above_num);
  }
  return 0;
}
