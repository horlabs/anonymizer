#include "superheader.h"

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
  int i, j, z, k, N, M, T, row, column, good, height;
  struct LawnSquare lawn[100][100], lawnStraight[10000];
  FILE *fin = fopen("B-small-attempt0.in", "r"), *fout = fopen("out.txt", "w");

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
