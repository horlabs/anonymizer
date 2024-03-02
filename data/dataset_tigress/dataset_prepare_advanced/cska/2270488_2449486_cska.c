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

struct LawnSquare {
  int i, j, dH, good;
};

int cmp(const void *elem1, const void *elem2) {
  return ((struct LawnSquare *)elem1)->dH - ((struct LawnSquare *)elem2)->dH;
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
  int z;
  int k;
  int N;
  int M;
  int T;
  int row;
  int column;
  int good;
  int height;

  struct LawnSquare lawn[100][100];
  struct LawnSquare lawnStraight[10000];

  FILE *fin = fopen("B-small-attempt0.in", "r");
  FILE *fout = fopen("out.txt", "w");

  fscanf(fin, "%d", &T);

  for (k = 0; k < T; k++) {
    fscanf(fin, "%d%d", &N, &M);
    for (i = 0; i < N; i++)
      for (j = 0; j < M; j++) {
        lawn[i][j].i = i;
        lawn[i][j].j = j;
        lawn[i][j].good = 0;
        fscanf(fin, "%d", &(lawn[i][j].dH));
      }

    for (z = i = 0; i < N; i++)
      for (j = 0; j < M; j++) {
        lawnStraight[z].i = lawn[i][j].i;
        lawnStraight[z].j = lawn[i][j].j;
        lawnStraight[z].good = lawn[i][j].good;
        lawnStraight[z].dH = lawn[i][j].dH;
        z++;
      }

    qsort(lawnStraight, z, sizeof(struct LawnSquare), cmp);

    for (i = 0, good = 1; i < z && good; i++) {
      height = lawnStraight[i].dH;
      row = lawnStraight[i].i;
      column = lawnStraight[i].j;

      for (j = 0; j < M && lawn[row][j].dH <= height; j++)
        ;
      if (j == M)
        good = 1;
      else {
        for (j = 0; j < N && lawn[j][column].dH <= height; j++)
          ;
        if (j == N)
          good = 1;
        else
          good = 0;
      }
    }

    fprintf(fout, "Case #%d: %s\n", k + 1, good == 1 ? "YES" : "NO");
  }

  fclose(fin);
  fclose(fout);
  return 0;
}
