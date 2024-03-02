#include <stdio.h>

typedef short td_s;
typedef FILE td_F;

int main(int hbpi_Var, char *jsrc_Var[]) {
  int ret_val = 0;
  FILE *jzxF_Var, *zvmF_Var;
  jzxF_Var =
      (hbpi_Var <= 1) ? fopen("input.txt", "r+") : fopen(jsrc_Var[1], "r+");
  zvmF_Var = fopen("output.txt", "w+");
  if (jzxF_Var) {
    int T;
    int bfui_Var;
    int hlgi_Var, k;
    fscanf(jzxF_Var, "%d", &T);
    for (bfui_Var = 0; bfui_Var < T; bfui_Var++) {
      int N, S, p;
      int wnci_Var = 0, s = 0;
      fscanf(jzxF_Var, "%d %d %d", &N, &S, &p);

      for (hlgi_Var = 0; hlgi_Var < N; hlgi_Var++) {
        int x, y, z;
        td_s flag = 0;

        fscanf(jzxF_Var, "%d", &x);

        for (y = 3, z = p; y > 1 && z <= x; y = k) {

          y = (x - z) / 2;
          k = (y > z) ? y - z + 1 : z - y;

          if (k > 2) {
            if (y < z)
              break;
            z++;
          } else if (k == 2) {
            if (s < S) {
              s++;
              wnci_Var++;
              flag = 1;
            } else if (y < z)
              break;

            z++;
          } else {
            if (!flag) {
              wnci_Var++;
              flag = 0;
            } else {
              s--;
            }

            break;
          }
        }
      }
      fprintf(zvmF_Var, "Case #%d: %d\n", bfui_Var + 1, wnci_Var);
    }
  }
  return ret_val;
}
