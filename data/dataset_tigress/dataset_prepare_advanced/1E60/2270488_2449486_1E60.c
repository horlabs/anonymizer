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
  int t;
  int T;

  int M;
  int N;

  int x;
  int y;

  scanf("%d\n", &T);
  for (t = 1; t <= T; t++) {
    scanf("%d %d\n", &N, &M);
    int Goal[M][100];
    int Board[M][100];

    for (y = 0; y < N; y++) {
      for (x = 0; x < M; x++) {
        scanf("%d ", &Goal[x][y]);
        Board[x][y] = 100;
      }
    }

    for (y = 0; y < N; y++) {
      int setting = 0;
      for (x = 0; x < M; x++) {
        if (setting < Goal[x][y]) {
          setting = Goal[x][y];
        }
      }
      for (x = 0; x < M; x++) {
        if (setting < Board[x][y]) {
          Board[x][y] = setting;
        }
      }
    }

    for (x = 0; x < M; x++) {
      int setting = 0;
      for (y = 0; y < N; y++) {
        if (setting < Goal[x][y]) {
          setting = Goal[x][y];
        }
      }
      for (y = 0; y < N; y++) {
        if (setting < Board[x][y]) {
          Board[x][y] = setting;
        }
      }
    }

    int possible = 1;
    for (y = 0; y < N; y++) {
      for (x = 0; x < M; x++) {
        if (Board[x][y] != Goal[x][y])
          possible = 0;
      }
    }
    printf("Case #%d: %s\n", t, (possible) ? "YES" : "NO");
  }
  return 0;
}