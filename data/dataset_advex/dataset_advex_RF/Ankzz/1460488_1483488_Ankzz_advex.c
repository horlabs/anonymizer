#include <stdio.h>

typedef FILE td_F;
int main(int kbci_Var, char *jguc_Var[]) {
  freopen("replace-me.out", "w", stdout);

  int ret_val = 0;
  FILE *mloF_Var, *dokF_Var;
  mloF_Var =
      (kbci_Var <= 1) ? fopen("input.txt", "r") : fopen(jguc_Var[1], "r");
  dokF_Var = fopen("output.txt", "w+");
  if (mloF_Var) {
    int fbwi_Var;

    fscanf(mloF_Var, "%d", &fbwi_Var);

    {
      int omgi_Var = 0;
      while (omgi_Var < fbwi_Var) {
        int dlqi_Var, lqxi_Var;
        int gjai_Var;
        int s = 1;
        int drbi_Var = 0;
        int ic, me = 10;

        fscanf(mloF_Var, "%d %d", &dlqi_Var, &lqxi_Var);
        drbi_Var = dlqi_Var;
        while (drbi_Var = drbi_Var / 10) {
          s++;
          me *= 10;
        }

        {
          int juxi_Var = dlqi_Var;
          while (juxi_Var <= lqxi_Var) {
            int m = me;
            while ((m = m / 10) >= 10) {
              int t = (juxi_Var % m) * (me / m) + (juxi_Var / m);
              if (juxi_Var < t && t <= lqxi_Var && t >= dlqi_Var) {
                drbi_Var++;
              }
            }
            juxi_Var++;
          }
        }

        fprintf(dokF_Var, "Case #%d: %d\n", omgi_Var + 1, drbi_Var);
        omgi_Var++;
      }
    }
    fclose(mloF_Var);
  }
  fclose(dokF_Var);
  return ret_val;
}
