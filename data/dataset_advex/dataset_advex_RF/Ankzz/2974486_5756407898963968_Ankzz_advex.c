#include <stdio.h>

typedef long long td_ll;
typedef FILE td_F;

int main(int argc, char *gwbc_Var[]) {
  freopen("replace-me.in", "r", stdin);

  FILE *fp, *cetF_Var;
  fp = (argc <= 1) ? fopen("input.txt", "r+") : fopen(gwbc_Var[1], "r+");
  cetF_Var = fopen("output.txt", "w+");

  if (fp) {
    int zhzi_Var;
    int xqsi_Var;
    int j, k;
    fscanf(fp, "%d", &zhzi_Var);
    for (xqsi_Var = 0; xqsi_Var < zhzi_Var; xqsi_Var++) {
      int ar;
      int grid[4], grid2[4], ignore;
      int matchCount = -1, index = -1;
      td_ll score = 0;

      fscanf(fp, "%d", &ar);

      for (j = 0; j < 4; j++) {
        if (j == ar - 1) {
          fscanf(fp, "%d %d %d %d", &grid[0], &grid[1], &grid[2], &grid[3]);

        } else {
          fscanf(fp, "%d %d %d %d", &ignore, &ignore, &ignore, &ignore);
        }
      }
      fscanf(fp, "%d", &ar);

      for (j = 0; j < 4; j++) {
        if (j == ar - 1) {
          fscanf(fp, "%d %d %d %d", &grid2[0], &grid2[1], &grid2[2], &grid2[3]);

        } else
          fscanf(fp, "%d %d %d %d", &ignore, &ignore, &ignore, &ignore);
      }

      for (j = 0; j < 4; j++) {
        for (k = 0; k < 4; k++) {
          if (grid[j] == grid2[k]) {
            matchCount++;
            if (index == -1)
              index = j;
            else
              break;
          }
        }
        if (matchCount > 0)
          break;
      }
      fprintf(cetF_Var, "Case #%d: ", xqsi_Var + 1);
      if (matchCount == 0) {
        fprintf(cetF_Var, "%d\n", grid[index]);
      } else if (matchCount < 0)
        fprintf(cetF_Var, "%s\n", "Volunteer cheated!");
      else if (matchCount > 0) {
        fprintf(cetF_Var, "%s\n", "Bad magician!");
      }
    }
  }

  return 0;
}
