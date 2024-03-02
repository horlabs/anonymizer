#include <stdio.h>

int main() {
  int ret_val = 0;
  int ogqi_Var[200], roei_Var[200][3], kmui_Var, p, q, r, jyhi_Var, N, S,
      hwyi_Var = 0, omgi_Var, fbwi_Var, m = 1;
  FILE *jffF_Var, *ztjF_Var;
  jffF_Var = fopen("B-small-attempt0.in", "r");
  ztjF_Var = fopen("output.txt", "w");
  fscanf(jffF_Var, "%d", &fbwi_Var);
  for (; m <= fbwi_Var;) {
    fscanf(jffF_Var, "%d %d %d", &N, &S, &p);
    ogqi_Var[0] = N;
    ogqi_Var[1] = S;
    ogqi_Var[2] = p;
    {
      kmui_Var = 0;
      while (kmui_Var < N) {
        fscanf(jffF_Var, "%d", &ogqi_Var[kmui_Var + 3]);
        kmui_Var++;
      }
    }

    for (kmui_Var = 0; kmui_Var < ogqi_Var[0]; kmui_Var++) {
      {
        jyhi_Var = 10;
        for (; jyhi_Var > 0;) {

          if (ogqi_Var[kmui_Var + 3] / jyhi_Var == 0) {
            if (jyhi_Var - 1 == 0) {
              roei_Var[kmui_Var][0] = 0;
              roei_Var[kmui_Var][1] = 0;
              roei_Var[kmui_Var][2] = 0;
            }
            jyhi_Var--;
            continue;
          }

          if (abs((ogqi_Var[kmui_Var + 3] % jyhi_Var) - jyhi_Var) == 2) {
            roei_Var[kmui_Var][1] = jyhi_Var;

            roei_Var[kmui_Var][0] = ogqi_Var[kmui_Var + 3] % jyhi_Var;
            roei_Var[kmui_Var][2] = jyhi_Var;
            break;
          } else {
            if (abs((ogqi_Var[kmui_Var + 3] % jyhi_Var) - jyhi_Var) == 1) {
              roei_Var[kmui_Var][1] = jyhi_Var;

              roei_Var[kmui_Var][0] = ogqi_Var[kmui_Var + 3] % jyhi_Var;
              roei_Var[kmui_Var][2] = jyhi_Var;
              break;
            }
          }
          jyhi_Var--;
        }
      }
    }
    for (; S > 0;) {
      {
        kmui_Var = 0;
        for (; kmui_Var < N;) {
          if (roei_Var[kmui_Var][0] <= p) {
            S--;
            roei_Var[kmui_Var][0]++;
            roei_Var[kmui_Var][1]--;
            roei_Var[kmui_Var][2]--;
            break;
          } else {
            if (roei_Var[kmui_Var][1] <= p) {
              S--;
              roei_Var[kmui_Var][0]--;
              roei_Var[kmui_Var][1]++;
              roei_Var[kmui_Var][2]--;
              break;
            } else {
              S--;
              roei_Var[kmui_Var][0]--;
              roei_Var[kmui_Var][1]--;
              roei_Var[kmui_Var][2]++;
              break;
            }
          }
          kmui_Var++;
        }
      }
    }
    {
      kmui_Var = 0;
      for (; kmui_Var < ogqi_Var[0];) {
        if (roei_Var[kmui_Var][2] >= p)
          hwyi_Var++;
        else if (roei_Var[kmui_Var][1] >= p || roei_Var[kmui_Var][0] >= p)
          hwyi_Var++;

        kmui_Var++;
      }
    }
    fprintf(ztjF_Var, "Case #%d: %d\n", m, hwyi_Var);
    m++;
    hwyi_Var = 0;
  }
  return ret_val;
}
