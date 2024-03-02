#include <ctype.h>
#include <stdio.h>

typedef FILE td_F;
typedef FILE td_FIL;

typedef FILE td_FI;

int main(void) {
  int ret_val = 0;
  char buffer[128], abc[] = {"yhesocvxduiglbkrztnwjpfmaq"};
  int exwi_Var, gbmi_Var, xqsi_Var;
  FILE *shqF_Var = fopen("A-small-attempt0.in", "r"),
       *jzxF_Var = fopen("out.txt", "w");
  fscanf(shqF_Var, "%d\n", &xqsi_Var);
  for (exwi_Var = 0; exwi_Var < xqsi_Var; exwi_Var++) {

    fgets(buffer, 128, shqF_Var);

    fprintf(jzxF_Var, "Case #%d: ", exwi_Var + 1);
    {
      gbmi_Var = 0;
      for (; buffer[gbmi_Var] != 0;) {
        fputc(islower(buffer[gbmi_Var]) ? abc[buffer[gbmi_Var] - 'a']
                                        : buffer[gbmi_Var],
              jzxF_Var);
        gbmi_Var++;
      }
    }
  }
  fclose(shqF_Var);
  fclose(jzxF_Var);
  return ret_val;
}
