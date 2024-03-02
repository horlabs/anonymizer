#include <stdio.h>

typedef long long td_ll;
int main(int argc, char *axec_Var[]) {
  int ret_val = 0;
  FILE *duaF_Var, *o;
  duaF_Var = (argc <= 1) ? fopen("input.txt", "r+") : fopen(axec_Var[1], "r+");
  o = fopen("output.txt", "w+");
  if (duaF_Var) {
    int fxyi_Var;
    int i;
    int j, k;
    fscanf(duaF_Var, "%d", &fxyi_Var);
    for (i = 0; i < fxyi_Var; i++) {
      int ar;
      int grid[4], grid2[4], ignore;
      int matchCount = -1, index = -1;
      td_ll score = 0;

      fscanf(duaF_Var, "%d", &ar);

      for (j = 0; j < 4; j++) {
        if (j == ar - 1) {
          fscanf(duaF_Var, "%d %d %d %d", &grid[0], &grid[1], &grid[2],
                 &grid[3]);

        } else {
          fscanf(duaF_Var, "%d %d %d %d", &ignore, &ignore, &ignore, &ignore);
        }
      }
      fscanf(duaF_Var, "%d", &ar);

      for (j = 0; j < 4; j++) {
        if (j == ar - 1) {
          fscanf(duaF_Var, "%d %d %d %d", &grid2[0], &grid2[1], &grid2[2],
                 &grid2[3]);

        } else {
          fscanf(duaF_Var, "%d %d %d %d", &ignore, &ignore, &ignore, &ignore);
        }
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
      fprintf(o, "Case #%d: ", i + 1);
      if (matchCount == 0) {
        fprintf(o, "%d\n", grid[index]);
      } else if (matchCount < 0)
        fprintf(o, "%s\n", "Volunteer cheated!");
      else if (matchCount > 0) {
        fprintf(o, "%s\n", "Bad magician!");
      }
    }
  }
  return ret_val;
}
