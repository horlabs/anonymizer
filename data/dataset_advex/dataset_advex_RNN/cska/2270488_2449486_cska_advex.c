#include <stdio.h>
#include <stdlib.h>

struct LawnSquare {
  int i, j, dH, good;
};

int cmp(const void *elem1, const void *elem2) {
  return ((struct LawnSquare *)elem1)->dH - ((struct LawnSquare *)elem2)->dH;
}

int main(void) {
  int ishi_Var, j, z, iixi_Var, N, M, T, row, column, good, height;
  struct LawnSquare lawn[100][100], lawnStraight[10000];
  FILE *duaF_Var = fopen("B-small-attempt0.in", "r"),
       *zvmF_Var = fopen("out.txt", "w");

  fscanf(duaF_Var, "%d", &T);

  for (iixi_Var = 0; iixi_Var < T; iixi_Var++) {
    fscanf(duaF_Var, "%d%d", &N, &M);
    for (ishi_Var = 0; ishi_Var < N; ishi_Var++)
      for (j = 0; j < M; j++) {
        lawn[ishi_Var][j].i = ishi_Var;
        lawn[ishi_Var][j].j = j;
        lawn[ishi_Var][j].good = 0;
        fscanf(duaF_Var, "%d", &(lawn[ishi_Var][j].dH));
      }

    for (z = ishi_Var = 0; ishi_Var < N; ishi_Var++)
      for (j = 0; j < M; j++) {
        lawnStraight[z].i = lawn[ishi_Var][j].i;
        lawnStraight[z].j = lawn[ishi_Var][j].j;
        lawnStraight[z].good = lawn[ishi_Var][j].good;
        lawnStraight[z].dH = lawn[ishi_Var][j].dH;
        z++;
      }

    qsort(lawnStraight, z, sizeof(struct LawnSquare), cmp);

    for (ishi_Var = 0, good = 1; ishi_Var < z && good; ishi_Var++) {
      height = lawnStraight[ishi_Var].dH;
      row = lawnStraight[ishi_Var].i;
      column = lawnStraight[ishi_Var].j;

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

    fprintf(zvmF_Var, "Case #%d: %s\n", iixi_Var + 1, good == 1 ? "YES" : "NO");
  }

  fclose(duaF_Var);
  fclose(zvmF_Var);
  return 0;
}
