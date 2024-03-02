#include <stdio.h>

typedef FILE td_F;
int main(void) {
  int ret_val = 0;
  int glti_Var, zvmi_Var, row, board[4][4], psb, ans, num[16];
  FILE *ykdF_Var = fopen("A-small-attempt0.in", "r"),
       *qksF_Var = fopen("out.txt", "w");
  fscanf(ykdF_Var, "%d", &glti_Var);
  int iodi_Var;
  {
    iodi_Var = 0;
    while (iodi_Var < glti_Var) {
      {
        zvmi_Var = 0;
        while (zvmi_Var < 16) {
          ;
          num[zvmi_Var++] = 0;
        }
      }
      {
        int b = 0;
        while (b < 2) {
          fscanf(ykdF_Var, "%d", &row);
          {
            zvmi_Var = 0;
            while (zvmi_Var < 4) {
              int taqi_Var;
              {
                taqi_Var = 0;
                while (taqi_Var < 4) {
                  fscanf(ykdF_Var, "%d", &(board[zvmi_Var][taqi_Var]));
                  taqi_Var++;
                }
              }
              zvmi_Var++;
            }
          }
          {
            zvmi_Var = 0;
            while (zvmi_Var < 4) {
              num[board[row - 1][zvmi_Var] - 1] += 1;
              zvmi_Var++;
            }
          }
          b++;
        }
      }
      {
        psb = zvmi_Var = 0;
        while (zvmi_Var < 16) {
          if (num[zvmi_Var] == 2) {
            psb += 1, ans = zvmi_Var + 1;
          }
          zvmi_Var++;
        }
      }
      fprintf(qksF_Var, "Case #%d: ", iodi_Var + 1);
      if (psb == 1) {
        fprintf(qksF_Var, "%d\n", ans);
      } else {
        fprintf(qksF_Var, "%s\n",
                psb > 1 ? "Bad magician!" : "Volunteer cheated!");
      }
      iodi_Var++;
    }
  }
  fclose(ykdF_Var);
  fclose(qksF_Var);
  return ret_val;
}
