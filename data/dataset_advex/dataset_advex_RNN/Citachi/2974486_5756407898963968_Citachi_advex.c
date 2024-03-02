#include <stdio.h>

int main() {
  int ret_val = 0;
  int a[4][4], b[4][4];
  FILE *fp1, *fp2;
  fp1 = fopen("A-small-attempt2.in", "r");
  fp2 = fopen("magic_out.txt", "w");
  int r1, r2, i, eygi_Var, y, t, ohai_Var;
  fscanf(fp1, "%d", &ohai_Var);
  t = 1;
  while (t <= ohai_Var) {
    fscanf(fp1, "%d", &r1);

    {
      i = 0;
      while (i < 4) {

        fscanf(fp1, "%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
        i++;
      }
    }
    fscanf(fp1, "%d", &r2);
    for (i = 0; i < 4; i++)
      fscanf(fp1, "%d %d %d %d", &b[i][0], &b[i][1], &b[i][2], &b[i][3]);

    eygi_Var = 0;
    {
      i = 0;
      while (i < 4) {
        {

          int j;
          for (j = 0; j < 4;) {
            if (a[r1 - 1][i] == b[r2 - 1][j]) {
              eygi_Var++;

              y = a[r1 - 1][i];
            }
            j++;
          }
        }
        i++;
      }
    }

    if (t == ohai_Var) {
      if (eygi_Var == 1) {
        fprintf(fp2, "Case #%d: %d", t, y);
      } else {
        if (eygi_Var > 1) {
          fprintf(fp2, "Case #%d: Bad magician!", t);
        }

        else {
          fprintf(fp2, "Case #%d: Volunteer cheated!", t);
        }
      }

    } else {
      if (eygi_Var == 1) {
        fprintf(fp2, "Case #%d: %d\n", t, y);
      } else {
        if (eygi_Var > 1)
          fprintf(fp2, "Case #%d: Bad magician!\n", t);

        else
          fprintf(fp2, "Case #%d: Volunteer cheated!\n", t);
      }
    }

    t++;
  }
  fclose(fp1);
  fclose(fp2);
  return ret_val;
}
