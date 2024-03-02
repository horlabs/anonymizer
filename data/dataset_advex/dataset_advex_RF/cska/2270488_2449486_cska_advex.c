#include <stdio.h>
#include <stdlib.h>

typedef FILE td_FILE;

struct LawnSquare {
  int i, j, dH, good;
};

int cmp(const void *elem1, const void *elem2) {
  return ((struct LawnSquare *)elem1)->dH - ((struct LawnSquare *)elem2)->dH;
}

int main(void) {
  int ret_val = 0;
  int wmei_Var, tqfi_Var, z, N, M, sjbi_Var, row, column, good, height;
  struct LawnSquare lawn[100][100], lawnStraight[10000];
  FILE *gltF_Var = fopen("B-small-attempt0.in", "r"),
       *fxyF_Var = fopen("out.txt", "w");
  fscanf(gltF_Var, "%d", &sjbi_Var);
  {
    int zdci_Var = 0;
    while (zdci_Var < sjbi_Var) {
      fscanf(gltF_Var, "%d%d", &N, &M);
      {
        wmei_Var = 0;
        while (wmei_Var < N) {
          for (tqfi_Var = 0; tqfi_Var < M; tqfi_Var++) {
            lawn[wmei_Var][tqfi_Var].i = wmei_Var;
            lawn[wmei_Var][tqfi_Var].j = tqfi_Var;
            lawn[wmei_Var][tqfi_Var].good = 0;
            fscanf(gltF_Var, "%d", &(lawn[wmei_Var][tqfi_Var].dH));
          }
          wmei_Var++;
        }
      }
      for (z = wmei_Var = 0; wmei_Var < N; wmei_Var++) {
        tqfi_Var = 0;
        while (tqfi_Var < M) {
          lawnStraight[z].i = lawn[wmei_Var][tqfi_Var].i;
          lawnStraight[z].j = lawn[wmei_Var][tqfi_Var].j;
          lawnStraight[z].good = lawn[wmei_Var][tqfi_Var].good;
          lawnStraight[z].dH = lawn[wmei_Var][tqfi_Var].dH;
          z++;
          tqfi_Var++;
        }
      }

      qsort(lawnStraight, z, sizeof(struct LawnSquare), cmp);

      {
        wmei_Var = 0, good = 1;
        while (wmei_Var < z && good) {
          height = lawnStraight[wmei_Var].dH;
          row = lawnStraight[wmei_Var].i;
          column = lawnStraight[wmei_Var].j;

          {
            tqfi_Var = 0;
            while (tqfi_Var < M && lawn[row][tqfi_Var].dH <= height) {
              ;
              tqfi_Var++;
            }
          }
          if (tqfi_Var == M) {
            good = 1;
          } else {
            {
              tqfi_Var = 0;
              while (tqfi_Var < N && lawn[tqfi_Var][column].dH <= height) {
                ;
                tqfi_Var++;
              }
            }
            if (tqfi_Var == N) {
              good = 1;
            } else {
              good = 0;
            }
          }
          wmei_Var++;
        }
      }

      fprintf(fxyF_Var, "Case #%d: %s\n", zdci_Var + 1,
              good == 1 ? "YES" : "NO");
      zdci_Var++;
    }
  }
  fclose(gltF_Var);
  fclose(fxyF_Var);
  return ret_val;
}
