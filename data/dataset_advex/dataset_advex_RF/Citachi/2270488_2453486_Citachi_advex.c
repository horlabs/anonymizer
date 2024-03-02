#include <stdio.h>
#include <stdlib.h>

typedef FILE td_FILEFILEFIL;

typedef FILE td_FILEFILEFI;

typedef FILE td_FILEFILEF;

typedef FILE td_FILEFILE;

typedef FILE td_FILEFIL;

typedef FILE td_FILEFI;

typedef FILE td_FILEF;

typedef FILE td_FILE;

typedef FILE td_FIL;

int main() {
  FILE *dyaF_Var, *fp_out;
  int ojdi_Var, svzi_Var, sjbi_Var, flag_x, flag_o, flagd_x, flagd_o, flag = 0;
  char hgec_Var[4][4];
  dyaF_Var = fopen("A-small-attempt1(1).in", "r");
  fp_out = fopen("output.txt", "w");
  fscanf(dyaF_Var, "%d", &sjbi_Var);
  for (int esdi_Var = 1; esdi_Var <= sjbi_Var; esdi_Var++) {
    for (ojdi_Var = 0; ojdi_Var < 4; ojdi_Var++)
      fscanf(dyaF_Var, "%s", hgec_Var[ojdi_Var]);
    flag = 0;
    flagd_x = flagd_o = 4;
    {
      ojdi_Var = 0;
      while (ojdi_Var < 4) {
        flag_x = flag_o = 4;
        for (svzi_Var = 0; svzi_Var < 4; svzi_Var++) {
          if (hgec_Var[ojdi_Var][svzi_Var] == 'T')
            flag_x -= 1;
          else if (hgec_Var[ojdi_Var][svzi_Var] == 'X')
            flag_x -= 1;
          if (hgec_Var[ojdi_Var][svzi_Var] == 'O' ||
              hgec_Var[ojdi_Var][svzi_Var] == 'T')
            flag_o -= 1;
          if (ojdi_Var == svzi_Var) {
            if (hgec_Var[ojdi_Var][svzi_Var] == 'X' ||
                hgec_Var[ojdi_Var][svzi_Var] == 'T')
              flagd_x -= 1;
            else {
              if (hgec_Var[ojdi_Var][svzi_Var] == 'O' ||
                  hgec_Var[ojdi_Var][svzi_Var] == 'T')
                flagd_o -= 1;
            }
          }
        }
        if (flag_x == 0) {
          fprintf(fp_out, "Case #%d: X won\n", esdi_Var);
          break;
        } else if (flag_o == 0) {
          fprintf(fp_out, "Case #%d: O won\n", esdi_Var);
          break;
        }
        ojdi_Var++;
      }
    }
    if (flagd_x == 0) {
      fprintf(fp_out, "Case #%d: X won\n", esdi_Var);
      continue;
    } else if (flagd_o == 0) {
      fprintf(fp_out, "Case #%d: O won\n", esdi_Var);
      continue;

    } else if (flag_x == 0 || flag_o == 0)
      continue;
    flagd_x = flagd_o = 4;
    for (svzi_Var = 0; svzi_Var < 4; svzi_Var++) {
      flag_x = flag_o = 4;
      for (ojdi_Var = 0; ojdi_Var < 4; ojdi_Var++) {
        if (hgec_Var[ojdi_Var][svzi_Var] == 'T')
          flag_x -= 1;
        else if (hgec_Var[ojdi_Var][svzi_Var] == 'X')
          flag_x -= 1;
        if (hgec_Var[ojdi_Var][svzi_Var] == 'T')
          flag_o -= 1;
        else if (hgec_Var[ojdi_Var][svzi_Var] == 'O')
          flag_o -= 1;
        if (hgec_Var[ojdi_Var][svzi_Var] == '.')
          flag = 1;

        if ((ojdi_Var + svzi_Var) == 3) {
          if (hgec_Var[ojdi_Var][svzi_Var] == 'X' ||
              hgec_Var[ojdi_Var][svzi_Var] == 'T')
            flagd_x -= 1;
          if (hgec_Var[ojdi_Var][svzi_Var] == 'T')
            flagd_o -= 1;
          else if (hgec_Var[ojdi_Var][svzi_Var] == 'O')
            flagd_o -= 1;
        }
      }
      if (flag_x == 0) {
        fprintf(fp_out, "Case #%d: X won\n", esdi_Var);
        break;
      } else if (flag_o == 0) {
        fprintf(fp_out, "Case #%d: O won\n", esdi_Var);
        break;
      }
    }
    if (flagd_x == 0) {
      fprintf(fp_out, "Case #%d: X won\n", esdi_Var);
      continue;
    } else if (flagd_o == 0) {
      fprintf(fp_out, "Case #%d: O won\n", esdi_Var);
      continue;

    } else if (flag_o == 0)
      continue;
    else if (flag_x == 0)
      continue;
    if (flag == 1)
      fprintf(fp_out, "Case #%d: Game has not completed\n", esdi_Var);
    else
      fprintf(fp_out, "Case #%d: Draw\n", esdi_Var);
  }
  fclose(dyaF_Var);
  fclose(fp_out);
  system("pause");
  return 0;
}
