#include <stdio.h>
#include <stdlib.h>

typedef FILE td_FILEFI;
typedef FILE td_FILEFIL;

typedef FILE td_F;

typedef FILE td_FILEF;

typedef FILE td_FILE;

typedef FILE td_FI;

typedef FILE td_FIL;

int main() {
  int ret_val = 0;
  FILE *tqfF_Var, *zskF_Var;
  int gzui_Var, lipi_Var, dtmi_Var, flag_x, flag_o, flagd_x, flagd_o, flag = 0;
  char lqxc_Var[4][4];
  tqfF_Var = fopen("A-small-attempt1(1).in", "r");
  zskF_Var = fopen("output.txt", "w");
  fscanf(tqfF_Var, "%d", &dtmi_Var);
  int urxi_Var;
  for (urxi_Var = 1; urxi_Var <= dtmi_Var; urxi_Var++) {
    for (gzui_Var = 0; gzui_Var < 4; gzui_Var++)
      fscanf(tqfF_Var, "%s", lqxc_Var[gzui_Var]);
    flag = 0;
    flagd_x = flagd_o = 4;
    for (gzui_Var = 0; gzui_Var < 4; gzui_Var++) {
      flag_x = flag_o = 4;
      for (lipi_Var = 0; lipi_Var < 4; lipi_Var++) {
        if (lqxc_Var[gzui_Var][lipi_Var] == 'T')
          flag_x -= 1;
        else if (lqxc_Var[gzui_Var][lipi_Var] == 'X')
          flag_x -= 1;
        if (lqxc_Var[gzui_Var][lipi_Var] == 'T')
          flag_o -= 1;
        else if (lqxc_Var[gzui_Var][lipi_Var] == 'O')
          flag_o -= 1;
        if (gzui_Var == lipi_Var) {
          if (lqxc_Var[gzui_Var][lipi_Var] == 'X' ||
              lqxc_Var[gzui_Var][lipi_Var] == 'T')
            flagd_x -= 1;
          else if (lqxc_Var[gzui_Var][lipi_Var] == 'O' ||
                   lqxc_Var[gzui_Var][lipi_Var] == 'T')
            flagd_o -= 1;
        }
      }
      if (flag_x == 0) {
        fprintf(zskF_Var, "Case #%d: X won\n", urxi_Var);
        break;
      } else if (flag_o == 0) {
        fprintf(zskF_Var, "Case #%d: O won\n", urxi_Var);
        break;
      }
    }
    if (flagd_x == 0) {
      fprintf(zskF_Var, "Case #%d: X won\n", urxi_Var);
      continue;
    } else if (flagd_o == 0) {
      fprintf(zskF_Var, "Case #%d: O won\n", urxi_Var);
      continue;

    } else if (flag_x == 0 || flag_o == 0)
      continue;
    flagd_x = flagd_o = 4;
    for (lipi_Var = 0; lipi_Var < 4; lipi_Var++) {
      flag_x = flag_o = 4;
      {
        gzui_Var = 0;
        for (; gzui_Var < 4;) {
          if (lqxc_Var[gzui_Var][lipi_Var] == 'T')
            flag_x -= 1;
          else if (lqxc_Var[gzui_Var][lipi_Var] == 'X')
            flag_x -= 1;

          if (lqxc_Var[gzui_Var][lipi_Var] == 'O' ||
              lqxc_Var[gzui_Var][lipi_Var] == 'T')
            flag_o -= 1;
          if (lqxc_Var[gzui_Var][lipi_Var] == '.')
            flag = 1;

          if ((gzui_Var + lipi_Var) == 3) {
            if (lqxc_Var[gzui_Var][lipi_Var] == 'X' ||
                lqxc_Var[gzui_Var][lipi_Var] == 'T')
              flagd_x -= 1;
            if (lqxc_Var[gzui_Var][lipi_Var] == 'O' ||
                lqxc_Var[gzui_Var][lipi_Var] == 'T')
              flagd_o -= 1;
          }
          gzui_Var++;
        }
      }
      if (flag_x == 0) {
        fprintf(zskF_Var, "Case #%d: X won\n", urxi_Var);
        break;
      } else if (flag_o == 0) {
        fprintf(zskF_Var, "Case #%d: O won\n", urxi_Var);
        break;
      }
    }
    if (flagd_x == 0) {
      fprintf(zskF_Var, "Case #%d: X won\n", urxi_Var);
      continue;
    } else {
      if (flagd_o == 0) {
        fprintf(zskF_Var, "Case #%d: O won\n", urxi_Var);
        continue;

      } else {
        if (flag_x == 0 || flag_o == 0)
          continue;
      }
    }
    if (flag == 1)
      fprintf(zskF_Var, "Case #%d: Game has not completed\n", urxi_Var);
    else
      fprintf(zskF_Var, "Case #%d: Draw\n", urxi_Var);
  }
  fclose(tqfF_Var);
  fclose(zskF_Var);
  system("pause");
  return ret_val;
}
