#include <stdio.h>

int main() {
  int ret_val = 0;
  int emqi_Var[4][4], jzxi_Var[4][4];
  FILE *fp1, *fp2;
  fp1 = fopen("A-small-attempt2.in", "r");
  fp2 = fopen("magic_out.txt", "w");
  int r1, r2, gbmi_Var, ddfi_Var, y, opvi_Var, zhzi_Var;
  fscanf(fp1, "%d", &zhzi_Var);
  opvi_Var = 1;
  for (; opvi_Var <= zhzi_Var;) {
    fscanf(fp1, "%d", &r1);

    {
      gbmi_Var = 0;
      while (gbmi_Var < 4) {

        fscanf(fp1, "%d %d %d %d", &emqi_Var[gbmi_Var][0],
               &emqi_Var[gbmi_Var][1], &emqi_Var[gbmi_Var][2],
               &emqi_Var[gbmi_Var][3]);
        gbmi_Var++;
      }
    }
    fscanf(fp1, "%d", &r2);
    {
      gbmi_Var = 0;
      for (; gbmi_Var < 4;) {
        fscanf(fp1, "%d %d %d %d", &jzxi_Var[gbmi_Var][0],
               &jzxi_Var[gbmi_Var][1], &jzxi_Var[gbmi_Var][2],
               &jzxi_Var[gbmi_Var][3]);
        gbmi_Var++;
      }
    }
    ddfi_Var = 0;
    for (gbmi_Var = 0; gbmi_Var < 4; gbmi_Var++) {

      for (int rffi_Var = 0; rffi_Var < 4; rffi_Var++) {
        if (emqi_Var[r1 - 1][gbmi_Var] == jzxi_Var[r2 - 1][rffi_Var]) {
          ddfi_Var++;

          y = emqi_Var[r1 - 1][gbmi_Var];
        }
      }
    }

    if (opvi_Var == zhzi_Var) {
      if (ddfi_Var == 1)
        fprintf(fp2, "Case #%d: %d", opvi_Var, y);
      else if (ddfi_Var > 1)
        fprintf(fp2, "Case #%d: Bad magician!", opvi_Var);

      else
        fprintf(fp2, "Case #%d: Volunteer cheated!", opvi_Var);

    } else {
      if (ddfi_Var == 1)
        fprintf(fp2, "Case #%d: %d\n", opvi_Var, y);
      else if (ddfi_Var > 1)
        fprintf(fp2, "Case #%d: Bad magician!\n", opvi_Var);

      else
        fprintf(fp2, "Case #%d: Volunteer cheated!\n", opvi_Var);
    }

    opvi_Var++;
  }
  fclose(fp1);
  fclose(fp2);
  return ret_val;
}
