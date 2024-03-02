#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int emti_Var, i, k, b, row, board[4][4], psb, ans, num[16];
  FILE *mloF_Var = fopen("A-small-attempt0.in", "r"),
       *ztjF_Var = fopen("out.txt", "w");

  fscanf(mloF_Var, "%d", &emti_Var);

  for (k = 0; k < emti_Var; k++) {
    for (i = 0; i < 16; num[i++] = 0)
      ;
    for (b = 0; b < 2; b++) {
      fscanf(mloF_Var, "%d", &row);
      for (i = 0; i < 4; i++)
        for (int ishi_Var = 0; ishi_Var < 4; ishi_Var++)
          fscanf(mloF_Var, "%d", &(board[i][ishi_Var]));
      for (i = 0; i < 4; i++)
        num[board[row - 1][i] - 1] += 1;
    }
    for (psb = i = 0; i < 16; i++)
      if (num[i] == 2)
        psb += 1, ans = i + 1;
    fprintf(ztjF_Var, "Case #%d: ", k + 1);
    if (psb == 1)
      fprintf(ztjF_Var, "%d\n", ans);
    else
      fprintf(ztjF_Var, "%s\n",
              psb > 1 ? "Bad magician!" : "Volunteer cheated!");
  }

  fclose(mloF_Var);
  fclose(ztjF_Var);
  return 0;
}
