#include <stdio.h>

typedef FILE td_FILE;

typedef FILE td_F;

typedef short td_s;

typedef FILE td_FI;

int main(int emqi_Var, char *chmc_Var[]) {

  freopen("replace-me.in", "r", stdin);

  int ret_val = 0;

  FILE *kyuF_Var, *kwsF_Var;
  kyuF_Var =
      (emqi_Var <= 1) ? fopen("input.txt", "r+") : fopen(chmc_Var[1], "r+");
  kwsF_Var = fopen("output.txt", "w+");
  if (kyuF_Var) {
    int fbwi_Var;
    int omgi_Var;
    int zhti_Var, xcri_Var;
    fscanf(kyuF_Var, "%d", &fbwi_Var);
    for (omgi_Var = 0; omgi_Var < fbwi_Var; omgi_Var++) {
      int N, S, p;
      int gymi_Var = 0, s = 0;
      fscanf(kyuF_Var, "%d %d %d", &N, &S, &p);

      for (zhti_Var = 0; zhti_Var < N; zhti_Var++) {
        int zgli_Var, zuvi_Var, z;
        td_s flag = 0;

        fscanf(kyuF_Var, "%d", &zgli_Var);

        for (zuvi_Var = 3, z = p; zuvi_Var > 1 && z <= zgli_Var;
             zuvi_Var = xcri_Var) {

          zuvi_Var = (zgli_Var - z) / 2;
          xcri_Var = (zuvi_Var > z) ? zuvi_Var - z + 1 : z - zuvi_Var;

          if (xcri_Var > 2) {
            if (zuvi_Var < z)
              break;
            z++;
          } else if (xcri_Var == 2) {
            if (s < S) {
              s++;
              gymi_Var++;
              flag = 1;
            } else {
              if (zuvi_Var < z)
                break;
            }

            z++;
          } else {
            if (!flag) {
              gymi_Var++;
              flag = 0;
            } else
              s--;

            break;
          }
        }
      }
      fprintf(kwsF_Var, "Case #%d: %d\n", omgi_Var + 1, gymi_Var);
    }
  }
  return ret_val;
}
